#pragma once

#include <iostream>

class Work
{
public:
	Work() {}
	Work(std::string name, int level, int interesting)
		: name(name),
		level(level),
		interesting(interesting) {}
	~Work() {}
	
	int level, interesting;	
	std::string name;
};
