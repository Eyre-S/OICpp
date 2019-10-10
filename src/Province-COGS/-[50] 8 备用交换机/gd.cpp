/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / /
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)
 *                                   /____/
 *
 *
 * COGS - 备用交换机（求割点裸题）
 * 作者：Cookie Sukazyo Eyre
 *
 * 代码思想：tarjan
 * 存图类型：数组型邻接表
 *
 */

#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

// 城市数
int citiesNum = 0;

int indexs = 1;

// 城市是否重要
bool cut[100]; // 是否为切点

// 图储存
int line[100]; // 节点的最后一条线段
int nextl[10000]; // 线段的邻线段
int to[10000]; // 线段目标节点

// 搜索相关
int dfn[100] = {0};// 搜索ID
int tag[100] = {0}; // 强连通标签
bool alive[10000]; // 线段是否可用（未访问过）
bool checked[100]; // 点是否访问过

// 根节点子树计数
int rootChild = 0; // 根节点子树数量
int root_id = 0; // 根节点的id

// 函数声明
int dfs (int);

int main () {
	
	// 重定向IO
	freopen("gd.in", "r", stdin);
	freopen("gd.out", "w", stdout);
	
	cin >> citiesNum;
	
	// 元素初始化 -1为空
	memset(line, -1, sizeof(line));
	memset(dfn, 0, sizeof(dfn));
	memset(to, -1, sizeof(to));
	memset(nextl, -1, sizeof(nextl));
	
	// 构图
	int ca, cb;
	for (int i = 0; !cin.eof(); i += 2) {
		// 双（无）向边存储存图
		
		cin >> ca >> cb;
		// cout << "Get " << ca << " " << cb << endl;
		ca--;cb--;
		if(line[ca] != -1)
			nextl[i] = line[ca];
		line[ca] = i;
		to[i] = cb;
		if(line[cb] != -1)
			nextl[i+1] = line[cb];
		line[cb] = i+1;
		to[i+1] = ca;
		alive[i] = true;
		alive[i+1] = true;
	}
	
	// for (int i = 0; i < 10000; i++) {
	// 	cout << i << "\t" << to[i] << "\t" << nextl[i] << endl;
	// }
	
	for (register int i = 0; i < citiesNum; i++) {
		if (checked[i] == false) {
			root_id = i; rootChild = 0;
			dfs(i);
			// cout << "Root " << root_id + 1 << " childs " << rootChild << endl;
			if (rootChild > 1) {
				// cout << "Root " << i + 1 << " CUT！" << endl;
				cut[i] = true;
			}
		}
	}
	
	// // cout << "Root " << rootChild << endl;
	// if (rootChild > 1)
	// 	cut[0] = true;
	
	// for (int i = 0; i < citiesNum; i++) {
	// 	cout << i+1 << "\t" << dfn[i] << "\t" << tag[i] << endl;
	// }
	
	// cout << rootSingle << " ";
	
	int counter = 0;
	string listing;
	for (int i = 0; i < citiesNum; i++) {
		if (cut[i] == true) {
			counter++;
		}
	}
	cout << counter << endl;
	for (int i = 0; i < citiesNum; i++) {
		if (cut[i] == true) {
			cout << i + 1 << endl;
		}
	}
	
	return 0;
}

// tarjan搜索主循环
int dfs (int node) {
	
	// cout << "Enter " << node + 1 << endl;
	if(dfn[node] == 0) {
		
		checked[node] = true;
		
		dfn[node] = indexs;
		tag[node] = indexs;
		indexs++;
		
		// cout << " - entered" << " indexd " << dfn[node] << endl;
		int l;
		while ((l = line[node]) != -1) {
			line[node] = nextl[l];
			if (alive[l]) {
				if (node == root_id) {
					// cout << " - Root child found!" << endl;
					rootChild++;
				}
				alive[l] = false;
				if (to[l+1] == node)
					alive[l+1] = false;
				else
					alive[l-1] = false;
				// cout << " - Goto " << to[l] + 1 << endl;
				int childTag = dfs(to[l]);
				if (tag[node] > childTag)
					tag[node] = childTag;
				if (childTag >= dfn[node]) {
					if (node != root_id) {
						// cout << " - Node " << node + 1 << " CUT!" << endl;
						cut[node] = true;
					}
				}
			}
		}
	}
	
	// cout << "left " << node + 1 << " return " << tag[node] << endl;
	
	return tag[node];
	
}