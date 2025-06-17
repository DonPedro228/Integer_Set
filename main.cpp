#include "Set.h"
#include <iostream>
using namespace std;


int main() {
	Set s1, s2;

	cout << "Input set_1: " << endl;
	cin >> s1;
	cout << "Input set_2: " << endl;
	cin >> s2;

	cout << s1 << endl;
	cout << s2 << endl;
	
	Set s3;
	
	s3 = s1 + s2;
	cout << "Union sets: " << s3 << endl;

	Set s4;

	s4 = s1 - s2;
	cout << "Difference sets: " << s4 << endl;

	Set s5;

	s5 = s1 * s2;
	cout << "Intersection sets: " << s5 << endl;


	return 0;
}