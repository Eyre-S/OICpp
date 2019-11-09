/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / /
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)
 *                                   /____/
 * 
 * 【LGR-064】洛谷11月月赛 II & CSG Round 2
 * 
 * 洛谷 - T107143 光骓者的荣耀
 * 链接 https://www.luogu.org/problem/T107143?contestId=23333
 * 作者：Cookie Sukazyo Eyre
 * 
 **/

#include <iostream>

using namespace std;

typedef long long ll;

int node_count;
ll distence[1000001];
ll sum_dist[1000001];
int portal = 0;
ll pass_max = 0;

int main () {
	
	cin >> node_count >> portal;
	ll curr_dist;
	for (register int i = 1; i < node_count; i++) {
		cin >> curr_dist;
		distence[i] = curr_dist;
		sum_dist[i] = sum_dist[i-1] + curr_dist;
	}
	
	// if (portal != 0) {
		
		register ll pass_curr = 0;
		(portal>=node_count) ? (portal=node_count-1) : 0;
		for (register int i = 0; i < node_count - portal; i++) {
			pass_curr = sum_dist[i+portal] - sum_dist[i];
			(pass_curr>pass_max) ? (pass_max=pass_curr) : 0;
		}
		
		// cout << sum_dist[node_count-1] << ' ' << pass_max << endl;
		cout << sum_dist[node_count-1] - pass_max << endl;
		
	// }
	
	// for (register int i = 0; i < node_count; i++) {
	// 	cout << i << '\t';
	// } cout << endl;
	// for (register int i = 0; i < node_count; i++) {
	// 	cout << distence[i] << '\t';
	// } cout << endl;
	// for (register int i = 0; i < node_count; i++) {
	// 	cout << sum_dist[i] << '\t';
	// } cout << endl;
	
	return 0;
	
}