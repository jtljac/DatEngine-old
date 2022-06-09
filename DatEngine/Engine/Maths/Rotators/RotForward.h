#pragma once

// Simple Pitch Yaw Roll Rotations
template <typename RotType>
struct Rotator {
	typedef Rotator<RotType> type;
	RotType pitch, yaw, roll;

	// Constructors
	// Empty
	Rotator() = default;

	/**
	 * Construct a Rotator with the same value for each component
	 * @param value The value to set each component to
	 */
	explicit Rotator(RotType value);

	/**
	 * Construct a Rotator from it's individual components
	 * @param Pitch The pitch component
	 * @param Yaw The yaw component
	 * @param Roll The roll component
	 */
	Rotator(RotType Pitch, RotType Yaw, RotType Roll);

	// Copy
	Rotator(const Rotator<RotType>& otherRot);

	// Type Conversion
    /**
     * Convert a Rotator of another type into this type
     * @tparam OtherType The type of the other Rotator
     * @param otherRot The rotator to convert
     */
	template<typename OtherType>
	explicit Rotator(const Rotator<OtherType>& otherRot);

    // Vector Axis
    /**
     * Construct a Rotator from an axis angle representation
     * @param axis The axis of the rotation
     * @param angle The angle of the rotation
     */
    explicit Rotator(Vector<3, RotType> axis, RotType angle);

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
	// Multiply
	// Multiply Vector
	// Multiply Single Value
	// Multiply in place
	// Multiply Single Value in place
	// Divide
	// Divide Single Value
	// Divide in place
	// Divide Single Value in place
	
	// Comparison
	// Equals
	// Equals with precision

};

#include "Source/Rotator.inl"