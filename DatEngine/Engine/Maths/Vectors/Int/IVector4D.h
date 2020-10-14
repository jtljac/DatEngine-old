#pragma once

#include "../VectorForward.h"

struct IVector4D {
	int x, y, z, w;

	/**
	 * Initialises at 0,0,0,0
	 */
	IVector4D();

	/**
	 * Initialises with xyzw each set to the given value
	 * @param Value The value to set xyzw to
	 */
	IVector4D(int Value);

	/**
	 * Initialises with xyzw set to their respective given value
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 * @param Z The Z component of the vector
	 * @param W The W component of the vector
	 */
	IVector4D(int X, int Y, int Z, int W);


	// Copy Constructors
	/**
	 * Initialises as a copy of the given vector
	 * @param Vec The vector to copy
	 */
	IVector4D(const IVector4D& Vec);

	/**
	 * Initialises as a copy of the given 3D vector and with the given W vector
	 * @param Vec The 3D Vector to copy from
	 * @param W The W component of the vector
	 */
	IVector4D(const IVector& Vec, int W);

	/**
	 * Initialises as a copy of the given 2D Vector and with the given Z and W vectors
	 * @param Vec The 4D Vector to copy from
	 * @param Z The Z component of the vector
	 * @param W The W component of the vector
	 */
	IVector4D(const IVector2D& Vec, int Z, int W);

	// Explicit Conversions
	explicit operator FVector4D() const;

	explicit operator DVector4D() const;

	// Setters
	/**
	 * Sets the values of the vector to the given vector in place
	 * @param newX The value to set X to
	 * @param newY The value to set Y to
	*/
	void set(int newX, int newY, int newZ, int newW);

	/**
	 * Sets the values of the vector to the given value in place
	 * @param newValue The value to set each of the components of the vector to
	 */
	void set(int newValue);

	/**
	 * Sets the values of the vector to the ones in the given vector, in place
	 * @param OtherVector The vector to copy the components from
	 */
	void set(const IVector4D& OtherVector);

	// Operators
	/**
	 * Adds together two vectors
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector4D operator+(const IVector4D& OtherVec) const;

	/**
	 * Adds a value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector4D operator+(int Amount) const;

	/**
	 * Adds a vector to this vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector4D operator+=(const IVector4D& OtherVec) const;

	/**
	 * Adds the value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector4D operator+=(int Amount) const;

	/**
	 * Adds a the given amount to each component of the vector
	 * @param Amount The amount to add to each component
	 * @return The resulting vector
	 */
	IVector4D operator++(int Amount);

	/**
	 * Minuses one vector from another
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	IVector4D operator-(const IVector4D& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount the amount to take from each component
	 * @return The resulting vector
	 */
	IVector4D operator-(int Amount) const;

	/**
	 * Minuses a vector from this vector
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	IVector4D operator-=(const IVector4D& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	IVector4D operator-=(int Amount) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	IVector4D operator--(int Amount);

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector4D operator*(const IVector4D& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector4D operator*(int Value) const;

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector4D operator*=(const IVector4D& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector4D operator*=(int Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector4D operator/(const IVector4D& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector4D operator/(int Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector4D operator/=(const IVector4D& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector4D operator/=(int Value) const;

	// Comparison
	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is smaller or not
	 */
	bool operator<(const IVector4D& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is bigger or not
	 */
	bool operator>(const IVector4D& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is less than or equal to the other or not
	 */
	bool operator<=(const IVector4D& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is more than or equal to the other or not
	 */
	bool operator>=(const IVector4D& OtherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator==(const IVector4D& OtherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator!=(const IVector4D& OtherVec) const;

	/**
	 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
	 * @param OtherVec The vector to compare to
	 * @param Tolerence How far off the vector can be before
	 * @return Whether the components are equal
	 */
	bool equals(const IVector4D& OtherVec) const;

	/**
	 * Gets the magnitude squared of the vector
	 * @return The magnitude squared of the vector
	 */
	float magnitudeSquared() const;

	/**
	 * Gets the magnitude of the vector
	 * @return The magnitude of the vector
	 */
	float magnitude() const;

	/**
	 * Gets the equivalent unit vector, returns a zero vector if the length is too small
	 * @return The equivalent unit vector
	 */
	FVector4D normalise() const;

	/**
	 * Checks if the vector is normalised
	 * @return If the vector is normalised
	 */
	bool isNormalised(float Tolerence = Tolerances::normalisedTolerance) const;
};