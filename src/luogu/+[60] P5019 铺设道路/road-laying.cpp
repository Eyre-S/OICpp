/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / /
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)
 *                                   /____/
 * 
 * NOIP - 2018提高组 - Day1 T1铺设道路
 * 洛谷 - P5019 铺设道路
 * 链接 https://www.luogu.org/problem/P5019
 * 作者：Cookie Sukazyo Eyre
 *
 **/

// #define DEBUG

#include <iostream>

using namespace std;

int road_len = 0; // 路长度
int road[100000] = {0}; // 单位上的深度
int work_times = 0; // 工作次数

int main () {
	
	// 输入
	cin >> road_len;
	for (register int i = 0; i < road_len; i++) {
		cin >> road[i];
	}
	
	register int total_zero = 0; // 已经平坦的数量
	
	for (register int i = 0; i < road_len; i++) {
		if (road[i] == 0) {
			#ifdef DEBUG
				cout << "Prefind zero at " << i << endl;
			#endif
			total_zero++;
		}
	}
	
	while (total_zero != road_len) {
		// 对每个路段检查
		for (register int i = 0, start = 0, min = 34748, now_zero = 0; i < road_len; i++) {
			// 修复开头为0时的工作段统计错误
			if (i == 0) {
				while (road[i] == 0 && i < road_len) {
					#ifdef DEBUG
						cout << "Find zero at " << i << " and i++" << endl;
					#endif
					i++;
				} start = i;
			}
			// cout << min << endl;
			// 如果存在工作段
			if (road[i] == 0 /* 部分路段 */|| i == road_len - 1 /* 全部路段 */) {
				if (i == road_len - 1) {
					// 对全部路段进行特殊处理
					if (road[i] < min) {
						// 找到最小值
						min = road[i];
						now_zero = 1;
						#ifdef DEBUG
							cout << "Resize zero" << endl;
						#endif
					}
					i++;
				}
				#ifdef DEBUG
					cout << "Find workspace from " << start << " to " << i - 1 << endl;
				#endif
				// 循环铺平路段
				for (register int p = start; p < i; p++) {
					road[p] -= min;
				}
				// 记录本次工作
				work_times += min;
				total_zero += now_zero;
				#ifdef DEBUG
					cout << " - Zero add " << now_zero << " to " << total_zero << endl;
					cout << " - ";for (register int p = 0; p < road_len; p++) {
						cout << road[p] << ' ';
					}cout << endl;
					cout << " - Worked " << work_times << endl;
				#endif
				// 初始化下次要用的值
				while (road[i] == 0 && i < road_len) {
					i++;
				} start = i; i--;
				min = 10001; now_zero = 0;
				#ifdef DEBUG
					cout << " - " << start << ' ' << i << endl;
				#endif
			} else if (road[i] < min) {
				// 找到最小值
				min = road[i];
				now_zero = 1;
				#ifdef DEBUG
					cout << "Resize zero" << endl;
				#endif
			} else if (road[i] == min) {
				// 找到和最小值同样的值
				now_zero++;
				#ifdef DEBUG
					cout << " - Zero++ to " << now_zero << endl;
				#endif
			}
		}
		// cout << total_zero << endl;
	}
	
	#ifdef DEBUG
		for (register int i = 0; i < road_len; i++) {
			cout << road[i] << ' ';
		}cout << endl;
	#endif
	
	cout << work_times << endl;
	
	return 0;
	
}
