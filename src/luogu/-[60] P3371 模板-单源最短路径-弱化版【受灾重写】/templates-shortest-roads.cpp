/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / /
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)
 *                                   /____/
 *
 * 洛谷 - P3371 模板-单源最短路径-弱化版
 * 链接 https://www.luogu.org/problem/P3371
 * 作者：Cookie Sukazyo Eyre
 * 
 * 代码移植源：洛谷 P1828 香甜的黄油 Sweet Butter
 * 
 * 存图类型：数组型邻接表
 * 代码思想：dijkstra
 * 复杂度：O(n^2)
 *
 **/

#include <iostream>
#include <memory.h>

#define DOT_MAX 10000
#define LINE_MAX 500000

using namespace std;

// 题目元数据
int dot_count = 0;
int line_count = 0;
int root = -1;

// 图
int dot_to_line[DOT_MAX];
int line_to[LINE_MAX];
int line_next[LINE_MAX];
int line_len[LINE_MAX];

// 最短路搜索
int shortest[DOT_MAX];
int visited[DOT_MAX];

int main () {
	
	// 图面初始化
	memset(dot_to_line, -1, sizeof(dot_to_line));
	memset(line_next, -1, sizeof(line_next));
	memset(line_to, -1, sizeof(line_to));
	
	// 输入元数据
	cin >> dot_count >> line_count >> root;
	
	// 图写入
	for (register int i = 0, start_dot, end_dot, curr_len; i < line_count; i++) {
		cin >> start_dot >> end_dot >> curr_len;
		if (dot_to_line[start_dot] != -1) {
			line_next[i] = dot_to_line[start_dot];
		}
		dot_to_line[start_dot] = i;
		line_to[i] = end_dot;
		line_len[i] = curr_len;
	}
	
	// // 图输出测试
	// for (register int i = 0; i < dot_count; i++) {
	// 	cout << dot_to_line[i] << '\t';
	// }cout << endl;
	// for (register int i = 0; i < line_count; i++) {
	// 	cout << line_to[i] << '\t';
	// }cout << endl;
	// for (register int i = 0; i < line_count; i++) {
	// 	cout << line_next[i] << '\t';
	// }cout << endl;
	
	// 搜索初始化
	memset(shortest, -1, sizeof(shortest));
	memset(visited, false, sizeof(visited));
	
	shortest[root] = 0;
	
	while (true) {
		
		// for (register int i = 1; i < dot_count + 1; i++) {
		// 	cout << shortest[i] << ' ';
		// }cout << endl;
		// 检索最小边
		register int dot_id = -1;
		for (register int i = 1; i < dot_count + 1; i++) {
			if (visited[i] == false && shortest[i] != -1) {
				if (dot_id == -1 || shortest[dot_id] > shortest[i]) {
					dot_id = i;
				}
			}
		}
		visited[dot_id] = true;
		// cout << "Chose dot " << dot_id << " ROOT" << endl;
		if (dot_id == -1) {
			break;
		}
		// 实现最短路
		while (dot_to_line[dot_id] != -1) {
			register int road_id = dot_to_line[dot_id];
			dot_to_line[dot_id] = line_next[road_id];
			register int curr_len = shortest[dot_id] + line_len[road_id];
			if (shortest[line_to[road_id]] == -1 || shortest[line_to[road_id]] > curr_len) {
				shortest[line_to[road_id]] = curr_len;
			}
		}
	}
	
	for (register int i = 1; i < dot_count + 1; i++) {
		cout << shortest[i] << ' ';
	}
	
}
