#include <iostream>
#include "stdarg.h"

using namespace std;

void Rd(int count, ...) {
	
	va_list args;
	
	va_start(args, count);
	for (register int i = 0; i < count; i++) {
		int* x = va_arg(args, int*);
		*x = 0;
		char c = getchar();
		int f = 1;
		while (c < '0' or c > '9')
			f = (c == '-') ? -1 : 1, c = getchar();
		while (c >= '0' and c <= '9')
			*x = (*x << 1) + (*x << 3) + (c ^ 48), c = getchar();
		*x = (f == 1) ? *x : -*x;
	}
}

int main() {

	int a, b, c;

	Rd(3, &a, &b, &c);
	
	cout << a << " " << b << " " << c << endl;

	return 0;
}

void R1(int &x) {
	x = 0;
	char c = getchar();
	int f = 1;
	while (c < '0' or c > '9')
		f = (c == '-') ? -1 : 1, c = getchar();
	while (c >= '0' and c <= '9')
		x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	x = (f == 1) ? x : -x;
}