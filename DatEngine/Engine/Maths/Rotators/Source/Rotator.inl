// Constructors
// Single value
template <typename RotType>
Rotator<RotType>::Rotator(const RotType value) : pitch(value), yaw(value), roll(value) {}

// Full
template<typename RotType>
Rotator<RotType>::Rotator(const RotType Pitch, const RotType Yaw, const RotType Roll) : pitch(Pitch), yaw(Yaw), roll(Roll) {}

// Vector Axis
template<typename RotType>
Rotator<RotType>::Rotator(Vector<3, RotType> axis, RotType angle) {
    // TODO: Finish
}

// Copy
template<typename RotType>
Rotator<RotType>::Rotator(const Rotator<RotType>& OtherRot) : pitch(OtherRot.pitch), yaw(OtherRot.yaw), roll(OtherRot.yaw) {}

// Type Conversion
template<typename RotType>
template<typename OtherType>
Rotator<RotType>::Rotator(const Rotator<OtherType>& otherRot) : pitch(static_cast<RotType>(otherRot.pitch)), yaw(static_cast<RotType>(otherRot.yaw)), roll(static_cast<RotType>(otherRot.yaw)) {}

// Set values
template<typename RotType>
void Rotator<RotType>::set(const RotType Pitch, const RotType Yaw, const RotType Roll) {
	pitch = Pitch;
	yaw = Yaw;
	roll = Roll;
}
