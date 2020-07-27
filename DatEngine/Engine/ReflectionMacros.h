#pragma once
#include <unordered_map>
#include <Engine/Utilities/Logging.h>

struct ReflectionNode {
	bool serialised;
	void* varPointer;

	ReflectionNode() {};

	ReflectionNode(bool Serialise, void* VarPointer) {
		serialised = Serialise;
		varPointer = VarPointer;
	}
};

// Placeholders
#define File_Title PlaceHolder
#define Class_Name PlaceHolder

// Markers for Build Tool
#define DatClass(...)
#define DatMember(...)
#define DatFunction(...)

// Stupid, but we need to chain this so File_Title and __LINE__ are translated to their macros
#define Generated_Combiner(a,b,c,d) a##b##c##d
#define Generated_Builder(a,b,c,d) Generated_Combiner(a,b,c,d)

// 
#define ENGINE_GENERATED(...) Generated_Builder(File_Title, _, __LINE__, _Generated);