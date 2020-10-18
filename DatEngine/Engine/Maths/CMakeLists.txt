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
				PRIVATE
					"Vectors/Source/Vec3.inl"
					"Vectors/Source/Vec2.inl"
					"Vectors/Source/Vec4.inl"
)