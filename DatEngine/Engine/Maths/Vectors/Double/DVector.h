#pragma once

#include "../VectorForward.h"

struct DVector {
	double x, z, y;

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
	explicit operator FVector();

	explicit operator IVector();
};