#ifdef _DEBUG
	#include <stdexcept>
#endif

// Set cell values
// Set specific cells
template<int columns, int rows, typename MatType>
void Matrix<columns, rows, MatType>::set(int Column, int Row, MatType Value) {
	cells[Column][Row] = Value;
}

// Set Column
template<int columns, int rows, typename MatType>
void Matrix<columns, rows, MatType>::setColumn(int ColumnIndex, columnType Column) {
	
}

// Set Row
template<int columns, int rows, typename MatType>
void Matrix<columns, rows, MatType>::setRow(int RowIndex, rowType Row) {
	
}

// Set all cells
template<int columns, int rows, typename MatType>
void Matrix<columns, rows, MatType>::set(MatType Value) {
	for (int column = 0; column < columns; ++column)  {
		for (int row = 0; row < rows; ++row)
		{
			cells[column][row] = Value;
		}
	}
}

// Constructors
// Empty constructor
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix() {}

// Single value
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(MatType Value) {
	set(Value);
}

// 2D Array
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(MatType Cells[columns][rows]) {
	std::memcpy(cells, Cells, columns * rows * sizeof(MatType));
}

// 1D Array
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(const MatType Cells[columns * rows]) {
	std::memcpy(cells, Cells, columns * rows * sizeof(MatType));
}

// Copy Constructor
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(const type& OtherMat) {
	std::memcpy(cells, OtherMat.cells, columns * rows * sizeof(MatType));
}

// Conversion Constructor
template<int columns, int rows, typename MatType>
template <int Columns, int Rows, typename OtherType>
Matrix<columns, rows, MatType>::Matrix(const Matrix<Columns, Rows, OtherType>& OtherMat) {
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			if (Columns > column && Rows > row) cells[column][row] = (OtherType)OtherMat.cells[column][row];
			else cells[column][row] = 0;
		}
	}
}
// From Vector
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>::Matrix(const Vector<columns, MatType>& OtherVec) {

}

// Identity Matrix
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::identity() {
	static_assert(rows == columns, "Only square matrices can be Identities");
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
Matrix<rows, columns, MatType> Matrix<columns, rows, MatType>::transpose() const {
	Matrix<rows, columns, MatType> temp();

	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			temp[column][row] = (*this)[row][column];
		}
	}
	return temp;
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
	for (int row = 0; row < rows; ++row) const {
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
template <int Columns>
Matrix<Columns, rows, MatType> Matrix<columns, rows, MatType>::operator*(const Matrix<Columns, columns, MatType>& OtherMat) const {
	Matrix<Columns, rows, MatType> temp = Matrix<Columns, rows, MatType>();

	for (int column = 0; column < Columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			MatType newValue = 0;
			for (int i = 0; i < columns; ++i) {
				newValue += cells[i][row] * OtherMat[column][i];
			}
			temp[column][row] = newValue;
		}
	}

	return temp;
}

// Vector Multiplication
template<int columns, int rows, typename MatType>
Vector<columns, MatType> Matrix<columns, rows, MatType>::operator*(const Vector<columns, MatType>& OtherVec) const {
	Vector<columns, MatType> temp = Vector<columns, MatType>();

	for (int row = 0; row < columns; ++row) {
		MatType newValue = 0;
		for (int i = 0; i < columns; ++i) {
			newValue += cells[i][row] * OtherVec[i];
		}
		temp[row] = newValue;
	}

	return temp;
}

// Single value Multiplication
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator*(MatType Value) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] * Value;
		}
	}
	return temp;
}

// In place Multiplication
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator*=(const type& OtherMat) {
	static_assert(rows == columns, "In place Matrices multiplication only works for square matrices");
	type copy = type(*this);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] = 0;
			for (int i = 0; i < columns; ++i) {
				(*this)[column][row] += copy[row][i] * OtherMat[i][column];
			}
		}
	}
	return (*this);
}

// Single value in place Multiplication
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator*=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] *= Value;
		}
	}
	return (*this);
}

// Single value Division
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator/(MatType Value) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] / Value;
		}
	}
	return temp;
}

// Single value in place Division
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator/=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] /= Value;
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

// Single Value And
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator&(MatType Value) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] & Value;
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

// Single Value In Place And
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator&=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] &= Value;
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

// Single Value Or
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator|(MatType Value) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] | Value;
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

// Single Value In Place Or
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator|=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] |= Value;
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

// Single Value XOR
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType> Matrix<columns, rows, MatType>::operator^(MatType Value) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] ^ Value;
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

// Single Value In Place XOR
template<int columns, int rows, typename MatType>
Matrix<columns, rows, MatType>& Matrix<columns, rows, MatType>::operator^=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] ^= Value;
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
			if (*this)[column][row] != otherMat[column][row] return false;
		}
	}
	return true;
}

// Not Equal
template<int columns, int rows, typename MatType>
bool Matrix<columns, rows, MatType>::operator!=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			if (*this)[column][row] != otherMat[column][row] return true;
		}
	}
	return false;
}