/** A vector pointing up (0,1,0) */
template<typename VecType>
const Vector<3, VecType> Vector<3, VecType>::up = Vector<3, VecType>(0, 1, 0);

/** A vector pointing down (0,-1,0) */
template<typename VecType>
const Vector<3, VecType> Vector<3, VecType>::down = Vector<3, VecType>(0, -1, 0);

/** A vector pointing north (0,0,1) */
template<typename VecType>
const Vector<3, VecType> Vector<3, VecType>::north = Vector<3, VecType>(0, 0, 1);

/** A vector pointing south (0,0,-1) */
template<typename VecType>
const Vector<3, VecType> Vector<3, VecType>::south = Vector<3, VecType>(0, 0, -1);

/** A vector pointing east (1,0,0) */
template<typename VecType>
const Vector<3, VecType> Vector<3, VecType>::east = Vector<3, VecType>(1, 0, 0);

/** A vector pointing west (-1,0,0) */
template<typename VecType>
const Vector<3, VecType> Vector<3, VecType>::west = Vector<3, VecType>(-1, 0, 0);

/**
 * Initialises at 0,0,0
 */
template<typename VecType>
Vector<3, VecType>::Vector() : x(0), y(0), z(0) {}

/**
 * Initialises with xyz each set to the given value
 * @param Value The value to set xyz to
 */
template<typename VecType>
Vector<3, VecType>::Vector(VecType Value) : x(Value), y(Value), z(Value) {}

/**
 * Initialises with xyz set to their respective given value
 * @param X The X component of the vector
 * @param Y The Y component of the vector
 * @param Z The Z component of the vector
 */
template<typename VecType>
Vector<3, VecType>::Vector(VecType X, VecType Y, VecType Z) : x(X), y(Y), z(Z) {}

/**
 * Initialises with an array
 * @param Array The Array containing the components of the vector
 */
template<typename VecType>
Vector<3, VecType>::Vector(VecType Array[3]) {
	std::memcpy(&x, Array, 3 * sizeof(VecType));
}


// Copy Constructors
/**
 * Initialises as a copy of the given vector
 * @param OtherVec The vector to copy
 */
template<typename VecType>
Vector<3, VecType>::Vector(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z) {}

/**
 * Initialises as a copy of the given 2D vector and with the given Z vector
 * @param OtherVec The 2D Vector to copy from
 * @param Z The Z component of the vector
 */
template<typename VecType>
Vector<3, VecType>::Vector(const Vector<2, VecType>& OtherVec, VecType Z) : x(OtherVec.x), y(OtherVec.y), z(Z);

/**
 * Initialises as a copy of the given 4D Vector, reduced down to a 3d vector
 * @param OtherVec The 4D Vector to copy from
 */
template<typename VecType>
Vector<3, VecType>::Vector(const Vector<4, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z) {}

/**
 * Initialises as a copy of a vector of a different type
 * @param OtherVec The other Vector to cast from
 */
template<typename VecType>
template<typename OtherType>
Vector<3, VecType>::Vector(const Vector<3, OtherType>& OtherVec) : x(static_cast<VecType>(OtherVec.x)), y(static_cast<VecType>(OtherVec.y)), z(static_cast<VecType>(OtherVec.z)) {}

// Setters
/**
 * Sets the values of the vector to the given vector in place
 * @param newX The value to set X to
 * @param newY The value to set Y to
 * @param newZ The value to set Z to
 */
template<typename VecType>
void Vector<3, VecType>::set(VecType newX, VecType newY, VecType newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

/**
 * Sets the values of the vector to the given value in place
 * @param newValue The value to set each of the components of the vector to
 */
template<typename VecType>
void Vector<3, VecType>::set(VecType newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
}

/**
 * Sets the values of the vector to the ones in the given vector, in place
 * @param OtherVector The vector to copy the components from
 */
template<typename VecType>
void Vector<3, VecType>::set(const type& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
}

// Operators
/**
 * Gets a reference to the component at the given index
 * @param Index The index of the component (0 -> X, 1 -> Y, 2 -> Z)
 * @return A reference to the component at the given index
 */
template<typename VecType>
VecType& Vector<3, VecType>::operator[](const size_t Index) {
#ifdef _DEBUG
	if (Index > 2) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

/**
 * Gets a const reference to the component at the given index
 * @param Index The index of the component (0 -> X, 1 -> Y, 2 -> Z)
 * @return A const reference to the component at the given index
 */
template<typename VecType>
VecType& Vector<3, VecType>::operator[](const size_t Index) const{
#ifdef _DEBUG
	if (Index > 2) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

/**
 * Adds together two vectors
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator+(const type& OtherVec) {
	return type(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

/**
 * Adds a value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator+(VecType Amount) const {
	return type(x + Amount, y + Amount, z + Amount);
}

/**
 * Adds a vector to this vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator+=(const type& OtherVec) {
	x += OtherVec.x;
	y += OtherVec.y;
	z += OtherVec.z;
	return *this;
}

/**
 * Adds the value to each component of the vector
 * @param OtherVec The vector you're adding to this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator+=(VecType Amount) {
	x += Amount;
	y += Amount;
	z += Amount;

	return *this;
}

/**
 * Increments each component of the vector and returns the incremented vector
 * @return The incremented vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator++() {
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
Vector<3, VecType> Vector<3, VecType>::operator++(int) {
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
Vector<3, VecType> Vector<3, VecType>::operator-(const type& OtherVec) const {
	return type(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

/**
 * Gets the negation of the vector
 * @return The negated vector
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator-() const {
	return type(-x, -y, -z);
}

/**
 * Minuses the given amount from each component
 * @param Amount the amount to take from each component
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator-(VecType Amount) const {
	return type(x - Amount, y - Amount, z - Amount);
}

/**
 * Minuses a vector from this vector
 * @param OtherVec The vector you're minusing from this one
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator-=(const type& OtherVec) {
	x -= OtherVec.x;
	y -= OtherVec.y;
	z -= OtherVec.z;
	return *this;
}

/**
 * Minuses the given amount from each component
 * @param Amount The amount to take from each vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator-=(VecType Amount) {
	x -= Amount;
	y -= Amount;
	z -= Amount;

	return *this;
}

/**
 * decrements each component of the vector and returns the dencremented vector
 * @return The dencremented vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator--() {
	x -= 1;
	y -= 1;
	z -= 1;
	return *this;
}

/**
 * decrements each component of the vector and returns the vector before being decremented
 * @return The vector before being decremented
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator--(int) {
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
Vector<3, VecType> Vector<3, VecType>::operator*(const type& OtherVec) const {
	return type(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator*(VecType Value) const {
	return type(x * Value, y * Value, z * Value);
}

/**
 * Multiplies each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator*=(const type& OtherVec) {
	x *= OtherVec.x;
	y *= OtherVec.y;
	z *= OtherVec.z;
	return *this;
}

/**
 * Multiplies each component of the vector by the given value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator*=(VecType Value) {
	x *= Value;
	y *= Value;
	z *= Value;

	return *this;
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator/(const type& OtherVec) const {
	return type(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator/(VecType Value) const {
	return type(x / Value, y / Value, z / Value);
}

/**
 * Divides each component by the equivilent component in the other vector
 * @param OtherVec The other vector
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator/=(const type& OtherVec) {
	x /= OtherVec.x;
	y /= OtherVec.y;
	z /= OtherVec.z;
	return *this;
}

/**
 * Divides each component of the vector by the given Value
 * @param Value The value to multiply each component by
 * @return The resulting vector
 */
template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator/=(VecType Value) {
	x /= Value;
	y /= Value;
	z /= Value;

	return *this;
}

// Compairson
/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vector<3, VecType>::operator==(const type& OtherVec) const {
	return x == OtherVec.x && y == OtherVec.y && z == OtherVec.z;
}

/**
 * Compares the components of the 2 vectors, returning true if all the components first vectors components are not equal to the seconds
 * @param OtherVec The vector to compare to
 * @return Whether the vector's components are equal to the other
 */
template<typename VecType>
bool Vector<3, VecType>::operator!=(const type& OtherVec) const {
	return x != OtherVec.x || y != OtherVec.y || z != OtherVec.z;
}

/**
 * Compares the components of this vector to the equivalent components of the given vector, returns true if the components are within ± the given tolerence of the given vector's components
 * @param OtherVec The vector to compare to
 * @param Tolerance How far off the vector can be before
 * @return Whether the components are equal
 */
template<typename VecType>
bool Vector<3, VecType>::equals(const type& OtherVec, VecType Tolerance) const {
	return fabs(x - OtherVec.x) < Tolerance && fabs(y - OtherVec.y) < Tolerance && fabs(z - OtherVec.z) < Tolerance;
}

/**
 * Gets the squared scalar size of the vector
 * The sum of the squares of each component
 * Useful for comparing the size of vectors as the length squared will remain bigger or smaller like the actualy lengths compared, but it skips the expensive square root calculation
 * @return The squared scalar size of the vector
 */
template<typename VecType>
VecType Vector<3, VecType>::lengthSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

/**
 * Gets the scalar size of the vector
 * The square root of the sum of the squares of each component
 * @return The scalar size of the vector
 */
template<typename VecType>
VecType Vector<3, VecType>::length() const {
	return sqrt(lengthSquared());
}

/**
 * Gets the vector pointing in the same direction, but with a length of 1
 * @return A unit vector pointing in the same direction
 */
template<typename VecType>
template<typename ResultType>
Vector<3, ResultType> Vector<3, VecType>::normalise() const {
	return (Vector<3, ResultType>)(*this) / length();
}

/**
 * Gets if the vector is normalised
 * (Has a length of one)
 * @return True if the vector is normalised
 */
template<typename VecType>
bool Vector<3, VecType>::isNormalised(VecType Tolerance) const {
	return fabs(lengthSquared() - 1.f) < Tolerance;
}