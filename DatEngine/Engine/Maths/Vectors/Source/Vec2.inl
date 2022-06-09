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

template<typename VecType>
Vector<2, VecType>::Vector(VecType value) : x(value), y(value) {}

template<typename VecType>
Vector<2, VecType>::Vector(VecType X, VecType Y) : x(X), y(Y) {}

template<typename VecType>
Vector<2, VecType>::Vector(VecType array[2]) {
	std::memcpy(&x, array, 2 * sizeof(VecType));
}


// Copy Constructors
template<typename VecType>
Vector<2, VecType>::Vector(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y) {}

template<typename VecType>
Vector<2, VecType>::Vector(const Vector<3, VecType>& otherVec) : x(otherVec.x), y(otherVec.y) {}

template<typename VecType>
Vector<2, VecType>::Vector(const Vector<4, VecType>& otherVec) : x(otherVec.x), y(otherVec.y) {}

template<typename VecType>
template<typename OtherType>
Vector<2, VecType>::Vector(const Vector<2, OtherType>& otherVec) : x(static_cast<VecType>(otherVec.x)), y(static_cast<VecType>(otherVec.y)) {}

// Setters
template<typename VecType>
void Vector<2, VecType>::set(VecType newX, VecType newY) {
	x = newX;
	y = newY;
}

template<typename VecType>
void Vector<2, VecType>::set(VecType newValue) {
	x = newValue;
	y = newValue;
}

template<typename VecType>
void Vector<2, VecType>::set(const type& otherVector) {
	x = otherVector.x;
	y = otherVector.y;
}

// Operators
template<typename VecType>
VecType& Vector<2, VecType>::operator[](const size_t index) {
#ifdef _DEBUG
	if (index > 1) throw std::out_of_range("index out of range");
#endif
	return *(&x + index);
}

template<typename VecType>
VecType& Vector<2, VecType>::operator[](const size_t index) const {
#ifdef _DEBUG
	if (index > 1) throw std::out_of_range("index out of range");
#endif
	return *(&x + index);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator+(const type& otherVec) const {
	return type(x + otherVec.x, y + otherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator+(VecType amount) const {
	return type(x + amount, y + amount);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator+=(const type& otherVec) {
	x += otherVec.x;
	y += otherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator+=(VecType amount) {
	x += amount;
	y += amount;

	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator++() {
	x += 1;
	y += 1;
	return *this;
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator++(int) {
	type temp(*this);
	++(*this);
	return temp;
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator-() const {
	return type(-x, -y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator-(const type& otherVec) const {
	return type(x - otherVec.x, y - otherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator-(VecType amount) const {
	return type(x - amount, y - amount);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator-=(const type& otherVec) {
	x -= otherVec.x;
	y -= otherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator-=(VecType amount) {
	x -= amount;
	y -= amount;

	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator--() {
	x -= 1;
	y -= 1;
	return *this;
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator--(int) {
	type temp(*this);
	--(*this);
	return temp;
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator*(const type& otherVec) const {
	return type(x * otherVec.x, y * otherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator*(VecType value) const {
	return type(x * value, y * value);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator*=(const type& otherVec) {
	x *= otherVec.x;
	y *= otherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator*=(VecType value) {
	x *= value;
	y *= value;

	return *this;
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator/(const type& otherVec) const {
	return type(x / otherVec.x, y / otherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator/(VecType value) const {
	return type(x / value, y / value);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator/=(const type& otherVec) {
	x /= otherVec.x;
	y /= otherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator/=(VecType value) {
	x /= value;
	y /= value;

	return *this;
}

// Compairson
template<typename VecType>
bool Vector<2, VecType>::operator==(const type& otherVec) const {
	return x == otherVec.x && y == otherVec.y;
}

template<typename VecType>
bool Vector<2, VecType>::operator!=(const type& otherVec) const {
	return x != otherVec.x || y != otherVec.y;
}

template<typename VecType>
[[maybe_unused]] bool Vector<2, VecType>::equals(const type& otherVec, VecType tolerance) const {
	return fabs(x - otherVec.x) < tolerance && fabs(y - otherVec.y) < tolerance;
}

template<typename VecType>
VecType Vector<2, VecType>::lengthSquared() const {
	return pow(x, 2) + pow(y, 2);
}

template<typename VecType>
VecType Vector<2, VecType>::length() const {
	return sqrt(lengthSquared());
}

template<typename VecType>
void Vector<2, VecType>::normalise() {
	(*this) *= Maths::inverseSqrt(lengthSquared());
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::normalised() const {
	return (Vector<2, VecType>)(*this) * Maths::inverseSqrt(lengthSquared());
}

template<typename VecType>
[[maybe_unused]] bool Vector<2, VecType>::isNormalised(VecType tolerance) const {
	return fabs(lengthSquared() - 1.f) < tolerance;
}