#pragma once

// Simple Pitch Yaw Roll Rotations
template <typename RotType>
struct Rotator {
	typedef Rotator<RotType> type;
	RotType pitch, yaw, roll;

	// Constructors
	// Empty
	Rotator();

	// Single Value
	Rotator(const RotType Value);

	// Full
	Rotator(const RotType Pitch, const RotType Yaw, const RotType Roll);

	// Vector Axis


	// Copy

	Rotator(const Rotator<RotType>& OtherRot);

	// Type Conversion
	template<typename OtherType>
	explicit Rotator(const Rotator<OtherType>& OtherRot);

	// Set values
	void set(const RotType Pitch, const RotType Yaw, const RotType Roll);

	// Maths
	// Reverse
	// Add
	// Add Single Value
	// Add in place
	// Add Single Value in place
	// Subtract
	// Subtract Single Value
	// Subtract in place
	// Subtract Single Value in place
	// Multiplay
	// Multiplay Single Value
	// Multiplay in place
	// Multiplay Single Value in place
	// Divide
	// Divide Single Value
	// Divide in place
	// Divide Single Value in place
	
	// Comparison
	// Equals
	// Equals with precision

};

#include "Source/Rotator.inl"