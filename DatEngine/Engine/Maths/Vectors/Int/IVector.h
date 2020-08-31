#pragma once

#include "../VectorForward.h"

struct IVector {
	int x, y, z;

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
	explicit operator FVector();

	explicit operator DVector();
};