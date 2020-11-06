#pragma once

#include <Maths/CommonMaths.h>
#include <iostream>
#include <stdexcept>


template<int columns, int rows, typename MatType> 
struct Mat {
	typedef Mat<columns, rows, MatType> type;
	typedef MatType rowType[columns], columnType[columns];

	MatType cells[rows][columns];

	// Set cell values
	// Set specific cells
	void set(int Column, int Row, MatType Value) {
		cells[Row][Column] = Value;
	}

	// Set Column
	void setColumn(int ColumnIndex, MatType Column[rows]) {
		for (int row = 0; row < rows; ++row) {
			cells[row][ColumnIndex] = Column[row];
		}
	}

	// Set Row
	void setRow(int RowIndex, MatType Row[columns]) {
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
	Mat() {
		setValue(0);
	}

	// Single value
	Mat(MatType Value) {
		setValue(Value);
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
	rowType& operator[](int rowIndex) {
#if _DEBUG
		if (rowIndex >= rows) {
			throw std::out_of_range("Index out of range");
		}
#endif // _DEBUG

		return cells[rowIndex];
	}


	// Maths
	// Addition
	// Addition
	// Single value addition
	// In place addition
	// Single value in place addition


	// Negation
	// Subtraction
	// Single value Subtraction
	// In place Subtraction
	// Single value in place Subtraction

	// Multiplication
	// Single value Multiplication
	// In place Multiplication
	// Single value in place Multiplication

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