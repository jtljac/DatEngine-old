#ifdef _DEBUG
	#include <stdexcept>
#endif

// Set cell values
// Set specific cells
template<int columns, int rows, typename MatType>
void Mat<columns, rows, MatType>::set(int Column, int Row, MatType Value) {
	cells[Column][Row] = Value;
}

// Set Column
template<int columns, int rows, typename MatType>
void Mat<columns, rows, MatType>::setColumn(int ColumnIndex, columnType Column) {
	
}

// Set Row
template<int columns, int rows, typename MatType>
void Mat<columns, rows, MatType>::setRow(int RowIndex, rowType Row) {
	
}

// Set all cells
template<int columns, int rows, typename MatType>
void Mat<columns, rows, MatType>::set(MatType Value) {
#pragma unroll
	for (int column = 0; column < columns; ++column)  {
#pragma unroll
		for (int row = 0; row < rows; ++row)
		{
			cells[column][row] = Value;
		}
	}
}

// Constructors
// Empty constructor
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>::Mat() {}

// Single value
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>::Mat(MatType Value) {
	set(Value);
}

// 2D Array
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>::Mat(MatType Cells[columns][rows]) {
	std::memcpy(cells, Cells, columns * rows * sizeof(MatType));
}

// 1D Array
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>::Mat(const MatType Cells[columns * rows]) {
	std::memcpy(cells, Cells, columns * rows * sizeof(MatType));
}

// Copy Constructor
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>::Mat(const type& OtherMat) {
	std::memcpy(cells, OtherMat.cells, columns * rows * sizeof(MatType));
}

// Conversion Constructor
template<int columns, int rows, typename MatType>
template <int Columns, int Rows, typename OtherType>
Mat<columns, rows, MatType>::Mat(const Mat<Columns, Rows, OtherType>& OtherMat) {
#pragma unroll
	for (int column = 0; column < columns; ++column) {
#pragma unroll
		for (int row = 0; row < rows; ++row) {
			if (Columns > column && Rows > row) cells[column][row] = (OtherType)OtherMat.cells[column][row];
			else cells[column][row] = 0;
		}
	}
}
// From Vector
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>::Mat(const Vec<columns, MatType>& OtherVec) {

}

// Identity Matrix
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::identity() {
	static_assert(rows == columns, "Only square matrices can be Identities");
	type temp = type(static_cast<MatType>(0));
	for (int i = 0; i < rows; ++i) {
		temp[i][i] = 1;
	}
	return temp;
}

// Transpose
template<int columns, int rows, typename MatType>
Mat<rows, columns, MatType> Mat<columns, rows, MatType>::transpose() const {
	Mat<rows, columns, MatType> temp();
#pragma unroll
	for (int column = 0; column < columns; ++column) {
#pragma unroll
		for (int row = 0; row < rows; ++row) {
			temp[column][row] = (*this)[row][column];
		}
	}
	return temp;
}

// Subscript
template<int columns, int rows, typename MatType>
MatType* Mat<columns, rows, MatType>::operator[](const size_t columnIndex) {
#if _DEBUG
	if (columnIndex >= columns) {
		throw std::out_of_range("Index out of range");
	}
#endif // _DEBUG

	return cells[columnIndex];
}

template<int columns, int rows, typename MatType>
MatType const* Mat<columns, rows, MatType>::operator[](const size_t columnIndex) const {
#if _DEBUG
	if (columnIndex >= rows) {
		throw std::out_of_range("Index out of range");
	}
#endif // _DEBUG

	return cells[columnIndex];
}


// Maths
// Addition
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator+(const type& otherMat) const {
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
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator+(MatType Value) const {
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
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator+=(const type& otherMat) {
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			(*this)[column][row]+= otherMat[column][row];
		}
	}
	return (*this);
}

// Single value in place addition
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator+=(MatType Value) {
	for (int column = 0; column < columns; ++column) {
		for (int row = 0; row < rows; ++row) {
			(*this)[column][row] += Value;
		}
	}
	return (*this);
}

// Precrement
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator++() {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] += 1;
		}
	}
}

// Postcrement
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator++(int) {
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
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator-() const {
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
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator-(const type& otherMat) const {
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
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator-(MatType Value) const {
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
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator-=(const type& otherMat) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] -= otherMat[column][row];
		}
	}
	return (*this);
}

// Single value in place Subtraction
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator-=(MatType Value) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] -= Value;
		}
	}
	return (*this);
}

// Predecrement
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator--() {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] -= 1;
		}
	}
}

// Postdecrement
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator--(int) {
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
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator*(const Mat<columns, Columns, MatType>& OtherMat) const {

}

// Vector Multiplication
template<int columns, int rows, typename MatType>
Vec<columns, MatType> Mat<columns, rows, MatType>::operator*(const Vec<columns, MatType>& OtherVec) const {

}

// Single value Multiplication
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator*(MatType Value) const {
	type temp = type();
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] * Value;
		}
	}
	return temp;
}

// In place Multiplication
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator*=(const type& OtherMat) {
	static_assert(rows == columns, "In place Matrices multiplication only works for square matrices");
	type copy = type(*this);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] = 0;
#pragma unroll
			for (int i = 0; i < columns; ++i) {
				(*this)[column][row] += copy[row][i] * OtherMat[i][column];
			}
		}
	}
	return (*this);
}

// Single value in place Multiplication
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator*=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] *= Value;
		}
	}
	return (*this);
}

// Single value Division
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator/(MatType Value) const {
	type temp = type();
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] / Value;
		}
	}
	return temp;
}

// Single value in place Division
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator/=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] /= Value;
		}
	}
	return (*this);
}

// Bitwise Maths
// And
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator&(const type& otherMat) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] & otherMat[column][row];
		}
	}
	return temp;
}

// Single Value And
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator&(MatType Value) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] & Value;
		}
	}
	return temp;
}

// In Place And
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator&=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] &= otherMat[column][row];
		}
	}
	return (*this);
}

// Single Value In Place And
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator&=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] &= Value;
		}
	}
	return (*this);
}

// Or
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator|(const type& otherMat) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] | otherMat[column][row];
		}
	}
	return temp;
}

// Single Value Or
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator|(MatType Value) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] | Value;
		}
	}
	return temp;
}

// In Place Or
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator|=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] |= otherMat[column][row];
		}
	}
	return (*this);
}

// Single Value In Place Or
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator|=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] |= Value;
		}
	}
	return (*this);
}

// XOR
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator^(const type& otherMat) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] ^ otherMat[column][row];
		}
	}
	return temp;
}

// Single Value XOR
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType> Mat<columns, rows, MatType>::operator^(MatType Value) const {
	type temp = type(0.f);
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			temp[column][row] = (*this)[column][row] ^ Value;
		}
	}
	return temp;
}

// In Place XOR
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator^=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] ^= otherMat[column][row];
		}
	}
	return (*this);
}

// Single Value In Place XOR
template<int columns, int rows, typename MatType>
Mat<columns, rows, MatType>& Mat<columns, rows, MatType>::operator^=(MatType Value) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			(*this)[column][row] ^= Value;
		}
	}
	return (*this);
}

// Comparisons
// Equal
template<int columns, int rows, typename MatType>
bool Mat<columns, rows, MatType>::operator==(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			if (*this)[column][row] != otherMat[column][row] return false;
		}
	}
	return true;
}

// Not Equal
template<int columns, int rows, typename MatType>
bool Mat<columns, rows, MatType>::operator!=(const type& otherMat) {
#pragma unroll
	for (int row = 0; row < rows; ++row) {
#pragma unroll
		for (int column = 0; column < columns; ++column) {
			if (*this)[column][row] != otherMat[column][row] return true;
		}
	}
	return false;
}