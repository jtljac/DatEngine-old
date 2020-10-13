#pragma once

#include "VecForward.h"


template<typename VecType>
struct Vec<3, VecType> {
	typedef Vec<3, VecType> type;

	VecType x, y, z;

	/** A vector pointing up (0,0,1) */
	const static type up;
	/** A vector pointing down (0,0,-1) */
	const static type down;
	/** A vector pointing north (0,1,0) */
	const static type north;
	/** A vector pointing south (0,-1,0) */
	const static type south;
	/** A vector pointing east (1,0,0) */
	const static type east;
	/** A vector pointing west (-1,0,0) */
	const static type west;

	/**
	 * Initialises at 0,0,0
	 */
	Vec();

	/**
	 * Initialises with xyz each set to the given value
	 * @param Value The value to set xyz to
	 */
	Vec(VecType Value);

	/**
	 * Initialises with xyz set to their respective given value
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 * @param Z The Z component of the vector
	 */
	Vec(VecType X, VecType Y, VecType Z);


	// Copy Constructors
	/**
	 * Initialises as a copy of the given vector
	 * @param OtherVec The vector to copy
	 */
	Vec(const type& OtherVec);

	/**
	 * Initialises as a copy of the given 2D vector and with the given Z vector
	 * @param OtherVec The 2D Vector to copy from
	 * @param Z The Z component of the vector
	 */
	Vec(const Vec<2, VecType>& OtherVec, VecType Z);

	/**
	 * Initialises as a copy of the given 4D Vector, reduced down to a 3d vector
	 * @param OtherVec The 4D Vector to copy from
	 */
	Vec(const Vec<4, VecType>& OtherVec);

	// Setters
	/**
	 * Sets the values of the vector to the given vector in place
	 * @param newX The value to set X to
	 * @param newY The value to set Y to
	 * @param newZ The value to set Z to
	 */
	void set(VecType newX, VecType newY, VecType newZ);

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
	 * Adds together two vectors
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type operator+(const VecType& OtherVec) const;

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
	type operator+=(const type& OtherVec) const;

	/**
	 * Adds the value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	type operator+=(VecType Amount) const;

	/**
	 * Increments each component of the vector and returns the incremented vector
	 * @return The incremented vector
	 */
	type operator++();

	/**
	 * Increments each component of the vector and returns the vector before incrementing
	 * @return The vector before being incremented
	 */
	type operator++(int);

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
	type operator-=(const type& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	type operator-=(VecType Amount) const;

	/**
	 * decrements each component of the vector and returns the dencremented vector
	 * @return The dencremented vector
	 */
	type operator--();

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
	type operator*=(const type& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator*=(VecType Value) const;

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
	type operator/=(const type& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	type operator/=(VecType Value) const;

	// Comparison
	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is smaller or not
	 */
	bool operator<(const type& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is bigger or not
	 */
	bool operator>(const type& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is less than or equal to the other or not
	 */
	bool operator<=(const type& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is more than or equal to the other or not
	 */
	bool operator>=(const type& OtherVec) const;

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
	bool equals(const type& OtherVec, float Tolerence = Numbers::tiny) const;
};