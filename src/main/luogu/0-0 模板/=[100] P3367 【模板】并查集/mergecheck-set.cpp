/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * 洛谷 - P3367 【模板】并查集
 * <https://www.luogu.org/problem/P3367>
 * 
 * 作者：Cookie Sukazyo Eyre
 * 
 */

#include <iostream>
// #include <list>

using namespace std;

int element_count;
int action_set;

int node_father[10000];

void link (int, int);
bool check (int, int);
int father (int);

int main () {
	
	#ifdef DEBUG
		cout << "HELLO WORLD!" << endl;
	#endif
	
	cin >> element_count >> action_set;
	
	for (register int i = 0; i < element_count; i++) {
		node_father[i] = i;
	}
	
	int act, one, another;
	for (register int i = 0; i < action_set; i++) {
		cin >> act >> one >> another;
		if (act == 1) {
			link(one-1, another-1);
		} else {
			cout << (check(one-1, another-1)?'Y':'N') << endl;
		}
	}
	
	return 0;
	
}

void link (int first, int second) {
	node_father[father(second)] = father(first);
}

inline bool check (int a, int b) {
	return (father(a) == father(b)) ? true : false;
}

int father(int id) {
	return node_father[id] == id ? id : node_father[id] = father(node_father[id]);
}