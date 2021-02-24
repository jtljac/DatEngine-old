#pragma once

#include <cstdint>

#include "Vectors/Vec3.h"
#include "Vectors/VecMaths.h"

// Floating Point
typedef Vector<3, float> FVector;
typedef Vector<3, double> DVector;
typedef Vector<3, long double> LDVector;

// Int
typedef Vector<3, int> IVector;
typedef Vector<3, int8_t> I8Vector;
typedef Vector<3, int16_t> I16Vector;
typedef Vector<3, int32_t> I32Vector;
typedef Vector<3, int64_t> I64Vector;

// Unsigned Int
typedef Vector<3, unsigned int> UVector;
typedef Vector<3,uint8_t> U8Vector;
typedef Vector<3,uint16_t> U16Vector;
typedef Vector<3,uint32_t> U32Vector;
typedef Vector<3,uint64_t> U64Vector;