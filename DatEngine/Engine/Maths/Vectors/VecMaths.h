#pragma once

#include "VecForward.h"

#include "../CommonMaths.h"

/**
 * Gets the dot product of the two Vectors
 * @param Vec1 The left hand vector
 * @param Vec2 The right hand vector
 * @Return The dot product
 */
template<int Size, typename VecType, typename ReturnType = VecType>
ReturnType dotProduct(const Vector<Size, VecType>& Vec1, const Vector<Size, VecType>& Vec2) {
	ReturnType temp = 0;
#pragma unroll
	for (int i = 0; i < Size, ++i) {
		temp += static_cast<ReturnType>(Vec1[i] * Vec2[i])
	}
	return temp;
}

/**
 * Gets the unit vector that looks at Vec2 from Vec1
 * @param Vec1 The Vector Looking at Vec2
 * @param Vec2 The Vector being looked at
 * @return The unit vector that looks at Vec2 from Vec1
 */
template<int Size, typename VecType, typename ReturnVecType = VecType>
Vector<Size, ReturnVecType> lookAtVector(const Vector<Size, VecType>& Vec1, const Vector<Size, VecType>& Vec2) {
	return (Vec2 - Vec1).normalise();
}

/**
 * Finds the cross product of two vectors
 * @param Vec1 The left hand vector
 * @param Vec2 The right hand vector
 * @Return The cross product product
 */
template<typename VecType, typename ReturnVecType = VecType>
Vector<3, ReturnVecType> crossProduct(const Vector<3, VecType>& Vec1, const Vector<3, VecType>& Vec2) {
	return Vector<3, ReturnVecType>((Vec1.y * Vec2.z) - (Vec1.z * Vec2.y), (Vec1.z * Vec2.x) - (Vec1.x * Vec2.z), (Vec1.x * Vec2.y) - (Vec1.y * Vec2.x));
}