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
 * 作者：zfy（赵范佑）
 * 格式化：Cookie Sukazyo Eyre
 * 注释：Cookie Sukazyo Eyre
 * 
 * 代码思想：tarjan
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// 序列id
int len1, len2;

/**
 * 单个线段的储存
 */
struct node1 {
	int x, y, nest;
} b1[5000010];

/**
 * 单个询问的储存
 */
struct node2 {
	int x, y, nom, nest;
} b2[5000010];

int last1[5000010], last2[5000010], f[5000010], ans[5000010], v[5000010];

/**
 * 往图上加入一条链接x, y的边
 * 
 * @param x 起始点
 * @param y 结束点
 */
void ints1(int x, int y) {
	b1[++len1].x = x;
	b1[len1].y = y;
	b1[len1].nest = last1[x];
	last1[x] = len1;
}

/**
 * 添加一个查寻
 * 
 * @param x 查寻起始节点
 * @param y 目标查询节点
 * @param z 本查询的序列id
 */
void ints2(int x, int y, int z) {
	b2[++len2].x = x;
	b2[len2].y = y;
	b2[len2].nest = last2[x];
	b2[len2].nom = z;
	last2[x] = len2;
}

int find(int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

void dfs(int x) {
	v[x] = 1;
	f[x] = x;
	for (int i = last2[x]; i; i = b2[i].nest) {
		int y = b2[i].y;
		if (v[y] == 1)
			ans[b2[i].nom] = find(y);
	}
	for (int i = last1[x]; i; i = b1[i].nest) {
		if (v[b1[i].y] == 0) {

			dfs(b1[i].y);
			f[b1[i].y] = x;
		}
	}
}

int main() {
	
	// 数组初始化
	memset(v, 0, sizeof(v));
	memset(last1, 0, sizeof(last1));
	memset(last2, 0, sizeof(last2));
	
	// 基础数据：n-树的结点个数 m-询问个数 s-树根结点的序号
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	
	// 输入图
	int x, y;
	for (int i = 1; i < n; i++) {
		f[i] = i;
		scanf("%d %d", &x, &y);
		ints1(x, y);
		ints1(y, x);
	}
	
	// 输入询问
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		ints2(x, y, i);
		ints2(y, x, i);
	}
	
	// 执行主循环
	dfs(s);
	
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
		
	return 0;
	
}