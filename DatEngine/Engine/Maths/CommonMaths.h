#pragma once
#include <math.h>
// Pi
constexpr double pi = 3.141592653589793;
constexpr double halfpi = 1.5707963267948966;
constexpr double doublepi = 6.283185307179586;
constexpr double invpi = 0.3183098861837907;

// Other
constexpr double eulersNum = 2.718281828459045;
constexpr double goldenRatio = 1.618033988749895;

namespace Numbers {
	constexpr double small = 1.e-4;
	constexpr double tiny = 1.e-8;
}

namespace Tolerences {
	constexpr float normalisedTolerence = 0.01;
}

// Functions
template <class T>
T min(T Value1, T Value2) {
	return (Value1 < Value2 ? Value1 : Value2);
}

template <class T>
T max(T Value1, T Value2) {
	return (Value1 > Value2 ? Value1 : Value2);
}

template <class T>
T clamp(T Value, T Min, T Max) {
	return min<T>(max<T>(Value, Min), Max);
}

template <class T, class AlphaType = float>
T lerp(T A, T B, AlphaType Alpha) {
	return (T) (A + Alpha * (B - A));
}

template <class T>
T inverseLerp(T A, T B, T Value) {
	return (Value - A) / (B - A);
}

template <class T, class AlphaType = float>
T steppedLerp(T A, T B, AlphaType Alpha) {
	const AlphaType newAlpha = floor(Alpha * steps) / (steps - 1);
	return lerp<T, AlphaType>(A, B, newAlpha);
}

template <class T = float>
T smoothStep(T value) {
	return pow(value, 2) * (3 - (2 * value));
}

template <class T, class AlphaType = float>
T smoothLerp(T A, T B, AlphaType Alpha) {
	const AlphaType newAlpha = smoothStep(Alpha);
	return lerp<T, AlphaType>(A, B, newAlpha);
}

template <class T, class AlphaType = float>
T interpEaseIn(T A, T B, AlphaType Alpha, float Exponent) {
	const AlphaType newAlpha = pow(Alpha, Exponent);
	return lerp<T, AlphaTypeT>(A, B, newAlpha);
}

template <class T, class AlphaType = float>
T interpEaseOut(T A, T B, AlphaType Alpha, float Exponent) {
	const AlphaType newAlpha = 1 - pow(1 - Alpha, Exponent);
	return lerp<T, AlphaType>(A, B, newAlpha);
}

template <class T, class AlphaType = float>
T interpEaseInOut(T A, T B, AlphaType Alpha, float Exponent) {
	const AlphaType newAlpha = (Alpha < 0.5 ? interpEaseIn<float, AlphaType>(0.f, 1.f, Alpha * 2.f, Exponent) * .5f : interpEaseOut<float, AlphaType>(0.f, 1.f, 2.f * Alpha - 1.f, Exponent));
	return lerp<T, AlphaType>(A, B, newAlpha);
}

template <class T, class AlphaType = float>
T interpCircularIn(T A, T B, AlphaType Alpha) {
	const AlphaType newAlpha = 1 - sqrt(1 - pow(Alpha, 2));
	return lerp<T, AlphaTypeT>(A, B, newAlpha);
}

template <class T, class AlphaType = float>
T interpCircularOut(T A, T B, AlphaType Alpha) {
	const AlphaType newAlpha = sqrt(1.f - pow((1.f - x), 2));
	return lerp<T, AlphaTypeT>(A, B, newAlpha);
}

template <class T, class AlphaType = float>
T interpCircularInOut(T A, T B, AlphaType Alpha) {
	const AlphaType newAlpha = (Alpha < 0.5 ? interpCircularIn<float, AlphaType>(0.f, 1.f, alpha * 2) * 0.5 : interpCircularOut(0.f, 1.f, 2 * alpha - 1));
	return lerp<T, AlphaTypeT>(A, B, newAlpha);
}

template <class T, class AlphaType = float>
T interpSeatInOut(T A, T B, AlphaType Alpha, float Inflection) {
	const AlphaType newAlpha = (Alpha < Inflection ? sqrt(pow(Inflection, 2) - pow(Alpha - Inflection, 2)) : 1 - sqrt(pow(1 - Inflection, 2) - pow(Alpha - Inflection, 2)));
	return lerp<T, AlphaTypeT>(A, B, newAlpha);
}

//TODO: Sin Cos Cubic Spline Exponential COMMENTS