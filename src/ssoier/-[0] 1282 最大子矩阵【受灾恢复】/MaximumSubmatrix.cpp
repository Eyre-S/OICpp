#include <iostream>
#include <cstdio>
// #define DEBUG

using namespace std;

int main(int argc, char const *argv[]) {

	// 定义矩阵
	int size = 0;
	// cin >> size;
	scanf("%d",&size);
	int matrix[size][size];

	// 输入矩阵
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			// cin >> matrix[i][j];
			scanf("%d", &matrix[i][j]);
		}
	}

	// #ifdef DEBUGx
	// 	cout << "打印矩阵" << endl;
	// 	for (int i = 0; i < size; ++i) {
	// 		for (int j = 0; j < size; ++j) {
	// 			cout << matrix[i][j] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// #endif

	// #ifdef DEBUGx
	// 	cout << "矩阵部分求和" << endl;
	// 	int sum = 0;
	// 	int sX = 0;
	// 	int sY = 0;
	// 	int fX = 3;
	// 	int fY = 2;
	// 	for (int i = sX; i < fX; ++i) {
	// 		for (int j = sY; j < fY; ++j) {
	// 			sum += matrix[i][j];
	// 		}
	// 	}
	// 	cout << sum << endl << endl;
	// #endif

	// 求矩阵坐标和
	register int sumMatrix[size][size];
	for (register int i = 0; i < size; ++i) {
		for (register int j = 0; j < size; ++j) {
			// 求和
			register int sum = 0;
			for (register int in = 0; in <= i; ++in) {
				for (register int jn = 0; jn <= j; ++jn) {
					sum += matrix[in][jn];
				}
			}
			sumMatrix[i][j] = sum;
		}
	}
	// #ifdef DEBUGx
	// 	cout << "坐标和矩阵" << endl;
	// 	for (int i = 0; i < size; ++i) {
	// 		for (int j = 0; j < size; ++j) {
	// 			cout << sumMatrix[i][j] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// #endif

	// 循环求子矩阵大小
	int max = 0;
	// 起始点
	for (register int i = 0; i < size; ++i) {
		for (register int j = 0; j < size; ++j) {
			// 结束点
			for (register int ix = i; ix < size; ++ix) {
				for (register int jx = j; jx < size; ++jx) {
					register int imax = sumMatrix[ix][jx] - sumMatrix[i][j];
					if (imax > max) {
						max = imax;
					}
				}
			}
		}
	}
	// cout << max;
	printf("%d", max);

	return 0;
}