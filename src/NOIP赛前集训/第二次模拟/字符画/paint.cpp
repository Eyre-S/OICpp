#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int paper[502][502] = {0};
int height = 0, width = 0;
int pen = 0;

int main() {

	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	cin >> height >> width;

	// 相框
	for (register int i = 0; i < height + 2; i++) {
		paper[i][0] = '#';
		paper[i][width + 1] = '#';
	} for (register int i = 0; i < width + 2; i++) {
		paper[0][i] = '#';
		paper[height + 1][i] = '#';
	}
	
	cin >> pen;
	int sx, sy, fx, fy;
	char c;
	int addx = 0, addy = 0, len = 0;
	for (register int n = 0; n < pen; n++) {

		cin >> sx >> sy >> fx >> fy >> c;

		if (!(sx == fx && sy == fy)) {

			// 确定增量
			if (sx == fx) { addx = 0;} else if (sx < fx) { addx = 1;} else { addx = -1;}
			if (sy == fy) { addy = 0;} else if (sy < fy) { addy = 1;} else { addy = -1;}

			// // 确定长度
			// cout << abs(sx - fx)
			// len = abs(sx - fx);
			// if (len < abs(sy - fy)) {
			// 	len = abs(sy - fy);
			// }

			// 书写
			for (register int x = sx, y = sy; !(x == fx && y == fy); x += addx , y += addy) {
				paper[x][y] = c;
			}
		}

		paper[fx][fy] = c;

	}

	// 输出
	for (register int i = 0; i < height + 2; i++) {
		for (register int j = 0; j < width + 2; j++) {
			if (paper[i][j] == 0) {
				cout << ' ';
			} else {
				cout << (char)paper[i][j];
			}
		}
		cout << endl;
	}

	return 0;

}