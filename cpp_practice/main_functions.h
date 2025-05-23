#pragma once

#include "classes.h"

void ObjectParamTest(LifecycleDebug val, LifecycleDebug & ref, LifecycleDebug* p);

void ObjectParamTest2(LifecycleDebug* p, LifecycleDebug** pp, LifecycleDebug*& ppp);

void PrintMemUsage();

void StaticArrayParamTest(char val[], char* ref);