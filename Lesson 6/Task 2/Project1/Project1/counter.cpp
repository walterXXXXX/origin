#include "counter.h"

Counter::Counter() { count = 1; }

Counter::Counter(int start) { count = start; }

void Counter::inc() { count++; }

void Counter::dec() { count--; }

int Counter::getCurrentPos() { return count; }

