#include "../Vector.h"
#include "../CommonMaths.h"

// FVector
//TODO: Other vector types
const FVector FVector::up = FVector(0.f,0.f,1.f);
const FVector FVector::down = FVector(0.f, 0.f, -1.f);
const FVector FVector::north = FVector(0.f, 1.f, 0.f);
const FVector FVector::south = FVector(0.f, -1.f, 0.f);
const FVector FVector::east = FVector(1.f, 0.f, 0.f);
const FVector FVector::west = FVector(-1.f, 0.f, 0.f);

FVector::FVector() : x(0.f), y(0.f), z(0.f) {}

FVector::FVector(float Value) : x(Value), y(Value), z(Value) {}

FVector::FVector(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

FVector::FVector(const FVector& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

FVector::FVector(const FVector2D& Vec, float Z) : x(Vec.x), y(Vec.y), z(Z) {}

FVector::FVector(const FVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

FVector::operator IVector() const {
	return IVector((int) x, (int) y, (int) z);
}

FVector::operator DVector() const {
	return DVector((double) x, (double) y, (double) z);
}

void FVector::set(float newX, float newY, float newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

void FVector::set(float newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
}

void FVector::set(const FVector& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
}

FVector FVector::operator+(const FVector& OtherVec) const {
	return FVector(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

FVector FVector::operator+(float Amount) const {
	return FVector(x + Amount, y + Amount, z + Amount);
}

FVector FVector::operator+=(const FVector& OtherVec) const {
	return FVector(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

FVector FVector::operator+=(float Amount) const {
	return FVector(x + Amount, y + Amount, z + Amount);
}

FVector FVector::operator++(int Amount) {
	FVector temp = FVector(*this);
	x += Amount;
	y += Amount;
	z += Amount;
	return temp;
}

FVector FVector::operator-(const FVector& OtherVec) const {
	return FVector(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

FVector FVector::operator-(float Amount) const {
	return FVector(x - Amount, y - Amount, z - Amount);
}

FVector FVector::operator-=(const FVector& OtherVec) const {
	return FVector(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

FVector FVector::operator-=(float Amount) const {
	return FVector(x - Amount, y - Amount, z - Amount);
}

FVector FVector::operator--(int Amount) {
	return (*this) - Amount;
}

FVector FVector::operator*(const FVector& OtherVec) const {
	return FVector(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

FVector FVector::operator*(float Value) const {
	return FVector(x * Value, y * Value, z * Value);
}

FVector FVector::operator*=(const FVector& OtherVec) const {
	return FVector(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

FVector FVector::operator*=(float Value) const {
	return FVector(x * Value, y * Value, z * Value);
}

FVector FVector::operator/(const FVector& OtherVec) const {
	return FVector(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

FVector FVector::operator/(float Value) const {
	return FVector(x / Value, y / Value, z / Value);
}

FVector FVector::operator/=(const FVector& OtherVec) const {
	return FVector(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

FVector FVector::operator/=(float Value) const {
	return FVector(x / Value, y / Value, z / Value);
}

bool FVector::operator<(const FVector& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool FVector::operator>(const FVector& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool FVector::operator<=(const FVector& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool FVector::operator>=(const FVector& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool FVector::operator==(const FVector& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y) && (z == OtherVec.z);
}

bool FVector::operator!=(const FVector& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y) || (z != OtherVec.z);
}

bool FVector::equals(const FVector& OtherVec, float Tolerence) const {
	return (abs(x - OtherVec.x) < Tolerence) && (abs(y - OtherVec.y) < Tolerence) && (abs(z - OtherVec.z) < Tolerence);
}

float FVector::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

float FVector::magnitude() const {
	return sqrt(magnitudeSquared());
}

FVector FVector::normalise() const {
	const float mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return *this / magnitude();
	}
	else {
		return FVector();
	}
}

bool FVector::isNormalised(float Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

// FVector2D
const FVector2D FVector2D::up = FVector2D(0.f, 1.f);
const FVector2D FVector2D::down = FVector2D(0.f, -1.f);
const FVector2D FVector2D::right = FVector2D(1.f, 0.f);
const FVector2D FVector2D::left = FVector2D(-1.f, 0.f);

FVector2D::FVector2D() : x(0.f), y(0.f) {}

FVector2D::FVector2D(float Value) : x(Value), y(Value) {}

FVector2D::FVector2D(float X, float Y) : x(X), y(Y) {}

FVector2D::FVector2D(const FVector2D& Vec) : x(Vec.x), y(Vec.y) {}

FVector2D::FVector2D(const FVector& Vec) : x(Vec.x), y(Vec.y) {}

FVector2D::FVector2D(const FVector4D& Vec) : x(Vec.x), y(Vec.y) {}

FVector2D::operator IVector2D() const {
	return IVector2D((int) x, (int) y);
}

FVector2D::operator DVector2D() const {
	return DVector2D((double) x, (double) y);
}

void FVector2D::set(float newX, float newY) {
	x = newX;
	y = newY;
}

void FVector2D::set(float newValue) {
	x = newValue;
	y = newValue;
}

void FVector2D::set(const FVector2D& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
}

FVector2D FVector2D::operator+(const FVector2D& OtherVec) const {
	return FVector2D(x + OtherVec.x, y + OtherVec.y);
}

FVector2D FVector2D::operator+(float Amount) const {
	return FVector2D(x + Amount, y + Amount);
}

FVector2D FVector2D::operator+=(const FVector2D& OtherVec) const {
	return FVector(x + OtherVec.x, y + OtherVec.y);
}

FVector2D FVector2D::operator+=(float Amount) const {
	return FVector2D(x + Amount, y + Amount);
}

FVector2D FVector2D::operator++(int Amount) {
	FVector2D temp = FVector2D(*this);
	x += Amount;
	y += Amount;
	return temp;
}

FVector2D FVector2D::operator-(const FVector2D& OtherVec) const {
	return FVector2D(x - OtherVec.x, y - OtherVec.y);
}

FVector2D FVector2D::operator-(float Amount) const {
	return FVector2D(x - Amount, y - Amount);
}

FVector2D FVector2D::operator-=(const FVector2D& OtherVec) const {
	return FVector2D(x - OtherVec.x, y - OtherVec.y);
}

FVector2D FVector2D::operator-=(float Amount) const {
	return FVector2D(x - Amount, y - Amount);
}

FVector2D FVector2D::operator--(int Amount) {
	return (*this) - Amount;
}

FVector2D FVector2D::operator*(const FVector2D& OtherVec) const {
	return FVector2D(x * OtherVec.x, y * OtherVec.y);
}

FVector2D FVector2D::operator*(float Value) const {
	return FVector2D(x * Value, y * Value);
}

FVector2D FVector2D::operator*=(const FVector2D& OtherVec) const {
	return FVector2D(x * OtherVec.x, y * OtherVec.y);
}

FVector2D FVector2D::operator*=(float Value) const {
	return FVector2D(x * Value, y * Value);
}

FVector2D FVector2D::operator/(const FVector2D& OtherVec) const {
	return FVector2D(x / OtherVec.x, y / OtherVec.y);
}

FVector2D FVector2D::operator/(float Value) const {
	return FVector2D(x / Value, y / Value);
}

FVector2D FVector2D::operator/=(const FVector2D& OtherVec) const {
	return FVector2D(x / OtherVec.x, y / OtherVec.y);
}

FVector2D FVector2D::operator/=(float Value) const {
	return FVector2D(x / Value, y / Value);
}

bool FVector2D::operator<(const FVector2D& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool FVector2D::operator>(const FVector2D& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool FVector2D::operator<=(const FVector2D& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool FVector2D::operator>=(const FVector2D& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool FVector2D::operator==(const FVector2D& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y);
}

bool FVector2D::operator!=(const FVector2D& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y);
}

bool FVector2D::equals(const FVector2D& OtherVec, float Tolerence) const {
	return (abs(x - OtherVec.x) < Tolerence) && (abs(y - OtherVec.y) < Tolerence);
}

float FVector2D::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2);
}

float FVector2D::magnitude() const {
	return sqrt(magnitudeSquared());
}

FVector2D FVector2D::normalise() const {
	const float mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return *this / magnitude();
	}
	else {
		return FVector2D();
	}
}

bool FVector2D::isNormalised(float Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

// FVector4D
FVector4D::FVector4D() : x(0.f), y(0.f), z(0.f), w(0.f) {}

FVector4D::FVector4D(float Value) : x(Value), y(Value), z(Value), w(Value) {}

FVector4D::FVector4D(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) {}

FVector4D::FVector4D(const FVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z), w(Vec.w) {}

FVector4D::FVector4D(const FVector& Vec, float W) : x(Vec.x), y(Vec.y), z(Vec.z), w(W) {}

FVector4D::FVector4D(const FVector2D& Vec, float Z, float W) : x(Vec.x), y(Vec.y), z(Z), w(W) {}

FVector4D::operator IVector4D() const {
	return IVector4D((int) x, (int) y, (int) z, (int) w);
}

FVector4D::operator DVector4D() const {
	return DVector4D((double) x, (double) y, (double) z, (double) w);
}

void FVector4D::set(float newX, float newY, float newZ, float newW) {
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

void FVector4D::set(float newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
	w = newValue;
}

void FVector4D::set(const FVector4D& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
	w = OtherVector.w;
}

FVector4D FVector4D::operator+(const FVector4D& OtherVec) const {
	return FVector4D(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

FVector4D FVector4D::operator+(float Amount) const {
	return FVector4D(x + Amount, y + Amount, z + Amount, w + Amount);
}

FVector4D FVector4D::operator+=(const FVector4D& OtherVec) const {
	return FVector4D(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

FVector4D FVector4D::operator+=(float Amount) const {
	return FVector4D(x + Amount, y + Amount, z + Amount, w + Amount);
}

FVector4D FVector4D::operator++(int Amount) {
	FVector4D temp = FVector4D(*this);
	x += Amount;
	y += Amount;
	z += Amount;
	w += Amount;
	return temp;
}

FVector4D FVector4D::operator-(const FVector4D& OtherVec) const {
	return FVector4D(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

FVector4D FVector4D::operator-(float Amount) const {
	return FVector4D(x - Amount, y - Amount, z - Amount, w - Amount);
}

FVector4D FVector4D::operator-=(const FVector4D& OtherVec) const {
	return FVector4D(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

FVector4D FVector4D::operator-=(float Amount) const {
	return FVector4D(x - Amount, y - Amount, z - Amount, w - Amount);
}

FVector4D FVector4D::operator--(int Amount) {
	return (*this) - Amount;
}

FVector4D FVector4D::operator*(const FVector4D& OtherVec) const {
	return FVector4D(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z , w * OtherVec.w);
}

FVector4D FVector4D::operator*(float Value) const {
	return FVector4D(x * Value, y * Value, z * Value, w * Value);
}

FVector4D FVector4D::operator*=(const FVector4D& OtherVec) const {
	return FVector4D(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z, w * OtherVec.w);
}

FVector4D FVector4D::operator*=(float Value) const {
	return FVector4D(x * Value, y * Value, z * Value, w * Value);
}

FVector4D FVector4D::operator/(const FVector4D& OtherVec) const {
	return FVector4D(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

FVector4D FVector4D::operator/(float Value) const {
	return FVector4D(x / Value, y / Value, z / Value, w / Value);
}

FVector4D FVector4D::operator/=(const FVector4D& OtherVec) const {
	return FVector4D(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

FVector4D FVector4D::operator/=(float Value) const {
	return FVector4D(x / Value, y / Value, z / Value, w / Value);
}

bool FVector4D::operator<(const FVector4D& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool FVector4D::operator>(const FVector4D& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool FVector4D::operator<=(const FVector4D& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool FVector4D::operator>=(const FVector4D& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool FVector4D::operator==(const FVector4D& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y) && (z == OtherVec.z) && (w == OtherVec.w);
}

bool FVector4D::operator!=(const FVector4D& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y) || (z != OtherVec.z) || (w != OtherVec.w);
}

bool FVector4D::equals(const FVector4D& OtherVec, float Tolerence) const {
	return (abs(x - OtherVec.x) < Tolerence) && (abs(y - OtherVec.y) < Tolerence) && (abs(z - OtherVec.z) < Tolerence);
}

float FVector4D::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
}

float FVector4D::magnitude() const {
	return sqrt(magnitudeSquared());
}

FVector4D FVector4D::normalise() const {
	const float mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return *this / magnitude();
	}
	else {
		return FVector4D();
	}
}

bool FVector4D::isNormalised(float Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

//TODO: Maths for I Vectors

// IVector
const IVector IVector::up = IVector(0, 0, 1);
const IVector IVector::down = IVector(0, 0, -1);
const IVector IVector::north = IVector(0, 1, 0);
const IVector IVector::south = IVector(0, -1, 0);
const IVector IVector::east = IVector(1, 0, 0);
const IVector IVector::west = IVector(-1, 0, 0);

IVector::IVector() : x(0), y(0), z(0) {}

IVector::IVector(int Value) : x(Value), y(Value), z(Value) {}

IVector::IVector(int X, int Y, int Z) : x(X), y(Y), z(Z) {}

IVector::IVector(const IVector& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

IVector::IVector(const IVector2D& Vec, int Z) : x(Vec.x), y(Vec.y), z(Z) {}

IVector::IVector(const IVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

IVector::operator FVector() const {
	return FVector((float) x, (float) y, (float) z);
}

IVector::operator DVector() const {
	return DVector((double) x, (double) y, (double) z);
}

void IVector::set(int newX, int newY, int newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

void IVector::set(int newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
}

void IVector::set(const IVector& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
}

IVector IVector::operator+(const IVector& OtherVec) const {
	return IVector(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

IVector IVector::operator+(int Amount) const {
	return IVector(x + Amount, y + Amount, z + Amount);
}

IVector IVector::operator+=(const IVector& OtherVec) const {
	return IVector(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

IVector IVector::operator+=(int Amount) const {
	return IVector(x + Amount, y + Amount, z + Amount);
}

IVector IVector::operator++(int Amount) {
	IVector temp = IVector(*this);
	x += Amount;
	y += Amount;
	z += Amount;
	return temp;
}

IVector IVector::operator-(const IVector& OtherVec) const {
	return IVector(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

IVector IVector::operator-(int Amount) const {
	return IVector(x - Amount, y - Amount, z - Amount);
}

IVector IVector::operator-=(const IVector& OtherVec) const {
	return IVector(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

IVector IVector::operator-=(int Amount) const {
	return IVector(x - Amount, y - Amount, z - Amount);
}

IVector IVector::operator--(int Amount) {
	return (*this) - Amount;
}

IVector IVector::operator*(const IVector& OtherVec) const {
	return IVector(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

IVector IVector::operator*(int Value) const {
	return IVector(x * Value, y * Value, z * Value);
}

IVector IVector::operator*=(const IVector& OtherVec) const {
	return IVector(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

IVector IVector::operator*=(int Value) const {
	return IVector(x * Value, y * Value, z * Value);
}

IVector IVector::operator/(const IVector& OtherVec) const {
	return IVector(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

IVector IVector::operator/(int Value) const {
	return IVector(x / Value, y / Value, z / Value);
}

IVector IVector::operator/=(const IVector& OtherVec) const {
	return IVector(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

IVector IVector::operator/=(int Value) const {
	return IVector(x / Value, y / Value, z / Value);
}

bool IVector::operator<(const IVector& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool IVector::operator>(const IVector& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool IVector::operator<=(const IVector& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool IVector::operator>=(const IVector& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool IVector::operator==(const IVector& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y) && (z == OtherVec.z);
}

bool IVector::operator!=(const IVector& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y) || (z != OtherVec.z);
}

bool IVector::equals(const IVector& OtherVec) const {
	return (*this) == OtherVec;
}

float IVector::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

float IVector::magnitude() const {
	return sqrt(magnitudeSquared());
}

FVector IVector::normalise() const {
	const float mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return (FVector)(*this) / magnitude();
	}
	else {
		return FVector();
	}
}

bool FVector::isNormalised(float Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

// IVector2D
const IVector2D IVector2D::up = IVector2D(0, 1);
const IVector2D IVector2D::down = IVector2D(0, -1);
const IVector2D IVector2D::right = IVector2D(1, 0);
const IVector2D IVector2D::left = IVector2D(-1, 0);

IVector2D::IVector2D() : x(0), y(0) {}

IVector2D::IVector2D(int Value) : x(Value), y(Value) {}

IVector2D::IVector2D(int X, int Y) : x(X), y(Y) {}

IVector2D::IVector2D(const IVector2D& Vec) : x(Vec.x), y(Vec.y) {}

IVector2D::IVector2D(const IVector& Vec) : x(Vec.x), y(Vec.y) {}

IVector2D::IVector2D(const IVector4D& Vec) : x(Vec.x), y(Vec.y) {}

IVector2D::operator FVector2D() const {
	return FVector2D((float) x, (float) y);
}

IVector2D::operator DVector2D() const {
	return DVector2D((double) x, (double) y);
}

void IVector2D::set(int newX, int newY) {
	x = newX;
	y = newY;
}

void IVector2D::set(int newValue) {
	x = newValue;
	y = newValue;
}

void IVector2D::set(const IVector2D& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
}

IVector2D IVector2D::operator+(const IVector2D& OtherVec) const {
	return IVector2D(x + OtherVec.x, y + OtherVec.y);
}

IVector2D IVector2D::operator+(int Amount) const {
	return IVector2D(x + Amount, y + Amount);
}

IVector2D IVector2D::operator+=(const IVector2D& OtherVec) const {
	return IVector2D(x + OtherVec.x, y + OtherVec.y);
}

IVector2D IVector2D::operator+=(int Amount) const {
	return IVector2D(x + Amount, y + Amount);
}

IVector2D IVector2D::operator++(int Amount) {
	IVector2D temp = IVector2D(*this);
	x += Amount;
	y += Amount;
	return temp;
}

IVector2D IVector2D::operator-(const IVector2D& OtherVec) const {
	return IVector2D(x - OtherVec.x, y - OtherVec.y);
}

IVector2D IVector2D::operator-(int Amount) const {
	return IVector2D(x - Amount, y - Amount);
}

IVector2D IVector2D::operator-=(const IVector2D& OtherVec) const {
	return IVector2D(x - OtherVec.x, y - OtherVec.y);
}

IVector2D IVector2D::operator-=(int Amount) const {
	return IVector2D(x - Amount, y - Amount);
}

IVector2D IVector2D::operator--(int Amount) {
	return (*this) - Amount;
}

IVector2D IVector2D::operator*(const IVector2D& OtherVec) const {
	return IVector2D(x * OtherVec.x, y * OtherVec.y);
}

IVector2D IVector2D::operator*(int Value) const {
	return IVector2D(x * Value, y * Value);
}

IVector2D IVector2D::operator*=(const IVector2D& OtherVec) const {
	return IVector2D(x * OtherVec.x, y * OtherVec.y);
}

IVector2D IVector2D::operator*=(int Value) const {
	return IVector2D(x * Value, y * Value);
}

IVector2D IVector2D::operator/(const IVector2D& OtherVec) const {
	return IVector2D(x / OtherVec.x, y / OtherVec.y);
}

IVector2D IVector2D::operator/(int Value) const {
	return IVector2D(x / Value, y / Value);
}

IVector2D IVector2D::operator/=(const IVector2D& OtherVec) const {
	return IVector2D(x / OtherVec.x, y / OtherVec.y);
}

IVector2D IVector2D::operator/=(int Value) const {
	return IVector2D(x / Value, y / Value);
}

bool IVector2D::operator<(const IVector2D& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool IVector2D::operator>(const IVector2D& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool IVector2D::operator<=(const IVector2D& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool IVector2D::operator>=(const IVector2D& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool IVector2D::operator==(const IVector2D& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y);
}

bool IVector2D::operator!=(const IVector2D& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y);
}

bool IVector2D::equals(const IVector2D& OtherVec) const {
	return (*this) == OtherVec;
}

float IVector2D::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2);
}

float IVector2D::magnitude() const {
	return sqrt(magnitudeSquared());
}

FVector2D IVector2D::normalise() const {
	const float mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return ((FVector2D)(*this)) / magnitude();
	}
	else {
		return FVector2D();
	}
}

bool IVector2D::isNormalised(float Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

// IVector4D
IVector4D::IVector4D() : x(0), y(0), z(0), w(0) {}

IVector4D::IVector4D(int Value) : x(Value), y(Value), z(Value), w(Value) {}

IVector4D::IVector4D(int X, int Y, int Z, int W) : x(X), y(Y), z(Z), w(W) {}

IVector4D::IVector4D(const IVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z), w(Vec.w) {}

IVector4D::IVector4D(const IVector& Vec, int W) : x(Vec.x), y(Vec.y), z(Vec.z), w(W) {}

IVector4D::IVector4D(const IVector2D& Vec, int Z, int W) : x(Vec.x), y(Vec.y), z(Z), w(W) {}

IVector4D::operator FVector4D() const {
	return FVector4D((float) x, (float) y, (float) z, (float) w);
}

IVector4D::operator DVector4D() const {
	return DVector4D((double) x, (double) y, (double) z, (double) w);
}

void IVector4D::set(int newX, int newY, int newZ, int newW) {
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

void IVector4D::set(int newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
	w = newValue;
}

void IVector4D::set(const IVector4D& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
	w = OtherVector.w;
}

IVector4D IVector4D::operator+(const IVector4D& OtherVec) const {
	return IVector4D(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

IVector4D IVector4D::operator+(int Amount) const {
	return IVector4D(x + Amount, y + Amount, z + Amount, w + Amount);
}

IVector4D IVector4D::operator+=(const IVector4D& OtherVec) const {
	return IVector4D(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

IVector4D IVector4D::operator+=(int Amount) const {
	return IVector4D(x + Amount, y + Amount, z + Amount, w + Amount);
}

IVector4D IVector4D::operator++(int Amount) {
	IVector4D temp = IVector4D(*this);
	x += Amount;
	y += Amount;
	z += Amount;
	w += Amount;
	return temp;
}

IVector4D IVector4D::operator-(const IVector4D& OtherVec) const {
	return IVector4D(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

IVector4D IVector4D::operator-(int Amount) const {
	return IVector4D(x - Amount, y - Amount, z - Amount, w - Amount);
}

IVector4D IVector4D::operator-=(const IVector4D& OtherVec) const {
	return IVector4D(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

IVector4D IVector4D::operator-=(int Amount) const {
	return IVector4D(x - Amount, y - Amount, z - Amount, w - Amount);
}

IVector4D IVector4D::operator--(int Amount) {
	return (*this) - Amount;
}

IVector4D IVector4D::operator*(const IVector4D& OtherVec) const {
	return IVector4D(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z, w * OtherVec.w);
}

IVector4D IVector4D::operator*(int Value) const {
	return IVector4D(x * Value, y * Value, z * Value, w * Value);
}

IVector4D IVector4D::operator*=(const IVector4D& OtherVec) const {
	return IVector4D(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z, w * OtherVec.w);
}

IVector4D IVector4D::operator*=(int Value) const {
	return IVector4D(x * Value, y * Value, z * Value, w * Value);
}

IVector4D IVector4D::operator/(const IVector4D& OtherVec) const {
	return IVector4D(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

IVector4D IVector4D::operator/(int Value) const {
	return IVector4D(x / Value, y / Value, z / Value, w / Value);
}

IVector4D IVector4D::operator/=(const IVector4D& OtherVec) const {
	return IVector4D(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

IVector4D IVector4D::operator/=(int Value) const {
	return IVector4D(x / Value, y / Value, z / Value, w / Value);
}

bool IVector4D::operator<(const IVector4D& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool IVector4D::operator>(const IVector4D& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool IVector4D::operator<=(const IVector4D& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool IVector4D::operator>=(const IVector4D& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool IVector4D::operator==(const IVector4D& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y) && (z == OtherVec.z) && (w == OtherVec.w);
}

bool IVector4D::operator!=(const IVector4D& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y) || (z != OtherVec.z) || (w != OtherVec.w);
}

bool IVector4D::equals(const IVector4D& OtherVec) const {
	return (*this) == OtherVec;
}

float IVector4D::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
}

float IVector4D::magnitude() const {
	return sqrt(magnitudeSquared());
}

FVector4D IVector4D::normalise() const {
	const float mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return (FVector4D)(*this) / magnitude();
	}
	else {
		return FVector4D();
	}
}

bool IVector4D::isNormalised(float Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

// Dvector
const DVector DVector::up = DVector(0., 0., 1.);
const DVector DVector::down = DVector(0., 0., -1.);
const DVector DVector::north = DVector(0., 1., 0.);
const DVector DVector::south = DVector(0., -1., 0.);
const DVector DVector::east = DVector(1., 0., 0.);
const DVector DVector::west = DVector(-1., 0., 0.);

DVector::DVector() : x(0.), y(0.), z(0.) {}

DVector::DVector(double Value) : x(Value), y(Value), z(Value) {}

DVector::DVector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

DVector::DVector(const DVector& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

DVector::DVector(const DVector2D& Vec, double Z) : x(Vec.x), y(Vec.y), z(Z) {}

DVector::DVector(const DVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z) {}

DVector::operator FVector() const {
	return FVector((float) x, (float) y, (float) z);
}

DVector::operator IVector() const {
	return IVector((int) x, (int) y, (int) z);
}

void DVector::set(double newX, double newY, double newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

void DVector::set(double newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
}

void DVector::set(const DVector& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
}

DVector DVector::operator+(const DVector& OtherVec) const {
	return DVector(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

DVector DVector::operator+(double Amount) const {
	return DVector(x + Amount, y + Amount, z + Amount);
}

DVector DVector::operator+=(const DVector& OtherVec) const {
	return DVector(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z);
}

DVector DVector::operator+=(double Amount) const {
	return DVector(x + Amount, y + Amount, z + Amount);
}

DVector DVector::operator++(int Amount) {
	DVector temp = DVector(*this);
	x += Amount;
	y += Amount;
	z += Amount;
	return temp;
}

DVector DVector::operator-(const DVector& OtherVec) const {
	return DVector(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

DVector DVector::operator-(double Amount) const {
	return DVector(x - Amount, y - Amount, z - Amount);
}

DVector DVector::operator-=(const DVector& OtherVec) const {
	return DVector(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z);
}

DVector DVector::operator-=(double Amount) const {
	return DVector(x - Amount, y - Amount, z - Amount);
}

DVector DVector::operator--(int Amount) {
	return (*this) - Amount;
}

DVector DVector::operator*(const DVector& OtherVec) const {
	return DVector(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

DVector DVector::operator*(double Value) const {
	return DVector(x * Value, y * Value, z * Value);
}

DVector DVector::operator*=(const DVector& OtherVec) const {
	return DVector(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z);
}

DVector DVector::operator*=(double Value) const {
	return DVector(x * Value, y * Value, z * Value);
}

DVector DVector::operator/(const DVector& OtherVec) const {
	return DVector(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

DVector DVector::operator/(double Value) const {
	return DVector(x / Value, y / Value, z / Value);
}

DVector DVector::operator/=(const DVector& OtherVec) const {
	return DVector(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z);
}

DVector DVector::operator/=(double Value) const {
	return DVector(x / Value, y / Value, z / Value);
}

bool DVector::operator<(const DVector& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool DVector::operator>(const DVector& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool DVector::operator<=(const DVector& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool DVector::operator>=(const DVector& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool DVector::operator==(const DVector& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y) && (z == OtherVec.z);
}

bool DVector::operator!=(const DVector& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y) || (z != OtherVec.z);
}

bool DVector::equals(const DVector& OtherVec, double Tolerence) const {
	return (abs(x - OtherVec.x) < Tolerence) && (abs(y - OtherVec.y) < Tolerence) && (abs(z - OtherVec.z) < Tolerence);
}

double DVector::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

double DVector::magnitude() const {
	return sqrt(magnitudeSquared());
}

DVector DVector::normalise() const {
	const double mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return *this / magnitude();
	}
	else {
		return DVector();
	}
}

bool DVector::isNormalised(double Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

// DVector2D
const DVector2D DVector2D::up = DVector2D(0., 1.);
const DVector2D DVector2D::down = DVector2D(0., -1.);
const DVector2D DVector2D::right = DVector2D(1., 0.);
const DVector2D DVector2D::left = DVector2D(-1., 0.);


DVector2D::DVector2D() : x(0.), y(0.) {}

DVector2D::DVector2D(double Value) : x(Value), y(Value) {}

DVector2D::DVector2D(double X, double Y) : x(X), y(Y) {}

DVector2D::DVector2D(const DVector2D& Vec) : x(Vec.x), y(Vec.y) {}

DVector2D::DVector2D(const DVector& Vec) : x(Vec.x), y(Vec.y) {}

DVector2D::DVector2D(const DVector4D& Vec) : x(Vec.x), y(Vec.y) {}

DVector2D::operator FVector2D() const {
	return FVector2D((float) x, (float) y);
}

DVector2D::operator IVector2D() const {
	return IVector2D((int) x, (int) y);
}

void DVector2D::set(double newX, double newY) {
	x = newX;
	y = newY;
}

void DVector2D::set(double newValue) {
	x = newValue;
	y = newValue;
}

void DVector2D::set(const DVector2D& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
}

DVector2D DVector2D::operator+(const DVector2D& OtherVec) const {
	return DVector2D(x + OtherVec.x, y + OtherVec.y);
}

DVector2D DVector2D::operator+(double Amount) const {
	return DVector2D(x + Amount, y + Amount);
}

DVector2D DVector2D::operator+=(const DVector2D& OtherVec) const {
	return DVector2D(x + OtherVec.x, y + OtherVec.y);
}

DVector2D DVector2D::operator+=(double Amount) const {
	return DVector2D(x + Amount, y + Amount);
}

DVector2D DVector2D::operator++(int Amount) {
	DVector2D temp = DVector2D(*this);
	x += Amount;
	y += Amount;
	return temp;
}

DVector2D DVector2D::operator-(const DVector2D& OtherVec) const {
	return DVector2D(x - OtherVec.x, y - OtherVec.y);
}

DVector2D DVector2D::operator-(double Amount) const {
	return DVector2D(x - Amount, y - Amount);
}

DVector2D DVector2D::operator-=(const DVector2D& OtherVec) const {
	return DVector2D(x - OtherVec.x, y - OtherVec.y);
}

DVector2D DVector2D::operator-=(double Amount) const {
	return DVector2D(x - Amount, y - Amount);
}

DVector2D DVector2D::operator--(int Amount) {
	return (*this) - Amount;
}

DVector2D DVector2D::operator*(const DVector2D& OtherVec) const {
	return DVector2D(x * OtherVec.x, y * OtherVec.y);
}

DVector2D DVector2D::operator*(double Value) const {
	return DVector2D(x * Value, y * Value);
}

DVector2D DVector2D::operator*=(const DVector2D& OtherVec) const {
	return DVector2D(x * OtherVec.x, y * OtherVec.y);
}

DVector2D DVector2D::operator*=(double Value) const {
	return DVector2D(x * Value, y * Value);
}

DVector2D DVector2D::operator/(const DVector2D& OtherVec) const {
	return DVector2D(x / OtherVec.x, y / OtherVec.y);
}

DVector2D DVector2D::operator/(double Value) const {
	return DVector2D(x / Value, y / Value);
}

DVector2D DVector2D::operator/=(const DVector2D& OtherVec) const {
	return DVector2D(x / OtherVec.x, y / OtherVec.y);
}

DVector2D DVector2D::operator/=(double Value) const {
	return DVector2D(x / Value, y / Value);
}

bool DVector2D::operator<(const DVector2D& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool DVector2D::operator>(const DVector2D& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool DVector2D::operator<=(const DVector2D& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool DVector2D::operator>=(const DVector2D& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool DVector2D::operator==(const DVector2D& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y);
}

bool DVector2D::operator!=(const DVector2D& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y);
}

bool DVector2D::equals(const DVector2D& OtherVec, double Tolerence) const {
	return (abs(x - OtherVec.x) < Tolerence) && (abs(y - OtherVec.y) < Tolerence);
}

double DVector2D::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2);
}

double DVector2D::magnitude() const {
	return sqrt(magnitudeSquared());
}

DVector2D DVector2D::normalise() const {
	const double mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return *this / magnitude();
	}
	else {
		return DVector2D();
	}
}

bool DVector2D::isNormalised(double Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}

// DVector4D
DVector4D::DVector4D() : x(0.), y(0.), z(0.), w(0.) {}

DVector4D::DVector4D(double Value) : x(Value), y(Value), z(Value), w(Value) {}

DVector4D::DVector4D(double X, double Y, double Z, double W) : x(X), y(Y), z(Z), w(W) {}

DVector4D::DVector4D(const DVector4D& Vec) : x(Vec.x), y(Vec.y), z(Vec.z), w(Vec.w) {}

DVector4D::DVector4D(const DVector& Vec, double W) : x(Vec.x), y(Vec.y), z(Vec.z), w(W) {}

DVector4D::DVector4D(const DVector2D& Vec, double Z, double W) : x(Vec.x), y(Vec.y), z(Z), w(W) {}

DVector4D::operator IVector4D() const {
	return IVector4D((int)x, (int)y, (int)z, (int)w);
}

DVector4D::operator FVector4D() const {
	return FVector4D((float)x, (float)y, (float)z, (float)w);
}

void DVector4D::set(double newX, double newY, double newZ, double newW) {
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

void DVector4D::set(double newValue) {
	x = newValue;
	y = newValue;
	z = newValue;
	w = newValue;
}

void DVector4D::set(const DVector4D& OtherVector) {
	x = OtherVector.x;
	y = OtherVector.y;
	z = OtherVector.z;
	w = OtherVector.w;
}

DVector4D DVector4D::operator+(const DVector4D& OtherVec) const {
	return DVector4D(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

DVector4D DVector4D::operator+(double Amount) const {
	return DVector4D(x + Amount, y + Amount, z + Amount, w + Amount);
}

DVector4D DVector4D::operator+=(const DVector4D& OtherVec) const {
	return DVector4D(x + OtherVec.x, y + OtherVec.y, z + OtherVec.z, w + OtherVec.w);
}

DVector4D DVector4D::operator+=(double Amount) const {
	return DVector4D(x + Amount, y + Amount, z + Amount, w + Amount);
}

DVector4D DVector4D::operator++(int Amount) {
	DVector4D temp = DVector4D(*this);
	x += Amount;
	y += Amount;
	z += Amount;
	w += Amount;
	return temp;
}

DVector4D DVector4D::operator-(const DVector4D& OtherVec) const {
	return DVector4D(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

DVector4D DVector4D::operator-(double Amount) const {
	return DVector4D(x - Amount, y - Amount, z - Amount, w - Amount);
}

DVector4D DVector4D::operator-=(const DVector4D& OtherVec) const {
	return DVector4D(x - OtherVec.x, y - OtherVec.y, z - OtherVec.z, w - OtherVec.w);
}

DVector4D DVector4D::operator-=(double Amount) const {
	return DVector4D(x - Amount, y - Amount, z - Amount, w - Amount);
}

DVector4D DVector4D::operator--(int Amount) {
	return (*this) - Amount;
}

DVector4D DVector4D::operator*(const DVector4D& OtherVec) const {
	return DVector4D(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z, w * OtherVec.w);
}

DVector4D DVector4D::operator*(double Value) const {
	return DVector4D(x * Value, y * Value, z * Value, w * Value);
}

DVector4D DVector4D::operator*=(const DVector4D& OtherVec) const {
	return DVector4D(x * OtherVec.x, y * OtherVec.y, z * OtherVec.z, w * OtherVec.w);
}

DVector4D DVector4D::operator*=(double Value) const {
	return DVector4D(x * Value, y * Value, z * Value, w * Value);
}

DVector4D DVector4D::operator/(const DVector4D& OtherVec) const {
	return DVector4D(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

DVector4D DVector4D::operator/(double Value) const {
	return DVector4D(x / Value, y / Value, z / Value, w / Value);
}

DVector4D DVector4D::operator/=(const DVector4D& OtherVec) const {
	return DVector4D(x / OtherVec.x, y / OtherVec.y, z / OtherVec.z, w / OtherVec.w);
}

DVector4D DVector4D::operator/=(double Value) const {
	return DVector4D(x / Value, y / Value, z / Value, w / Value);
}

bool DVector4D::operator<(const DVector4D& OtherVec) const {
	return normalise() < OtherVec.normalise();
}

bool DVector4D::operator>(const DVector4D& OtherVec) const {
	return normalise() > OtherVec.normalise();
}

bool DVector4D::operator<=(const DVector4D& OtherVec) const {
	return normalise() <= OtherVec.normalise();
}

bool DVector4D::operator>=(const DVector4D& OtherVec) const {
	return normalise() >= OtherVec.normalise();
}

bool DVector4D::operator==(const DVector4D& OtherVec) const {
	return (x == OtherVec.x) && (y == OtherVec.y) && (z == OtherVec.z) && (w == OtherVec.w);
}

bool DVector4D::operator!=(const DVector4D& OtherVec) const {
	return (x != OtherVec.x) || (y != OtherVec.y) || (z != OtherVec.z) || (w != OtherVec.w);
}

bool DVector4D::equals(const DVector4D& OtherVec, double Tolerence) const {
	return (abs(x - OtherVec.x) < Tolerence) && (abs(y - OtherVec.y) < Tolerence) && (abs(z - OtherVec.z) < Tolerence);
}

double DVector4D::magnitudeSquared() const {
	return pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
}

double DVector4D::magnitude() const {
	return sqrt(magnitudeSquared());
}

DVector4D DVector4D::normalise() const {
	const double mag = magnitudeSquared();
	if (mag > Numbers::small) {
		return *this / magnitude();
	}
	else {
		return DVector4D();
	}
}

bool FVector4D::isNormalised(float Tolerence) const {
	return abs(magnitude() - 1.f) < Tolerence;
}