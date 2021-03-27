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
	Quaternion();

	// Components
	Quaternion(QuatType Scalar, VecType Vec);

	Quaternion(QuatType S, QuatType X, QuatType Y, QuatType Z);

	// Copy
	Quaternion(const type& OtherQuat);

	// Conversion
	// Type
	template <typename OtherType>
	Quaternion(Quaternion<OtherType> OtherQuat);

	// Rotator
	Quaternion(Rotator<QuatType> OtherRot);

	// Rotator Components
	Quaternion(QuatType Pitch, QuatType Yaw, QuatType Roll);

	// Tests
	bool isPure() const;

	bool isReal() const;

	// Maths
	// Addition
	type operator+(const type& OtherQuat) const;
	type& operator+=(const type& OtherQuat);

	// Subtraction
	type operator-(const type& OtherQuat) const;
	type& operator-=(const type& OtherQuat);

	// Multiplication
	type operator*(const type& OtherQuat) const;
	type& operator*=(const type& OtherQuat);

	// Scalar Multiplication
	type operator*(const QuatType& Scalar) const;
	type& operator*=(const QuatType& Scalar);

	// Norm
	QuatType normSquared() const;
	QuatType norm() const;

	// Normalise
	void normalise();
	type normalised() const;

	// Unit Normalise
	void unitNormalise();
	type unitNormalised() const;

	// Conjugate
	type conjugate() const;

	// Inverse
	type inverse() const;

	// Vectors
	VecType forwardVector() const;
	VecType upVector() const;
	VecType rightVector() const;
};

namespace Maths {
	// Dot Product
	template<typename QuatType>
	QuatType dotProduct(const Quaternion<QuatType>& Quat1, const Quaternion<QuatType>& Quat2);

	// Angle Between
	template<typename QuatType>
	QuatType angleBetween(const Quaternion<QuatType>& Quat1, const Quaternion<QuatType>& Quat2);
	template<typename QuatType>
	QuatType angleBetweenUnitNorm(const Quaternion<QuatType>& Quat1, const Quaternion<QuatType>& Quat2);

	// Rotation
	template<typename Type>
	Vector<3, Type> rotateVector(const Vector<3, Type>& Vec, const Quaternion< Type> Quat);

	// Interpolation
	template<typename QuatType>
	Quaternion<QuatType> slerp(Quaternion<QuatType> Quat1, Quaternion<QuatType> Quat2, QuatType Alpha);
}

#include "Source/Quaternion.inl"
#include "Source/QuatMaths.inl"