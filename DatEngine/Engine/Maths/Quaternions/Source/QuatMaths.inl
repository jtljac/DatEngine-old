// Dot Product
template<typename QuatType>
QuatType Maths::dotProduct(const Quaternion<QuatType>& Quat1, const Quaternion<QuatType>& Quat2) {
	return Quat1.s * Quat2.s + Maths::dotProduct(Quat1.vec, Quat2.vec);
}

template<typename QuatType>
QuatType Maths::angleBetween(const Quaternion<QuatType>& Quat1, const Quaternion<QuatType>& Quat2) {
	return acos(dotProduct(Quat1, Quat2) / (Quat1.norm() * Quat2.norm()));
}

template<typename QuatType>
QuatType Maths::angleBetweenUnitNorm(const Quaternion<QuatType>& Quat1, const Quaternion<QuatType>& Quat2) {
	return acos(dotProduct(Quat1, Quat2));
}

template<typename Type>
Vector<3, Type> Maths::rotateVector(const Vector<3, Type>& Vec, const Quaternion<Type>& Quat) {
	/*
	
	Quaternion<Type> p(0, Vec);
	Quaternion<Type> qInverse = Quat.inverse();

	return (Quat * p * qInverse).vec;
	*/

	Vector<3, Type> cross = Maths::crossProduct(Quat.vec, Vec) * 2;

	return ((cross * Quat.s) + Maths::crossProduct(Quat.vec, cross)) + Vec;
}

// Interpolation
template<typename QuatType>
Quaternion<QuatType> Maths::slerp(const Quaternion<QuatType>& Quat1, const Quaternion<QuatType>& Quat2, QuatType Alpha){
	QuatType cosTheta = Maths::dotProduct(Quat1, Quat2);

	Quaternion<QuatType> quat1;

	if (cosTheta < 0) {
		cosTheta = -cosTheta;
		quat1 = -Quat1;
	}
	else {
		quat1 = Quat1;
	}

	if (cosTheta > 1 - Maths::Tolerances::normalisedTolerance) {
		return Maths::lerp(Quat1, Quat2, Alpha);
	}
	else {
		QuatType theta = acos(cosTheta);

		return (sin((1 - Alpha) * theta) * quat1 + sin(Alpha * theta) * Quat2) / sqrt(1 - (cosTheta * cosTheta));
	}
}