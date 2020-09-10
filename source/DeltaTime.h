#ifndef DELTATIME_H
#define DELTATIME_H

#include <chrono>

class DeltaTime
{
private:
	std::chrono::system_clock::time_point b;
	std::chrono::system_clock::time_point e;
	std::chrono::duration<double> diff;
public:
	static double delta;

	DeltaTime();
	~DeltaTime();

	void begin();
	void end();
};

#endif
