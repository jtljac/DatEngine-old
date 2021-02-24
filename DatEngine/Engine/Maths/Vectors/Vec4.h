#pragma once

#include "VecForward.h"


template<typename VecType>
struct Vector<4, VecType> {
	typedef Vector<4, VecType> type;

	VecType x, y, z, w;

	/**
	 * Initialises at 0,0,0,0
	 */
	Vector();

	/**
	 * Initialises with xyzw each set to the given value
	 * @param Value The value to set xyzw to
	 */
	Vector(VecType Value);

	/**
	 * Initialises with xyz set to their respective given value
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 * @param Z The Z component of the vector
	 * @param W The W component of the vector
	 */
	Vector(VecType X, VecType Y, VecType Z, VecType W);

	/**
	 * Initialises with an array
	 * @param Array The Array containing the components of the vector
	 */
	Vector(VecType Array[4]);


	// Copy Constructors
	/**
	 * Initialises as a copy of the given vector
	 * @param OtherVec The vector to copy
	 */
	Vector(const type& OtherVec);

	/**
	 * Initialises as a copy of the given 2D vector and with the given Z and W component
	 * @param OtherVec The 2D Vector to copy from
	 * @param Z The Z component of the vector
	 * @param W The W component of the vector
	 */
	Vector(const Vector<2, VecType>& OtherVec, VecType Z, VecType W);

	/**
	 * Initialises as a copy of the given 3D Vector and with the given W component
	 * @param OtherVec The 3D Vector to copy from
	 * @param W The W component of the vector
	 */
	Vector(const Vector<3, VecType>& OtherVec);
	
	/**
	 * Initialises as a copy of a vector of a different type
	 * @param OtherVec The other Vector to cast from
	 */
	template<typename OtherType>
	explicit Vector(const Vector<4, OtherType>& OtherVec);

	// Setters
	/**
	 * Sets the values of the vector to the given vector in place
	 * @param newX The value to set X to
	 * @param newY The value to set Y to
	 * @param newZ The value to set Z to
	 * @param newZ The value to set W to
	 */
	void set(VecType newX, VecType newY, VecType newZ, VecType newW);

	/**
	 * Sets the values of the vector to the given value in place
	 * @param newValue The value to set each of the components of the vector to
	 */
	void set(VecType newValue);

	/**
	 * Sets the values of the vector to the ones in the given vector, in place
	 * @param OtherVector The vector to copy the components from
	 */
	void set(const type& OtherVector);

	// Operators
	/**
	 * Gets a reference to the component at the given index
	 * @param Index The index of the component (0 -> X, 1 -> Y, 2 -> Z, 3 -> W)
	 * @return A reference to the component at the given index
	 */
	VecType& operator[](const size_t Index);

	/**
	 * Gets a const reference to the component at the given index
	 * @param Index The index of the component (0 -> X, 1 -> Y, 2 -> Z, 3 -> W)
	 * @return A const reference to the component at the given index
	 */
	VecType const& operator[](const size_t Index) const;

	/**
	 * Adds together two vectors
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type operator+(const type& OtherVec) const;

	/**
	 * Adds a value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type operator+(VecType Amount) const;

	/**
	 * Adds a vector to this vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type& operator+=(const type& OtherVec);

	/**
	 * Adds the value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type& operator+=(VecType Amount);

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
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	type operator-(const type& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount the amount to take from each component
	 * @return The resulting vector
	 */
	type operator-(VecType Amount) const;

	/**
	 * Minuses a vector from this vector
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	type& operator-=(const type& OtherVec);

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	type& operator-=(VecType Amount);

	/**
	 * decrements each component of the vector and returns the dencremented vector
	 * @return The dencremented vector
	 */
	type& operator--();

	 /**
	  * decrements each component of the vector and returns the vector before being decremented
	  * @return The vector before being decremented
	  */
	type operator--(int);

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	type operator*(const type& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator*(VecType Value) const;

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	type& operator*=(const type& OtherVec);

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	type& operator*=(VecType Value);

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	type operator/(const type& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator/(VecType Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	type& operator/=(const type& OtherVec);

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	type& operator/=(VecType Value);

	// Comparison
	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator==(const type& OtherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator!=(const type& OtherVec) const;

	/**
	 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
	 * @param OtherVec The vector to compare to
	 * @param Tolerence How far off the vector can be before
	 * @return Whether the components are equal
	 */
	bool equals(const type& OtherVec, VecType Tolerance = Numbers::tiny) const;

	/**
	 * Gets the squared scalar size of the vector
	 * The sum of the squares of each component
	 * Useful for comparing the size of vectors as the length squared will remain bigger or smaller like the actualy lengths compared, but it skips the expensive square root calculation
	 * @return The squared scalar size of the vector
	 */
	VecType lengthSquared() const;

	/**
	 * Gets the scalar size of the vector
	 * The square root of the sum of the squares of each component
	 * @return The scalar size of the vector
	 */
	VecType length() const;

	/**
	 * Gets the vector pointing in the same direction, but with a length of 1
	 * @return A unit vector pointing in the same direction
	 */
	template<typename ResultType = float>
	Vector<4, ResultType> normalise() const;

	/**
	 * Gets if the vector is normalised
	 * (Has a length of one)
	 * @return True if the vector is normalised
	 */
	bool isNormalised(VecType Tolerance = Tolerances::normalisedTolerance) const;
};

#include "Source/Vec4.inl"