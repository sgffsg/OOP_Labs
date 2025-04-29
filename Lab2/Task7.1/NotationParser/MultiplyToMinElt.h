#pragma once
#include <iosfwd>
#include <vector>

std::vector<float> ReadVector(std::istream& input);

void PrintVector(std::vector<float> vector, std::ostream& output);

void MultiplyEltsToMinElt(std::vector<float>& vector);