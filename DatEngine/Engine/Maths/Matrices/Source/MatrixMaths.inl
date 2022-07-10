// Translate
template<typename MatType>
[[maybe_unused]] Matrix<4, 4, MatType>
Maths::translate(const Matrix<4, 4, MatType>& baseMatrix, const Vector<3, MatType>& translationVector) {
    Matrix<4, 4, MatType> temp(baseMatrix);

    temp[3][0] = baseMatrix[0][0] * translationVector.x + baseMatrix[1][0] * translationVector.y +
                 baseMatrix[2][0] * translationVector.z + baseMatrix[3][0];
    temp[3][1] = baseMatrix[0][1] * translationVector.x + baseMatrix[1][1] * translationVector.y +
                 baseMatrix[2][1] * translationVector.z + baseMatrix[3][1];
    temp[3][2] = baseMatrix[0][2] * translationVector.x + baseMatrix[1][2] * translationVector.y +
                 baseMatrix[2][2] * translationVector.z + baseMatrix[3][2];
    temp[3][3] = baseMatrix[0][3] * translationVector.x + baseMatrix[1][3] * translationVector.y +
                 baseMatrix[2][3] * translationVector.z + baseMatrix[3][3];

    return temp;
}

// Rotate
// Pitch
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotatePitch(const Matrix<4, 4, MatType>& baseMatrix, const MatType angle) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType cp = cos(angle);
    MatType sp = sin(angle);

    temp[0][0] = 1.f;
    temp[1][0] = 0.f;
    temp[2][0] = 0.f;
    temp[3][0] = 0.f;

    temp[0][1] = 0.f;
    temp[1][1] = cp;
    temp[2][1] = -sp;
    temp[3][1] = 0.f;

    temp[0][2] = 0.f;
    temp[1][2] = sp;
    temp[2][2] = cp;
    temp[3][2] = 0.f;

    temp[0][3] = 0.f;
    temp[1][3] = 0.f;
    temp[2][3] = 0.f;
    temp[3][3] = 1.f;

    return baseMatrix * temp;
}

// Yaw
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotateYaw(const Matrix<4, 4, MatType>& baseMatrix, const MatType angle) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType cy = cos(angle);
    MatType sy = sin(angle);

    temp[0][0] = cy;
    temp[1][0] = 0.f;
    temp[2][0] = sy;
    temp[3][0] = 0.f;

    temp[0][1] = 0.f;
    temp[1][1] = 1.f;
    temp[2][1] = 0.f;
    temp[3][1] = 0.f;

    temp[0][2] = -sy;
    temp[1][2] = 0.f;
    temp[2][2] = cy;
    temp[3][2] = 0.f;

    temp[0][3] = 0.f;
    temp[1][3] = 0.f;
    temp[2][3] = 0.f;
    temp[3][3] = 1.f;

    return baseMatrix * temp;
}

// Roll
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotateRoll(const Matrix<4, 4, MatType>& baseMatrix, const MatType angle) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType cr = cos(angle);
    MatType sr = sin(angle);

    temp[0][0] = cr;
    temp[1][0] = -sr;
    temp[2][0] = 0.f;
    temp[3][0] = 0.f;

    temp[0][1] = sr;
    temp[1][1] = cr;
    temp[2][1] = 0.f;
    temp[3][1] = 0.f;

    temp[0][2] = 0.f;
    temp[1][2] = 0.f;
    temp[2][2] = 0.f;
    temp[3][2] = 0.f;

    temp[0][3] = 0.f;
    temp[1][3] = 0.f;
    temp[2][3] = 0.f;
    temp[3][3] = 1.f;

    return baseMatrix * temp;
}

// Rotator
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotate(const Matrix<4, 4, MatType>& baseMatrix, const Rotator<MatType>& rotation) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType cp = cos(rotation.pitch);
    MatType sp = sin(rotation.pitch);
    MatType cy = cos(rotation.yaw);
    MatType sy = sin(rotation.yaw);
    MatType cr = cos(rotation.roll);
    MatType sr = sin(rotation.roll);

    temp[0][0] = cy * cr + sy * sp * sr;
    temp[1][0] = cy * (-sr) + sy * sp * cr;
    temp[2][0] = sy * cp;
    temp[3][0] = 0.f;

    temp[0][1] = cp * sr;
    temp[1][1] = cp * cr;
    temp[2][1] = -sp;
    temp[3][1] = 0.f;

    temp[0][2] = (-sy) * cr + cy * sp * sr;
    temp[1][2] = sy * sr + cy * sp * cr;
    temp[2][2] = cy * cp;
    temp[3][2] = 0.f;

    temp[0][3] = 0.f;
    temp[1][3] = 0.f;
    temp[2][3] = 0.f;
    temp[3][3] = 1.f;

    return baseMatrix * temp;
}

template<typename MatType>
inline Matrix<4, 4, MatType>
Maths::rotate(const Matrix<4, 4, MatType>& baseMatrix, const MatType angle, const FVector& axis) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();
    MatType c = cos(angle);
    MatType s = sin(angle);

    Vector<3, MatType> t = (1 - c) * axis;

    temp[0][0] = t.x * axis.x + c;
    temp[0][1] = t.x * axis.y - axis.z * s;
    temp[0][2] = t.x * axis.z + axis.y * s;
    temp[0][3] = 0.f;

    temp[1][0] = t.x * axis.y + axis.z * s;
    temp[1][1] = t.y * axis.y + c;
    temp[1][2] = t.y * axis.z + axis.x * s;
    temp[1][3] = 0.f;

    temp[2][0] = t.x * axis.z - axis.y * s;
    temp[2][1] = t.y * axis.z - axis.x * s;
    temp[2][2] = t.z * axis.z + c;
    temp[2][3] = 0.f;

    temp[3][0] = 0.f;
    temp[3][1] = 0.f;
    temp[3][2] = 0.f;
    temp[3][3] = 1.f;

    return baseMatrix * temp;
}

// quat
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotate(const Matrix<4, 4, MatType>& baseMatrix, const Quaternion<MatType>& quat) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType xx2 = 2 * quat.vec.x * quat.vec.x;
    MatType xy2 = 2 * quat.vec.x * quat.vec.y;

    MatType yy2 = 2 * quat.vec.y * quat.vec.y;

    MatType xz2 = 2 * quat.vec.x * quat.vec.z;
    MatType yz2 = 2 * quat.vec.y * quat.vec.z;
    MatType zz2 = 2 * quat.vec.z * quat.vec.z;

    MatType xw2 = 2 * quat.vec.x * quat.s;
    MatType yw2 = 2 * quat.vec.y * quat.s;
    MatType zw2 = 2 * quat.vec.z * quat.s;

    temp[0][0] = 1 - yy2 - zz2;
    temp[0][1] = xy2 - zw2;
    temp[0][2] = xz2 + yw2;
    temp[0][3] = 0.f;

    temp[1][0] = xy2 + zw2;
    temp[1][1] = 1 - xx2 - zz2;
    temp[1][2] = yz2 - xw2;
    temp[1][3] = 0.f;

    temp[2][0] = xz2 - yw2;
    temp[2][1] = yz2 + xw2;
    temp[2][2] = 1 - xx2 - yy2;
    temp[2][3] = 0.f;

    temp[3][0] = 0.f;
    temp[3][1] = 0.f;
    temp[3][2] = 0.f;
    temp[3][3] = 1.f;

    return baseMatrix * temp;
}

// Scale
template<typename MatType>
Matrix<4, 4, MatType> Maths::scale(const Matrix<4, 4, MatType>& baseMatrix, const MatType amount) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = baseMatrix[0][0] * amount;
    temp[1][0] = baseMatrix[1][0] * amount;
    temp[2][0] = baseMatrix[2][0] * amount;
    temp[3][0] = baseMatrix[3][0] * amount;

    temp[0][1] = baseMatrix[0][1] * amount;
    temp[1][1] = baseMatrix[1][1] * amount;
    temp[2][1] = baseMatrix[2][1] * amount;
    temp[3][1] = baseMatrix[3][1] * amount;

    temp[0][2] = baseMatrix[0][2] * amount;
    temp[1][2] = baseMatrix[1][2] * amount;
    temp[2][2] = baseMatrix[2][2] * amount;
    temp[3][2] = baseMatrix[3][2] * amount;

    temp[0][3] = baseMatrix[0][3];
    temp[1][3] = baseMatrix[1][3];
    temp[2][3] = baseMatrix[2][3];
    temp[3][3] = baseMatrix[3][3];

    return temp;
}

template<typename MatType>
Matrix<4, 4, MatType>
Maths::scale(const Matrix<4, 4, MatType>& baseMatrix, const MatType x, const MatType y, const MatType z) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = baseMatrix[0][0] * x;
    temp[1][0] = baseMatrix[1][0] * x;
    temp[2][0] = baseMatrix[2][0] * x;
    temp[3][0] = baseMatrix[3][0] * x;

    temp[0][1] = baseMatrix[0][1] * y;
    temp[1][1] = baseMatrix[1][1] * y;
    temp[2][1] = baseMatrix[2][1] * y;
    temp[3][1] = baseMatrix[3][1] * y;

    temp[0][2] = baseMatrix[0][2] * z;
    temp[1][2] = baseMatrix[1][2] * z;
    temp[2][2] = baseMatrix[2][2] * z;
    temp[3][2] = baseMatrix[3][2] * z;

    temp[0][3] = baseMatrix[0][3];
    temp[1][3] = baseMatrix[1][3];
    temp[2][3] = baseMatrix[2][3];
    temp[3][3] = baseMatrix[3][3];

    return temp;
}

template<typename MatType>
Matrix<4, 4, MatType> Maths::scale(const Matrix<4, 4, MatType>& baseMatrix, const Vector<3, MatType>& vector) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = baseMatrix[0][0] * vector.x;
    temp[1][0] = baseMatrix[1][0] * vector.x;
    temp[2][0] = baseMatrix[2][0] * vector.x;
    temp[3][0] = baseMatrix[3][0] * vector.x;

    temp[0][1] = baseMatrix[0][1] * vector.y;
    temp[1][1] = baseMatrix[1][1] * vector.y;
    temp[2][1] = baseMatrix[2][1] * vector.y;
    temp[3][1] = baseMatrix[3][1] * vector.y;

    temp[0][2] = baseMatrix[0][2] * vector.y;
    temp[1][2] = baseMatrix[1][2] * vector.y;
    temp[2][2] = baseMatrix[2][2] * vector.y;
    temp[3][2] = baseMatrix[3][2] * vector.y;

    temp[0][3] = baseMatrix[0][3];
    temp[1][3] = baseMatrix[1][3];
    temp[2][3] = baseMatrix[2][3];
    temp[3][3] = baseMatrix[3][3];

    return temp;
}

template<typename MatType>
Matrix<4, 4, MatType>
Maths::perspectiveProjection(const MatType fov, const MatType aspectRatio, const MatType nearPlane, const MatType farPlane) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType f = tan(fov / 2.f);

    temp[0][0] = 1.f / (f * aspectRatio);
    temp[1][0] = 0;
    temp[2][0] = 0;
    temp[3][0] = 0;

    temp[0][1] = 0;
    temp[1][1] = -1.f / f;
    temp[2][1] = 0;
    temp[3][1] = 0;

    temp[0][2] = 0;
    temp[1][2] = 0;
    temp[2][2] = farPlane / (nearPlane - farPlane);
    temp[3][2] = -(farPlane * nearPlane) / (farPlane - nearPlane);

    temp[0][3] = 0;
    temp[1][3] = 0;
    temp[2][3] = -1;
    temp[3][3] = 0;

    return temp;
}

// Look at
template <typename MatType>
Matrix<4, 4, MatType> Maths::lookAt(const Vector<3, MatType>& cameraPosition, const Vector<3, MatType>& targetPosition, const Vector<3, MatType>& upVector) {
    Vector<3, MatType> forwardVector = (targetPosition - cameraPosition).normalised();
    Vector<3, MatType> rightVector = Maths::crossProduct(upVector, forwardVector);

    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = rightVector.x;
    temp[1][0] = upVector.x;
    temp[2][0] = forwardVector.x;
    temp[3][0] = cameraPosition.x;

    temp[0][1] = rightVector.y;
    temp[1][1] = upVector.y;
    temp[2][1] = forwardVector.y;
    temp[3][1] = cameraPosition.y;

    temp[0][2] = rightVector.z;
    temp[1][2] = upVector.z;
    temp[2][2] = forwardVector.z;
    temp[3][2] = cameraPosition.z;

    temp[0][3] = 0;
    temp[1][3] = 0;
    temp[2][3] = 0;
    temp[3][3] = 1;

    return temp;
}

// View Matrix
// Rotator
template <typename MatType>
Matrix<4, 4, MatType> Maths::viewMatrix(const Vector<3, MatType>& cameraPosition, const Rotator<MatType>& cameraRotation) {

}

// Quaternion
template <typename MatType>
Matrix<4, 4, MatType> Maths::viewMatrix(const Vector<3, MatType>& cameraPosition, const Quaternion<MatType>& cameraRotation) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    Vector<3, MatType> forwardVector = cameraRotation.forwardVector();
    Vector<3, MatType> rightVector = cameraRotation.rightVector();
    Vector<3, MatType> upVector = cameraRotation.upVector();

    temp[0][0] = rightVector.x;
    temp[1][0] = upVector.x;
    temp[2][0] = forwardVector.x;
    temp[3][0] = cameraPosition.x;

    temp[0][1] = rightVector.y;
    temp[1][1] = upVector.y;
    temp[2][1] = forwardVector.y;
    temp[3][1] = cameraPosition.y;

    temp[0][2] = rightVector.z;
    temp[1][2] = upVector.z;
    temp[2][2] = forwardVector.z;
    temp[3][2] = cameraPosition.z;

    temp[0][3] = 0;
    temp[1][3] = 0;
    temp[2][3] = 0;
    temp[3][3] = 1;

    return temp;
}