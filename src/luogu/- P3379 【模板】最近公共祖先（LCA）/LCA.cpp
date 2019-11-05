/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * 洛谷 - P3379 【模板】最近公共祖先（LCA）
 * 链接：https://www.luogu.org/problem/P3379
 * 作者：Cookie Sukazyo Eyre
 * 
 * 使用算法：tarjan
 * 存树类型：图状树
 * 存图类型：数组型邻接表 起始id-0
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

/** 图的储存 */
int last_line[1000000]; // 点连接的最后一条边
int to_node[1000000]; // 边指向的点
int link_line[1000000]; // 边的下一条边

/** 询问的储存 */
// 询问关系
int ask_link[1000000]; // 点->边
int ask_for[1000000]; // 边->点
int ask_about[1000000]; // 边->边
int ask_id[1000000]; // 对应元数据id
bool avaliable[1000000]; // 边是否可访问
// 询问元数据
int ask_line1[500000];
int ask_line2[500000];
int answer[500000];

int node_count = 0;
int ask_times = 0;
int root = 0;

int main () {
	
	cin >> node_count >> ask_times >> root;
	
	memset(last_line, -1, sizeof(last_line));
	memset (to_node, -1 , sizeof(to_node));
	memset(link_line, -1 , sizeof(link_line));
	memset(ask_about, -1, sizeof(ask_about));
	memset(ask_for, -1, sizeof(ask_for));
	memset(ask_link, -1, sizeof(ask_link));
	
	
	// 输入图状树
	for (register int i = 0, d1, d2; i < node_count * 2 - 1; i += 2) {
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
	
	// 输入询问
	for (register int i = 0, d1, d2, fd; i < ask_times; i++) {
		fd = i * 2;
		cin >> d1 >> d2;
		ask_line1[fd]; ask_line2[fd+1];
		if (ask_link[d1] != -1)
			ask_about[fd] = ask_link[d1];
		// last
	}
	
	return 0;
	
}

void tarjan_lca () {
	
	
	
}