#pragma once

#include <cstdint>

#include <Maths/Vectors/Vec3.h>

// Floating Point
typedef Vec<3, float> FVector;
typedef Vec<3, double> DVector;
typedef Vec<3, long double> LDVector;

// Int
typedef Vec<3, int> IVector;
typedef Vec<3, int8_t> I8Vector;
typedef Vec<3, int16_t> I16Vector;
typedef Vec<3, int32_t> I32Vector;
typedef Vec<3, int64_t> I64Vector;

// Unsigned Int
typedef Vec<3, unsigned int> UVector;
typedef Vec<3,uint8_t> U8Vector;
typedef Vec<3,uint16_t> U16Vector;
typedef Vec<3,uint32_t> U32Vector;
typedef Vec<3,uint64_t> U64Vector;

template<typename VecType, typename ReturnType = VecType>
ReturnType dotProduct(const Vec<3, VecType>& Vec1, const Vec<3, VecType>& Vec2) {
	return static_cast<ReturnType>(Vec1.x * Vec2.x + Vec1.y * Vec2.y + Vec1.z * Vec2.z);
}

template<typename VecType, typename ReturnVecType = VecType>
Vec<3, ReturnVecType> crossProduct(const Vec<3, VecType>& Vec1, const Vec<3, VecType>& Vec2) {
	return Vec<3, ReturnVecType>((Vec1.y * Vec2.z) - (Vec1.z * Vec2.y), (Vec1.z * Vec2.x) - (Vec1.x * Vec2.z), (Vec1.x * Vec2.y) - (Vec1.y * Vec2.x));
}

template<typename VecType, typename ReturnVecType = VecType>
Vec<3, ReturnVecType> lookAtVector(const Vec<3, VecType>& Vec1, const Vec<3, VecType>& Vec2) {
	return (Vec2 - Vec1).normalise();
}