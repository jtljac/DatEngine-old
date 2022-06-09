// Components
template<typename QuatType>
Quaternion<QuatType>::Quaternion(QuatType scalar, VecType vector) : s(scalar), vec(vector) {}

template<typename QuatType>
Quaternion<QuatType>::Quaternion(QuatType scaler, QuatType x, QuatType y, QuatType z) : s(scaler), vec(x, y, z) {}

// Copy
template<typename QuatType>
Quaternion<QuatType>::Quaternion(const type& OtherQuat) : s(OtherQuat.s), vec(OtherQuat.vec) {}

// Conversion
// Type
template<typename QuatType>
template <typename OtherType>
Quaternion<QuatType>::Quaternion(Quaternion<OtherType> otherQuat) : s((QuatType) otherQuat.s), vec((QuatType) otherQuat.vec) {}

// Rotator
template<typename QuatType>
Quaternion<QuatType>::Quaternion(Rotator<QuatType> otherRot) : Quaternion(otherRot.pitch, otherRot.yaw, otherRot.roll) {}

// Rotator Components
template<typename QuatType>
Quaternion<QuatType>::Quaternion(QuatType pitch, QuatType yaw, QuatType roll) {
    // Attitude: pitch
    // Heading: yaw
    // Bank: roll
    QuatType c1 = cos(yaw / 2);
    QuatType s1 = sin(yaw / 2);
    QuatType c2 = cos(roll / 2);
    QuatType s2 = sin(roll / 2);
    QuatType c3 = cos(pitch / 2);
    QuatType s3 = sin(pitch / 2);
    QuatType c1c2 = c1 * c2;
    QuatType s1s2 = s1 * s2;

    QuatType x = c1c2 * s3 + s1s2 * c3;
    QuatType y = s1 * c2 * c3 + c1 * s2 * s3;
    QuatType z = c1 * s2 * c3 - s1 * c2 * s3;

    this->s = c1c2 * c3 - s1s2 * s3;
    this->vec = VecType(x, y, z);
}

// Axis Angle
template<typename QuatType>
Quaternion<QuatType>::Quaternion(VecType axis, QuatType angle) {
    const QuatType halfAngle = angle * .5;

    this->s = cos(halfAngle);
    this->vec = axis * sin(halfAngle);
}

// Tests
template<typename QuatType>
bool Quaternion<QuatType>::isPure() const {
    return s < Maths::Tolerances::normalisedTolerance;
}

template<typename QuatType>
bool Quaternion<QuatType>::isReal() const {
    return vec.lengthSqaured() < Maths::Tolerances::normalisedTolerance;
}

// Maths
// Addition
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator+(const type& otherQuat) const {
    return type(s + otherQuat.s, vec + otherQuat.vec);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator+=(const type& otherQuat) {
    s += otherQuat.s;
    vec += otherQuat.vec;

    return *this;
}

// Subtraction
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator-(const type& otherQuat) const {
    return type(s - otherQuat.s, vec - otherQuat.vec);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator-=(const type& otherQuat) {
    s -= otherQuat.s;
    vec -= otherQuat.vec;

    return *this;
}

// Multiplication
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator*(const type& otherQuat) const {
    QuatType scalar = s * otherQuat.s - Maths::dotProduct(vec, otherQuat.vec);

    VecType theVec = otherQuat.vec * s + vec * otherQuat.s + Maths::crossProduct(vec, otherQuat.vec);

    return type(scalar, theVec);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator*=(const type& otherQuat) {
    QuatType temp = s;
    s = s * otherQuat.s - Maths::dotProduct(vec, otherQuat.vec);

    vec = otherQuat.vec * temp + vec * otherQuat.s + Maths::crossProduct(vec, otherQuat.vec);

    return *this;
}

// scalar Multiplication
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator*(const QuatType& scalar) const {
    return type(s * scalar, vec * scalar);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator*=(const QuatType& scalar) {
    s *= scalar;
    vec *= scalar;

    return *this;
}

// Vec Multiplication
template<typename QuatType>
Vector<3, QuatType> Quaternion<QuatType>::operator*(const VecType& otherVec) const {
    return Maths::rotateVector(otherVec, *this);
}

// Magnitude
template<typename QuatType>
QuatType Quaternion<QuatType>::magnitudeSquared() const {
    QuatType scalar = s * s;
    VecType theVec = vec * vec;
    return scalar + theVec.x + theVec.y + theVec.z;
}
template<typename QuatType>
QuatType Quaternion<QuatType>::magnitude() const {
    return sqrt(magnitudeSquared());
}

// Normalise
template<typename QuatType>
void Quaternion<QuatType>::normalise() {
    QuatType iNorm = Maths::inverseSqrt(magnitudeSquared());

    s *= iNorm;
    vec *= iNorm;
}

template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::normalised() const {
    QuatType iNorm = Maths::inverseSqrt(magnitudeSquared());

    return type(s * iNorm, vec * iNorm);
}

// Conjugate
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::conjugate() const {
    return type(s, -vec);
}

// Inverse
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::inverse() const {
    return conjugate() * (1 / magnitudeSquared());
}

// Vectors
template<typename QuatType>
Vector<3, QuatType> Quaternion<QuatType>::forwardVector() const {
    return Maths::rotateVector(VecType::north, (*this))
}

template<typename QuatType>
Vector<3, QuatType> Quaternion<QuatType>::rightVector() const {
    return Maths::rotateVector(VecType::east, (*this))
}

template<typename QuatType>
Vector<3, QuatType> Quaternion<QuatType>::upVector() const {
    return Maths::rotateVector(VecType::up, (*this))
}