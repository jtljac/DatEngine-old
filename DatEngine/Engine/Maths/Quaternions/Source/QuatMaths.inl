// Dot Product
template<typename QuatType>
QuatType Maths::dotProduct(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2) {
	return quat1.s * quat2.s + Maths::dotProduct(quat1.vec, quat2.vec);
}

template<typename QuatType>
QuatType Maths::angleBetween(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2) {
	return acos(dotProduct(quat1, quat2) / (quat1.magnitude() * quat2.magnitude()));
}

template<typename QuatType>
QuatType Maths::angleBetweenUnitNorm(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2) {
	return acos(dotProduct(quat1, quat2));
}

template<typename Type>
Vector<3, Type> Maths::rotateVector(const Vector<3, Type>& vec, const Quaternion<Type>& quat) {
	Vector<3, Type> cross = Maths::crossProduct(quat.vec, vec) * 2;

	return ((cross * quat.s) + Maths::crossProduct(quat.vec, cross)) + vec;
}

// Interpolation
template<typename QuatType>
[[maybe_unused]] [[maybe_unused]] [[maybe_unused]] Quaternion<QuatType> Maths::slerp(const Quaternion<QuatType>& quat1, const Quaternion<QuatType>& quat2, QuatType alpha){
	QuatType cosTheta = Maths::dotProduct(quat1, quat2);

	Quaternion<QuatType> quat;

	if (cosTheta < 0) {
		cosTheta = -cosTheta;
		quat = -quat;
	}
	else {
		quat = quat1;
	}

	if (cosTheta > 1 - Maths::Tolerances::normalisedTolerance) {
		return Maths::lerp(quat, quat2, alpha);
	}
	else {
		QuatType theta = acos(cosTheta);

		return (sin((1 - alpha) * theta) * quat + sin(alpha * theta) * quat2) / sqrt(1 - (cosTheta * cosTheta));
	}
}