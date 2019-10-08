/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * 洛谷题目 - 模板：最近公共祖先
 * 作者：Cookie Sukazyo Eyre
 * 
 * 使用算法：tarjan
 * 存树类型：图状树
 * 存图类型：数组型邻接表
 * 
 */

#define DEBUG

#ifdef DEBUG
	#define s cout << "HelloWorld" << endl
#else
	#define s
#endif

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

// struct node_unit {
// 	int last_line;
// };
// struct line_unit {
// 	int to_node;
// 	int last_lint;
// };

// node_unit node[10000];
// line_unit line[10000];

// @node_unit
int last_line[10000];

// @line_unit
int to_node[10000];
int link_line[10000];

int node_count = 0;
int ask_times = 0;
int root = 0;

int main () {
	
	cin >> node_count >> ask_times >> root;
	
	memset(last_line, -1, sizeof(last_line));
	memset (to_node, -1 , sizeof(to_node));
	memset(link_line, -1 , sizeof(link_line));
	
	// 输入图状树
	for (register int i = 0, d1, d2; i < node_count - 1; i += 2) {
		cin >> d1 >> d2;
		if (last_line[d1] != -1)
			link_line[i] = last_line[d1];
		last_line[d1] = i;
		to_node[i] = d2;
		if (last_line[d2] != -1)
			link_line[i+1] = last_line[d2];
		last_line[d2] = i+1;
		to_node[i+1] = d1;
	}
	s;
	return 0;
	
}

void tarjan_lca () {
	
}