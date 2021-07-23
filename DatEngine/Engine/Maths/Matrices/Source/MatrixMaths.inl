// Translate
template<typename MatType>
Matrix<4, 4, MatType>
Maths::translate(const Matrix<4, 4, MatType>& BaseMatrix, const Vector<3, MatType>& TranslationVector) {
    Matrix<4, 4, MatType> temp(BaseMatrix);

    temp[3][0] = BaseMatrix[0][0] * TranslationVector.x + BaseMatrix[1][0] * TranslationVector.y +
                 BaseMatrix[2][0] * TranslationVector.z + BaseMatrix[3][0];
    temp[3][1] = BaseMatrix[0][1] * TranslationVector.x + BaseMatrix[1][1] * TranslationVector.y +
                 BaseMatrix[2][1] * TranslationVector.z + BaseMatrix[3][1];
    temp[3][2] = BaseMatrix[0][2] * TranslationVector.x + BaseMatrix[1][2] * TranslationVector.y +
                 BaseMatrix[2][2] * TranslationVector.z + BaseMatrix[3][2];
    temp[3][3] = BaseMatrix[0][3] * TranslationVector.x + BaseMatrix[1][3] * TranslationVector.y +
                 BaseMatrix[2][3] * TranslationVector.z + BaseMatrix[3][3];

    return temp;
}

// Rotate
// Pitch
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotatePitch(const Matrix<4, 4, MatType>& BaseMatrix, const MatType angle) {
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

    return BaseMatrix * temp;
}

// Yaw
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotateYaw(const Matrix<4, 4, MatType>& BaseMatrix, const MatType angle) {
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

    return BaseMatrix * temp;
}

// Roll
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotateRoll(const Matrix<4, 4, MatType>& BaseMatrix, const MatType angle) {
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

    return BaseMatrix * temp;
}

// Rotator
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotate(const Matrix<4, 4, MatType>& BaseMatrix, const Rotator<MatType>& Rotation) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType cp = cos(Rotation.pitch);
    MatType sp = sin(Rotation.pitch);
    MatType cy = cos(Rotation.yaw);
    MatType sy = sin(Rotation.yaw);
    MatType cr = cos(Rotation.roll);
    MatType sr = sin(Rotation.roll);

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

    return BaseMatrix * temp;
}

/**
 * Calculates a rotation matrix from an axis and an angle
 * Algorithm sourced from <a href="https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm">https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm</a>, lightly optimised
 * @param Matrix The matrix to apply the rotation to
 * @param Angle The angle to rotate by (In radians)
 * @param Axis The axis to rotate around, must be normalised
 */
template<typename MatType>
inline Matrix<4, 4, MatType>
Maths::rotate(const Matrix<4, 4, MatType>& BaseMatrix, const MatType Angle, const FVector& Axis) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();
    MatType c = cos(Angle);
    MatType s = sin(Angle);

    Vector<3, MatType> t = (1 - c) * Axis;

    temp[0][0] = t.x * Axis.x + c;
    temp[0][1] = t.x * Axis.y - Axis.z * s;
    temp[0][2] = t.x * Axis.z + Axis.y * s;
    temp[0][3] = 0.f;

    temp[1][0] = t.x * Axis.y + Axis.z * s;
    temp[1][1] = t.y * Axis.y + c;
    temp[1][2] = t.y * Axis.z + Axis.x * s;
    temp[1][3] = 0.f;

    temp[2][0] = t.x * Axis.z - Axis.y * s;
    temp[2][1] = t.y * Axis.z - Axis.x * s;
    temp[2][2] = t.z * Axis.z + c;
    temp[2][3] = 0.f;

    temp[3][0] = 0.f;
    temp[3][1] = 0.f;
    temp[3][2] = 0.f;
    temp[3][3] = 1.f;

    return BaseMatrix * temp;
}

// Quat
template<typename MatType>
Matrix<4, 4, MatType> Maths::rotate(const Matrix<4, 4, MatType>& BaseMatrix, const Quaternion<MatType>& Quat) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType xx2 = 2 * Quat.vec.x * Quat.vec.x;
    MatType xy2 = 2 * Quat.vec.x * Quat.vec.y;

    MatType yy2 = 2 * Quat.vec.y * Quat.vec.y;

    MatType xz2 = 2 * Quat.vec.x * Quat.vec.z;
    MatType yz2 = 2 * Quat.vec.y * Quat.vec.z;
    MatType zz2 = 2 * Quat.vec.z * Quat.vec.z;

    MatType xw2 = 2 * Quat.vec.x * Quat.s;
    MatType yw2 = 2 * Quat.vec.y * Quat.s;
    MatType zw2 = 2 * Quat.vec.z * Quat.s;

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

    return BaseMatrix * temp;
}

// Scale
template<typename MatType>
Matrix<4, 4, MatType> Maths::scale(const Matrix<4, 4, MatType>& BaseMatrix, const MatType Amount) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = BaseMatrix[0][0] * Amount;
    temp[1][0] = BaseMatrix[1][0] * Amount;
    temp[2][0] = BaseMatrix[2][0] * Amount;
    temp[3][0] = BaseMatrix[3][0] * Amount;

    temp[0][1] = BaseMatrix[0][1] * Amount;
    temp[1][1] = BaseMatrix[1][1] * Amount;
    temp[2][1] = BaseMatrix[2][1] * Amount;
    temp[3][1] = BaseMatrix[3][1] * Amount;

    temp[0][2] = BaseMatrix[0][2] * Amount;
    temp[1][2] = BaseMatrix[1][2] * Amount;
    temp[2][2] = BaseMatrix[2][2] * Amount;
    temp[3][2] = BaseMatrix[3][2] * Amount;

    temp[0][3] = BaseMatrix[0][3];
    temp[1][3] = BaseMatrix[1][3];
    temp[2][3] = BaseMatrix[2][3];
    temp[3][3] = BaseMatrix[3][3];

    return temp;
}

template<typename MatType>
Matrix<4, 4, MatType>
Maths::scale(const Matrix<4, 4, MatType>& BaseMatrix, const MatType X, const MatType Y, const MatType Z) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = BaseMatrix[0][0] * X;
    temp[1][0] = BaseMatrix[1][0] * X;
    temp[2][0] = BaseMatrix[2][0] * X;
    temp[3][0] = BaseMatrix[3][0] * X;

    temp[0][1] = BaseMatrix[0][1] * Y;
    temp[1][1] = BaseMatrix[1][1] * Y;
    temp[2][1] = BaseMatrix[2][1] * Y;
    temp[3][1] = BaseMatrix[3][1] * Y;

    temp[0][2] = BaseMatrix[0][2] * Z;
    temp[1][2] = BaseMatrix[1][2] * Z;
    temp[2][2] = BaseMatrix[2][2] * Z;
    temp[3][2] = BaseMatrix[3][2] * Z;

    temp[0][3] = BaseMatrix[0][3];
    temp[1][3] = BaseMatrix[1][3];
    temp[2][3] = BaseMatrix[2][3];
    temp[3][3] = BaseMatrix[3][3];

    return temp;
}

template<typename MatType>
Matrix<4, 4, MatType> Maths::scale(const Matrix<4, 4, MatType>& BaseMatrix, const Vector<3, MatType>& scaleVec) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = BaseMatrix[0][0] * scaleVec.x;
    temp[1][0] = BaseMatrix[1][0] * scaleVec.x;
    temp[2][0] = BaseMatrix[2][0] * scaleVec.x;
    temp[3][0] = BaseMatrix[3][0] * scaleVec.x;

    temp[0][1] = BaseMatrix[0][1] * scaleVec.y;
    temp[1][1] = BaseMatrix[1][1] * scaleVec.y;
    temp[2][1] = BaseMatrix[2][1] * scaleVec.y;
    temp[3][1] = BaseMatrix[3][1] * scaleVec.y;

    temp[0][2] = BaseMatrix[0][2] * scaleVec.y;
    temp[1][2] = BaseMatrix[1][2] * scaleVec.y;
    temp[2][2] = BaseMatrix[2][2] * scaleVec.y;
    temp[3][2] = BaseMatrix[3][2] * scaleVec.y;

    temp[0][3] = BaseMatrix[0][3];
    temp[1][3] = BaseMatrix[1][3];
    temp[2][3] = BaseMatrix[2][3];
    temp[3][3] = BaseMatrix[3][3];

    return temp;
}

template<typename MatType>
Matrix<4, 4, MatType>
Maths::perspectiveProjection(const MatType FOV, const MatType AspectRatio, const MatType NearPlane, const MatType FarPlane) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    MatType f = tan(FOV / 2.f);

    temp[0][0] = 1.f / (f * AspectRatio);
    temp[1][0] = 0;
    temp[2][0] = 0;
    temp[3][0] = 0;

    temp[0][1] = 0;
    temp[1][1] = -1.f / f;
    temp[2][1] = 0;
    temp[3][1] = 0;

    temp[0][2] = 0;
    temp[1][2] = 0;
    temp[2][2] = FarPlane / (NearPlane - FarPlane);
    temp[3][2] = -(FarPlane * NearPlane) / (FarPlane - NearPlane);

    temp[0][3] = 0;
    temp[1][3] = 0;
    temp[2][3] = -1;
    temp[3][3] = 0;

    return temp;
}

// Look at
template <typename MatType>
Matrix<4, 4, MatType> Maths::lookAt(const Vector<3, MatType>& CameraPosition, const Vector<3, MatType>& TargetPosition, const Vector<3, MatType>& WorldUp) {
    Vector<3, MatType> forwardVector = (TargetPosition - CameraPosition).normalised();
    Vector<3, MatType> rightVector = Maths::crossProduct(WorldUp, forwardVector);
    Vector<3, MatType> upVector = Maths::crossProduct(forwardVector, rightVector);

    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    temp[0][0] = rightVector.x;
    temp[1][0] = upVector.x;
    temp[2][0] = forwardVector.x;
    temp[3][0] = CameraPosition.x;

    temp[0][1] = rightVector.y;
    temp[1][1] = upVector.y;
    temp[2][1] = forwardVector.y;
    temp[3][1] = CameraPosition.y;

    temp[0][2] = rightVector.z;
    temp[1][2] = upVector.z;
    temp[2][2] = forwardVector.z;
    temp[3][2] = CameraPosition.z;

    temp[0][3] = 0;
    temp[1][3] = 0;
    temp[2][3] = 0;
    temp[3][3] = 1;

    return temp;
}

// View Matrix
// Rotator
template <typename MatType>
Matrix<4, 4, MatType> Maths::viewMatrix(const Vector<3, MatType>& CameraPosition, const Rotator<MatType>& CameraRotation) {

}

// Quaternion
template <typename MatType>
Matrix<4, 4, MatType> Maths::viewMatrix(const Vector<3, MatType>& CameraPosition, const Quaternion<MatType>& CameraRotation) {
    Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

    Vector<3, MatType> forwardVector = CameraRotation.forwardVector();
    Vector<3, MatType> rightVector = CameraRotation.rightVector();
    Vector<3, MatType> upVector = CameraRotation.upVector();

    temp[0][0] = rightVector.x;
    temp[1][0] = upVector.x;
    temp[2][0] = forwardVector.x;
    temp[3][0] = CameraPosition.x;

    temp[0][1] = rightVector.y;
    temp[1][1] = upVector.y;
    temp[2][1] = forwardVector.y;
    temp[3][1] = CameraPosition.y;

    temp[0][2] = rightVector.z;
    temp[1][2] = upVector.z;
    temp[2][2] = forwardVector.z;
    temp[3][2] = CameraPosition.z;

    temp[0][3] = 0;
    temp[1][3] = 0;
    temp[2][3] = 0;
    temp[3][3] = 1;

    return temp;
}