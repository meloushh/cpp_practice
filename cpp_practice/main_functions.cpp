#include <iostream>
#include <Windows.h>
#include <Psapi.h>

#include "main_functions.h"
#include "classes.h"

void ObjectParamTest(LifecycleDebug val, LifecycleDebug& ref, LifecycleDebug* p) {
	// Copying is done for first parameter
}

void ObjectParamTest2(LifecycleDebug* p, LifecycleDebug** pp) {
	p = new LifecycleDebug; // This leaks memory
	*pp = new LifecycleDebug;
}

void PrintMemUsage() {
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T mem_usage = pmc.WorkingSetSize;
	std::cout << "Mem usage: " << mem_usage << std::endl;
}

void StaticArrayParamTest(char val[], char* ref) {
	// All params are the same address as the outer var and changes are visible outside
}