#include <Maths/CommonMaths.h>

/** A vector pointing up (0,1) */
template<typename VecType>
const Vector<2, VecType> Vector<2, VecType>::up = Vector<2, VecType>(0, 1);
/** A vector pointing down (0,-1) */
template<typename VecType>
const Vector<2, VecType> Vector<2, VecType>::down = Vector<2, VecType>(0, -1);
/** A vector pointing right (1,0) */
template<typename VecType>
const Vector<2, VecType> Vector<2, VecType>::right = Vector<2, VecType>(1, 0);
/** A vector pointing left (-1,0) */
template<typename VecType>
const Vector<2, VecType> Vector<2, VecType>::left = Vector<2, VecType>(-1, 0);

/**
 * Initialises at 0,0
 */
template<typename VecType>
Vector<2, VecType>::Vector() : x(0), y(0) {}

/**
 * Initialises with xy each set to the given value
 * @param Value The value to set xyz to
 */
template<typename VecType>
Vector<2, VecType>::Vector(VecType Value) : x(Value), y(Value) {}

/**
 * Initialises with xyz set to their respective given value
 * @param X The X component of the vector
 * @param Y The Y component of the vector
 */
template<typename VecType>
Vector<2, VecType>::Vector(VecType X, VecType Y) : x(X), y(Y) {}

/**
 * Initialises with an array
 * @param Array The Array containing the components of the vector
 */
template<typename VecType>
Vector<2, VecType>::Vector(VecType Array[2]) {
	std::memcpy(&x, Array, 2 * sizeof(VecType));
}


// Copy Constructors
/**
 * Initialises as a copy of the given vector
 * @param OtherVec The vector to copy
 */
template<typename VecType>
Vector<2, VecType>::Vector(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y) {}

/**
 * Initialises as a copy of the given 3D vector, reduced down to a 2d vector
 * @param OtherVec The 3D Vector to copy from
 */
template<typename VecType>
Vector<2, VecType>::Vector(const Vector<3, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y) {}

/**
 * Initialises as a copy of the given 4D Vector, reduced down to a 2d vector
 * @param OtherVec The 4D Vector to copy from
 */
template<typename VecType>
Vector<2, VecType>::Vector(const Vector<4, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y) {}

/**
 * Initialises as a copy of a vector of a different type
 * @param OtherVec The other Vector to cast from
 */
template<typename VecType>
template<typename OtherType>
Vector<2, VecType>::Vector(const Vector<2, OtherType>& OtherVec) : x(static_cast<VecType>(OtherVec.x)), y(static_cast<VecType>(OtherVec.y)) {}

// Setters
/**
 * Sets the values of the vector to the given vector in place
 * @param newX The value to set X to
 * @param newY The value to set Y to
 */
template<typename VecType>
void Vector<2, VecType>::set(VecType newX, VecType newY) {
	x = newX;
	y = newY;
}

/**
 * Sets the values of the vector to the given value in place
 * @param newValue The value to set each of the components of the vector to
 */
template<typename VecType>
void Vector<2, VecType>::set(VecType newValue) {
	x = newValue;
	y = newValue;
}

/**
 * Sets the values of the vector to the ones in the given vector, in place
 * @param OtherVector The vector to copy the components from
 */
template<typename VecType>
void Vector<2, VecType>::set(const type& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
}

// Operators
/**
 * Gets a reference to the component at the given index
 * @param Index The index of the component (0 -> X, 1 -> Y)
 * @return A reference to the component at the given index
 */
template<typename VecType>
VecType& Vector<2, VecType>::operator[](const size_t Index) {
#ifdef _DEBUG
	if (Index > 1) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

/**
 * Gets a const reference to the component at the given index
 * @param Index The index of the component (0 -> X, 1 -> Y)
 * @return A const reference to the component at the given index
 */
template<typename VecType>
VecType& Vector<2, VecType>::operator[](const size_t Index) const {
#ifdef _DEBUG
	if (Index > 1) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

/**
 * Adds together two vectors
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator+(const type& OtherVec) const {
	return type(x + OtherVec.x, y + OtherVec.y);
}

/**
 * Adds a value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator+(VecType Amount) const {
	return type(x + Amount, y + Amount);
}

/**
 * Adds a vector to this vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator+=(const type& OtherVec) {
	x += OtherVec.x;
	y += OtherVec.y;
	return *this;
}

/**
 * Adds the value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator+=(VecType Amount) {
	x += Amount;
	y += Amount;

	return *this;
}

/**
 * Increments each component of the vector and returns the incremented vector
 * @return The incremented vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator++() {
	x += 1;
	y += 1;
	return *this;
}

/**
 * Increments each component of the vector and returns the vector before incrementing
 * @return The vector before being incremented
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator++(int) {
	type temp(*this);
	++(*this);
	return temp;
}

/**
 * Gets the negation of the vector
 * @return The negated vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator-() const {
	return type(-x, -y);
}

/**
 * Minuses one vector from another
 * @param OtherVec The vector you're minusing from this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator-(const type& OtherVec) const {
	return type(x - OtherVec.x, y - OtherVec.y);
}

/**
 * Minuses the given amount from each component
 * @param Amount the amount to take from each component
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator-(VecType Amount) const {
	return type(x - Amount, y - Amount);
}

/**
 * Minuses a vector from this vector
 * @param OtherVec The vector you're minusing from this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator-=(const type& OtherVec) {
	x -= OtherVec.x;
	y -= OtherVec.y;
	return *this;
}

/**
 * Minuses the given amount from each component
 * @param Amount The amount to take from each vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator-=(VecType Amount) {
	x -= Amount;
	y -= Amount;

	return *this;
}

/**
 * decrements each component of the vector and returns the dencremented vector
 * @return The dencremented vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator--() {
	x -= 1;
	y -= 1;
	return *this;
}

/**
 * decrements each component of the vector and returns the vector before being decremented
 * @return The vector before being decremented
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator--(int) {
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
Vector<2, VecType> Vector<2, VecType>::operator*(const type& OtherVec) const {
	return type(x * OtherVec.x, y * OtherVec.y);
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator*(VecType Value) const {
	return type(x * Value, y * Value);
}

/**
 * Multiplies each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator*=(const type& OtherVec) {
	x *= OtherVec.x;
	y *= OtherVec.y;
	return *this;
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator*=(VecType Value) {
	x *= Value;
	y *= Value;

	return *this;
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator/(const type& OtherVec) const {
	return type(x / OtherVec.x, y / OtherVec.y);
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator/(VecType Value) const {
	return type(x / Value, y / Value);
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator/=(const type& OtherVec) {
	x /= OtherVec.x;
	y /= OtherVec.y;
	return *this;
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator/=(VecType Value) {
	x /= Value;
	y /= Value;

	return *this;
}

// Compairson
/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vector<2, VecType>::operator==(const type& OtherVec) const {
	return x == OtherVec.x && y == OtherVec.y;
}

/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vector<2, VecType>::operator!=(const type& OtherVec) const {
	return x != OtherVec.x || y != OtherVec.y;
}

/**
 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within � the given tolerence of the given vector's components
 * @param OtherVec The vector to compare to
 * @param Tolerence How far off the vector can be before
 * @return Whether the components are equal
 */
template<typename VecType>
[[maybe_unused]] bool Vector<2, VecType>::equals(const type& OtherVec, VecType Tolerance) const {
	return fabs(x - OtherVec.x) < Tolerance && fabs(y - OtherVec.y) < Tolerance;
}

/**
 * Gets the squared scalar size of the vector
 * The sum of the squares of each component
 * Useful for comparing the size of vectors as the length squared will remain bigger or smaller like the actualy lengths compared, but it skips the expensive square root calculation
 * @return The squared scalar size of the vector
 */
template<typename VecType>
VecType Vector<2, VecType>::lengthSquared() const {
	return pow(x, 2) + pow(y, 2);
}

/**
 * Gets the scalar size of the vector
 * The square root of the sum of the squares of each component
 * @return The scalar size of the vector
 */
template<typename VecType>
VecType Vector<2, VecType>::length() const {
	return sqrt(lengthSquared());
}

/**
 * Normalises the vector in place
 */
template<typename VecType>
void Vector<2, VecType>::normalise() {
	(*this) *= Maths::inverseSqrt(lengthSquared());
}

/**
 * Gets the vector pointing in the same direction, but with a length of 1
 * @return A unit vector pointing in the same direction
 */
template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::normalised() const {
	return (Vector<2, VecType>)(*this) * Maths::inverseSqrt(lengthSquared());
}

/**
 * Gets if the vector is normalised
 * (Has a length of one)
 * @return True if the vector is normalised
 */
template<typename VecType>
[[maybe_unused]] bool Vector<2, VecType>::isNormalised(VecType Tolerance) const {
	return fabs(lengthSquared() - 1.f) < Tolerance;
}