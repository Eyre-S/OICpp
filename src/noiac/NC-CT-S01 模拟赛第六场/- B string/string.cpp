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
			mid_l = str_len / 2 - 1;
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
		if (!all_phrase) {
			goto out_time;
		}
		
		// 判断是否为不可删除串
		if (all_equal)
			goto out_time;
		
		// 输出
		out_time:
		if (!all_phrase) {
			cout << 1 << endl;
			continue;
		} else if (
			(str_len == 2 && common_str[0] == common_str[1]) ||
			(str_len == 3 && (
				common_str[0] == common_str[2] ||
				common_str[1] == common_str[2]
			))
		) {
			cout << -1 << endl;
			break;
		} else {
			cout << 2 << endl;
		}
		
	}
	
	return 0;
	
}