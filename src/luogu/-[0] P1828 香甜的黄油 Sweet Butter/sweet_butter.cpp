/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / /
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)
 *                                   /____/
 *
 * 洛谷 - P1828 香甜的黄油 Sweet Butter
 * 链接 https://www.luogu.org/problem/P1828
 * 作者：Cookie Sukazyo Eyre
 * 
 * 存图类型：数组型邻接表
 *
 **/

#include <iostream>
#include <memory.h>

#define FARM_MAX 800 // 农场最大量
#define ROAD_MAX 1450 // 道路最大量

using namespace std;

void shortest_path(int);

int cow_count; // 奶牛数量
int farm_count; // 农场数量
int road_count; // 道路数量

int cow_in_farm[FARM_MAX]; // 每个农场中的奶牛数
int road_distance[ROAD_MAX * 2]; // 路的长度

// 牧场地图
int farm_road[FARM_MAX];
int road_to[ROAD_MAX * 2];
int road_next[ROAD_MAX * 2];

int path_sum = -1; // 当前最短牧场时的总行走值
int curr_farm; // 当前牧场

int shortest[FARM_MAX]; // 从当前开始的最短路径
bool searched[FARM_MAX]; // 牧场是否已被搜索

int main () {
	
	// 数据初始化
	memset(farm_road, -1, sizeof(farm_road));
	memset(road_to, -1, sizeof(road_to));
	memset(road_next, -1, sizeof(road_next));
	
	cin >> cow_count >> farm_count >> road_count;
	
	// for (register int i = 0; i < FARM_MAX; i++) {
	// 	cout << farm_road[i] << ' ';
	// }
	
	for (register int i = 0, cow; i < cow_count; i++) {
		cin >> cow;
		cow_in_farm[cow]++;
	}
	
	for (register int i = 0, id = 0, px, py, len; i < road_count; i++, id += 2) {
		cin >> px >> py >> len;
		px--; py--;
		// cout << px << py << len << endl;
		if (farm_road[px] != -1)
			road_next[id] = farm_road[px];
		farm_road[px] = id;
		road_to[id] = py;
		if (farm_road[py] != -1)
			road_next[id+1] = farm_road[py];
		farm_road[py] = id+1;
		road_to[id] = px;
		road_distance[id] = len;
		road_distance[id + 1] = len;
	}
	
	// 图输出测试
	for (register int i = 0; i < farm_count; i++) {
		cout << farm_road[i] << '\t';
	}cout << endl;
	for (register int i = 0; i < road_count; i++) {
		cout << road_to[i] << '\t';
	}cout << endl;
	for (register int i = 0; i < road_count; i++) {
		cout << road_next[i] << '\t';
	}cout << endl;
	
	for (register int i = 0; i < farm_count; i++) {
		
		shortest_path(i);
		
		for (register int i = 0; i < farm_count; i++) {
			cout << shortest[i] << ' ';
		} cout << endl;
		
		register int sum = 0;
		for (register int m = 0; m < farm_count; m++) {
			sum += shortest[m] * cow_in_farm[m];
		}
		
		if (path_sum == -1 || path_sum > sum) {
			path_sum = sum;
			curr_farm = i;
		}
		
	}
	
	cout << curr_farm + 1 << endl;
	
	return 0;
	
}

void shortest_path (int root) {
	
	// 初始化
	memset(shortest, -1, sizeof(shortest));
	memset(searched, false, sizeof(searched));
	
	shortest[root] = 0;
	
	while (true) {
		// 检索最小边
		register int farm_id = -1;
		for (register int i = 0; i < farm_count; i++) {
			if (searched[i] == false && shortest[i] != -1) {
				if (farm_id == -1 || shortest[farm_id] > shortest[i]) {
					farm_id = i;
				}
			}
		}
		cout << "Root " << farm_id << endl;
		searched[farm_id] = true;
		if (farm_id == -1) {
			break;
		}
		// 实现最短路
		while (farm_road[farm_id] != -1) {
			register int road_id = farm_road[farm_id];
			farm_road[farm_id] = road_next[road_id];
			register int curr_len = shortest[farm_id] + road_distance[road_id];
			if (shortest[road_to[road_id]] == -1 ||shortest[road_to[road_id]] > curr_len) {
				shortest[road_to[road_id]] = curr_len;
			}
		}
	}
	
}
