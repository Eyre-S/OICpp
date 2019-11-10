#include <iostream>

using namespace std;

bool space[20001][20001];
int dim = 0;
int dotNum = 0;

int change = 0;

int getLink (int);

int main () {

	cin >> dotNum >> dim;

	register int posx;
	register int posy = 0;
	for (register int i = 0; i < dotNum; i++) {
		// 输入
		if (dim == 1) {
			cin >> posx;
			posx += 10000; posy = 10000;
		} else {
			cin >> posx >> posy;
			posx += 10000; posy += 10000;
		}
		if (space[posx][posy]) {
			change--;
		}
		space[posx][posy] = true;

		// 处理
		if (!space[getLink(posx)][getLink(posy)]) {
			space[getLink(posx)][getLink(posy)] = true;
			change++;
		}
	}

	cout << change << endl;
	// for (register int i = 0; i < 20001; i++) {
	// 	if (i == 10000) {
			// cout << '-';
	// 	} else {
	// 		cout << space[i];
	// 	}
	// }

	return 0;
}

inline int getLink (int original) {
	return 20000 - original;
}