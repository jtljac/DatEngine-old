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
Vector<2, VecType>::Vector() : x(0), y(0) {}

template<typename VecType>
Vector<2, VecType>::Vector(VecType Value) : x(Value), y(Value) {}

template<typename VecType>
Vector<2, VecType>::Vector(VecType X, VecType Y) : x(X), y(Y) {}

template<typename VecType>
Vector<2, VecType>::Vector(VecType Array[2]) {
	std::memcpy(&x, Array, 2 * sizeof(VecType));
}


// Copy Constructors
template<typename VecType>
Vector<2, VecType>::Vector(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y) {}

template<typename VecType>
Vector<2, VecType>::Vector(const Vector<3, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y) {}

template<typename VecType>
Vector<2, VecType>::Vector(const Vector<4, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y) {}

template<typename VecType>
template<typename OtherType>
Vector<2, VecType>::Vector(const Vector<2, OtherType>& OtherVec) : x(static_cast<VecType>(OtherVec.x)), y(static_cast<VecType>(OtherVec.y)) {}

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
void Vector<2, VecType>::set(const type& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
}

// Operators
template<typename VecType>
VecType& Vector<2, VecType>::operator[](const size_t Index) {
#ifdef _DEBUG
	if (Index > 1) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

template<typename VecType>
VecType& Vector<2, VecType>::operator[](const size_t Index) const {
#ifdef _DEBUG
	if (Index > 1) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator+(const type& OtherVec) const {
	return type(x + OtherVec.x, y + OtherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator+(VecType Amount) const {
	return type(x + Amount, y + Amount);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator+=(const type& OtherVec) {
	x += OtherVec.x;
	y += OtherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator+=(VecType Amount) {
	x += Amount;
	y += Amount;

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
Vector<2, VecType> Vector<2, VecType>::operator-(const type& OtherVec) const {
	return type(x - OtherVec.x, y - OtherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator-(VecType Amount) const {
	return type(x - Amount, y - Amount);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator-=(const type& OtherVec) {
	x -= OtherVec.x;
	y -= OtherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator-=(VecType Amount) {
	x -= Amount;
	y -= Amount;

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
Vector<2, VecType> Vector<2, VecType>::operator*(const type& OtherVec) const {
	return type(x * OtherVec.x, y * OtherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator*(VecType Value) const {
	return type(x * Value, y * Value);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator*=(const type& OtherVec) {
	x *= OtherVec.x;
	y *= OtherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator*=(VecType Value) {
	x *= Value;
	y *= Value;

	return *this;
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator/(const type& OtherVec) const {
	return type(x / OtherVec.x, y / OtherVec.y);
}

template<typename VecType>
Vector<2, VecType> Vector<2, VecType>::operator/(VecType Value) const {
	return type(x / Value, y / Value);
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator/=(const type& OtherVec) {
	x /= OtherVec.x;
	y /= OtherVec.y;
	return *this;
}

template<typename VecType>
Vector<2, VecType>& Vector<2, VecType>::operator/=(VecType Value) {
	x /= Value;
	y /= Value;

	return *this;
}

// Compairson
template<typename VecType>
bool Vector<2, VecType>::operator==(const type& OtherVec) const {
	return x == OtherVec.x && y == OtherVec.y;
}

template<typename VecType>
bool Vector<2, VecType>::operator!=(const type& OtherVec) const {
	return x != OtherVec.x || y != OtherVec.y;
}

template<typename VecType>
[[maybe_unused]] bool Vector<2, VecType>::equals(const type& OtherVec, VecType Tolerance) const {
	return fabs(x - OtherVec.x) < Tolerance && fabs(y - OtherVec.y) < Tolerance;
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
[[maybe_unused]] bool Vector<2, VecType>::isNormalised(VecType Tolerance) const {
	return fabs(lengthSquared() - 1.f) < Tolerance;
}