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
ReturnType dotProduct(const Vec<Size, VecType>& Vec1, const Vec<Size, VecType>& Vec2) {
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
Vec<Size, ReturnVecType> lookAtVector(const Vec<Size, VecType>& Vec1, const Vec<Size, VecType>& Vec2) {
	return (Vec2 - Vec1).normalise();
}