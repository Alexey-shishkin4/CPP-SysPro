#include <iostream>


template <typename T>
class DeepCopyScopedPointerScopedPointer {
	T* pointer;

public:
	explicit DeepCopyScopedPointerScopedPointer(T* raw) : pointer(raw) {}

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

	~DeepCopyScopedPointerScopedPointer() { delete pointer; }
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
	const t& get() const { return *pointer; }

	~MoveOnlyScopedPointer() { delete pointer; }
};