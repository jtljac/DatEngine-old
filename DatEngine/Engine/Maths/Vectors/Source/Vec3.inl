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

template<typename VecType>
Vector<3, VecType>::Vector() : x(0), y(0), z(0) {}

template<typename VecType>
Vector<3, VecType>::Vector(VecType Value) : x(Value), y(Value), z(Value) {}

template<typename VecType>
Vector<3, VecType>::Vector(VecType X, VecType Y, VecType Z) : x(X), y(Y), z(Z) {}

template<typename VecType>
Vector<3, VecType>::Vector(VecType Array[3]) {
	std::memcpy(&x, Array, 3 * sizeof(VecType));
}

// Copy Constructors
template<typename VecType>
Vector<3, VecType>::Vector(const type& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z) {}

template<typename VecType>
Vector<3, VecType>::Vector(const Vector<2, VecType>& OtherVec, VecType Z) : x(OtherVec.x), y(OtherVec.y), z(Z) {}

template<typename VecType>
Vector<3, VecType>::Vector(const Vector<4, VecType>& OtherVec) : x(OtherVec.x), y(OtherVec.y), z(OtherVec.z) {}

template<typename VecType>
template<typename OtherType>
Vector<3, VecType>::Vector(const Vector<3, OtherType>& OtherVec) : x(static_cast<VecType>(OtherVec.x)), y(static_cast<VecType>(OtherVec.y)), z(static_cast<VecType>(OtherVec.z)) {}

// Setters
template<typename VecType>
void Vector<3, VecType>::set(VecType newX, VecType newY, VecType newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

template<typename VecType>
void Vector<3, VecType>::set(VecType newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
}

template<typename VecType>
void Vector<3, VecType>::set(const type& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
}

// Operators
template<typename VecType>
VecType& Vector<3, VecType>::operator[](const size_t Index) {
#ifdef _DEBUG
	if (Index > 2) throw std::out_of_range("Index out of range");
#endif
	return *(&x + Index);
}

template<typename VecType>
const VecType& Vector<3, VecType>::operator[](const size_t Index) const {
#ifdef _DEBUG
	if (Index > 2) throw std::out_of_range("Index out of range");
#endif
	const VecType* item = (&x + Index);
	return *item;
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator+(const type& OtherVec) {
	return type(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator+(VecType Amount) const {
	return type(x + Amount, y + Amount, z + Amount);
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator+=(const type& OtherVec) {
	x += OtherVec.x;
	y += OtherVec.y;
	z += OtherVec.z;
	return *this;
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator+=(VecType Amount) {
	x += Amount;
	y += Amount;
	z += Amount;

	return *this;
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator++() {
	x += 1;
	y += 1;
	z += 1;
	return *this;
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator++(int) {
	type temp(*this);
	++(*this);
	return temp;
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator-(const type& OtherVec) const {
	return type(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator-() const {
	return type(-x, -y, -z);
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator-(VecType Amount) const {
	return type(x - Amount, y - Amount, z - Amount);
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator-=(const type& OtherVec) {
	x -= OtherVec.x;
	y -= OtherVec.y;
	z -= OtherVec.z;
	return *this;
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator-=(VecType Amount) {
	x -= Amount;
	y -= Amount;
	z -= Amount;

	return *this;
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator--() {
	x -= 1;
	y -= 1;
	z -= 1;
	return *this;
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator--(int) {
	type temp(*this);
	--(*this);
	return temp;
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator*(const type& OtherVec) const {
	return type(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator*(VecType Value) const {
	return type(x * Value, y * Value, z * Value);
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator*=(const type& OtherVec) {
	x *= OtherVec.x;
	y *= OtherVec.y;
	z *= OtherVec.z;
	return *this;
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator*=(VecType Value) {
	x *= Value;
	y *= Value;
	z *= Value;

	return *this;
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator/(const type& OtherVec) const {
	return type(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::operator/(VecType Value) const {
	return type(x / Value, y / Value, z / Value);
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator/=(const type& OtherVec) {
	x /= OtherVec.x;
	y /= OtherVec.y;
	z /= OtherVec.z;
	return *this;
}

template<typename VecType>
Vector<3, VecType>& Vector<3, VecType>::operator/=(VecType Value) {
	x /= Value;
	y /= Value;
	z /= Value;

	return *this;
}

// Compairson
template<typename VecType>
bool Vector<3, VecType>::operator==(const type& OtherVec) const {
	return x == OtherVec.x && y == OtherVec.y && z == OtherVec.z;
}

template<typename VecType>
bool Vector<3, VecType>::operator!=(const type& OtherVec) const {
	return x != OtherVec.x || y != OtherVec.y || z != OtherVec.z;
}

template<typename VecType>
[[maybe_unused]] bool Vector<3, VecType>::equals(const type& OtherVec, VecType Tolerance) const {
	return fabs(x - OtherVec.x) < Tolerance && fabs(y - OtherVec.y) < Tolerance && fabs(z - OtherVec.z) < Tolerance;
}

template<typename VecType>
VecType Vector<3, VecType>::lengthSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

template<typename VecType>
VecType Vector<3, VecType>::length() const {
	return sqrt(lengthSquared());
}

template<typename VecType>
void Vector<3, VecType>::normalise() {
	(*this) *= Maths::inverseSqrt(lengthSquared());
}

template<typename VecType>
Vector<3, VecType> Vector<3, VecType>::normalised() const {
	return (*this) * Maths::inverseSqrt(lengthSquared());
}

template<typename VecType>
[[maybe_unused]] bool Vector<3, VecType>::isNormalised(VecType Tolerance) const {
	return abs(lengthSquared() - 1.f) < Tolerance;
}