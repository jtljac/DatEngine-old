#pragma once
#include <stdexcept>
#include <typeinfo>

class UnknownResourceFactoryException : public std::runtime_error {
public:
	UnknownResourceFactoryException(const std::type_info &Info) : std::runtime_error("Unable to find factory for asset of type " + (*Info.name())) {}
};