#pragma once

#include <Maths/CommonMaths.h>

#include "MatForward.h"
#include "../Vectors/VecForward.h"
#include "../Rotators/RotForward.h"
#include "../Quaternions/QuatForward.h"

namespace Maths {

	// Translate
    /**
     * Apply a translation onto the baseMatrix using the translationVector
     * @tparam MatType The type of the elements in the matrix
     * @param baseMatrix The Matrix the translation is being applied to
     * @param translationVector The vector representing the translation
     * @return The matrix with the translation applied to it
     */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> translate(const Matrix<4, 4, MatType>& baseMatrix, const Vector<3, MatType>& translationVector);

	// Rotate
	/**
	 * Apply a rotation onto the baseMatrix around the pitch axis
	 * @tparam MatType The type of the elements in the matrix
	 * @param baseMatrix The Matrix the rotation is being applied to
	 * @param angle The angle to rotate by (In radians)
     * @return The matrix with the rotation applied to it
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> rotatePitch(const Matrix<4, 4, MatType>& baseMatrix, MatType angle);

    /**
     * Apply a rotation onto the baseMatrix around the yaw axis
     * @tparam MatType The type of the elements in the matrix
     * @param baseMatrix The Matrix the rotation is being applied to
     * @param angle The angle to rotate by (In radians)
     * @return The matrix with the rotation applied to it
     */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> rotateYaw(const Matrix<4, 4, MatType>& baseMatrix, MatType angle);

    /**
     * Apply a rotation onto the baseMatrix around the Roll axis
     * @tparam MatType The type of the elements in the matrix
     * @param baseMatrix The Matrix the rotation is being applied to
     * @param angle The angle to rotate by (In radians)
     * @return The matrix with the rotation applied to it
     */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> rotateRoll(const Matrix<4, 4, MatType>& baseMatrix, MatType angle);


	// Rotator
    /**
	 * Apply a rotation described by a Rotator onto the baseMatrix
	 * @tparam MatType The type of the elements in the matrix
	 * @param baseMatrix The Matrix the rotation is being applied to
	 * @param rotation The Rotator describing the rotation
     * @return The matrix with the rotation applied to it
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& baseMatrix, const Rotator<MatType>& rotation);

	/**
	 * Apply a rotation described using an axis and an angle onto the baseMatrix
	 * Algorithm sourced from <a href="https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm">https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm</a>, lightly optimised
	 * @tparam MatType The type of the elements in the matrix
	 * @param baseMatrix The matrix to apply the rotation to
	 * @param angle The angle to rotate by (In radians)
	 * @param axis The axis to rotate around, must be normalised
     * @return The matrix with the rotation applied to it
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& baseMatrix, MatType angle, const FVector& axis);

	/**
	 * Apply a rotation described using a Quaternion onto the baseMatrix
	 * @tparam MatType The type of the elements in the matrix
	 * @param baseMatrix The matrix to apply the rotation to
	 * @param quat The Quaternion descrining the rotation
     * @return The matrix with the rotation applied to it
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> rotate(const Matrix<4, 4, MatType>& baseMatrix, const Quaternion<MatType>& quat);

	// Scale
	/**
	 * Apply a scale on all axis onto the baseMatrix
	 * @tparam MatType The type of the elements in the matrix
	 * @param baseMatrix The matrix to apply the scale to
	 * @param amount The amount to scale all the axis by
	 * @return The scaled matrix
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& baseMatrix, MatType amount);

    /**
     * Apply a scale described by axis components onto the baseMatrix
     * @tparam MatType The type of the elements in the matrix
     * @param baseMatrix The matrix to apply the scale to
     * @param x The amount to scale the x-axis by
     * @param y The amount to scale the y-axis by
     * @param z The amount to scale the z-axis by
     * @return The scaled matrix
     */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& baseMatrix, MatType x, MatType y, MatType z);

    /**
     * Apply a scale described by a vector onto the baseMatrix
     * @tparam MatType The type of the elements in the matrix
     * @param baseMatrix The matrix to apply the scale to
     * @param vector A vector describing the scale
     * @return The scaled matrix
     */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> scale(const Matrix<4, 4, MatType>& baseMatrix, const Vector<3, MatType>& vector);

	/**
	 * Calculate a perspective projection
	 * @tparam MatType The type of the elements in the matrix
	 * @param fov The vertical fov of the camera
	 * @param aspectRatio The aspect ratio of the camera
	 * @param nearPlane the distance to the nearplane from the camera
	 * @param farPlane the distance to the farplane from the camera
	 * @return
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> perspectiveProjection(MatType fov, MatType aspectRatio, MatType nearPlane, MatType farPlane);

	// TODO: Orthographic

    // View Matrix
	/**
	 * Calculate a view matrix looking at a targetPosition from a sourcePosition
	 * @tparam MatType The type of the elements in the matrix
	 * @param cameraPosition The position of the source
	 * @param targetPosition The position being looked at
	 * @param upVector The upwards direction
	 * @return A camera matrix
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> lookAt(const Vector<3, MatType>& cameraPosition, const Vector<3, MatType>& targetPosition, const Vector<3, MatType>& upVector);

	/**
	 * Calculate a view matrix using a Rotator
	 * @tparam MatType The type of the elements in the matrix
	 * @param cameraPosition The position of the camera
	 * @param cameraRotation A Rotator describing the rotation of the camera
	 * @return a view matrix at the given position with the given rotation
	 */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> viewMatrix(const Vector<3, MatType>& cameraPosition, const Rotator<MatType>& cameraRotation);

    /**
     * Calculate a view matrix using a Rotator
     * @tparam MatType The type of the elements in the matrix
     * @param cameraPosition The position of the camera
     * @param cameraRotation A Quaternion describing the rotation of the camera
     * @return a view matrix at the given position with the given rotation
     */
	template <typename MatType>
    [[maybe_unused]] Matrix<4, 4, MatType> viewMatrix(const Vector<3, MatType>& cameraPosition, const Quaternion<MatType>& cameraRotation);
}

#include "Source/MatrixMaths.inl"