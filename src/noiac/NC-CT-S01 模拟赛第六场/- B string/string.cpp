/*
        quu..__
         $$$b  `---.__
          "$$b        `--.                          ___.---uuudP
           `$$b           `.__.------.__     __.---'      $$$$"              .
             "$b          -'            `-.-'            $$$"              .'|
               ".                                       d$"             _.'  |
                 `.   /                              ..."             .'     |
                   `./                           ..::-'            _.'       |
                    /                         .:::-'            .-'         .'
                   :                          ::''\          _.'            |
                  .' .-.             .-.           `.      .'               |
                  : /'$$|           .@"$\           `.   .'              _.-'
                 .'|$u$$|          |$$,$$|           |  <            _.-'
                 | `:$$:'          :$$$$$:           `.  `.       .-'
                 :                  `"--'             |    `-.     \
                :##.       ==             .###.       `.      `.    `\
                |##:                      :###:        |        >     >
                |#'     `..'`..'          `###'        x:      /     /
                 \                                   xXX|     /    ./
                  \                                xXXX'|    /   ./
                  /`-.                                  `.  /   /
                 :    `-  ...........,                   | /  .'
                 |         ``:::::::'       .            |<    `.
                 |             ```          |           x| \ `.:``.
                 |                         .'    /'   xXX|  `:`M`M':.
                 |    |                    ;    /:' xXXX'|  -'MMMMM:'
                 `.  .'                   :    /:'       |-'MMMM.-'
                  |  |                   .'   /'        .'MMM.-'
                  `'`'                   :  ,'          |MMM<
                    |                     `'            |tbap\
                     \                                  :MM.-'
                      \                 |              .''
                       \.               `.            /
                        /     .:::::::.. :           /
                       |     .:::::::::::`.         /
                       |   .:::------------\       /
                      /   .''               >::'  /
                      `',:                 :    .'
                                           `:.:'
         

 首段祭神
*/
#include <iostream>
#include <cstdio>

using namespace std;

string common_str;
int str_len;
int ask_count = 0;

int main () {
	
	cin >> ask_count;
	for (register int timey = 0; timey < ask_count; timey++) {
		// 输入
		cin >> str_len;
		getchar();
		cin >> common_str;
		
		// // INPUT测试
		// cout << common_str << endl;
		
		// 判断初始串是否为回文串
		register int mid_l = 0, mid_r = 0;
		if (str_len % 2 == 0) {
			mid_r = str_len / 2 - 1;
			mid_l = mid_r - 1;
		} else {
			mid_l = str_len / 2;
			mid_r = mid_l;
		}
		register bool all_phrase = true;
		register bool all_equal = true;
		for (register int m = 0; all_phrase; m++) {
			if (common_str[mid_r] != common_str[mid_r+m])
				all_equal = false;
			if (common_str[mid_l-m] != common_str[mid_r+m]) {
				all_phrase = false;
				all_equal = false;
				break;
			} else {
				if (mid_l - m == 0) {
					break;
				}
			}
		}
		
		// 判断是否为不可删除串
		register char sono = common_str[0];
		register char sampa = common_str[1];
		register bool ababa = true;
		for (register int i = 2; i < str_len; i += 2) {
			if (i == str_len - 1) {
				if (common_str[i] != sono) {
					ababa = false;
				}
				break;
			}
			if (common_str[i] != sono && common_str[i+1] != sampa) {
				ababa = false;
				break;
			}
		}
		
		// 输出
		if (!all_phrase) {
			cout << 1 << endl;
			continue;
		} else if (all_equal || ababa) {
			cout << -1 << endl;
			continue;
		} else {
			cout << 2 << endl;
		}
		
	}
	
	return 0;
	
}