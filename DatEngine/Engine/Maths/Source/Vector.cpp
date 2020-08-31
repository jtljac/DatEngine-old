#include "../Vector.h"

// FVector
FVector::FVector() : x(0.f), y(0.f), z(0.f) {}

FVector::FVector(float Value) : x(Value), y(Value), z(Value) {}

FVector::FVector(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

FVector::FVector(const FVector& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

FVector::FVector(const FVector2D& Vec, float Z) : x(Vec.x), y(Vec.y), z(Z) {}

FVector::FVector(const FVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

FVector::operator IVector() {
	return IVector((int)x, (int)y, (int)z);
}

FVector::operator DVector() {
	return DVector((double)x, (double)y, (double)z);
}

// IVector
IVector::IVector() : x(0.f), y(0.f), z(0.f) {}

IVector::IVector(int Value) : x(Value), y(Value), z(Value) {}

IVector::IVector(int X, int Y, int Z) : x(X), y(Y), z(Z) {}

IVector::IVector(const IVector& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

IVector::IVector(const IVector2D& Vec, int Z) : x(Vec.x), y(Vec.y), z(Z) {}

IVector::IVector(const IVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

IVector::operator FVector() {
	return FVector((float)x, (float)y, (float)z);
}

IVector::operator DVector() {
	return DVector((double)x, (double)y, (double)z);
}

// Dvector
DVector::DVector() : x(0.f), y(0.f), z(0.f) {}

DVector::DVector(double Value) : x(Value), y(Value), z(Value) {}

DVector::DVector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

DVector::DVector(const DVector& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

DVector::DVector(const DVector2D& Vec, double Z) : x(Vec.x), y(Vec.y), z(Z) {}

DVector::DVector(const DVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

DVector::operator FVector() {
	return FVector((float) x, (float) y, (float) z);
}

DVector::operator IVector() {
	return IVector((int) x, (int) y, (int) z);
}