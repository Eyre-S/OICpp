#include <iostream>

using namespace std;

int count;
string matrix[3];
int checkPos[8][3][2] = {
	{{0,0},{0,1},{0,2}},
	{{1,0},{1,1},{1,2}},
	{{2,0},{2,1},{2,2}},
	{{0,0},{1,0},{2,0}},
	{{0,1},{1,1},{2,1}},
	{{0,2},{1,2},{2,2}},
	{{0,0},{1,1},{2,2}},
	{{0,2},{1,1},{2,0}}
};
int checkRes[2];

void dfs (int, int);
void check ();

int main () {

	cin >> count;

	for (int i = 0; i < count; i++) {
		for (register int a = 0; a < 3; a++) {
			cin >> matrix[a];
		}
		if (matrix[0][0] == '.') {
			cout << 0 << endl;
		} else {
			check();
			cout << checkRes[0] - checkRes[1] << endl;
		}
	}



	// for (register int a = 0; a < 3; a++) {
	// 	for (register int b = 0; b < 3; b++) {
	// 		cout << motrix[a][b];
	// 	}
	// 	cout << endl;
	// }

	return 0;

}

void dfs (int px, int py) {



}

void check () {
	// cout << "Running..." << endl;
	char res = '.';
	bool loss = false;
	for (int i = 0; i < 8; i++) {
		loss = false;
		res = '.';
		for (register int m = 0; m < 3 && !loss; m++) {
			if (res == '.') {
				res = matrix[checkPos[i][m][0]][checkPos[i][m][1]];
				// cout << "Get " << matrix[checkPos[i][m][0]][checkPos[i][m][1]] << " start..." << endl;
			} else {
				if (matrix[checkPos[i][m][0]][checkPos[i][m][1]] != res) {
					// cout << " - Get " << matrix[checkPos[i][m][0]][checkPos[i][m][1]] << " breaked!" << endl;
					loss = true;
				}
			}
		}
		if (!loss) {
			// cout << " - Finished |" << res << "| ++" << endl;
			res=='o' ? checkRes[0]+=1 : checkRes[1]+=1;
		}
	}
}