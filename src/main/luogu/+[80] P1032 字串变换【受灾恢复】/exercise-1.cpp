#define t

#ifdef t

    #include <iostream>

    using namespace std;

    string article, todo;
    string exchange[6][2];
    int ans = 11;

    void search (string str, int count) {

        for (int i = 0; i < 6; ++i) {

            if (str.find(exchange[i][0]) != string::npos && exchange[i][0] != "\0") {

                str.replace(str.find(exchange[i][0]), exchange[i][0].size(), exchange[i][1]);
                count++;

                if (str != todo && count <= 10) {
                    search(str, count);
                } else if (str == todo && count < ans) {
                    ans = count;
                }

            }

        }

    }

    int main() {

        cin >> article >> todo;

        for (int i = 0; i < 6; ++i) {
            cin >> exchange[i][0] >> exchange[i][1];
        }

        search(article, 0);

        if (ans == 11) {
            cout << "NO ANSWER!";
        } else {
            cout << ans;
        }

        return 0;
    }

#endif