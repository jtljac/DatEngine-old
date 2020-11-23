#pragma once

#include <Maths/CommonMaths.h>

#include "../Vectors/VecForward.h"

#ifdef _DEBUG
	#include <stdexcept>
#endif


template<int rows, int columns, typename MatType> 
struct Mat {
	typedef Mat<rows, columns, MatType> type;
	typedef MatType rowType[rows], columnType[columns];

	MatType cells[rows][columns];

	// Set cell values
	// Set specific cells
	void set(int Row, int Column, MatType Value) {
		cells[Row][Column] = Value;
	}

	// Set Column
	void setColumn(int ColumnIndex, columnType Column) {
		for (int row = 0; row < rows; ++row) {
			cells[row][ColumnIndex] = Column[row];
		}
	}

	// Set Row
	void setRow(int RowIndex, rowType Row) {
		std::memcpy(cells[RowIndex], Row, columns * sizeof(MatType));
	}

	// Set all cells
	void set(MatType Value) {
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
	Mat() {}

	// Single value
	Mat(MatType Value) {
		set(Value);
	}

	// 2D Array
	Mat(MatType Cells[rows][columns]) {
		std::memcpy(cells, Cells, rows * columns * sizeof(MatType));
	}

	// 1D Array
	Mat(const MatType Cells[rows*columns]) {
		std::memcpy(cells, Cells, rows * columns * sizeof(MatType));
	}

	// Copy Constructor
	Mat(const type &OtherMat) {
		std::memcpy(cells, OtherMat.cells, rows * columns * sizeof(MatType));
	}

	// Conversion Constructor
	template <int Columns, int Rows, typename OtherType> 
	explicit Mat(const Mat<Columns, Rows, OtherType>& OtherMat) {
#pragma unroll
		for (int y = 0; y < rows; ++y) {
#pragma unroll
			for (int x = 0; x < columns; ++x) {
				if (Columns > x && Rows > y)	cells[y][x] = (OtherType) OtherMat.cells[y][x];
				else cells[y][x] = 0;
			}
		}
	}

	explicit Mat(const Vec<columns, MatType>& OtherVec) {
		std::memcpy(cells, &OtherVec.x, columns * sizeof(MatType));
	}

	// Vector Conversion
	explicit operator Vec<columns, MatType>() {
		return Vec<columns, MatType>(cells[0]);
	}

	// Identity Matrix
	static type identity() {
		static_assert(rows == columns, "Only square matrices can be Identities");
		type temp = type(static_cast<MatType>(0));
		for (int i = 0; i < rows; ++i) {
			temp[i][i] = 1;
		}
		return temp;
	}

	// Transpose
	Mat<columns, rows, MatType> transpose() const {
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
	MatType* operator[](const size_t rowIndex) {
#if _DEBUG
		if (rowIndex >= rows) {
			throw std::out_of_range("Index out of range");
		}
#endif // _DEBUG

		return cells[rowIndex];
	}

	MatType const* operator[](const size_t rowIndex) const {
#if _DEBUG
		if (rowIndex >= rows) {
			throw std::out_of_range("Index out of range");
		}
#endif // _DEBUG

		return cells[rowIndex];
	}


	// Maths
	// Addition
	type operator+(const type& otherMat) const {
		type temp = type(0.f);
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = (*this)[row][column] + otherMat[row][column];
			}
		}
		return temp;
	}

	// Single value addition
	type operator+(MatType Value) const {
		type temp = type(0.f);
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = (*this)[row][column] + Value;
			}
		}
		return temp;
	}

	// In place addition
	type& operator+=(const type& otherMat) {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] += otherMat[row][column];
			}
		}
		return (*this);
	}

	// Single value in place addition
	type& operator+=(MatType Value) {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] += Value;
			}
		}
		return (*this);
	}

	// Precrement
	type& operator++() {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] += 1;
			}
		}
	}

	// Postcrement
	type operator++(int) {
		type temp = type(*this);
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] += 1;
			}
		}
		return temp;
	}

	// Negation
	type operator-() const {
		type temp = type(0.f);
		for (int row = 0; row < rows; ++row) const {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = -(*this)[row][column];
			}
		}
		return temp;
	}

	// Subtraction
	type operator-(const type& otherMat) const {
		type temp = type();
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = (*this)[row][column] - otherMat[row][column];
			}
		}
		return temp;
	}

	// Single value Subtraction
	type operator-(MatType Value) const {
		type temp = type();
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = (*this)[row][column] - Value;
			}
		}
		return temp;
	}

	// In place Subtraction
	type& operator-=(const type& otherMat) {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] -= otherMat[row][column];
			}
		}
		return (*this);
	}

	// Single value in place Subtraction
	type& operator-=(MatType Value) {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] -= Value;
			}
		}
		return (*this);
	}

	// Predecrement
	type& operator--() {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] -= 1;
			}
		}
	}

	// Postdecrement
	type operator--(int) {
		type temp = type(*this);
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] -= 1;
			}
		}
		return temp;
	}

	// Multiplication
	template <int Columns>
	Mat<rows, Columns, MatType> operator*(const Mat<columns, Columns, MatType>& OtherMat) const {
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
	Vec<columns, MatType> operator*(const Vec<columns, MatType>& OtherVec) const {
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
	type operator*(MatType Value) const {
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
	type& operator*=(const type& OtherMat) {
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
	type& operator*=(MatType Value) {
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
	type operator/(MatType Value) const {
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
	type& operator/=(MatType Value) {
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
	type operator&(const type& otherMat) const {
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
	type operator&(MatType Value) const {
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
	type& operator&=(const type& otherMat) {
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
	type& operator&=(MatType Value) {
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
	type operator|(const type& otherMat) const {
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
	type operator|(MatType Value) const {
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
	type& operator|=(const type& otherMat) {
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
	type& operator|=(MatType Value) {
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
	type operator^(const type& otherMat) const {
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
	type operator^(MatType Value) const {
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
	type& operator^=(const type& otherMat) {
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
	type& operator^=(MatType Value) {
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
	bool operator==(const type& otherMat) {
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
	bool operator!=(const type& otherMat) {
#pragma unroll
		for (int row = 0; row < rows; ++row) {
#pragma unroll
			for (int column = 0; column < columns; ++column) {
				if (*this)[row][column] != otherMat[row][column] return true;
			}
		}
		return false;
	}
};

#include "Source/Matrix.inl"