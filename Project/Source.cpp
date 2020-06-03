#include <iostream>
#include <Engine/Utilities/FileUtilities.h>
#include <Engine/Config/EngineConfig.h>

int main() {
	EngineConfig test = EngineConfig();

	std::cout << test.test << std::endl;
	(*(int*) test.reflection["test"].varPointer) = 10;

	std::cout << test.test << std::endl;
}