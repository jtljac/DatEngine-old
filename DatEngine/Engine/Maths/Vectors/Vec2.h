#pragma once

#include "VecForward.h"


template<typename VecType>
struct Vector<2, VecType> {
	typedef Vector<2, VecType> type;

	VecType x, y;

	/** A vector pointing up (0,1) */
	const static type up;
	/** A vector pointing down (0,-1) */
	const static type down;
	/** A vector pointing right (1,0) */
	const static type right;
	/** A vector pointing left (-1, 0) */
	const static type left;

	Vector() = default;

	/**
	 * Constructs the 2d Vector with both components set to the given value
	 * @param value The value to set both components to
	 */
	explicit Vector(VecType value);

	/**
	 * Constructs the 2d Vector with its individual components
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 */
	Vector(VecType X, VecType Y);

	/**
	 * Constructs the 2d Vector with an array
	 * @param array The array containing the components of the vector
	 */
	explicit Vector(VecType array[2]);


	// Copy Constructors
	Vector(const type& otherVec);

	/**
	 * Constructs a 2d Vector using the X and Y Components of a 3d Vector
	 * @param otherVec The 3D Vector to copy from
	 */
	explicit Vector(const Vector<3, VecType>& otherVec);

	/**
	 * Constructs a 2d Vector using the X and Y Components of a 4D Vector
	 * @param otherVec The 4D Vector to copy from
	 */
	explicit Vector(const Vector<4, VecType>& otherVec);
	
	/**
	 * Constructs the 2d Vector as a copy of a vector of a different type
	 * @param otherVec The 2D Vector to cast from
	 */
	template<typename OtherType>
	explicit Vector(const Vector<2, OtherType>& otherVec);

	// Setters
	/**
	 * Sets the components to the given values
	 * @param newX The value to set X to
	 * @param newY The value to set Y to
	 */
	void set(VecType newX, VecType newY);

	/**
	 * Sets both the components of the vector to the given value
	 * @param newValue The value to set each of the components to
	 */
	void set(VecType newValue);

	/**
	 * Sets the values of the vector to the ones in the given vector, in place
	 * @param otherVector The vector to copy the components from
	 */
	void set(const type& otherVector);

	// Operators
	/**
	 * Gets a reference to the component at the given index
	 * @param index The index of the component (0 -> X, 1 -> Y)
	 * @return A reference to the component at the given index
	 */
	VecType& operator[](size_t index);

	/**
	 * Gets a const reference to the component at the given index
	 * @param index The index of the component (0 -> X, 1 -> Y)
	 * @return A const reference to the component at the given index
	 */
	VecType& operator[](size_t index) const;

	/**
	 * Adds together two vectors
	 * @param otherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type operator+(const type& otherVec) const;

	/**
	 * Adds a value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type operator+(VecType amount) const;

	/**
	 * Adds a vector to this vector
	 * @param otherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type& operator+=(const type& otherVec);

	/**
	 * Adds the value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type& operator+=(VecType amount);

	/**
	 * Increments each component of the vector and returns the incremented vector
	 * @return The incremented vector
	 */
	type& operator++();

	/**
	 * Increments each component of the vector and returns the vector before incrementing
	 * @return The vector before being incremented
	 */
    type operator++(int);

	/**
	 * Gets the negation of the vector
	 * @return The negated vector
	 */
	type operator-() const;

	/**
	 * Minuses one vector from another
	 * @param otherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	type operator-(const type& otherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param amount the amount to take from each component
	 * @return The resulting vector
	 */
	type operator-(VecType amount) const;

	/**
	 * Minuses a vector from this vector
	 * @param otherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	type& operator-=(const type& otherVec);

	/**
	 * Minuses the given amount from each component
	 * @param amount The amount to take from each vector
	 * @return The resulting vector
	 */
	type& operator-=(VecType amount);

	/**
	 * decrements each component of the vector and returns the decremented vector
	 * @return The decremented vector
	 */
	type& operator--();

	 /**
	  * decrements each component of the vector and returns the vector before being decremented
	  * @return The vector before being decremented
	  */
	type operator--(int);

	/**
	 * Multiplies each component by the equivalent component in the other vector
	 * @param otherVec The other vector
	 * @return The resulting vector
	 */
	type operator*(const type& otherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator*(VecType value) const;

	/**
	 * Multiplies each component by the equivalent component in the other vector
	 * @param otherVec The other vector
	 * @return The resulting vector
	 */
	type& operator*=(const type& otherVec);

	/**
	 * Multiplies each component of the vector by the given value
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type& operator*=(VecType value);

	/**
	 * Divides each component by the equivalent component in the other vector
	 * @param otherVec The other vector
	 * @return The resulting vector
	 */
	type operator/(const type& otherVec) const;

	/**
	 * Divides each component of the vector by the given value
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator/(VecType value) const;

	/**
	 * Divides each component by the equivalent component in the other vector
	 * @param otherVec The other vector
	 * @return The resulting vector
	 */
	type& operator/=(const type& otherVec);

	/**
	 * Divides each component of the vector by the given value
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type& operator/=(VecType value);

	// Comparison
	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
	 * @param otherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator==(const type& otherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
	 * @param otherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator!=(const type& otherVec) const;

	/**
	 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerance of the given vector's components
	 * @param otherVec The vector to compare to
	 * @param tolerance How far off the vector can be before
	 * @return Whether the components are equal
	 */
    [[maybe_unused]] bool equals(const type& otherVec, VecType tolerance = Maths::Numbers::tinyNumber) const;

	/**
	 * Gets the squared magintude of the vector
	 * The sum of the squares of each component
	 * Useful for comparing the size of vectors as the length squared will remain bigger or smaller like the actually lengths compared, but it skips the expensive square root calculation
	 * @return The squared scalar size of the vector
	 */
	VecType lengthSquared() const;

	/**
	 * Gets the magnitude of the vector
	 * The square root of the sum of the squares of each component
	 * @return The scalar size of the vector
	 */
	VecType length() const;

	/**
	 * Normalises the vector in place
	 */
	void normalise();

	/**
	 * Gets the vector pointing in the same direction, but with a length of 1
	 * @return A unit vector pointing in the same direction
	 */
	Vector<2, VecType> normalised() const;

	/**
	 * Gets if the vector is normalised
	 * (Has a length of one)
	 * @return True if the vector is normalised
	 */
    [[maybe_unused]] bool isNormalised(VecType tolerance = Maths::Tolerances::normalisedTolerance) const;
};

#include "Source/Vec2.inl"