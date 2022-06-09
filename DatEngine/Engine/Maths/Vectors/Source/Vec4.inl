template<typename VecType>
Vector<4, VecType>::Vector(VecType Value) : x(Value), y(Value), z(Value), w(Value) {}

template<typename VecType>
Vector<4, VecType>::Vector(VecType X, VecType Y, VecType Z, VecType W) : x(X), y(Y), z(Z), w(W) {}

template<typename VecType>
Vector<4, VecType>::Vector(VecType Array[4]) {
	std::memcpy(&x, Array, 4 * sizeof(VecType));
}


// Copy Constructors
template<typename VecType>
Vector<4, VecType>::Vector(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z), w(OtherVec.w) {}

template<typename VecType>
Vector<4, VecType>::Vector(const Vector<2, VecType>& otherVec, VecType Z, VecType W) : x(otherVec.x), y(otherVec.y), z(Z), w(W) {}

template<typename VecType>
Vector<4, VecType>::Vector(const Vector<3, VecType>& otherVec, VecType W) : x(otherVec.x), y(otherVec.y), z(otherVec.z), w(W) {}

template<typename VecType>
template<typename OtherType>
Vector<4, VecType>::Vector(const Vector<4, OtherType>& OtherVec) : x(static_cast<VecType>(OtherVec.x)), y(static_cast<VecType>(OtherVec.y)), z(static_cast<VecType>(OtherVec.z)), w(static_cast<VecType>(OtherVec.w)) {}

// Setters
template<typename VecType>
void Vector<4, VecType>::set(VecType newX, VecType newY, VecType newZ, VecType newW) {
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

template<typename VecType>
void Vector<4, VecType>::set(VecType newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
	w = newValue;
}

template<typename VecType>
void Vector<4, VecType>::set(const type& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
	w = OtherVector.w;
}

// Operators
template<typename VecType>
VecType& Vector<4, VecType>::operator[](const size_t Index) {
#ifdef _DEBUG
	if (Index > 3) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

template<typename VecType>
VecType const& Vector<4, VecType>::operator[](const size_t Index) const {
#ifdef _DEBUG
	if (Index > 3) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator+(const type& OtherVec) const {
	return type(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator+(VecType Amount) const {
	return type(x + Amount, y + Amount, z + Amount, w + Amount);
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator+=(const type& OtherVec) {
	x += OtherVec.x;
	y += OtherVec.y;
	z += OtherVec.z;
	w += OtherVec.w;
	return *this;
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator+=(VecType Amount) {
	x += Amount;
	y += Amount;
	z += Amount;
	w += Amount;

	return *this;
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator++() {
	x += 1;
	y += 1;
	z += 1;
	w += 1;

	return *this;
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator++(int) {
	type temp(*this);
	++(*this);
	return temp;
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator-() const {
	return type(-x, -y, -z, -w);
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator-(const type& OtherVec) const {
	return type(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator-(VecType Amount) const {
	return type(x - Amount, y - Amount, z - Amount, w - Amount);
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator-=(const type& OtherVec) {
	x -= OtherVec.x;
	y -= OtherVec.y;
	z -= OtherVec.z;
	w -= OtherVec.w;
	return *this;
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator-=(VecType Amount) {
	x -= Amount;
	y -= Amount;
	z -= Amount;
	w -= Amount;

	return *this;
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator--() {
	x -= 1;
	y -= 1;
	z -= 1;
	w -= 1;
	return *this;
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator--(int) {
	type temp(*this);
	--(*this);
	return temp;
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator*(const type& OtherVec) const {
	return type(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z, w * OtherVec.w);
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator*(VecType Value) const {
	return type(x * Value, y * Value, z * Value, w * Value);
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator*=(const type& OtherVec) {
	x *= OtherVec.x;
	y *= OtherVec.y;
	z *= OtherVec.z;
	w *= OtherVec.w;
	return *this;
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator*=(VecType Value) {
	x *= Value;
	y *= Value;
	z *= Value;
	w *= Value;

	return *this;
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator/(const type& OtherVec) const {
	return type(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::operator/(VecType Value) const {
	return type(x / Value, y / Value, z / Value, w / Value);
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator/=(const type& OtherVec) {
	x /= OtherVec.x;
	y /= OtherVec.y;
	z /= OtherVec.z;
	w /= OtherVec.w;
	return *this;
}

template<typename VecType>
Vector<4, VecType>& Vector<4, VecType>::operator/=(VecType Value) {
	x /= Value;
	y /= Value;
	z /= Value;
	w /= Value;

	return *this;
}

// Compairson
template<typename VecType>
bool Vector<4, VecType>::operator==(const type& OtherVec) const {
	return x == OtherVec.x && y == OtherVec.y && z == OtherVec.z && w == OtherVec.w;
}

template<typename VecType>
bool Vector<4, VecType>::operator!=(const type& OtherVec) const {
	return x != OtherVec.x || y != OtherVec.y || z != OtherVec.z || w != OtherVec.w;
}

template<typename VecType>
[[maybe_unused]] bool Vector<4, VecType>::equals(const type& OtherVec, VecType Tolerance) const {
	return fabs(x - OtherVec.x) < Tolerance && fabs(y - OtherVec.y) < Tolerance && fabs(z - OtherVec.z) < Tolerance && fabs(w - OtherVec.w) < Tolerance;
}

template<typename VecType>
VecType Vector<4, VecType>::lengthSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
}

template<typename VecType>
VecType Vector<4, VecType>::length() const {
	return sqrt(lengthSquared());
}

template<typename VecType>
void Vector<4, VecType>::normalise() {
	(*this) *= Maths::inverseSqrt(length());
}

template<typename VecType>
Vector<4, VecType> Vector<4, VecType>::normalised() const {
	return (Vector<4, VecType>)(*this) * Maths::inverseSqrt(length());
}

template<typename VecType>
[[maybe_unused]] bool Vector<4, VecType>::isNormalised(VecType Tolerance) const {
	return fabs(lengthSquared() - 1.f) < Tolerance;
}
