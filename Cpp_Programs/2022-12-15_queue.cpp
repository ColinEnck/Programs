#include <iostream>

const int DATA_SIZE = 100;

class Queue {
	int len;
	char data[DATA_SIZE];
public:
	Queue();
	void put(char item);
	void get();
};

int main(int argc, char const *argv[]) {
	Queue list;
	int counter = 1;
	do {
		std::cout << "\nHere is the queue so far:\n";
		list.get();
		std::cout << "\n";
		if (counter != 1)
			getchar();
		std::cout << "Input the character you want added to the queue: ";
		list.put(getchar());
	} while (counter += 1);
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
	// shifts the elements over one element
	for (int i = len - 1; i > 0; --i) {
		data[i] = data[i - 1];
	}
	data[0] = item;
}

void Queue::get() {
	for (int i = 0; i < len; ++i) {
		putchar(data[i]);
	}
}