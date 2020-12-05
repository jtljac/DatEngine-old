#pragma once

#include "MatForward.h"
#include "../Vectors/VecForward.h"

// Translate
template <typename MatType>
Mat<4, 4, MatType> translate(Mat<4, 4, MatType> Matrix, Vec<3, MatType> TranslationVector);

// Rotate
// Rotator
// Quat

// Scale

#include "Source/MatrixMaths.inl"