// Translate
template <typename MatType>
Matrix<4, 4, MatType> translate(const Matrix<4, 4, MatType>& Matrix, const Vector<3, MatType>& TranslationVector) {
	Matrix<4, 4, MatType> temp(Matrix);

	temp[3][0] = Matrix[0][0] * TranslationVector.x + Matrix[1][0] * TranslationVector.y + Matrix[2][0] * TranslationVector.z + Matrix[3][0];
	temp[3][1] = Matrix[0][1] * TranslationVector.x + Matrix[1][1] * TranslationVector.y + Matrix[2][1] * TranslationVector.z + Matrix[3][1];
	temp[3][2] = Matrix[0][2] * TranslationVector.x + Matrix[1][2] * TranslationVector.y + Matrix[2][2] * TranslationVector.z + Matrix[3][2];
	temp[3][3] = Matrix[0][3] * TranslationVector.x + Matrix[1][3] * TranslationVector.y + Matrix[2][3] * TranslationVector.z + Matrix[3][3];

	return temp;
}

// Rotate
// Pitch
template <typename MatType>
Matrix<4, 4, MatType> rotatePitch(const Matrix<4, 4, MatType>& Matrix, const MatType angle) {
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

	return Matrix * temp;
}

// Yaw
template <typename MatType>
Matrix<4, 4, MatType> rotateYaw(const Matrix<4, 4, MatType>& Matrix, const MatType angle) {
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

	return Matrix * temp;
}

// Roll
template <typename MatType>
Matrix<4, 4, MatType> rotateRoll(const Matrix<4, 4, MatType>& Matrix, const MatType angle) {
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

	return Matrix * temp;
}

// Rotator
template <typename MatType>
Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& Matrix, const Rotator<MatType>& Rotation) {
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

	return Matrix * temp;
}

/**
 * Calculates a rotation matrix from an axis and an angle
 * Algorithm sourced from <a href="https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm">https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm</a>, lightly optimised
 * @param Matrix The matrix to apply the rotation to
 * @param Angle The angle to rotate by (In radians)
 * @param Axis The axis to rotate around, must be normalised
 */
template<typename MatType>
inline Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& Matrix, const MatType Angle, const FVector& Axis)
{
	Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();
	MatType c = cos(angle);
	MatType s = sin(angle);

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

	return Matrix * temp;
}

// Scale
template <typename MatType>
Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& Matrix, const MatType Amount) {
	Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

	temp[0][0] = Matrix[0][0] * Amount;
	temp[1][0] = Matrix[1][0] * Amount;
	temp[2][0] = Matrix[2][0] * Amount;
	temp[3][0] = Matrix[3][0] * Amount;

	temp[0][1] = Matrix[0][1] * Amount;
	temp[1][1] = Matrix[1][1] * Amount;
	temp[2][1] = Matrix[2][1] * Amount;
	temp[3][1] = Matrix[3][1] * Amount;

	temp[0][2] = Matrix[0][2] * Amount;
	temp[1][2] = Matrix[1][2] * Amount;
	temp[2][2] = Matrix[2][2] * Amount;
	temp[3][2] = Matrix[3][2] * Amount;

	temp[0][3] = Matrix[0][3] * Amount;
	temp[1][3] = Matrix[1][3] * Amount;
	temp[2][3] = Matrix[2][3] * Amount;
	temp[3][3] = Matrix[3][3] * Amount;

	return temp;
}

template <typename MatType>
Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& Matrix, const MatType X, const MatType Y, const MatType Z) {
	Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

	temp[0][0] = Matrix[0][0] * X;
	temp[1][0] = Matrix[1][0] * X;
	temp[2][0] = Matrix[2][0] * X;
	temp[3][0] = Matrix[3][0] * X;

	temp[0][1] = Matrix[0][1] * Y;
	temp[1][1] = Matrix[1][1] * Y;
	temp[2][1] = Matrix[2][1] * Y;
	temp[3][1] = Matrix[3][1] * Y;

	temp[0][2] = Matrix[0][2] * Z;
	temp[1][2] = Matrix[1][2] * Z;
	temp[2][2] = Matrix[2][2] * Z;
	temp[3][2] = Matrix[3][2] * Z;

	temp[0][3] = Matrix[0][3];
	temp[1][3] = Matrix[1][3];
	temp[2][3] = Matrix[2][3];
	temp[3][3] = Matrix[3][3];

	return temp;
}

template <typename MatType>
Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& Matrix, const Vector<3, MatType>& scaleVec) {
	Matrix<4, 4, MatType> temp = Matrix<4, 4, MatType>();

	temp[0][0] = Matrix[0][0] * scaleVec.x;
	temp[1][0] = Matrix[1][0] * scaleVec.x;
	temp[2][0] = Matrix[2][0] * scaleVec.x;
	temp[3][0] = Matrix[3][0] * scaleVec.x;

	temp[0][1] = Matrix[0][1] * scaleVec.y;
	temp[1][1] = Matrix[1][1] * scaleVec.y;
	temp[2][1] = Matrix[2][1] * scaleVec.y;
	temp[3][1] = Matrix[3][1] * scaleVec.y;

	temp[0][2] = Matrix[0][2] * scaleVec.y;
	temp[1][2] = Matrix[1][2] * scaleVec.y;
	temp[2][2] = Matrix[2][2] * scaleVec.y;
	temp[3][2] = Matrix[3][2] * scaleVec.y;

	temp[0][3] = Matrix[0][3];
	temp[1][3] = Matrix[1][3];
	temp[2][3] = Matrix[2][3];
	temp[3][3] = Matrix[3][3];

	return temp;
}