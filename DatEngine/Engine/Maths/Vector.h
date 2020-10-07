#pragma once
#include "Vectors/Double/DVector.h"
#include "Vectors/Double/DVector2D.h"
#include "Vectors/Double/DVector4D.h"
#include "Vectors/Int/IVector.h"
#include "Vectors/Int/IVector2D.h"
#include "Vectors/Int/IVector4D.h"
#include "Vectors/Float/FVector.h"
#include "Vectors/Float/FVector2D.h"
#include "Vectors/Float/FVector4D.h"

float dotProduct(FVector vec1, FVector vec2);
float dotProduct(FVector2D vec1, FVector2D vec2);
float dotProduct(FVector4D vec1, FVector4D vec2);
double dotProduct(DVector vec1, DVector vec2);
double dotProduct(DVector2D vec1, DVector2D vec2);
double dotProduct(DVector4D vec1, DVector4D vec2);
int dotProduct(IVector vec1, IVector vec2);
int dotProduct(IVector2D vec1, IVector2D vec2);
int dotProduct(IVector4D vec1, IVector4D vec2);

FVector crossProduct(FVector vec1, FVector vec2);
DVector crossProduct(DVector vec1, DVector vec2);
IVector crossProduct(IVector vec1, IVector vec2);