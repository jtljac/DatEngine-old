#include "../Vectors/Vec3.h"


/** A vector pointing up (0,0,1) */
template<typename VecType>
const static Vec<3, VecType>::type Vec<3, VecType>::up;
/** A vector pointing down (0,0,-1) */
template<typename VecType>
const static Vec<3, VecType>::type Vec<3, VecType>::down;
/** A vector pointing north (0,1,0) */
template<typename VecType>
const static Vec<3, VecType>::type Vec<3, VecType>::north;
/** A vector pointing south (0,-1,0) */
template<typename VecType>
const static Vec<3, VecType>::type Vec<3, VecType>::south;
/** A vector pointing east (1,0,0) */
template<typename VecType>
const static Vec<3, VecType>::type Vec<3, VecType>::east;
/** A vector pointing west (-1,0,0) */
template<typename VecType>
const static Vec<3, VecType>::type Vec<3, VecType>::west;

/**
 * Initialises at 0,0,0
 */
template<typename VecType>
Vec<3, VecType>::Vec() : x(0), y(0), z(0) {}

/**
 * Initialises with xyz each set to the given value
 * @param Value The value to set xyz to
 */
template<typename VecType>
Vec<3, VecType>::Vec(VecType Value) : x(Value), y(Value), z(Value) {}

/**
 * Initialises with xyz set to their respective given value
 * @param X The X component of the vector
 * @param Y The Y component of the vector
 * @param Z The Z component of the vector
 */
template<typename VecType>
Vec<3, VecType>::Vec(VecType X, VecType Y, VecType Z) : x(X), y(Y), z(Z) {}


// Copy Constructors
/**
 * Initialises as a copy of the given vector
 * @param OtherVec The vector to copy
 */
template<typename VecType>
Vec<3, VecType>::Vec(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z) {}

/**
 * Initialises as a copy of the given 2D vector and with the given Z vector
 * @param OtherVec The 2D Vector to copy from
 * @param Z The Z component of the vector
 */
template<typename VecType>
Vec<3, VecType>::Vec(const Vec<2, VecType>& OtherVec, VecType Z) : x(OtherVec.x), y(OtherVec.y), z(Z) {}

/**
 * Initialises as a copy of the given 4D Vector, reduced down to a 3d vector
 * @param OtherVec The 4D Vector to copy from
 */
template<typename VecType>
Vec<3, VecType>::Vec(const Vec<4, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z) {}

// Setters
/**
 * Sets the values of the vector to the given vector in place
 * @param newX The value to set X to
 * @param newY The value to set Y to
 * @param newZ The value to set Z to
 */
template<typename VecType>
void Vec<3, VecType>::set(VecType newX, VecType newY, VecType newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

/**
 * Sets the values of the vector to the given value in place
 * @param newValue The value to set each of the components of the vector to
 */
template<typename VecType>
void Vec<3, VecType>::set(VecType newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
}

/**
 * Sets the values of the vector to the ones in the given vector, in place
 * @param OtherVector The vector to copy the components from
 */
template<typename VecType>
void Vec<3, VecType>::set(const type& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
}

// Operators
/**
 * Adds together two vectors
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator+(const VecType& OtherVec) const {
	return type(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

/**
 * Adds a value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator+(VecType Amount) const {
	return type(x + Amount, y + Amount, z + Amount);
}

/**
 * Adds a vector to this vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator+=(const type& OtherVec) const {
	return (*this) + OtherVec;
}

/**
 * Adds the value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator+=(VecType Amount) const {
	return (*this) + Amount;
}

/**
 * Increments each component of the vector and returns the incremented vector
 * @return The incremented vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator++() {
	x += 1;
	y += 1;
	z += 1;
	return *this;
}

/**
 * Increments each component of the vector and returns the vector before incrementing
 * @return The vector before being incremented
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator++(int) {
	type temp(*this);
	++(*this);
	return temp;
}

/**
 * Minuses one vector from another
 * @param OtherVec The vector you're minusing from this one
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator-(const type& OtherVec) const {
	return type(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

/**
 * Minuses the given amount from each component
 * @param Amount the amount to take from each component
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator-(VecType Amount) const {
	return type(x - Amount, y - Amount, z - Amount);
}

/**
 * Minuses a vector from this vector
 * @param OtherVec The vector you're minusing from this one
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator-=(const type& OtherVec) const {
	return (*this) - OtherVec;
}

/**
 * Minuses the given amount from each component
 * @param Amount The amount to take from each vector
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator-=(VecType Amount) const {
	return (*this) - Amount;
}

/**
 * decrements each component of the vector and returns the dencremented vector
 * @return The dencremented vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator--() {
	x += 1;
	y += 1;
	z += 1;
	return *this;
}

/**
 * decrements each component of the vector and returns the vector before being decremented
 * @return The vector before being decremented
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator--(int) {
	type temp(*this);
	--(*this);
	return temp;
}

/**
 * Multiplies each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator*(const type& OtherVec) const {
	return type(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator*(VecType Value) const {
	return type(x * Value, y * Value, z * Value);
}

/**
 * Multiplies each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator*=(const type& OtherVec) const {
	return (*this)* OtherVec;
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator*=(VecType Value) const {
	return (*this) * Value;
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator/(const type& OtherVec) const {
	return type(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator/(VecType Value) const {
	return type(x / Value, y / Value, z / Value);
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator/=(const type& OtherVec) const {
	return (*this) / OtherVec;
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vec<3, VecType>::type Vec<3, VecType>::operator/=(VecType Value) const {
	return (*this) / Value;
}

// Comparison
/**
 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than the second's
 * @param OtherVec The vector to compare to
 * @return Whether the vector's magnitude is smaller or not
 */
template<typename VecType>
bool Vec<3, VecType>::operator<(const type& OtherVec) const;

/**
 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than the second's
 * @param OtherVec The vector to compare to
 * @return Whether the vector's magnitude is bigger or not
 */
template<typename VecType>
bool Vec<3, VecType>::operator>(const type& OtherVec) const;

/**
 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is less than or equal to the second's
 * @param OtherVec The vector to compare to
 * @return Whether the vector's magnitude is less than or equal to the other or not
 */
template<typename VecType>
bool Vec<3, VecType>::operator<=(const type& OtherVec) const;

/**
 * Compares the magnitude of the 2 vectors, returning true if the first vector's magnitude is more than or equal to the second's
 * @param OtherVec The vector to compare to
 * @return Whether the vector's magnitude is more than or equal to the other or not
 */
template<typename VecType>
bool Vec<3, VecType>::operator>=(const type& OtherVec) const;

/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vec<3, VecType>::operator==(const type& OtherVec) const;

/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vec<3, VecType>::operator!=(const type& OtherVec) const;

/**
 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
 * @param OtherVec The vector to compare to
 * @param Tolerence How far off the vector can be before
 * @return Whether the components are equal
 */
template<typename VecType>
bool Vec<3, VecType>::equals(const type& OtherVec, float Tolerence = Numbers::tiny) const;