#ifndef DBHELPER_H
#define DBHELPER_H

#pragma once

#include <chrono>
#include <stdio.h>

class DBHelper
{
private:
	static std::chrono::system_clock::time_point st;
public:
	static double delta;

	static void begin() noexcept;
	static void end() noexcept;

	template<typename T, typename... TArgs>
	static T check_exectime(T(*func)(TArgs... MArgs), TArgs... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		T buf = func(MArgs...);
		fprintf(stderr, "\n[DBHelper]: Function with address %p ends with duration: %f\n\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
		return buf;
	}
	template<typename T, typename CLASS, typename... TArgs>
	static T check_exectime(T(CLASS::*func)(TArgs... MArgs), CLASS* obj, TArgs... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		T buf = (obj->*func)(MArgs...);
		fprintf(stderr, "\n[DBHelper]: Function with address %p ends with duration: %f\n\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
		return buf;
	}
	template<typename... TArgs>
	static void check_exectime(void(*func)(TArgs... MArgs), TArgs... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		func(MArgs...);
		fprintf(stderr, "\n[DBHelper]: Function with address %p ends with duration: %f\n\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
	}
	template<typename T, typename... TArgs>
	static void check_exectime(void(T::*func)(TArgs... MArgs), T* obj, TArgs... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		(obj->*func)(MArgs...);
		fprintf(stderr, "\n[DBHelper]: Function with address %p ends with duration: %f\n\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
	}
};

#endif
