#include <iostream>


template <typename T>
class DeepCopyScopedPointer {
	T* pointer;

public:
	explicit DeepCopyScopedPointer(T* raw) : pointer(raw) {}

	DeepCopyScopedPointer(const DeepCopyScopedPointer& other)
		: pointer(other.pointer ? new T(*other.pointer) : nullptr) {
	}

	DeepCopyScopedPointer& operator=(const DeepCopyScopedPointer& other) {
		if (this == &other)
			return *this;

		delete pointer;
		pointer = other.pointer ? new T(*other.pointer) : nullptr;

		return *this;
	}

	DeepCopyScopedPointer(DeepCopyScopedPointer&& other)
		: pointer(other.pointer) {
		other.pointer = nullptr;
	}

	DeepCopyScopedPointer& operator=(DeepCopyScopedPointer&& other) {
		if (this == &other)
			return *this;

		delete pointer;
		pointer = other.pointer;
		other.pointer = nullptr;

		return *this;
	}

	T& get() { return *pointer; }
	const T& get() const { return *pointer; }

	~DeepCopyScopedPointer() { delete pointer; }
};


template <typename T>
class MoveOnlyScopedPointer {
	T* pointer;

public:
	explicit MoveOnlyScopedPointer(T* raw) : pointer(raw) {}

	MoveOnlyScopedPointer(const MoveOnlyScopedPointer&) = delete;
	MoveOnlyScopedPointer& operator=(const MoveOnlyScopedPointer&) = delete;

	MoveOnlyScopedPointer(MoveOnlyScopedPointer&& other)
		: pointer(other.pointer) {
		other.pointer = nullptr;
	}

	MoveOnlyScopedPointer& operator=(MoveOnlyScopedPointer&& other) {
		if (this == &other)
			return *this;

		delete pointer;
		pointer = other.pointer;
		other.pointer = nullptr;

		return *this;
	}


	T& get() { return *pointer; }
	const T& get() const { return *pointer; }

	~MoveOnlyScopedPointer() { delete pointer; }
};


struct Data {
	int value;
	Data(int v) : value(v) {}
};

int main() {
	// Deep copy version
	DeepCopyScopedPointer<Data> ptr1(new Data(10));
	DeepCopyScopedPointer<Data> ptr2 = ptr1;  // Deep copy!
	ptr1.get().value = 20;

	std::cout << ptr1.get().value << std::endl;  // 20
	std::cout << ptr2.get().value << std::endl;  // 10

	// Move-only version
	MoveOnlyScopedPointer<Data> ptr3(new Data(30));
	MoveOnlyScopedPointer<Data> ptr4 = std::move(ptr3); // Ownership transferred!

	if (ptr3.get().value) {} // ptr3 no longer holds anything (nullptr dereference if accessed!)

	std::cout << ptr4.get().value << std::endl;  // 30

	return 0;
}