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
int line_to[400000];
int line_next[400000];
int line_len[400000];

void add_line (int, int, int, int);

int main () {
	
	memset(node_link, -1, sizeof(node_link));
	memset(line_to, -1, sizeof(line_to));
	memset(line_next, -1, sizeof(line_next));
	
	cin >> node_count >> line_count;
	
	int from, to, len;
	for (register int i = 0; i < line_count; i++) {
		cin >> from >> to >> len;
		add_line(from, to, len, i * 2);
		add_line(to, from, len, i * 2 + 1);
	}
	
	return 0;
	
}

inline void add_line (int from, int to, int len, int id) {
	
	(node_link[from] == -1) ? (line_next[node_link[from]] = id) : 0;
	
	node_link[from] = id;
	line_to[id] = to;
	
	line_len[id] = len;
	
}
