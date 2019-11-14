/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * platform - subject
 * <link>
 * 
 * 作者：Cookie Sukazyo Eyre
 * 
 */

// #define DEBUG

#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long bign;

// 题目数据
unsigned long long str_hash[10000];
int str_count;
int answer = 0;

// hash常数
unsigned long long base = 131;
unsigned long long mod = 212370440130137957ll;

unsigned long long func_hash (string);

int main () {
	
	cin >> str_count;
	
	string inpu;
	for (register int i = 0; i < str_count; i++) {
		cin >> inpu;
		str_hash[i] = func_hash(inpu);
	}
	
	#ifdef DEBUG
		for (register int i = 0; i < str_count; i++) {
			cout << str_hash[i] << endl;
		}
	#endif
	
	sort(str_hash, str_hash + str_count);
	
	for (register int i = 0; i < str_count; i++) {
		(str_hash[i] != str_hash[i+1]) ? answer++ : 0;
	}
	
	cout << answer << endl;
	
	return 0;
	
}

unsigned long long func_hash (register string s) {
	
	unsigned long long number = 0;
	int len = s.size();
	for (register int i = 0; i < len; i++) {
		number = (number*base + (unsigned long long)s[i]) % mod;
	}
	
	return number;
	
}