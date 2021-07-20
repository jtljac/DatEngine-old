#pragma once

#include <Maths/CommonMaths.h>

#include "MatForward.h"
#include "../Vectors/VecForward.h"
#include "../Rotators/RotForward.h"
#include "../Quaternions/QuatForward.h"

namespace Maths {

	// Translate
	template <typename MatType>
	Matrix<4, 4, MatType> translate(const Matrix<4, 4, MatType>& BaseMatrix, const Vector<3, MatType>& TranslationVector);

	// Rotate
	// Pitch
	template <typename MatType>
	Matrix<4, 4, MatType> rotatePitch(const Matrix<4, 4, MatType>& BaseMatrix, MatType angle);

	// Yaw
	template <typename MatType>
	Matrix<4, 4, MatType> rotateYaw(const Matrix<4, 4, MatType>& BaseMatrix, MatType angle);

	// Roll
	template <typename MatType>
	Matrix<4, 4, MatType> rotateRoll(const Matrix<4, 4, MatType>& BaseMatrix, MatType angle);


	// Rotator
	template <typename MatType>
	Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& BaseMatrix, const Rotator<MatType>& Rotation);

	/**
	 * Calculates a rotation matrix from an axis and an angle
	 * Algorithm sourced from <a href="https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm">https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm</a>, lightly optimised
	 * @param BaseMatrix The matrix to apply the rotation to
	 * @param Angle The angle to rotate by (In radians)
	 * @param Axis The axis to rotate around, must be normalised
	 */
	template <typename MatType>
	Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& BaseMatrix, MatType Angle, const FVector& Axis);

	// Quat
	template <typename MatType>
	Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& BaseMatrix, const Quaternion<MatType>& Quat);

	// Scale
	// Single Value
	template <typename MatType>
	Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& BaseMatrix, MatType Amount);

	// Components
	template <typename MatType>
	Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& BaseMatrix, MatType X, MatType Y, MatType Z);

	// Scale Vector
	template <typename MatType>
	Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& BaseMatrix, const Vector<3, MatType>& scaleVec);

	// Perspective
	template <typename MatType>
	Matrix<4, 4, MatType> perspectiveProjection(MatType FOV, MatType AspectRatio, MatType NearPlane, MatType FarPlane);

	// TODO: Orthographic

	// Look at
	template <typename MatType>
	Matrix<4, 4, MatType> lookAt(const Vector<3, MatType>& CameraPosition, const Vector<3, MatType>& TargetPosition, const Vector<3, MatType>& worldUp);

	// View Matrix
	// Rotator
	template <typename MatType>
	Matrix<4, 4, MatType> viewMatrix(const Rotator<MatType>& CameraRotation);

	// Quaternion
	template <typename MatType>
	Matrix<4, 4, MatType> viewMatrix(const Quaternion<MatType>& CameraRotation);
}

#include "Source/MatrixMaths.inl"