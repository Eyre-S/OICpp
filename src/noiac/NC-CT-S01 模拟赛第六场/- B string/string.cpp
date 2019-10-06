#include <iostream>

using namespace std;

string common_str;
int str_len;
int ask_count = 0;

int main () {
	
	cin >> ask_count;
	for (register int timey = 0; timey < ask_count; timey) {
		cin >> str_len;
		getchar(); cin >> common_str;
	}
	
	return 0;
	
}