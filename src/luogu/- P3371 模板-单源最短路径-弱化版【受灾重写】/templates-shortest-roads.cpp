#include <iostream>

using namespace std;

// 单位线段
struct lineUnit {
	int startId;	//起始点
	int arrivalId;	// 到达点
	int distance;	// 长度
	int lastLine;	// 上一条边
};

int pointNum;	// 点数量
int lineNum;	// 线段数量
int rootId;	// 起始点Id
int dotLine[10000];	// 点对应的边
lineUnit lines[500000];	// 线段集

int main () {
	cin >> pointNum >> lineNum >> rootId;

	for (register int i = 0; i < pointNum; i++) {
		dotLine[i] = -1;
	}

	// 数据输入
	for (register int i = 0; i < lineNum; ++i) {
		cin >> lines[i].startId >> lines[i].arrivalId >> lines[i].distance;
		if (dotLine[lines[i].startId] == -1)  {
			dotLine[lines[i].startId] = i;
			lines[i].lastLine = -1;
		} else {
			lines[i].lastLine = dotLine[lines[i].startId];
			dotLine[lines[i].startId] = i;
		}
	}

	for (register int i = 0; i < pointNum; i++) {
		dotLine[rootId];
	}

	return 0;
}

