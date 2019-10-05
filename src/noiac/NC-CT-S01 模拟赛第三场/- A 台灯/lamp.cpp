#include <iostream>

using namespace std;

// 询问次数
int T = 0;
// 灯的数量
int num = 0;

// 灯属性
int light[6];	// 常亮时间
int power[6];	// 充电

int lasting[6];	// 本状态持续/剩余时间
bool lighting[6];	// 是否常亮中

int tick = 0;	// 已常亮时间

void work();

int main () {

	cin >> T;
	// cout << T << endl;

	for (register int i = 0; i < T; i++) {
	// 	// cin >> num;
	// 	// // cout << num << endl;
	// 	// if (num == 0) {
	// 	// 	cout << 0 << endl;
	// 	// } else if (num == 1) {
	// 	// 	cin >> light[0] >> power[0];
	// 	// 	// cout << light[0] << power[0] << endl;
	// 	// 	cout << light[0] << endl;
	// 	// } else if (num == 2) {
	// 	// 	cin >> light[0] >> power[0] >> light[1] >> power[1];
	// 	// 	// cout << light[0] << power[0] << light[1] << power[1];
	// 	// 	lightTime = light[0] + light[1];
	// 	// 	if (power[0] <= light[1]) {
	// 	// 		lightTime += light[0];
	// 	// 		if (power[1] <= light[0]) {
	// 	// 			cout << "INF" << endl;
	// 	// 			continue;
	// 	// 		}
	// 	// 	}
	// 	// 	cout << lightTime << endl;
	// 	// }

		// 原始数据输入
		cin >> num;
		for (register int i = 0; i < num; i++) {
			cin >> light[i] >> power[i];
		}

		work();

		// 输出结果
		if (tick == -1) {
			cout << "INF" << endl;
		} else {
			cout << tick << endl;
		}
	}

	return 0;

}

void work () {

	// 寻找充电时间最短做根
	register int root = 0;
	for (register int id = 1; id < num; id++) {
		if (power[root] > power[id])
			root = id;
	}

	register bool death = false;
	register bool first = true;
	for (tick = 0; tick != -1 && !death; tick++) {
		if (tick == 0) {
			lighting[root] = true;
			lasting[root] = light[root];
			continue;
		}
		register bool change = false;
		for (register int id = 0; id < num; id++) {
			// 充电状态处理
			if (!lighting[id] && lasting[id] > 0) {
				lasting[id]--;				
			// 常亮状态处理
			} else if (lighting[id]) {
				lasting[id]--;
				// 电量耗尽处理
				if (lasting == 0) {
					change = true;
					lighting[id] = false;
					lasting[id] = power[id];
				}
			}
		}
		// 更换电灯处理
		if (change) {
			register int changeId = -1;
			register int freeNum = 0;
			// 寻找充电时间最短
			for (register int id = 0; id < num; id++) {
				if (changeId == -1 && lasting[id] == 0) {
					changeId = id;
					freeNum++;
				} else if (lasting[id] == 0 && power[changeId] > power[id]) {
					changeId = id;
					freeNum++;
				}
			}
			if (changeId == -1) {
				death = true;
			} else if (freeNum == num - 1) {
				if (first) {
					first = false;
				} else {
					tick = -1;
				}
			}
			lighting[changeId] = true;
			lasting[changeId] = light[changeId];
		}
	}
}