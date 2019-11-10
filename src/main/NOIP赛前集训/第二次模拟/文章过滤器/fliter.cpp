#include <iostream>
#include <cstdio>

using namespace std;

int keyAmount = 0;
string keys[50] = "";
int keyLen[50] = {0};
string article = "";
int isKey[15000] = {0};
string articleB;

// 大小写转换
void strlower (string &a) {
    int c = a.size();
    for (int i = 0; i < c; i ++ ) {
        if(isupper(a[i])) {
            a[i] = tolower(a[i]);
        }
    }
}

int main () {

	freopen("fliter.in", "r", stdin);
	freopen("fliter.out", "w", stdout);

	// 读入
	cin >> keyAmount;
	cin.get();
	for (register int i = 0; i < keyAmount; i++) {
		getline(cin, keys[i]);
		keyLen[i] = keys[i].size();
		strlower (keys[i]);
	}

	getline(cin, article);
	articleB = article;
	strlower(article);
	int artLen = article.size();
	bool get = true;

	// 每个屏蔽词执行一次过滤
	for (register int i = 0; i < keyAmount; i++) {
		// cout << "Start " << keys[i] << " fliter..." << endl;
		// 对于文章的每个位置
		for (register int j = 0; j < artLen; j++) {
			// 循环遍历条件
			get = true;
			for (register int m = 0; m < keyLen[i]; m++) {
				// cout << " -Compare " << keys[i][m] << " || " << article[j+m] << endl;
				if (keys[i][m] != article[j+m]) {
					// cout << "   -Breaked..." << endl;
					get = false;
					break;
				}
			}
			if (get) {
				// cout << "   -On " << j << " get!" << endl;
				for (register int l = j; l < keyLen[i] + j; l++) {
					// cout << "     -Set " << l << " false!" << endl;
					isKey[l] = 1;
				}
			}
		}
	}

	//输出
	for (register int i = 0; article[i] != '\0'; i++) {
		if (isKey[i] == 1) {
			putchar('*');
		} else {
			putchar(articleB[i]);
		}
		// cout << isKey[i];
	}

	return 0;

}