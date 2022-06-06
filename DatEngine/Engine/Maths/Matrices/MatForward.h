#pragma once

#include "../Vectors/VecForward.h"


/**
 * A class representing a Matrix (The maths kind).
 * Column major, meaning the matrix is stored in memory a column at a time.
 * For a 3x3 Matrix, the order looks like:
 * 0, 3, 6
 * 1, 4, 7
 * 2, 5, 8
 *
 * @tparam columns The number of columns the matrix has
 * @tparam rows The number of rows the matrix has
 * @tparam MatType The type of the matrix
 */
template<int columns, int rows, typename MatType> 
struct Matrix {
	typedef Matrix<columns, rows, MatType> type;
	typedef MatType rowType[rows], columnType[columns];

	MatType cells[columns][rows];

	// Set cell values
	/**
	 * Set a specific cell in the matrix to the given value
	 * @param column The column index
	 * @param row The row index
	 * @param value The value to set the cell to
	 */
	void set(int column, int row, MatType value);

	/**
	 * Set the column at the specified column index to the new set of values
	 * @param columnIndex The index of the column
	 * @param column The new values for the column
	 */
    [[maybe_unused]] void setColumn(int columnIndex, columnType column);

	/**
	 * Set the row at the specified row index to the new set of values
	 * @param rowIndex The index of the row
	 * @param row The new values for the row
	 */
    [[maybe_unused]] void setRow(int rowIndex, rowType row);

	/**
	 * Set all the cells in the matrix to the specified value
	 * @param value The new value for the cells
	 */
	void set(MatType value);

	// Constructors
	/**
	 * Construct the matrix without initialising the cells
	 * Will result in random data in each cell
	 */
	Matrix();

	/**
	 * Construct the matrix with all the cells set to the given value
	 * @see Matrix() when you don't care about the initial values of the matrix
	 * @param value The value to set each of the cells to
	 */
	explicit Matrix(MatType value);

	/**
	 * Initialise the matrix with values from a 2d array
	 * Note: The matrix is column major, which means the first index is the column, and the second index is the row
	 * for a 3x3 matrix, it is filled in the following order:
	 * 0,0 1,0 2,0
	 * 0,1 1,1 2,1
	 * 0,2 1,2 2,2
	 * @param cellArray The 2d array to copy the values from
	 */
	explicit Matrix(MatType cellArray[columns][rows]);

	/**
	 * Initialise the matrix with values from a 1d array
	 * Note: The matrix is column major, which for a 3x3 matrix, it is filled in the following order:
	 * 0 3 6
	 * 1 4 7
	 * 2 5 8
	 * @param cellArray a 1d to copy the values from
	 */
	explicit Matrix(const MatType cellArray[columns * rows]);

	// Copy Constructor
    /**
     * Constructs a Matrix, copying the values from another matrix
     * @param otherMat The Matrix to copy from
     */
	Matrix(const type &otherMat);

	// Conversion Constructor
    /**
     * Construct a Matrix copying values from another Matrix, handling a different shape and type if needed.
     * If either dimension of the other matrix is larger, then the values outside the range of this matrix will be discarded
     * If either dimension of the other matrix is smaller, then the extra cells will be filled in with zeros
     * @tparam otherColumns The amount of columns the other matrix has
     * @tparam otherRows The amount of rows the other matrix has
     * @tparam otherType The type of the other matrix
     * @param otherMat The other matrix to copy from
     */
	template <int otherColumns, int otherRows, typename otherType>
	explicit Matrix(const Matrix<otherColumns, otherRows, otherType>& otherMat);

    /**
     * Create a matrix using a vector, where the first row is set to the vector, and the remaining rows are left as their
     * defaults
     * @param otherVec
     */
	explicit Matrix(const Vector<columns, MatType>& otherVec);

	// Identity Matrix
    /**
     * Get the identity matrix, where the main diagonal contains ones, and all other values are set to 0
     * For a 3x3 matrix, this looks like:
     * 1 0 0
     * 0 1 0
     * 0 0 1
     *
     * This method uses [sfinae](https://en.cppreference.com/w/cpp/language/sfinae) to only compile when the Matrix is square
     *
     * @return The Identity Matrix
     */
    template<int uCol=columns, int uRow=rows, std::enable_if_t<uCol == uRow, int> = 0>
	static type identity();

	// Subscript
	MatType* operator[](size_t columnIndex);
	MatType const* operator[](size_t columnIndex) const;

	// Maths
	/**
	 * Transpose the Matrix
	 * Essentially, flip it by its main diagonal
	 * Not inplace, this does not affect the original Matrix
	 * @return The transposed matrix
	 */
    [[maybe_unused]] Matrix<rows, columns, MatType> transpose() const;

    /**
     * Find the determinant of a 2x2 Matrix
     * This method uses [sfinae](https://en.cppreference.com/w/cpp/language/sfinae) to only compile when the Matrix is 2x2
     * @return The determinant of the Matrix
     */
    template<int uCol=columns, int uRow=rows, std::enable_if_t<uCol == 2 && uRow == 2, int> = 0>
    [[maybe_unused]] inline MatType determinant() const {
        return cells[0][0] * cells[1][1] - cells[1][0] * cells[0][1];
    }

    /**
     * Find the determinant of a Matrix
     * This method uses [sfinae](https://en.cppreference.com/w/cpp/language/sfinae) to only compile when the Matrix is square
     * and greater than 2x2
     * @return The determinant of the Matrix
     */
    template<int uCol=columns, int uRow=rows, std::enable_if_t<(uCol != 2 || uRow != 2) && uCol == uRow, int> = 0>
    [[maybe_unused]] MatType determinant() const {
        if (columns != rows) return nan("");

        MatType value = 0;
        for (int column = 0; column < columns; ++column) {
            Matrix<columns - 1, rows - 1, MatType> subDeterminant;

            for (int subColumn = 0, i = 0; subColumn < columns; ++subColumn) {
                if (subColumn != column) {
                    for (int j = 0; j < rows - 1; ++j) {
                        subDeterminant[i][j] = cells[subColumn][j + 1];
                    }
                    ++i;
                }
            }

            value += (column % 2 == 0 ? 1 : -1) * cells[column][0] * subDeterminant.determinant();
        }

        return value;
    }

    /**
     * Get the inverse of a Matrix
     * This method uses [sfinae](https://en.cppreference.com/w/cpp/language/sfinae) to only compile when the Matrix is square
     * @return The inverse of the Matrix
     */
    template<int uCol=columns, int uRow=rows, std::enable_if_t<uCol == uRow, int> = 0>
    type inverse();

	// Addition
	type operator+(const type& otherMat) const;

	// Single value addition
	type operator+(MatType Value) const;

	// In place addition
	type& operator+=(const type& otherMat);

	// Single value in place addition
	type& operator+=(MatType Value);

	// Precrement
	type& operator++();

	// Postcrement
    type operator++(int);

	// Negation
	type operator-() const;

	// Subtraction
	type operator-(const type& otherMat) const;

	// Single value Subtraction
	type operator-(MatType Value) const;

	// In place Subtraction
	type& operator-=(const type& otherMat);

	// Single value in place Subtraction
	type& operator-=(MatType Value);

	// Predecrement
	type& operator--();

	// Postdecrement
	type operator--(int);

	// Multiplication
	template <int otherColumns>
	Matrix<otherColumns, rows, MatType> operator*(const Matrix<otherColumns, columns, MatType>& otherMat) const;

	// Vector Multiplication
	Vector<columns, MatType> operator*(const Vector<columns, MatType>& otherVec) const;

	// Single matType Multiplication
	type operator*(MatType matType) const;

	// In place Multiplication
	type& operator*=(const type& otherMat);

	// Single value in place Multiplication
	type& operator*=(MatType value);

	// Single value Division
	type operator/(MatType value) const;

	// Single value in place Division
	type& operator/=(MatType value);

	// Bitwise Maths
	// And
	type operator&(const type& otherMat) const;

	// Single value And
	type operator&(MatType value) const;

	// In Place And
	type& operator&=(const type& otherMat);

	// Single value In Place And
	type& operator&=(MatType value);

	// Or
	type operator|(const type& otherMat) const;

	// Single value Or
	type operator|(MatType value) const;

	// In Place Or
	type& operator|=(const type& otherMat);

	// Single value In Place Or
	type& operator|=(MatType value);

	// XOR
	type operator^(const type& otherMat) const;

	// Single value XOR
	type operator^(MatType value) const;

	// In Place XOR
	type& operator^=(const type& otherMat);

	// Single value In Place XOR
	type& operator^=(MatType value);

	// Comparisons
	// Equal
	bool operator==(const type& otherMat);

	// Not Equal
	bool operator!=(const type& otherMat);

protected:
    /**
     * Calculate a matrix of cofactors (A matrix of minors with the checkerboard of minuses already applied) for use
     * calculating the inverse matrix
     * This method uses [sfinae](https://en.cppreference.com/w/cpp/language/sfinae) to only compile when the Matrix is 2x2
     * @return The Matrix of Cofactors
     */
    template<int uCol=columns, int uRow=rows, std::enable_if_t<uCol == 2 && uRow == 2, int> = 0>
    inline type calculateCofactors() {
        type minors;

        minors[0][0] = cells[1][1];
        minors[0][1] = -cells[1][0];
        minors[1][0] = -cells[0][1];
        minors[1][1] = cells[0][0];
    }

    /**
     * Calculate a matrix of cofactors (A matrix of minors with the checkerboard of minuses already applied) for use
     * calculating the inverse matrix
     * This method uses [sfinae](https://en.cppreference.com/w/cpp/language/sfinae) to only compile when the Matrix is square
     * and greater than 2x2
     * @return The Matrix of Cofactors
     */
    template<int uCol=columns, int uRow=rows, std::enable_if_t<(uCol != 2 || uRow != 2) && uCol == uRow, int> = 0>
    type calculateCofactors() {
        type minors;

        for (int column = 0; column < columns; ++column) {
            for (int row = 0; row < rows; ++row) {
                Matrix<columns - 1, rows - 1, MatType> subDeterminant;

                for (int subColumn = 0, i = 0; subColumn < columns; ++subColumn) {
                    if (subColumn != column) {
                        for (int subRow = 0, j = 0; subRow < rows; ++subRow){
                            if (subRow != row) {
                                subDeterminant[i][j] = cells[subColumn][subRow];

                                ++j;
                            }
                        }

                        ++i;
                    }

                }

                minors[column][row] = (column % 2 == 0 ? 1 : -1) * (row % 2 == 0 ? 1 : -1) * subDeterminant.determinant();
            }
        }

        return minors;
    }
};

#include "Source/Matrix.inl"