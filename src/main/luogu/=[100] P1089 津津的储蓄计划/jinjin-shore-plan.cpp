/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / /
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)
 *                                   /____/
 * 
 * 【恢复题目】
 * 
 * 洛谷 - P1089 津津的储蓄计划
 * 链接 https://www.luogu.org/problem/P1089
 * 作者：Cookie Sukazyo Eyre
 * 
 **/

#include <iostream>

using namespace std;

int main() {

	int money = 0;
	int stage = 0;
	int result = 0;
	int monthOut;

	for (int month = 1; month < 13; month++) {

		money += 300;
		cin >> monthOut;

		money -= monthOut;
		if (money < 0 && result == 0) {
			result = month * -1;
		}

		if (money > 100) {

			stage += money - (money % 100);
			money %= 100;

		}
	}
	if (result == 0) {
		result = money + stage * 1.2;
	}
	cout << result;

	return 0;
	
}