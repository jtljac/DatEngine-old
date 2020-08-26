#pragma once
#include <iostream>
#include <unordered_map>
#include "EngineConfig.gen"


DatFunction()
// testes
	void de(int te, char* tell, mems test);

DatClass(test, tes2)
class EngineConfig
{
public:
	EngineConfig() {};

	int test = 1;
	DatMember(Reflect)
	std::string test2 = "hi";
	DatMember()
	float test3 = 2.3f;

	DatEnum()
	enum class testests {
		t,
		t2,
		t3
	};

	DatMember()
	test* tester = &test3;

	DatMember()
	test& testere = test3;

	// test
	DatFunction()
	template <typename test, class tester>
	void test(int te, char* tell, test test);

	ENGINE_GENERATED()
};