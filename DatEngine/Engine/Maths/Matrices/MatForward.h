#pragma once

#include <Maths/CommonMaths.h>
#include <iostream>
#include <stdexcept>


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

	inline MatType const& get(int Row, int Column) const {
		return cells[Row][Column];
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

	// Subscript
	MatType const* operator[](size_t rowIndex) const {
#if _DEBUG
		if (rowIndex >= rows) {
			throw std::out_of_range("Index out of range");
		}
#endif // _DEBUG

		return cells[rowIndex];
	}

	// Subscript
	MatType* operator[](size_t rowIndex) {
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
				temp[row][column] = get(row, column) + otherMat.get(row, column);
			}
		}
		return temp;
	}

	// Single value addition
	type operator+(MatType Value) const {
		type temp = type(0.f);
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = get(row, column) + Value;
			}
		}
		return temp;
	}

	// In place addition
	type& operator+=(const type& otherMat) {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] += otherMat.get(row, column);
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
				temp[row][column] = -get(row, column);
			}
		}
		return temp;
	}

	// Subtraction
	type operator-(const type& otherMat) const {
		type temp = type();
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = get(row, column) - otherMat.get(row, column);
			}
		}
		return temp;
	}

	// Single value Subtraction
	type operator-(MatType Value) const {
		type temp = type();
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = get(row, column) - Value;
			}
		}
		return temp;
	}

	// In place Subtraction
	type& operator-=(const type& otherMat) {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] -= otherMat.get(row, column);
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
	template<int Columns>
	Mat<rows, Columns, MatType> operator*(const Mat<columns, Columns, MatType>& OtherMat) {
		Mat<rows, Columns, MatType> temp = Mat<rows, Columns, MatType>();
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < Columns; ++column) {
				temp[row][column] = 0;
				for (int i = 0; i < columns; ++i) {
					temp[row][column] += (*this)[row][i] * OtherMat[i][column];
				}			
			}
		}
		return temp;
	}

	// Single value Multiplication
	type operator*(MatType Value) const {
		type temp = type();
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				temp[row][column] = get(row, column) * Value;
			}
		}
		return temp;
	}

	// In place Multiplication
	type& operator*=(const type& OtherMat) {
		type copy = type(*this);
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] = 0;

				for (int i = 0; i < columns; ++i) {
					(*this)[row][column] += copy[row][i] * OtherMat[i][column];
				}
			}
		}
		return (*this);
	}

	// Single value in place Multiplication
	type& operator*=(MatType Value) {
		for (int row = 0; row < rows; ++row) {
			for (int column = 0; column < columns; ++column) {
				(*this)[row][column] = get(row, column) * Value;
			}
		}
		return (*this);
	}

	// Division
	// Single value Division
	// In place Division
	// Single value in place Division

	// Bitwise Maths
	// And
	// Single Value And
	// Or
	// Single Value Or
	// XOR
	// Single Value XOR
	// Shift
	// Single Value Shift

	// Comparisons
	// Equals
	// 
};