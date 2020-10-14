#pragma once

#include "../VectorForward.h"

struct IVector {
	int x, y, z;

	/** A vector pointing up (0,0,1) */
	const static IVector up;
	/** A vector pointing down (0,0,-1) */
	const static IVector down;
	/** A vector pointing north (0,1,0) */
	const static IVector north;
	/** A vector pointing south (0,-1,0) */
	const static IVector south;
	/** A vector pointing east (1,0,0) */
	const static IVector east;
	/** A vector pointing west (-1,0,0) */
	const static IVector west;

	/**
	 * Initialises at 0,0,0
	 */
	IVector();

	/**
	 * Initialises with xyz each set to the given value
	 * @param Value The value to set xyz to
	 */
	IVector(int Value);

	/**
	 * Initialises with xyz set to their respective given value
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 * @param Z The Z component of the vector
	 */
	IVector(int X, int Y, int Z);


	// Copy Constructors
	/**
	 * Initialises as a copy of the given vector
	 * @param vec The vector to copy
	 */
	IVector(const IVector& Vec);

	/**
	 * Initialises as a copy of the given 2D vector and with the given Z vector
	 * @param Vec The 2D Vector to copy from
	 * @param Z The Z component of the vector
	 */
	IVector(const IVector2D& Vec, int Z);

	/**
	 * Initialises as a copy of the given 4D Vector, reduced down to a 3d vector
	 * @param Vec The 4D Vector to copy from
	 */
	IVector(const IVector4D& Vec);

	// Explicit Conversions
	explicit operator FVector() const;

	explicit operator DVector() const;

	// Setters
	/**
	 * Sets the values of the vector to the given vector in place
	 * @param newX The value to set X to
	 * @param newY The value to set Y to
	 * @param newZ The value to set Z to
	 */
	void set(int newX, int newY, int newZ);

	/**
	 * Sets the values of the vector to the given value in place
	 * @param newValue The value to set each of the components of the vector to
	 */
	void set(int newValue);

	/**
	 * Sets the values of the vector to the ones in the given vector, in place
	 * @param OtherVector The vector to copy the components from
	 */
	void set(const IVector& OtherVector);

	// Operators
	/**
	 * Adds together two vectors
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector operator+(const IVector& OtherVec) const;

	/**
	 * Adds a value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector operator+(int Amount) const;

	/**
	 * Adds a vector to this vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector operator+=(const IVector& OtherVec) const;

	/**
	 * Adds the value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	IVector operator+=(int Amount) const;

	/**
	 * Adds a the given amount to each component of the vector
	 * @param Amount The amount to add to each component
	 * @return The resulting vector
	 */
	IVector operator++(int Amount);

	/**
	 * Minuses one vector from another
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	IVector operator-(const IVector& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount the amount to take from each component
	 * @return The resulting vector
	 */
	IVector operator-(int Amount) const;

	/**
	 * Minuses a vector from this vector
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	IVector operator-=(const IVector& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	IVector operator-=(int Amount) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	IVector operator--(int Amount);

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector operator*(const IVector& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector operator*(int Value) const;

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector operator*=(const IVector& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector operator*=(int Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector operator/(const IVector& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector operator/(int Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	IVector operator/=(const IVector& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	IVector operator/=(int Value) const;

	// Comparison
	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is smaller or not
	 */
	bool operator<(const IVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is bigger or not
	 */
	bool operator>(const IVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is less than or equal to the other or not
	 */
	bool operator<=(const IVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is more than or equal to the other or not
	 */
	bool operator>=(const IVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is equal to the other or not
	 */
	bool operator==(const IVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is not equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is equal to the other or not
	 */
	bool operator!=(const IVector& OtherVec) const;

	/**
	 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
	 * @param OtherVec The vector to compare to
	 * @param Tolerence How far off the vector can be before
	 * @return Whether the components are equal
	 */
	bool equals(const IVector& OtherVec) const;

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
	FVector normalise() const;

	/**
	 * Checks if the vector is normalised
	 * @return If the vector is normalised
	 */
	bool isNormalised(float Tolerence = Tolerances::normalisedTolerance) const;
};