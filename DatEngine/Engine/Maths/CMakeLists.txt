# Maths
target_sources (DatEngine 
				PUBLIC
					"CommonMaths.h"
)

# Vectors
target_sources (DatEngine 
				PUBLIC
					"Vector.h"
					"Vector2D.h"
					"Vector4D.h"
					"Vectors/VecForward.h"
					"Vectors/Vec2.h"
					"Vectors/Vec3.h"
					"Vectors/Vec4.h"
					"Vectors/VecMaths.h"
				PRIVATE
					"Vectors/Source/Vec3.inl"
					"Vectors/Source/Vec2.inl"
					"Vectors/Source/Vec4.inl"
)

# Matrices
target_sources (DatEngine
				PUBLIC
					"Matrix.h"
					"Matrices/MatForward.h"
					"Matrices/MatMaths.h"
				PRIVATE
					"Matrices/Source/Matrix.inl"
)

# Quaternions
target_sources (DatEngine
				PUBLIC
					"Quaternions/QuatForward.h"
				PRIVATE
					"Quaternions/Source/Quaternion.inl"
					"Quaternions/Source/QuatMaths.inl"
)

# Rotators
target_sources (DatEngine
				PUBLIC
					"Rotator.h"
					"Rotators/RotForward.h"
				PRIVATE
					"Rotators/Source/Rotator.inl"
)