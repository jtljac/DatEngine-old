#pragma once

#include "VecForward.h"

#include "../CommonMaths.h"

namespace Maths {
	/**
	 * Calculates the dot product of the two Vectors
	 * @param vec1 The left-hand vector
	 * @param vec2 The right-hand vector
	 * @Return The dot product
	 */
	template<int Size, typename VecType>
    VecType dotProduct(const Vector<Size, VecType>& vec1, const Vector<Size, VecType>& vec2) {
        VecType temp = 0;
		for (int i = 0; i < Size; ++i) {
			temp += vec1[i] * vec2[i];
		}
		return temp;
	}

	/**
	 * Calculates the unit vector that looks at vec2 from vec1
	 * @param vec1 The position being looked from
	 * @param vec2 The Vector being looked at
	 * @return A unit vector representing the look at direction
	 */
	template<int Size, typename VecType>
	Vector<Size, VecType> lookAtVector(const Vector<Size, VecType>& vec1, const Vector<Size, VecType>& vec2) {
		return (vec2 - vec1).normalise();
	}

	/**
	 * Finds the cross product of two vectors
	 * @param vec1 The left-hand vector
	 * @param vec2 The right-hand vector
	 * @Return The cross product
	 */
	template<typename VecType>
	Vector<3, VecType> crossProduct(const Vector<3, VecType>& vec1, const Vector<3, VecType>& vec2) {
		return Vector<3, VecType>((vec1.y * vec2.z) - (vec1.z * vec2.y), (vec1.z * vec2.x) - (vec1.x * vec2.z), (vec1.x * vec2.y) - (vec1.y * vec2.x));
	}
}