// Constructors
// Empty
template <typename RotType>
Rotator<RotType>::Rotator() {}

// Single Value
template <typename RotType>
Rotator<RotType>::Rotator(const RotType Value) : pitch(Value), yaw(Value), roll(Value) {}

// Full
template<typename RotType>
Rotator<RotType>::Rotator(const RotType Pitch, const RotType Yaw, const RotType Roll) : pitch(Pitch), yaw(Yaw), roll(Roll) {}

// Vector Axis


// Copy
template<typename RotType>
Rotator<RotType>::Rotator(const Rotator<RotType>& OtherRot) : pitch(OtherRot.pitch), yaw(OtherRot.yaw), roll(OtherRot.yaw) {}

// Type Conversion
template<typename RotType>
template<typename OtherType>
Rotator<RotType>::Rotator(const Rotator<OtherType>& OtherRot) : pitch(static_cast<RotType>(OtherRot.pitch)), yaw(static_cast<RotType>(OtherRot.yaw)), roll(static_cast<RotType>(OtherRot.yaw)) {}

// Set values
template<typename RotType>
void Rotator<RotType>::set(const RotType Pitch, const RotType Yaw, const RotType Roll) {
	pitch = Pitch;
	yaw = Yaw;
	roll = Roll;
}