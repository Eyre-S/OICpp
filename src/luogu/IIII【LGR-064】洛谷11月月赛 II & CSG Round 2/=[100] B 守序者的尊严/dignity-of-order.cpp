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
 * 洛谷 - T106050 守序者的尊严
 * 链接 https://www.luogu.org/problem/T106050?contestId=23333
 * 作者：Cookie Sukazyo Eyre
 * 
 * 作者注：本题由于过于简单，直接写完就交了根本没有本地测试
 *        所以不存在 .in .out 文件
 * 
 **/

#include <iostream>

using namespace std;

int curr = 0;
int nex = 0;
int time_last = 1;
int count = 0;

int main () {
	
	cin >> count;
	
	for (register int i = 0; i < count; i++) {
		
		cin >> nex;
		if (nex != curr) {
			time_last++;
			curr = nex;
		}
		
	}
	
	cout << time_last << endl;
	
	return 0;
	
}