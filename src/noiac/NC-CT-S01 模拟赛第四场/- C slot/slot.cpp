#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

struct map {
	int id;
	double value;
};

int turns = 0;
vector<vector<int> > slots;
map possibility[100000];
int possi_at[100000];

bool cmp (map, map);

int main () {
	
	register vector<int> empty;
	register int slots_count;
	register int balls_count;
	register int ball_tag;
	register double tag_possi;
	register int count_in_slot[100000];
	
	// 初始化
	for (register int i = 0; i < 100000; i++) {
		possibility[i].id = i;
		possibility[i].value = 0;
	}
	memset(possi_at, 100, sizeof(possi_at));
	// memset(possibility, 0, sizeof(possibility));
	// // memset检查
	// for (register int i = 0; i < 10000; i++) {
	// 	cout << possibility[i] << endl;
	// }
	
	cin >> turns;
	for (register int times = 0; times < turns; times++) {
		
		// 输入老虎机
		cin >> slots_count;
		for (register int i = 0; i < slots_count; i++) {
			
			// 初始化要用到的内容
			memset(count_in_slot, 0, sizeof(count_in_slot));
			// 添加老虎机
			slots.push_back(empty);
			// cout << "Add slot:" << i << endl;
			cin >> balls_count;
			for (register int j = 0; j < balls_count; j++) {
				// 添加球
				cin >> ball_tag;
				// cout << "Add tag:" << ball_tag << endl;
				ball_tag--;
				slots[i].push_back(ball_tag);
				// 计算并记录可能性
				count_in_slot[ball_tag]++;
				tag_possi = count_in_slot[ball_tag] * 1.0 / balls_count;
				if (possibility[ball_tag].value < tag_possi/* || possibility[ball_tag].value == 0*/) {
					possibility[ball_tag].value = tag_possi;
					possi_at[ball_tag] = i;
				}
			}
		}
		
		sort(possibility, possibility + 100000, cmp);
		
		for (register int i = 0; i < 1000; i++) {
			cout << possibility[i].value << endl;
		}
		
	}
	
	return 0;
	
}

bool cmp (map a, map b) {
	if (a.value == 0)
		a.value = 2;
	if (b.value == 0)
		b.value = 2;
	return a.value < b.value;
}