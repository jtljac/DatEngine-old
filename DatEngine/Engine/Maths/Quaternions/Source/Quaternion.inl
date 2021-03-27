// Components
template<typename QuatType>
Quaternion<QuatType>::Quaternion(QuatType Scalar, VecType Vec) : s(Scalar), vec(Vec) {}

template<typename QuatType>
Quaternion<QuatType>::Quaternion(QuatType S, QuatType X, QuatType Y, QuatType Z) : s(S), vec(X, Y, Z) {}

// Copy
template<typename QuatType>
Quaternion<QuatType>::Quaternion(const type& OtherQuat) : s(OtherQuat.s), vec(OtherQuat.vec) {}

// Conversion
// Type
template<typename QuatType>
template <typename OtherType>
Quaternion<QuatType>::Quaternion(Quaternion<OtherType> OtherQuat) : s((QuatType) OtherQuat.s), vec((QuatType) OtherQuat.vec) {}

// Rotator
template<typename QuatType>
Quaternion<QuatType>::Quaternion(Rotator<QuatType> OtherRot) : Quarternion(OtherRot.pitch, OtherRot.yaw, OtherRot.roll) {}

// Rotator Components
template<typename QuatType>
Quaternion<QuatType>::Quaternion(QuatType Pitch, QuatType Yaw, QuatType Roll) {
    // Attitude: Pitch
    // Heading: Yaw
    // Bank: Roll
    QuatType c1 = cos(Yaw / 2);
    QuatType s1 = sin(Yaw / 2);
    QuatType c2 = cos(Pitch / 2);
    QuatType s2 = sin(Pitch / 2);
    QuatType c3 = cos(Roll / 2);
    QuatType s3 = sin(Roll / 2);
    QuatType c1c2 = c1 * c2;
    QuatType s1s2 = s1 * s2;

    s = c1c2 * c3 - s1s2 * s3;

    QuatType x = c1c2 * s3 + s1s2 * c3;
    QuatType y = s1 * c2 * c3 + c1 * s2 * s3;
    QuatType z = c1 * s2 * c3 - s1 * c2 * s3;
    vec = VecType(x, y, z);
}

// Tests
/**
 * Returns true if the scaler term is 0.
 */
template<typename QuatType>
bool Quaternion<QuatType>::isPure() const {
    return s < Maths::Tolerances::normalisedTolerance;
}

/**
 * Returns true if the vector term is 0.
 */
template<typename QuatType>
bool Quaternion<QuatType>::isReal() const {
    return vec.lengthSqaured() < Maths::Tolerances::normalisedTolerance;
}

// Maths
// Addition
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator+(const type& OtherQuat) const {
    return type(s + OtherQuat.s, vec + OtherQuat.vec);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator+=(const type& OtherQuat) {
    s += OtherQuat.s;
    vec += OtherQuat.vec;

    return *this;
}

// Subtraction
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator-(const type& OtherQuat) const {
    return type(s - OtherQuat.s, vec - OtherQuat.vec);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator-=(const type& OtherQuat) {
    s -= OtherQuat.s;
    vec -= OtherQuat.vec;

    return *this;
}

// Multiplication
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator*(const type& OtherQuat) const {
    QuatType scalar = s * OtherQuat.s - Maths::dotProduct(vec, OtherQuat.vec);

    VecType theVec = OtherQuat.vec * s + vec * OtherQuat.s + Maths::crossProduct(vec, OtherQuat.vec);

    return type(scalar, theVec);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator*=(const type& OtherQuat) {
    QuatType temp = s;
    s = s * OtherQuat.s - Maths::dotProduct(vec, OtherQuat.vec);

    vec = OtherQuat.vec * temp + vec * OtherQuat.s + Maths::crossProduct(vec, OtherQuat.vec);

    return *this;
}

// Scalar Multiplication
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::operator*(const QuatType& Scalar) const {
    return type(s * Scalar, vec * Scalar);
}
template<typename QuatType>
Quaternion<QuatType>& Quaternion<QuatType>::operator*=(const QuatType& Scalar) {
    s *= Scalar;
    vec *= Scalar;

    return *this;
}

// Norm
template<typename QuatType>
QuatType Quaternion<QuatType>::normSquared() const {
    QuatType scalar = s * s;
    VecType theVec = vec * vec;
    return scalar + theVec.x + theVec.y + theVec.z;
}
template<typename QuatType>
QuatType Quaternion<QuatType>::norm() const {
    return sqrt(normSquared());
}

// Normalise
template<typename QuatType>
void Quaternion<QuatType>::normalise() {
    QuatType iNorm = Maths::inverseSqrt(normSquared());

    s *= iNorm;
    vec *= iNorm;
}

template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::normalised() const {
    QuatType iNorm = Maths::inverseSqrt(normSquared());

    return type(s * iNorm, vec * iNorm);
}

// Unit Normalise
template<typename QuatType>
void Quaternion<QuatType>::unitNormalise() {
    QuatType halfAngle = s * .5;

    vec.normalise();

    s = cos(halfAngle);
    vec *= sin(halfAngle);
}

template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::unitNormalised() const {
    QuatType halfAngle = s * .5;

    QuatType scalar = cos(halfAngle);

    VecType theVec = vec.normalised() * sin(halfAngle);

    return type(scalar, theVec);
}

// Conjugate
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::conjugate() const {
    return type(s, -vec);
}

// Inverse
template<typename QuatType>
Quaternion<QuatType> Quaternion<QuatType>::inverse() const {
    return conjugate() * (1 / normSquared());
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