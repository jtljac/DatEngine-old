#pragma once

#include <Maths/Vectors/Vec3.h>
#include <Maths/CommonMaths.h>
#include <Maths/Vectors/VecMaths.h>
#include <Maths/Rotators/RotForward.h>

// TODO: Shit's about to get fuckey https://www.haroldserrano.com/blog/developing-a-math-engine-in-c-implementing-quaternions
template <typename QuatType>
struct Quaternion {
	QuatType s;
	Vector<3, QuatType> vec;

	typedef Quaternion<QuatType> type;
	typedef Vector<3, QuatType> VecType;

	// Constructors
	// Empty
	Quaternion() = default;

	/**
	 * Construct a Quaternion using its vector component and scalar component
	 * @param scalar The scalar component
	 * @param vector the vector component
	 */
	Quaternion(QuatType scalar, VecType vector);

    /**
     * Construct a Quaternion using its individual components
     * @param scaler The scalar component
     * @param x The x part of the vector component
     * @param y The y part of the vector component
     * @param z The z part of the vector component
     */
	Quaternion(QuatType scaler, QuatType x, QuatType y, QuatType z);

	// Copy
	Quaternion(const type& OtherQuat);

	// Conversion
	/**
	 * Construct a Quaternion using a Quaternion of another type
	 * @tparam OtherType The type of the other Quaternion
	 * @param otherQuat The Quaternion to convert from
	 */
	template <typename OtherType>
	explicit Quaternion(Quaternion<OtherType> otherQuat);

	/**
	 * Convert a Rotator into a Quaternion
	 * @param otherRot The Rotator to convert from
	 */
	explicit Quaternion(Rotator<QuatType> otherRot);

	/**
	 * Construct a Quaternion using rotator components
	 * @param pitch The pitch component of the Rotator
	 * @param yaw The yaw component of the Rotator
	 * @param roll The roll component of the Rotator
	 */
	explicit Quaternion(QuatType pitch, QuatType yaw, QuatType roll);

	/**
	 * Construct a Quaternion using an axis and an angle
	 * @param axis The axis of rotation
	 * @param angle The angle of rotation
	 */
	explicit Quaternion(VecType axis, QuatType angle);

	// Tests
    /**
     * Test the Quaternion is pure
     * I.E. the real part equals zero
     * @return If the Quaternion is pure
     */
	[[nodiscard]] bool isPure() const;

    /**
     * Test the Quaternion is real
     * I.E. the 4d Vector length equals one
     * @return If the Quaternion is real
     */
	[[nodiscard]] bool isReal() const;

	// Maths
	// Addition
	type operator+(const type& otherQuat) const;
	type& operator+=(const type& otherQuat);

	// Subtraction
	type operator-(const type& otherQuat) const;
	type& operator-=(const type& otherQuat);

	// Multiplication
	type operator*(const type& otherQuat) const;
	type& operator*=(const type& otherQuat);

	// scalar Multiplication
	type operator*(const QuatType& scalar) const;
	type& operator*=(const QuatType& scalar);

	// Vec Multiplication
	VecType operator*(const VecType& otherVec) const;

	// Magnitude
    /**
     * Calculate the magnitude squared of the quaternion
     * @return The magnitude squared of the quaternion
     */
	QuatType magnitudeSquared() const;

    /**
     * Calculate the magnitude of the quaternion
     * @return The magnitude of the quaternion
     */
	QuatType magnitude() const;

	/**
	 * Normalise the Quaternion in place
	 */
	void normalise();

    /**
     * Get the normalised Quaternion
     * @return The normalised Quaternion
     */
	type normalised() const;

	/**
	 * Calculate the conjugate of the Quaternion
	 * Used to calculate the inverse
	 * @return The conjugate of the Quaternion
	 */
	type conjugate() const;

	/**
	 * Calculate the inverse of the Quaternion
	 * @return The inverse of the Quaternion
	 */
	type inverse() const;

	// Vectors
    /**
     * Get a unit vector pointing in the direction represented by the Quaternion
     *
     * This only works when the quaternion is real
     *
     * @return A vector pointing in the direction represented by the Quaternion
     */
	VecType forwardVector() const;

    /**
     * Get a unit vector pointing 90 degrees up from the direction represented by the Quaternion
     *
     * This only works when the quaternion is real
     *
     * @return A vector pointing 90 degrees up from the direction represented by the Quaternion
     */
	VecType upVector() const;

    /**
     * Get a unit vector pointing 90 degrees right from the direction represented by the Quaternion
     *
     * This only works when the quaternion is real
     *
     * @return A vector pointing 90 degrees right from the direction represented by the Quaternion
     */
	VecType rightVector() const;
};

namespace Maths {
	/**
	 * Find the dot product between two Quaternions
	 *
     * This only works when the quaternion is real
     *
	 * @tparam QuatType The type of the Quaternion
	 * @param quat1 The first Quaternion
	 * @param quat2 The second Quaternion
	 * @return The dot product between the two Quaternions
	 */
	template<typename QuatType>
	QuatType dotProduct(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2);

	/**
	 * Find the angle between two Quaternions
	 *
     * This only works when the quaternion is real
     *
	 * @tparam QuatType The type of the Quaternion
	 * @param quat1 The first Quaternion
	 * @param quat2 The second Quaternion
	 * @return The angle between the two Quaternions
	 */
	template<typename QuatType>
	QuatType angleBetween(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2);

    /**
	 * Find the angle between two real Quaternions
     *
     * This only works when the quaternion is real
     *
	 * @tparam QuatType The type of the Quaternion
	 * @param quat1 The first Quaternion
	 * @param quat2 The second Quaternion
	 * @return The angle between the two Quaternions
	 */
	template<typename QuatType>
	QuatType angleBetweenUnitNorm(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2);

	/**
	 * Rotate the given vector by the given Quaternion
	 *
     * This only works when the quaternion is real
     *
	 * @tparam Type The type of the Vector and Quaternion
	 * @param vec The Vector to rotate
	 * @param quat The quat representing the rotation
	 * @return The given Vector rotated by the given Quaternion
	 */
	template<typename Type>
	Vector<3, Type> rotateVector(const Vector<3, Type>& vec, const Quaternion<Type>& quat);

	/**
	 * Spherically interpolate by the alpha between the given Quaternions
	 *
     * This only works when the quaternion is real
     *
	 * @tparam QuatType The type of the Quaternion
	 * @param quat1 The first Quaternion
	 * @param quat2 The second Quaternion
	 * @param alpha The progress between the two quaternions (A value of 0 results in quat1, A value of 1 results in quat2)
	 * @return The spherical interpolation by the alpha between the two Quarternions
	 */
	template<typename QuatType>
    [[maybe_unused]] Quaternion<QuatType> slerp(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2, QuatType alpha);
}

#include "Source/Quaternion.inl"
#include "Source/QuatMaths.inl"