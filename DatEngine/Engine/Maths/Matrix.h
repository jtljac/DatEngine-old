#pragma once

#include "Matrices/MatForward.h"
#include "Matrices/MatMaths.h"

// 4x4
template<typename MatType>
using Mat4 = Mat<4, 4, MatType>;

typedef Mat4<float> FMat4;
typedef Mat4<double> DMat4;
typedef Mat4<int> IMat4;

// 3x3
template<typename MatType>
using Mat3 = Mat<3, 3, MatType>;

typedef Mat3<float> FMat3;
typedef Mat3<double> DMat3;
typedef Mat3<int> IMat3;

// 2x2
template<typename MatType>
using Mat2 = Mat<2, 2, MatType>;

typedef Mat2<float> FMat2;
typedef Mat2<double> DMat2;
typedef Mat2<int> IMat2;

