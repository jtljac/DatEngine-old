#pragma once
#include <iostream>
#include <unordered_map>
#include "EngineConfig.gen"

DatClass(test, tes2)
class EngineConfig {
public:
	EngineConfig() {};

	DatMember(Reflect)
	int test = 1;
	DatMember(Reflect)
	std::string test2 = "hi";
	DatMember()
	float test3 = 2.3f;

	ENGINE_GENERATED()
};