#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int num = 0;
int quesNum = 0;
vector<int> vecArray[3];
multiset<int> ansList;

int check(int, int);

int main () {

	cin >> num >> quesNum;
	for (int i = 0; i < 3; i++) {
		register int tmp = 0;
		for (register int m = 0; m < num; m++) {
			cin >> tmp;
			vecArray[i].push_back(tmp);
		}
	}

	for (register int i = 0; i < num; i++) {
		for (register int j = 0; j < num; j++) {
			for (register int k = 0; k < num; k++) {
				ansList.insert(vecArray[0][i]^vecArray[1][j]^vecArray[2][k]);
			}
		}
	}

	register int ques = 0;

	for (int i = 0; i < quesNum; i++) {
		cin >> ques;
		cout << check(ques, INT_MIN) << endl;
	}

	return 0;
}


int check (int level, int father) {
	level - ansList.count(father);
	if (level > 0) {
		return check (level, *(ansList.upper_bound(father + 1)));
	} else {
		return father;
	}
} 