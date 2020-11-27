#ifdef _DEBUG
	#include <stdexcept>
#endif

// Set cell values
// Set specific cells
template<int rows, int columns, typename MatType>
void Mat<rows, columns, MatType>::set(int Row, int Column, MatType Value) {
	cells[Row][Column] = Value;
}

// Set Column
template<int rows, int columns, typename MatType>
void Mat<rows, columns, MatType>::setColumn(int ColumnIndex, columnType Column) {
	for (int row = 0; row < rows; ++row) {
		cells[row][ColumnIndex] = Column[row];
	}
}

// Set Row
template<int rows, int columns, typename MatType>
void Mat<rows, columns, MatType>::setRow(int RowIndex, rowType Row) {
	std::memcpy(cells[RowIndex], Row, columns * sizeof(MatType));
}

// Set all cells
template<int rows, int columns, typename MatType>
void Mat<rows, columns, MatType>::set(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			cells[row][column] = Value;
		}
	}
}

// Constructors
// Empty constructor
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>::Mat() {}

// Single value
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>::Mat(MatType Value) {
	set(Value);
}

// 2D Array
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>::Mat(MatType Cells[rows][columns]) {
	std::memcpy(cells, Cells, rows * columns * sizeof(MatType));
}

// 1D Array
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>::Mat(const MatType Cells[rows * columns]) {
	std::memcpy(cells, Cells, rows * columns * sizeof(MatType));
}

// Copy Constructor
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>::Mat(const type& OtherMat) {
	std::memcpy(cells, OtherMat.cells, rows * columns * sizeof(MatType));
}

// Conversion Constructor
template<int rows, int columns, typename MatType>
template <int Columns, int Rows, typename OtherType>
Mat<rows, columns, MatType>::Mat(const Mat<Columns, Rows, OtherType>& OtherMat) {
#pragma unroll
	for (int y = 0; y < rows; ++y) {
#pragma unroll
		for (int x = 0; x < columns; ++x) {
			if (Columns > x && Rows > y)	cells[y][x] = (OtherType)OtherMat.cells[y][x];
			else cells[y][x] = 0;
		}
	}
}

template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>::Mat(const Vec<columns, MatType>& OtherVec) {
	std::memcpy(cells, &OtherVec.x, columns * sizeof(MatType));
}

// Vector Conversion
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>::operator Vec<columns, MatType>() {
	return Vec<columns, MatType>(cells[0]);
}

// Identity Matrix
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::identity() {
	static_assert(rows == columns, "Only square matrices can be Identities");
	type temp = type(static_cast<MatType>(0));
	for (int i = 0; i < rows; ++i) {
		temp[i][i] = 1;
	}
	return temp;
}

// Transpose
template<int rows, int columns, typename MatType>
Mat<columns, rows, MatType> Mat<rows, columns, MatType>::transpose() const {
	Mat<columns, rows, MatType> temp();
#pragma unroll
	for (int y = 0; y < rows; ++y) {
#pragma unroll
		for (int x = 0; x < columns; ++x) {
			temp[x][y] = (*this)[y][x];
		}
	}
	return temp;
}

// Subscript
template<int rows, int columns, typename MatType>
MatType* Mat<rows, columns, MatType>::operator[](const size_t rowIndex) {
#if _DEBUG
	if (rowIndex >= rows) {
		throw std::out_of_range("Index out of range");
	}
#endif // _DEBUG

	return cells[rowIndex];
}

template<int rows, int columns, typename MatType>
MatType const* Mat<rows, columns, MatType>::operator[](const size_t rowIndex) const {
#if _DEBUG
	if (rowIndex >= rows) {
		throw std::out_of_range("Index out of range");
	}
#endif // _DEBUG

	return cells[rowIndex];
}


// Maths
// Addition
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator+(const type& otherMat) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] + otherMat[row][column];
		}
	}
	return temp;
}

// Single value addition
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator+(MatType Value) const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] + Value;
		}
	}
	return temp;
}

// In place addition
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator+=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] += otherMat[row][column];
		}
	}
	return (*this);
}

// Single value in place addition
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator+=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] += Value;
		}
	}
	return (*this);
}

// Precrement
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator++() {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] += 1;
		}
	}
}

// Postcrement
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator++(int) {
	type temp = type(*this);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] += 1;
		}
	}
	return temp;
}

// Negation
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator-() const {
	type temp = type(0.f);
	for (int row = 0; row < rows; ++row) const {
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = -(*this)[row][column];
		}
	}
	return temp;
}

// Subtraction
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator-(const type& otherMat) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] - otherMat[row][column];
		}
	}
	return temp;
}

// Single value Subtraction
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator-(MatType Value) const {
	type temp = type();
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] - Value;
		}
	}
	return temp;
}

// In place Subtraction
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator-=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] -= otherMat[row][column];
		}
	}
	return (*this);
}

// Single value in place Subtraction
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator-=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] -= Value;
		}
	}
	return (*this);
}

// Predecrement
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator--() {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] -= 1;
		}
	}
}

// Postdecrement
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator--(int) {
	type temp = type(*this);
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] -= 1;
		}
	}
	return temp;
}

// Multiplication
template<int rows, int columns, typename MatType>
template <int Columns>
Mat<rows, Columns, MatType> Mat<rows, columns, MatType>::operator*(const Mat<columns, Columns, MatType>& OtherMat) const {
	Mat<rows, Columns, MatType> temp = Mat<rows, Columns, MatType>();
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < Columns; ++column) {
			temp[row][column] = 0;
			for (int i = 0; i < columns; ++i) {
				temp[row][column] += cells[row][i] * OtherMat[i][column];
			}
		}
	}
	return temp;
}

// Vector Multiplication
template<int rows, int columns, typename MatType>
Vec<columns, MatType> Mat<rows, columns, MatType>::operator*(const Vec<columns, MatType>& OtherVec) const {
	Vec<columns, MatType> temp = Vec<columns, MatType>();
#pragma unroll
	for (int component = 0; component < columns; ++component) {
		temp[component] = 0;
#pragma unroll
		for (int i = 0; i < columns; ++i) {
			temp[component] += (*this)[component][i] * OtherVec[i];
		}
	}
	return temp;
}

// Single value Multiplication
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator*(MatType Value) const {
	type temp = type();
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] * Value;
		}
	}
	return temp;
}

// In place Multiplication
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator*=(const type& OtherMat) {
	static_assert(rows == columns, "In place Matrices multiplication only works for square matrices");
	type copy = type(*this);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] = 0;
#pragma unroll
			for (int i = 0; i < columns; ++i) {
				(*this)[row][column] += copy[row][i] * OtherMat[i][column];
			}
		}
	}
	return (*this);
}

// Single value in place Multiplication
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator*=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] *= Value;
		}
	}
	return (*this);
}

// Single value Division
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator/(MatType Value) const {
	type temp = type();
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] / Value;
		}
	}
	return temp;
}

// Single value in place Division
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator/=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] /= Value;
		}
	}
	return (*this);
}

// Bitwise Maths
// And
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator&(const type& otherMat) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] & otherMat[row][column];
		}
	}
	return temp;
}

// Single Value And
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator&(MatType Value) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] & Value;
		}
	}
	return temp;
}

// In Place And
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator&=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] &= otherMat[row][column];
		}
	}
	return (*this);
}

// Single Value In Place And
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator&=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] &= Value;
		}
	}
	return (*this);
}

// Or
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator|(const type& otherMat) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] | otherMat[row][column];
		}
	}
	return temp;
}

// Single Value Or
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator|(MatType Value) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] | Value;
		}
	}
	return temp;
}

// In Place Or
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator|=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] |= otherMat[row][column];
		}
	}
	return (*this);
}

// Single Value In Place Or
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator|=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] |= Value;
		}
	}
	return (*this);
}

// XOR
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator^(const type& otherMat) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] ^ otherMat[row][column];
		}
	}
	return temp;
}

// Single Value XOR
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType> Mat<rows, columns, MatType>::operator^(MatType Value) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[row][column] = (*this)[row][column] ^ Value;
		}
	}
	return temp;
}

// In Place XOR
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator^=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] ^= otherMat[row][column];
		}
	}
	return (*this);
}

// Single Value In Place XOR
template<int rows, int columns, typename MatType>
Mat<rows, columns, MatType>& Mat<rows, columns, MatType>::operator^=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[row][column] ^= Value;
		}
	}
	return (*this);
}

// Comparisons
// Equal
template<int rows, int columns, typename MatType>
bool Mat<rows, columns, MatType>::operator==(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			if (*this)[row][column] != otherMat[row][column] return false;
		}
	}
	return true;
}

// Not Equal
template<int rows, int columns, typename MatType>
bool Mat<rows, columns, MatType>::operator!=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			if (*this)[row][column] != otherMat[row][column] return true;
		}
	}
	return false;
}