#pragma once

struct FVector2D {
	float x, y;

	/** A vector pointing up (0,1) */
	const static FVector2D up;
	/** A vector pointing down (0,-1) */
	const static FVector2D down;
	/** A vector pointing north (1,0) */
	const static FVector2D right;
	/** A vector pointing south (-1,0) */
	const static FVector2D left;

	/**
	 * Initialises at 0,0
	 */
	FVector2D();

	/**
	 * Initialises with xy each set to the given value
	 * @param Value The value to set xy to
	 */
	FVector2D(float Value);

	/**
	 * Initialises with xyz set to their respective given value
	 * @param X The X component of the vector
	 * @param Y The Y component of the vector
	 */
	FVector2D(float X, float Y);


	// Copy Constructors
	/**
	 * Initialises as a copy of the given vector
	 * @param Vec The vector to copy
	 */
	FVector2D(const FVector2D& Vec);

	/**
	 * Initialises as a copy of the given 3D vector, reduced down to a 2d vector
	 * @param Vec The 3D Vector to copy from
	 */
	FVector2D(const FVector& Vec);

	/**
	 * Initialises as a copy of the given 4D Vector, reduced down to a 2d vector
	 * @param Vec The 4D Vector to copy from
	 */
	FVector2D(const FVector4D& Vec);

	// Explicit Conversions
	explicit operator IVector2D() const;

	explicit operator DVector2D() const;

	// Setters
	/**
	 * Sets the values of the vector to the given vector in place
	 * @param newX The value to set X to
	 * @param newY The value to set Y to
	*/
	void set(float newX, float newY);

	/**
	 * Sets the values of the vector to the given value in place
	 * @param newValue The value to set each of the components of the vector to
	 */
	void set(float newValue);

	/**
	 * Sets the values of the vector to the ones in the given vector, in place
	 * @param OtherVector The vector to copy the components from
	 */
	void set(const FVector2D& OtherVector);

	// Operators
	/**
	 * Adds together two vectors
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	FVector2D operator+(const FVector2D& OtherVec) const;

	/**
	 * Adds a value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	FVector2D operator+(float Amount) const;

	/**
	 * Adds a vector to this vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	FVector2D operator+=(const FVector2D& OtherVec) const;

	/**
	 * Adds the value to each component of the vector
	 * @param OtherVec The vector you're adding to this one
	 * @return The resulting vector
	 */
	FVector2D operator+=(float Amount) const;

	/**
	 * Adds a the given amount to each component of the vector
	 * @param Amount The amount to add to each component
	 * @return The resulting vector
	 */
	FVector2D operator++(int Amount);

	/**
	 * Minuses one vector from another
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	FVector2D operator-(const FVector2D& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount the amount to take from each component
	 * @return The resulting vector
	 */
	FVector2D operator-(float Amount) const;

	/**
	 * Minuses a vector from this vector
	 * @param OtherVec The vector you're minusing from this one
	 * @return The resulting vector
	 */
	FVector2D operator-=(const FVector2D& OtherVec) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	FVector2D operator-=(float Amount) const;

	/**
	 * Minuses the given amount from each component
	 * @param Amount The amount to take from each vector
	 * @return The resulting vector
	 */
	FVector2D operator--(int Amount);

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	FVector2D operator*(const FVector2D& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	FVector2D operator*(float Value) const;

	/**
	 * Multiplies each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	FVector2D operator*=(const FVector2D& OtherVec) const;

	/**
	 * Multiplies each component of the vector by the given value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	FVector2D operator*=(float Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	FVector2D operator/(const FVector2D& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	FVector2D operator/(float Value) const;

	/**
	 * Divides each component by the equivilent component in the other vector
	 * @param OtherVec The other vector
	 * @return The resulting vector
	 */
	FVector2D operator/=(const FVector2D& OtherVec) const;

	/**
	 * Divides each component of the vector by the given Value
	 * @param Value The value to multiply each component by
	 * @return The resulting vector
	 */
	FVector2D operator/=(float Value) const;

	// Comparison
	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is smaller or not
	 */
	bool operator<(const FVector2D& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is bigger or not
	 */
	bool operator>(const FVector2D& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is less than or equal to the other or not
	 */
	bool operator<=(const FVector2D& OtherVec) const;

	/**
	 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than or equal to the second's
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's magnitude is more than or equal to the other or not
	 */
	bool operator>=(const FVector2D& OtherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator==(const FVector2D& OtherVec) const;

	/**
	 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
	 * @param OtherVec The vector to compare to
	 * @return Whether the vector's components are equal to the other
	 */
	bool operator!=(const FVector2D& OtherVec) const;

	/**
	 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
	 * @param OtherVec The vector to compare to
	 * @param Tolerence How far off the vector can be before
	 * @return Whether the components are equal
	 */
	bool equals(const FVector2D& OtherVec, float Tolerence = Numbers::tiny) const;

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
	FVector2D normalise() const;

	/**
	 * Checks if the vector is normalised
	 * @return If the vector is normalised
	 */
	bool isNormalised(float Tolerence = Tolerences::normalisedTolerence) const;
};