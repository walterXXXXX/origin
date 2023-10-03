#pragma once

class Counter {
public:
	Counter();
	Counter(int start);
	void inc();
	void dec();
	int getCurrentPos();

private:
	int count;
};


