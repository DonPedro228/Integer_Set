#include "Set.h"


//Constructors
Set::Set() : data(nullptr), size(0), capacity(0) {}

Set::Set(int* _data, int _size, int _capacity) {
	if (_capacity < _size) {
		_capacity = _size; 
	}

	size = 0;
	capacity = _capacity;
	data = new int[capacity];

	for (int i = 0; i < _size; ++i) {
		bool found = false;
		for (int j = 0; j < size; ++j) {
			if (_data[i] == data[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			data[size++] = _data[i];
		}
	}
}

Set::Set(const Set& other) {
	capacity = other.capacity;            
	size = other.size;
	data = new int[capacity];           
	for (int i = 0; i < size; ++i) {
		data[i] = other.data[i];          
	}
}

Set::~Set() {
	delete[] data;
}


//Additional methods
bool Set::contains(int value) const {
	for (int i = 0; i < size; ++i) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}

void Set::resize() {
	capacity = (capacity == 0) ? 4 : capacity * 2;
	int* new_data = new int[capacity];
	for (int i = 0; i < size; ++i) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
}

void Set::insert(int value) {
	if (!contains(value)) {
		if (size == capacity) {
			resize();
		}
		data[size++] = value;
	}
}


//Main methods
Set operator + (Set& s1, Set& s2) {
	Set result;

	for (int i = 0; i < s1.size; ++i) {
		result.insert(s1.data[i]);
	}

	for (int i = 0; i < s2.size; ++i) {
		result.insert(s2.data[i]);
	}
	
	return result;
}

Set operator - (Set& s1, Set& s2) {
	Set result;

	for (int i = 0; i < s1.size; ++i) {
		bool found = false;

		for (int j = 0; j < s2.size; ++j) {
			if (s1.data[i] == s2.data[j]) {
				found = true;
				break;
			}
		}

		if (!found) {
			result.insert(s1.data[i]);
		}
	}

	return result;
}

Set operator * (Set& s1, Set& s2) {
	Set result;

	for (int i = 0; i < s1.size; ++i) {

		for (int j = 0; j < s2.size; ++j) {
			if (s1.data[i] == s2.data[j]) {
				result.insert(s1.data[i]);
				break;
			}
		}
	}

	return result;
}

Set& Set::operator=(const Set& other) {
	if (this != &other) {
		delete[] data;
		capacity = other.capacity;
		size = other.size;
		data = new int[capacity];
		for (int i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}
	return *this;
}


//In and Out methods
ostream& operator << (ostream& out, const Set& s) {
	for (int i = 0; i < s.size; ++i) {
		out << setw(4) << s.data[i];
	}

	return out;
}

istream& operator >> (istream& in, Set& s) {
	int n;
	cout << "Enter number of elements: ";
	in >> n;

	delete[] s.data;
	s.size = 0;
	s.capacity = n * 2;
	s.data = new int[s.capacity];

	cout << "Enter " << n << " integers: " << endl;
	for (int i = 0; i < n; ++i) {
		int value;
		in >> value;
		s.insert(value);
	}

	return in;
}