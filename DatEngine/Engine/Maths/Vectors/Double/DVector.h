#pragma once

#include "../VectorForward.h"

struct DVector {
	double x, z, y;

	/** A vector pointing up (0,0,1) */
	const static DVector up;
	/** A vector pointing down (0,0,-1) */
	const static DVector down;
	/** A vector pointing north (0,1,0) */
	const static DVector north;
	/** A vector pointing south (0,-1,0) */
	const static DVector south;
	/** A vector pointing east (1,0,0) */
	const static DVector east;
	/** A vector pointing west (-1,0,0) */
	const static DVector west;

	/**
	 * Initialises at 0,0,0
	 */
	DVector();

	/**
	 * Initialises with xyz each set to the given value
	 * @param Value The value to set xyz to
	 */
	DVector(double Value);

	/**
	 * Initialises with xyz set to their respective given value
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 * @param Z The Z component of the vector
	 */
	DVector(double X, double Y, double Z);


	// Copy Constructors
	/**
	 * Initialises as a copy of the given vector
	 * @param vec The vector to copy
	 */
	DVector(const DVector& Vec);

	/**
	 * Initialises as a copy of the given 2D vector and with the given Z vector
	 * @param Vec The 2D Vector to copy from
	 * @param Z The Z component of the vector
	 */
	DVector(const DVector2D& Vec, double Z);

	/**
	 * Initialises as a copy of the given 4D Vector, reduced down to a 3d vector
	 * @param Vec The 4D Vector to copy from
	 */
	DVector(const DVector4D& Vec);

	// Explicit Conversions
	explicit operator FVector() const;

	explicit operator IVector() const;

	// Setters
	/**
	 * Sets the values of the vector to the given vector in place
	 * @param newX The value to set X to
	 * @param newY The value to set Y to
	 * @param newZ The value to set Z to
	 */
	void set(double newX, double newY, double newZ);

	/**
	 * Sets the values of the vector to the given value in place
	 * @param newValue The value to set each of the components of the vector to
	 */
	void set(double newValue);

	/**
	 * Sets the values of the vector to the ones in the given vector, in place
	 * @param OtherVector The vector to copy the components from
	 */
	void set(const DVector& OtherVector);

	// Operators
	/**
	 * Adds together two vectors
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	DVector operator+(const DVector& OtherVec) const;

	/**
	 * Adds a value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	DVector operator+(double Amount) const;

	/**
	 * Adds a vector to this vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	DVector operator+=(const DVector& OtherVec) const;

	/**
	 * Adds the value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	DVector operator+=(double Amount) const;

	/**
	 * Adds a the given amount to each component of the vector
	 * @param Amount The amount to add to each component
	 * @return The resulting vector
	 */
	DVector operator++(int Amount);

	/**
	 * Minuses one vector from another
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	DVector operator-(const DVector& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount the amount to take from each component
	 * @return The resulting vector
	 */
	DVector operator-(double Amount) const;

	/**
	 * Minuses a vector from this vector
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	DVector operator-=(const DVector& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	DVector operator-=(double Amount) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	DVector operator--(int Amount);

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	DVector operator*(const DVector& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	DVector operator*(double Value) const;

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	DVector operator*=(const DVector& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	DVector operator*=(double Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	DVector operator/(const DVector& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	DVector operator/(double Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	DVector operator/=(const DVector& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	DVector operator/=(double Value) const;

	// Comparison
	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is smaller or not
	 */
	bool operator<(const DVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is bigger or not
	 */
	bool operator>(const DVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is less than or equal to the other or not
	 */
	bool operator<=(const DVector& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is more than or equal to the other or not
	 */
	bool operator>=(const DVector& OtherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator==(const DVector& OtherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator!=(const DVector& OtherVec) const;

	/**
	 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
	 * @param OtherVec The vector to compare to
	 * @param Tolerence How far off the vector can be before
	 * @return Whether the components are equal
	 */
	bool equals(const DVector& OtherVec, double Tolerence = Numbers::tiny) const;

	/**
	 * Gets the magnitude squared of the vector
	 * @return The magnitude squared of the vector
	 */
	double magnitudeSquared() const;

	/**
	 * Gets the magnitude of the vector
	 * @return The magnitude of the vector
	 */
	double magnitude() const;

	/**
	 * Gets the equivalent unit vector, returns a zero vector if the length is too small
	 * @return The equivalent unit vector
	 */
	DVector normalise() const;

	/**
	 * Checks if the vector is normalised
	 * @return If the vector is normalised
	 */
	bool isNormalised(double Tolerence = Tolerences::normalisedTolerence) const;
};