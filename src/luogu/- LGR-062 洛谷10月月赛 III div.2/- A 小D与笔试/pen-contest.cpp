/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / /
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)
 *                                   /____/
 * 
 * 【LGR-062】洛谷10月月赛 III div.2
 * 
 * 洛谷 - LGR-062-A 洛谷10月月赛 III div.2
 * 链接 https://www.luogu.org/problem/T104062?contestId=22461
 * 作者：Cookie Sukazyo Eyre
 * 
 **/

#include <iostream>
#include <map>

using namespace std;

int map_count;
map<string, string> answer;

int question_count;

int main () {
	
	cin >> map_count >> question_count;
	
	register string ques, ans, ga, gb, gc, gd;
	for (register int i = 0; i < map_count; i++) {
		cin >> ques >> ans;
		answer[ques] = ans;
	}
	
	for (register int i = 0; i < question_count; i++) {
		cin >> ques >> ga >> gb >> gc >> gd;
		ans = answer[ques];
		if (ans == ga) {
			cout << "A" << endl;
		} else if (ans == gb) {
			cout << "B" << endl;
		} else if (ans == gc) {
			cout << "C" << endl;
		} else {
			cout << "D" << endl;
		}
	}
	
	return 0;
	
}