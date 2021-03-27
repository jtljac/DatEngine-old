#include <Maths/CommonMaths.h>

/**
 * Initialises at 0,0,0,0
 */
template<typename VecType>
Vector<4, VecType>::Vector() : x(0), y(0), z(0), w(0) {}

/**
 * Initialises with xyz each set to the given value
 * @param Value The value to set xyz to
 */
template<typename VecType>
Vector<4, VecType>::Vector(VecType Value) : x(Value), y(Value), z(Value), w(Value) {}

/**
 * Initialises with xyz set to their respective given value
 * @param X The X component of the vector
 * @param Y The Y component of the vector
 * @param Z The Z component of the vector
 * @param W The W component of the vector
 */
template<typename VecType>
Vector<4, VecType>::Vector(VecType X, VecType Y, VecType Z, VecType W) : x(X), y(Y), z(Z), w(W) {}

/**
 * Initialises with an array
 * @param Array The Array containing the components of the vector
 */
template<typename VecType>
Vector<4, VecType>::Vector(VecType Array[4]) {
	std::memcpy(&x, Array, 4 * sizeof(VecType));
}


// Copy Constructors
/**
 * Initialises as a copy of the given vector
 * @param OtherVec The vector to copy
 */
template<typename VecType>
Vector<4, VecType>::Vector(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z), w(OtherVec.w) {}

/**
 * Initialises as a copy of the given 2D vector and with the given Z and W components
 * @param OtherVec The 2D Vector to copy from
 * @param Z The Z component of the vector
 * @param W The W component of the vector
 */
template<typename VecType>
Vector<4, VecType>::Vector(const Vector<2, VecType>& OtherVec, VecType Z, VecType W) : x(OtherVec.x), y(OtherVec.y), z(Z), w(W);

/**
 * Initialises as a copy of the given 3D Vector and with the given W component
 * @param OtherVec The 3D Vector to copy from
 * @param W The W component of the vector
 */
template<typename VecType>
Vector<4, VecType>::Vector(const Vector<3, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z), w(OtherVec.w) {}

/**
 * Initialises as a copy of a vector of a different type
 * @param OtherVec The other Vector to cast from
 */
template<typename VecType>
template<typename OtherType>
Vector<4, VecType>::Vector(const Vector<4, OtherType>& OtherVec) : x(static_cast<VecType>(OtherVec.x)), y(static_cast<VecType>(OtherVec.y)), z(static_cast<VecType>(OtherVec.z)), w(static_cast<VecType>(OtherVec.w)) {}

// Setters
/**
 * Sets the values of the vector to the given vector in place
 * @param newX The value to set X to
 * @param newY The value to set Y to
 * @param newZ The value to set Z to
 * @param newW The value to set W to
 */
template<typename VecType>
void Vector<4, VecType>::set(VecType newX, VecType newY, VecType newZ, VecType newW) {
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

/**
 * Sets the values of the vector to the given value in place
 * @param newValue The value to set each of the components of the vector to
 */
template<typename VecType>
void Vector<4, VecType>::set(VecType newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
	w = newValue;
}

/**
 * Sets the values of the vector to the ones in the given vector, in place
 * @param OtherVector The vector to copy the components from
 */
template<typename VecType>
void Vector<4, VecType>::set(const type& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
	w = OtherVector.w;
}

// Operators
/**
 * Gets a reference to the component at the given index
 * @param Index The index of the component (0 -> X, 1 -> Y, 2 -> Z, 3 -> W)
 * @return A reference to the component at the given index
 */
template<typename VecType>
VecType& Vector<4, VecType>::operator[](const size_t Index) {
#ifdef _DEBUG
	if (Index > 3) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

/**
	 * Gets a const reference to the component at the given index
	 * @param Index The index of the component (0 -> X, 1 -> Y, 2 -> Z, 3 -> W)
	 * @return A const reference to the component at the given index
	 */
template<typename VecType>
VecType const& Vector<4, VecType>::operator[](const size_t Index) const {
#ifdef _DEBUG
	if (Index > 3) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

/**
 * Adds together two vectors
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator+(const type& OtherVec) const {
	return type(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

/**
 * Adds a value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator+(VecType Amount) const {
	return type(x + Amount, y + Amount, z + Amount, w + Amount);
}

/**
 * Adds a vector to this vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator+=(const type& OtherVec) {
	x += OtherVec.x;
	y += OtherVec.y;
	z += OtherVec.z;
	w += OtherVec.w;
	return *this;
}

/**
 * Adds the value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator+=(VecType Amount) {
	x += Amount;
	y += Amount;
	z += Amount;
	w += Amount;

	return *this;
}

/**
 * Increments each component of the vector and returns the incremented vector
 * @return The incremented vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator++() {
	x += 1;
	y += 1;
	z += 1;
	w += 1;
	return *this;
}

/**
 * Increments each component of the vector and returns the vector before incrementing
 * @return The vector before being incremented
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator++(int) {
	type temp(*this);
	++(*this);
	return temp;
}

/**
 * Gets the negation of the vector
 * @return The negated vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator-() const {
	return type(-x, -y, -z, -w);
}

/**
 * Minuses one vector from another
 * @param OtherVec The vector you're minusing from this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator-(const type& OtherVec) const {
	return type(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

/**
 * Minuses the given amount from each component
 * @param Amount the amount to take from each component
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator-(VecType Amount) const {
	return type(x - Amount, y - Amount, z - Amount, w - Amount);
}

/**
 * Minuses a vector from this vector
 * @param OtherVec The vector you're minusing from this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator-=(const type& OtherVec) {
	x -= OtherVec.x;
	y -= OtherVec.y;
	z -= OtherVec.z;
	w -= OtherVec.w;
	return *this;
}

/**
 * Minuses the given amount from each component
 * @param Amount The amount to take from each vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator-=(VecType Amount) {
	x -= Amount;
	y -= Amount;
	z -= Amount;
	w -= Amount;

	return *this;
}

/**
 * decrements each component of the vector and returns the dencremented vector
 * @return The dencremented vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator--() {
	x -= 1;
	y -= 1;
	z -= 1;
	w -= 1;
	return *this;
}

/**
 * decrements each component of the vector and returns the vector before being decremented
 * @return The vector before being decremented
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator--(int) {
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
Vector<4, VecType> Vector<4, VecType>::operator*(const type& OtherVec) const {
	return type(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z, w * OtherVec.w);
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator*(VecType Value) const {
	return type(x * Value, y * Value, z * Value, w * Value);
}

/**
 * Multiplies each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator*=(const type& OtherVec) {
	x *= OtherVec.x;
	y *= OtherVec.y;
	z *= OtherVec.z;
	w *= OtherVec.w;
	return *this;
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator*=(VecType Value) {
	x *= Value;
	y *= Value;
	z *= Value;
	w *= Value;

	return *this;
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator/(const type& OtherVec) const {
	return type(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator/(VecType Value) const {
	return type(x / Value, y / Value, z / Value, w / Value);
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator/=(const type& OtherVec) {
	x /= OtherVec.x;
	y /= OtherVec.y;
	z /= OtherVec.z;
	w /= OtherVec.w;
	return *this;
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator/=(VecType Value) {
	x /= Value;
	y /= Value;
	z /= Value;
	w /= Value;

	return *this;
}

// Compairson
/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vector<4, VecType>::operator==(const type& OtherVec) const {
	return x == OtherVec.x && y == OtherVec.y && z == OtherVec.z && w == OtherVec.w;
}

/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vector<4, VecType>::operator!=(const type& OtherVec) const {
	return x != OtherVec.x || y != OtherVec.y || z != OtherVec.z || w != OtherVec.w;
}

/**
 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
 * @param OtherVec The vector to compare to
 * @param Tolerance How far off the vector can be before
 * @return Whether the components are equal
 */
template<typename VecType>
bool Vector<4, VecType>::equals(const type& OtherVec, VecType Tolerance) const {
	return fabs(x - OtherVec.x) < Tolerance && fabs(y - OtherVec.y) < Tolerance && fabs(z - OtherVec.z) < Tolerance && fabs(w - OtherVec.w) < Tolerance;
}

/**
 * Gets the squared scalar size of the vector
 * The sum of the squares of each component
 * Useful for comparing the size of vectors as the length squared will remain bigger or smaller like the actualy lengths compared, but it skips the expensive square root calculation
 * @return The squared scalar size of the vector
 */
template<typename VecType>
VecType Vector<4, VecType>::lengthSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
}

/**
 * Gets the scalar size of the vector
 * The square root of the sum of the squares of each component
 * @return The scalar size of the vector
 */
template<typename VecType>
VecType Vector<4, VecType>::length() const {
	return sqrt(lengthSquared());
}

/**
 * Normalises the vector in place
 */
template<typename VecType>
void Vector<4, VecType>::normalise() {
	(*this) *= Maths::inverseSqrt(length());
}

/**
 * Gets the vector pointing in the same direction, but with a length of 1
 * @return A unit vector pointing in the same direction
 */
template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::normalised() const {
	return (Vector<4, ResultType>)(*this) * Maths::inverseSqrt(length());
}

/**
 * Gets if the vector is normalised
 * (Has a length of one)
 * @return True if the vector is normalised
 */
template<typename VecType>
bool Vector<4, VecType>::isNormalised(VecType Tolerance) const {
	return fabs(lengthSquared() - 1.f) < Tolerance;
}