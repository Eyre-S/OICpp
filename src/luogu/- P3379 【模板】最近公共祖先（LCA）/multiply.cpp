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
 * 使用算法：倍增
 * 存树类型：图状树
 * 存图类型：数组型邻接表 起始id-0
 * 
 */

#include <iostream>

using namespace std;

// 单位线
struct line {
	int next; // 线的下一个
	int to; // 
};

struct node {
	int line;
};

int main () {
	
}