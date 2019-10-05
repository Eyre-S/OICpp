#include <iostream>
#include <cstdio>

using namespace std;

struct loc {
	int px;
	int py;
	
	loc() {}
	loc(int ax, int ay) {
		px = ax;
		py = ay;
	}
};

int ask_count = 0;

loc position;

loc dir_get (loc);

int list4[9][9] = {
	{4, 3, 2, 3, 2, 3, 2, 3, 4},
	{3, 2, 3, 2, 3, 2, 3, 2, 3},
	{2, 3, 4, 1, 2, 1, 4, 3, 2},
	{3, 2, 1, 2, 3, 2, 1, 2, 3},
	{2, 3, 2, 3, 0, 3, 2, 3, 2},
	{3, 2, 1, 2, 3, 2, 1, 2, 3},
	{2, 3, 4, 1, 2, 1, 4, 3, 2},
	{3, 2, 3, 2, 3, 2, 3, 2, 3},
	{4, 3, 2, 3, 2, 3, 2, 3, 4},
};

int main () {
	
	cin >> ask_count;
	register loc horse;
	register int distance = 0;
	long long step = 0;
	register long long r;
	register loc dis;
	for (int i = 0; i< ask_count; i++) {
		
		horse.px = 0, horse.py = 0;
		
		cin >> position.px >> position.py;
		
		for (r = 0; horse.px != position.px || horse.py != position.py; r++) {
			dis = loc(position.px-horse.px, position.py-horse.py);
			if (dis.px < 5 && dis.py < 5 && dis.px > -5 && dis.py > -5)
				break;
			loc dir = dir_get(dis);
			// printf("#%d : Horse from (%d, %d) go %d, %d. ", r, horse.px, horse.py, dir.px, dir.py);
			horse.px += dir.px; horse.py += dir.py;
			// printf("Now at (%d, %d)\n", horse.px, horse.py);
		}
		
		// step = r;
		// printf("%d, %d\n", dis.px, dis.py);
		// printf("%d\n", list4[dis.px+4][dis.py+4]);
		
		r += list4[dis.px+4][dis.py+4];
		
		step = r;
		cout << step << endl;
		
	}
	
	return 0;
	
}

loc dir_get (loc location) {
	if (location.px > 0) {
		if (location.py > 0) {
			if (location.px > location.py) {
				return loc(2, 1);
			} else {
				return loc(1, 2);
			}
		} else {
			if (location.px > 0 - location.py) {
				return loc(2, -1);
			} else {
				return loc(1, -2);
			}
		}
	} else {
		if (location.py > 0) {
			if (0 - location.px > location.py) {
				return loc(-2, 1);
			} else {
				return loc(-1, 2);
			}
		} else {
			if (0 - location.px > 0 - location.py) {
				return loc(-2, -1);
			} else {
				return loc(-1, -2);
			}
		}
	}
}
