#include <iostream>

const int DATA_SIZE = 100;

class Queue {
	int len;
	char data[DATA_SIZE];
public:
	Queue();
	~Queue();
	void put(char item);
	char get();
};

int main(int argc, char const *argv[]) {
	Queue a_queue;

	return 0;
}

Queue::Queue() {
	len = 0;
	for (int i = 0; i < DATA_SIZE; ++i) {
		data[i] = 0;
	}
}

void Queue::put(char item) {
	len++;


	data[0] = item;
}

char Queue::get() {
	for (int i = 0; i < len; ++i) {
		cout << data[i];
	}
}

// shifts an array over one element, pushing the last element off
void shift(char data[], int len) {
	for (int i = len; i > 0; --i) {

	}
}