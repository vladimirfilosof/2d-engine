#include "DeltaTime.h"

DeltaTime::DeltaTime()
{
	b = std::chrono::system_clock::now();
	e = std::chrono::system_clock::now();
	diff = e - b;
	delta = diff.count();
}

DeltaTime::~DeltaTime()
{
}

double DeltaTime::delta = 0;

void DeltaTime::begin()
{
	diff = e - b;
	delta = diff.count();
	b = std::chrono::system_clock::now();
}

void DeltaTime::end()
{
	e = std::chrono::system_clock::now();
}
