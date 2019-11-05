/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * 洛谷 - P5594 【XR-4】模拟赛
 * 链接：https://www.luogu.org/problem/P5594
 * 作者：Cookie Sukazyo Eyre
 * 
 */

#include <iostream>

using namespace std;

// 成员数量
int person_count;
// 比赛数量
int game_count;
// 持续天数
int day_count;
// 在第？天是否有第？场比赛
bool exercise[1000][1000];

int main () {
	
	cin >> person_count >> game_count >> day_count;
	
	int day = 0;
	for (register int p = 0; p < person_count; p++) {
		for (register int game = 0; game < game_count; game++) {
			cin >> day;
			exercise[day - 1][game] = true;
		}
	}
	
	int curr_game = 0;
	for (register int day = 0; day < day_count; day++) {
		curr_game = 0;
		for (register int game = 0; game < game_count; game++) {
			if (exercise[day][game] == true) {
				curr_game++;
			}
		}
		cout << curr_game << ' ';
	}cout << endl;
	
	return 0;
	
}
