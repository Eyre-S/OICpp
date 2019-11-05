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

// 函数定义：是否为数字组成部分
bool is_number(char);

/** 
 * 数字处理单元
 * 这里存放的数字为一种特殊格式：
 *  - 如果为负数，则第9位为 '-'
 *  - 从最后的一个空余位数开始向前按位存储数
 *     - 数为从前向后读为正序
 */
char str[11] = "";

int main () {
	
	// 当前所输入的字符
	register char curr;
	// 当前字符的位置
	register int point = 10;
	// 输入字符数量
	register int count = 0;
	// 倒序输入字符
	do {
		point--;
		curr = getchar();
		str[point] = curr;
		count++;
	} while (is_number(curr));
	
	// 输入的数是否为负
	register bool negative = false;
	// 检查是否为负值
	if (str[9] == '-') {
		negative = true;
		putchar('-');
	}
	
	// 最后一个数字位置
	register int last = (negative?8:9);
	// 是否已经开始输出数字
	register bool start = true;
	// 从第一个存数位开始向后遍历输出，至最后一个存数位
	for (register int i = 10 - count + 1;i <= last;i++) {
		if (!(start && str[i] == '0' && i != last)) { // 如果开始为0则忽略输出
			putchar(str[i]);
			start = false;
		}
	}
	
	return 0;
	
}

/**
 * 是否为数字的组成部分
 *  - 用于检查一个字符是否为数字的组成部分
 *  - 这里狭义的 组成数字的字符 是且仅是一下之一：
 *     - {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, -}
 * 
 * @param curr 待检查的数字
 */
bool is_number (char curr) {
	register bool state;
	((curr >= '0' && curr <= '9')||curr == '-') ? state = true : state = false;
	return state;
}