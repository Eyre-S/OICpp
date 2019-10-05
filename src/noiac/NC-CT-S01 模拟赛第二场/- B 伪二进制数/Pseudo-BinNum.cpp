#include <iostream>
#include <stdio.h>

using namespace std;

int ori = 0;
int ans;

int main () {

	cin >> ori;

	register bool notfound = true;
	register string mem = "\0";
	for (register int i = 1; notfound ; i++) {
		register char tmp[1000000];
		sprintf(tmp, "%d", ori * i);
		mem = tmp;
		register int len = mem.size();
		register bool right = true;
		// cout << mem << endl;
		for (register int m = 0; m < len && right; m++) {
			if (mem[m] != '0' && mem[m] != '1')
				right = false;
		}
		if (right) {
			notfound = false;
			ans = ori*i;
		}
	}

	cout << ans;

	return 0;

}