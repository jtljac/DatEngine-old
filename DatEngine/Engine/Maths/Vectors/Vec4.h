#pragma once

#include "VecForward.h"
#include "../CommonMaths.h"


template<typename VecType>
struct Vector<4, VecType> {
	typedef Vector<4, VecType> type;

	VecType x, y, z, w;

	Vector() = default;

	/**
	 * Constructs a 4d Vector using the given value for each component
	 * @param value The value to set each component to
	 */
	explicit Vector(VecType value);

	/**
	 * Constructs a 4d Vector using it's individual components
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 * @param Z The Z component of the vector
	 * @param W The W component of the vector
	 */
	Vector(VecType X, VecType Y, VecType Z, VecType W);

	/**
	 * Constructs a 4d Vector using values from an array
	 * @param array The array containing the components of the vector
	 */
	explicit Vector(VecType array[4]);


	// Copy Constructors
	Vector(const type& otherVec);

	/**
	 * Constructs a 4d vector using the xy components of a 2d vector and the given Z and W components
	 * @param otherVec The 2D Vector to copy from
	 * @param Z The Z component of the vector
	 * @param W The W component of the vector
	 */
	Vector(const Vector<2, VecType>& otherVec, VecType Z, VecType W);

	/**
	 * Constructs a 4d vector using the xyz components of a 3d vector and the given W component
	 * @param otherVec The 3D Vector to copy from
	 * @param W The W component of the vector
	 */
	Vector(const Vector<3, VecType>& otherVec, VecType W);
	
	/**
	 * Converts a 4d vector of a different type
	 * @param otherVec The other Vector to cast from
	 */
	template<typename OtherType>
	explicit Vector(const Vector<4, OtherType>& otherVec);

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
	 * @param index The index of the component (0 -> X, 1 -> Y, 2 -> Z, 3 -> W)
	 * @return A reference to the component at the given index
	 */
	VecType& operator[](size_t index);

	/**
	 * Gets a const reference to the component at the given index
	 * @param index The index of the component (0 -> X, 1 -> Y, 2 -> Z, 3 -> W)
	 * @return A const reference to the component at the given index
	 */
	VecType const& operator[](size_t index) const;

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
	type operator+(VecType amount) const;

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
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	type operator-(const type& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param amount the amount to take from each component
	 * @return The resulting vector
	 */
	type operator-(VecType amount) const;

	/**
	 * Minuses a vector from this vector
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	type& operator-=(const type& OtherVec);

	/**
	 * Minuses the given amount from each component
	 * @param amount The amount to take from each vector
	 * @return The resulting vector
	 */
	type& operator-=(VecType amount);

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
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator*(VecType value) const;

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	type& operator*=(const type& OtherVec);

	/**
	 * Multiplies each component of the vector by the given value
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type& operator*=(VecType value);

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	type operator/(const type& OtherVec) const;

	/**
	 * Divides each component of the vector by the given value
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator/(VecType value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	type& operator/=(const type& OtherVec);

	/**
	 * Divides each component of the vector by the given value
	 * @param value The value to multiply each component by
	 * @return The resulting vector
	 */
	type& operator/=(VecType value);

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
    [[maybe_unused]] bool equals(const type& OtherVec, VecType Tolerance = Maths::Numbers::tinyNumber) const;

	/**
	 * Gets the squared magnitude of the vector
	 * The sum of the squares of each component
	 * Useful for comparing the size of vectors as the length squared will remain bigger or smaller like the actualy lengths compared, but it skips the expensive square root calculation
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
	Vector<4, VecType> normalised() const;

	/**
	 * Gets if the vector is normalised
	 * (Has a length of one)
	 * @return True if the vector is normalised
	 */
    [[maybe_unused]] bool isNormalised(VecType tolerance = Maths::Tolerances::normalisedTolerance) const;
};

#include "Source/Vec4.inl"