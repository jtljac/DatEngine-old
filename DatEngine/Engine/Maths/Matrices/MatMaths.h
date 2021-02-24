#pragma once

#include <Maths/CommonMaths.h>

#include "MatForward.h"
#include "../Vectors/VecForward.h"
#include "../Rotators/RotForward.h"

// Translate
template <typename MatType>
Matrix<4, 4, MatType> translate(const Matrix<4, 4, MatType>& Matrix, const Vector<3, MatType>& TranslationVector);

// Rotate
// Pitch
template <typename MatType>
Matrix<4, 4, MatType> rotatePitch(const Matrix<4, 4, MatType>& Matrix, const MatType angle);

// Yaw
template <typename MatType>
Matrix<4, 4, MatType> rotateYaw(const Matrix<4, 4, MatType>& Matrix, const MatType angle);

// Roll
template <typename MatType>
Matrix<4, 4, MatType> rotateRoll(const Matrix<4, 4, MatType>& Matrix, const MatType angle);


// Rotator
template <typename MatType>
Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& Matrix, const Rotator<MatType>& Rotation);

/**
 * Calculates a rotation matrix from an axis and an angle
 * Algorithm sourced from <a href="https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm">https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm</a>, lightly optimised
 * @param Matrix The matrix to apply the rotation to
 * @param Angle The angle to rotate by (In radians)
 * @param Axis The axis to rotate around, must be normalised
 */
template <typename MatType>
Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& Matrix, const MatType Angle, const FVector& Axis);

// Quat

// Scale
// Single Value
template <typename MatType>
Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& Matrix, const MatType Amount);

// Components
template <typename MatType>
Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& Matrix, const MatType X, const MatType Y, const MatType Z);

// Scale Vector
template <typename MatType>
Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& Matrix, const Vector<3, MatType>& scaleVec);

template <typename MatType>
Mat<4, 4, MatType> perspectiveProjection(const Vec<3, MatType>& scaleVec);

#include "Source/MatrixMaths.inl"