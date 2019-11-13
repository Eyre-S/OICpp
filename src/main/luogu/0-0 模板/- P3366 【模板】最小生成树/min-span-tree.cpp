/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * 洛谷 - P3366 【模板】最小生成树
 * <https://www.luogu.org/problem/P3366>
 * 
 * 作者：Cookie Sukazyo Eyre
 * 
 */

#include <iostream>
#include <memory.h>

using namespace std;

int node_count;
int line_count;

int node_link[5000];
int node_tag[5000];
int line_to[400000];
int line_next[400000];
int line_len[400000];

int unvisit[400000];

int linked_len = 0;
int tag_tie = 1;

void add_line (int, int, int, int);

int main () {
	
	cin >> node_count >> line_count;
	
	memset(node_link, -1, sizeof(node_link));
	memset(line_to, -1, sizeof(line_to));
	memset(line_next, -1, sizeof(line_next));
	// memset(unvisit, 1, sizeof(unvisit));
	memset(node_tag, -1, sizeof(node_tag));
	for (register int i = 0; i < line_count * 2; i++) {
		unvisit[i] = true;
	}
	
	
	int from, to, len;
	for (register int i = 0; i < line_count; i++) {
		cin >> from >> to >> len;
		add_line(from, to, len, i * 2);
		add_line(to, from, len, i * 2 + 1);
	}
	
	register int min_id;
	// register int id = -1;
	for (register int i = 0; i < node_count - 1; i++) {
		// 初始化/恢复数据
		min_id = -1;
		// // 生成id
		// id = i * 2;
		// 检索最小边
		for (register int m = 0; m < line_count; m++) {
			// if (unvisit[m*2]) {
			// 	if (min_id == -1 || line_len[m*2] < line_len[min_id]) {
			// 		min_id = m*2;
			// 	}
			// }
			(unvisit[m*2] && (min_id == -1 || line_len[m*2] < line_len[min_id])) ? min_id = m*2 : 0;
		}
		unvisit[min_id] = false;
		// 判断边是否添加
		if (!(line_to[min_id] == line_to[min_id+1] && node_tag[line_to[min_id]])) {
			linked_len += line_len[min_id];
			#ifdef DEBUG 
				cout << "find line "<< min_id << " to add as len " << line_len[min_id] << endl;
			#endif
			if (node_tag[line_to[min_id]] == -1) {
				if (node_tag[line_to[min_id+1]] == -1) {
					#ifdef DEBUG
						cout << "AAA" << endl;
					#endif
					node_tag[line_to[min_id]] = tag_tie;
					node_tag[line_to[min_id+1]] = tag_tie;
					#ifdef DEBUG
						cout << "A " << node_tag[line_to[min_id]] << " B " << node_tag[line_to[min_id+1]] << endl;
					#endif
					tag_tie++;
				} else {
					#ifdef DEBUG
						cout << "ABB" << endl;
					#endif
					node_tag[line_to[min_id]] = node_tag[line_to[min_id+1]];
				}
			} else {
				if (node_tag[line_to[min_id+1]] == -1) {
					#ifdef DEBUG
						cout << "ABB" << endl;
					#endif
					node_tag[line_to[min_id+1]] = node_tag[line_to[min_id]];
				} else {
					#ifdef DEBUG
						cout << "BBB" << endl;
					#endif
					// tag_change(line_to[min_id], node_tag[line_to[min_id+1]]);
					register int from = node_tag[line_to[min_id+1]], to = node_tag[line_to[min_id]];
					for (register int m = 0; m < node_count; m++) {
						node_tag[m] == from ? node_tag[m] = to : 0;
					}
				}
			}
		}
	}
	
	cout << linked_len << endl;
	
	return 0;
	
}

inline void add_line (int from, int to, int len, int id) {
	
	(node_link[from] == -1) ? (line_next[node_link[from]] = id) : 0;
	
	node_link[from] = id;
	line_to[id] = to;
	
	line_len[id] = len;
	
}
