/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * 洛谷 - P1307 数字反转
 * 链接：https://www.luogu.org/problem/P1307
 * 作者：Cookie Sukazyo Eyre
 * 
 */

#include <cstdio>

using namespace std;

bool is_number(char);

char str[11] = "";

int main () {
	
	register char curr;
	register int point = 10;
	register int count = 0;
	do {
		point--;
		curr = getchar();
		str[point] = curr;
		count++;
	} while (is_number(curr));
	
	register bool negative = false;
	if (str[9] == '-') {
		negative = true;
		putchar('-');
	}
	
	register int last = (negative?8:9);
	register bool start = true;
	for (register int i = 10 - count + 1;i <= last;i++) {
		if (!(str[i] == '0' && i != last && start)) {
			putchar(str[i]);
			start = false;
		}
	}
	
	return 0;
	
}

bool is_number (char curr) {
	register bool state;
	((curr >= '0' && curr <= '9')||curr == '-') ? state = true : state = false;
	return state;
}