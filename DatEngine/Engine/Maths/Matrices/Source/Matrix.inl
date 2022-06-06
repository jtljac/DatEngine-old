#ifdef _DEBUG
	#include <stdexcept>
#endif

// Set cell values
// Set specific cells
template<int columns, int rows, typename MatType>
void Matrix<columns, rows, MatType>::set(int column, int row, MatType value) {
	cells[column][row] = value;
}

// Set column
template<int columns, int rows, typename MatType>
[[maybe_unused]] void Matrix<columns, rows, MatType>::setColumn(int columnIndex, columnType column) {
    std::memcpy(cells[columnIndex], &column, sizeof(column));
}

// Set row
template<int columns, int rows, typename MatType>
[[maybe_unused]] void Matrix<columns, rows, MatType>::setRow(int rowIndex, rowType row) {
    for (int i = 0; i < columns; ++i) {
        cells[i][rowIndex] = row[i];
    }
}

// Set all cells
template<int columns, int rows, typename MatType>
void Matrix<columns, rows, MatType>::set(MatType value) {
	for (int column = 0; column < columns; ++column)  {
		for (int row = 0; row < rows; ++row)
		{
			cells[column][row] = value;
		}
	}
}

// Constructors
// Empty constructor
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix() = default;

// Single value
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(MatType value) {
	set(value);
}

// 2D Array
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(MatType cellArray[columns][rows]) {
	std::memcpy(cells, cellArray, columns * rows * sizeof(MatType));
}

// 1D Array
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(const MatType cellArray[columns * rows]) {
	std::memcpy(cells, cellArray, columns * rows * sizeof(MatType));
}

// Copy Constructor
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(const type& OtherMat) {
	std::memcpy(cells, OtherMat.cells, columns * rows * sizeof(MatType));
}

// Conversion Constructor
template<int columns, int rows, typename MatType>
template <int Columns, int Rows, typename OtherType>
Matrix<columns, rows, MatType>::Matrix(const Matrix<Columns, Rows, OtherType>& otherMat) {
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			if (Columns > column && Rows > row) cells[column][row] = (OtherType)otherMat.cells[column][row];
			else cells[column][row] = 0;
		}
	}
}
// From Vector
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(const Vector<columns, MatType>& otherVec) {
    std::memcpy(cells, &otherVec, columns * sizeof(MatType));
}

// Identity Matrix
template<int columns, int rows, typename MatType>
template<int uCol, int uRow, std::enable_if_t<uCol == uRow, int>>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::identity() {
	type temp = type(static_cast<MatType>(0));
	for (int i = 0; i < rows; ++i) {
		temp[i][i] = 1;
	}
	return temp;
}

// Subscript
template<int columns, int rows, typename MatType>
MatType* Matrix<columns, rows, MatType>::operator[](const size_t columnIndex) {
#if _DEBUG
	if (columnIndex >= columns) {
		throw std::out_of_range("Index out of range");
	}
#endif // _DEBUG

	return cells[columnIndex];
}

template<int columns, int rows, typename MatType>
MatType const* Matrix<columns, rows, MatType>::operator[](const size_t columnIndex) const {
#if _DEBUG
	if (columnIndex >= columns) {
		throw std::out_of_range("Index out of range");
	}
#endif // _DEBUG

	return cells[columnIndex];
}

// Maths
// Transpose
template<int columns, int rows, typename MatType>
[[maybe_unused]] Matrix<rows, columns, MatType> Matrix<columns, rows, MatType>::transpose() const {
	Matrix<rows, columns, MatType> temp{};

	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			temp[column][row] = (*this)[row][column];
		}
	}
	return temp;
}

template<int columns, int rows, typename MatType>
template<int uCol, int uRow, std::enable_if_t<uCol == uRow, int>>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::inverse() {
    Matrix<columns, rows, MatType> minors = calculateCofactors();

    MatType determinant = 0;
    for (int i = 0; i < columns; ++i) {
        determinant += cells[i][0] * minors[i][0];
    }

    return minors.transpose() * (1 / determinant);
}

// Addition
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator+(const type& otherMat) const {
	type temp = type(0.f);
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			temp[column][row] = (*this)[column][row] + otherMat[column][row];
		}
	}
	return temp;
}

// Single value addition
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator+(MatType Value) const {
	type temp = type(0.f);
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			temp[column][row]= (*this)[column][row]+ Value;
		}
	}
	return temp;
}

// In place addition
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator+=(const type& otherMat) {
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			(*this)[column][row]+= otherMat[column][row];
		}
	}
	return (*this);
}

// Single value in place addition
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator+=(MatType Value) {
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			(*this)[column][row] += Value;
		}
	}
	return (*this);
}

// Precrement
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator++() {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] += 1;
		}
	}
}

// Postcrement
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator++(int) {
	type temp = type(*this);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] += 1;
		}
	}
	return temp;
}

// Negation
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator-() const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = -(*this)[column][row];
		}
	}
	return temp;
}

// Subtraction
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator-(const type& otherMat) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] - otherMat[column][row];
		}
	}
	return temp;
}

// Single value Subtraction
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator-(MatType Value) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] - Value;
		}
	}
	return temp;
}

// In place Subtraction
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator-=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] -= otherMat[column][row];
		}
	}
	return (*this);
}

// Single value in place Subtraction
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator-=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] -= Value;
		}
	}
	return (*this);
}

// Predecrement
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator--() {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] -= 1;
		}
	}
}

// Postdecrement
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator--(int) {
	type temp = type(*this);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] -= 1;
		}
	}
	return temp;
}

// TODO: ALSO

// Multiplication
template<int columns, int rows, typename MatType>
template <int otherColumns>
Matrix<otherColumns, rows, MatType> Matrix<columns, rows, MatType>::operator*(const Matrix<otherColumns, columns, MatType>& otherMat) const {
	Matrix<otherColumns, rows, MatType> temp = Matrix<otherColumns, rows, MatType>();

	for (int column = 0; column < otherColumns; ++column) {
		for (int row = 0; row < rows; ++row) {
			MatType newValue = 0;
			for (int i = 0; i < columns; ++i) {
				newValue += cells[i][row] * otherMat[column][i];
			}
			temp[column][row] = newValue;
		}
	}

	return temp;
}

// Vector Multiplication
template<int columns, int rows, typename MatType>
Vector<columns, MatType> Matrix<columns, rows, MatType>::operator*(const Vector<columns, MatType>& otherVec) const {
	Vector<columns, MatType> temp = Vector<columns, MatType>();

	for (int row = 0; row < columns; ++row) {
		MatType newValue = 0;
		for (int i = 0; i < columns; ++i) {
			newValue += cells[i][row] * otherVec[i];
		}
		temp[row] = newValue;
	}

	return temp;
}

// Single matType Multiplication
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator*(MatType matType) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] * matType;
		}
	}
	return temp;
}

// In place Multiplication
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator*=(const type& otherMat) {
	static_assert(rows == columns, "In place Matrices multiplication only works for square matrices");
	type copy = type(*this);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] = 0;
			for (int i = 0; i < columns; ++i) {
				(*this)[column][row] += copy[row][i] * otherMat[i][column];
			}
		}
	}
	return (*this);
}

// Single value in place Multiplication
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator*=(MatType value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] *= value;
		}
	}
	return (*this);
}

// Single value Division
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator/(MatType value) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] / value;
		}
	}
	return temp;
}

// Single value in place Division
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator/=(MatType value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] /= value;
		}
	}
	return (*this);
}

// Bitwise Maths
// And
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator&(const type& otherMat) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] & otherMat[column][row];
		}
	}
	return temp;
}

// Single value And
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator&(MatType value) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] & value;
		}
	}
	return temp;
}

// In Place And
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator&=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] &= otherMat[column][row];
		}
	}
	return (*this);
}

// Single value In Place And
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator&=(MatType value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] &= value;
		}
	}
	return (*this);
}

// Or
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator|(const type& otherMat) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] | otherMat[column][row];
		}
	}
	return temp;
}

// Single value Or
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator|(MatType value) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] | value;
		}
	}
	return temp;
}

// In Place Or
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator|=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] |= otherMat[column][row];
		}
	}
	return (*this);
}

// Single value In Place Or
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator|=(MatType value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] |= value;
		}
	}
	return (*this);
}

// XOR
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator^(const type& otherMat) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] ^ otherMat[column][row];
		}
	}
	return temp;
}

// Single value XOR
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator^(MatType value) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] ^ value;
		}
	}
	return temp;
}

// In Place XOR
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator^=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] ^= otherMat[column][row];
		}
	}
	return (*this);
}

// Single value In Place XOR
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator^=(MatType value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] ^= value;
		}
	}
	return (*this);
}

// Comparisons
// Equal
template<int columns, int rows, typename MatType>
bool Matrix<columns, rows, MatType>::operator==(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			if ((*this)[column][row] != otherMat[column][row]) return false;
		}
	}
	return true;
}

// Not Equal
template<int columns, int rows, typename MatType>
bool Matrix<columns, rows, MatType>::operator!=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			if ((*this)[column][row] != otherMat[column][row]) return true;
		}
	}
	return false;
}