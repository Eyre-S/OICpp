#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

string word = "";
string article = "";
int first = -1;
int count = 0;

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
    // 输入
    cin >> word;
    getchar();
    getline(cin, article);

    // 转码
    strlower(word);
    strlower(article);
    word.push_back(' ');

    // cout << word << endl << article << endl;

    int len = article.size();
    int wlen = word.size() - 1;
    for (register int i = 0; i < len; i++) {
        if (article[i-1] == ' ' || i == 0) {
            bool is = true;
            for (register int j = 0; j <= wlen; i++,j++) {
                // cout << "Compare " << article[i] << " || " << word[j] << endl;
                if (article[i] != word[j]) {
                    if ( word[j] == ' ' && article[i] == '\0') {
                        // cout << " -Special end" << endl;
                        continue;
                    }
                    is = false;
                    // cout << " -Breaked..." << endl;
                    break;
                }
            }
            if (is == true) {
                count++;
                if (first == -1) {
                    first = i - wlen - 1;
                }
                i--;
                // cout << " -On " << i - wlen << " get!" << endl;
            }
        }
    }

    if (first == -1) {
        cout << "-1" << endl;
    } else {
        cout << count << " " << first;
    }

    return 0;
}