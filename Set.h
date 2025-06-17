#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


class Set {
private:
	int* data;
	int size;
	int capacity;
public:
	
	//Constructors
	Set();
	Set(int* _data, int _size, int _capacity);
	Set(const Set& other);
	~Set();

	//Getters
	int get_size() const { return size; }
	int get_capacity() const { return capacity; }

	//Setters
	void set_size(int _size) { size = _size; }
	void set_capacity(int _capacity) { capacity = _capacity; }
	void set_data(int* _data) { data = _data; }

	//Main methods
	friend Set operator + (Set& s1, Set& s2);
	friend Set operator - (Set& s1, Set& s2);
	friend Set operator * (Set& s1, Set& s2);
	Set& operator=(const Set& other);


	//In and Out methods
	friend ostream& operator << (ostream&, const Set&);
	friend istream& operator >> (istream&, Set&);

	//Additional methods
	bool contains(int value) const;
	void insert(int value);
	void resize();
};