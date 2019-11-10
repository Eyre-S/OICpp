#include <iostream>

using namespace std;

int main () {
	
	int a = 2, b = 3, c = 0;
	
	cout << (c = a * b, c) << endl;
	
	return 0;
	
}