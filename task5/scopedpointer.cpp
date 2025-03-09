#include <iostream>


template <typename T>
class ScopedPointer {
	T* pointer;

public:
	explicit ScopedPointer(T* raw) : pointer(raw) {}

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

	DeepCopyScopedPointer(DeepCopyScopedPointer&& other) noexcept
		: pointer(other.pointer) {
		other.pointer = nullptr;
	}

	// Move assignment
	DeepCopyScopedPointer& operator=(DeepCopyScopedPointer&& other) noexcept {
		if (this == &other)
			return *this;

		delete pointer;
		pointer = other.pointer;
		other.pointer = nullptr;

		return *this;
	}

	T& get() { return *pointer; }
	const T& get() const { return *pointer; }

	~ScopedPointer() { delete pointer; }
};