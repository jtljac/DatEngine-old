#pragma once

#include "MatForward.h"
#include <Maths/Vector4D.h>

template<typename MatType>
struct Mat<4, 4, MatType> {
	typedef Mat<4, 4, MatType> type;
	typedef Vec<4, MatType> colType;
	typedef colType rowType;

	colType[4] matrix;
	//TODO: 
	/*
		Constructors:
			Single Value
			Individual components
			Individual vectors
			Copy constructor

		Conversions:
			Individual Components
			Vectors

		Operators:
			+
			-
			*
			/
			+=
			-=
			*=
			/=

		Comparisons:
			==
			!=
	*/
}