#include <iostream>
#include <cstdio>
 
using namespace std;
 
struct node {
	int leftPos;
	int rightPos;
	int sum;
};
 
// 数据体
node lineingTree[400004];
int nativeArray[100000] = {0};
 
// 数据参数
int numCount = 0;
 
// 递归建树
int build (int id, int left, int right) {
	// 基本初始化
	lineingTree[id-1].sum = 0;
	lineingTree[id-1].leftPos = left;
	lineingTree[id-1].rightPos = right;
	// 分割&计算区间和
	if (left != right) {
		int mid = (left  + right) / 2;
		lineingTree[id-1].sum = build(id * 2, left, mid) + build(id * 2 + 1, mid + 1, right);
	} else { // 从原数据输入数据并返回
		lineingTree[id-1].sum = nativeArray[left];
	}
	return lineingTree[id-1].sum;
}
 
// 区间增加
void add (int id, int numId, int value) {
	lineingTree[id-1].sum += value;
	int mid = (lineingTree[id-1].leftPos  + lineingTree[id-1].rightPos) / 2;
	
	if ((numId-1) == lineingTree[id-1].leftPos && (numId-1) == lineingTree[id-1].rightPos) {
		return;
	} else if ((numId-1) > mid) {
		add (id * 2 + 1, numId, value);
	} else {
		add (id * 2, numId, value);
	}
}
 
// 检索区间和
int check (int id, int left, int right) {
	if (lineingTree[id-1].leftPos == left && lineingTree[id-1].rightPos == right) {
		return lineingTree[id-1].sum;
	}
	int mid = (lineingTree[id-1].leftPos  + lineingTree[id-1].rightPos) / 2;
	if (mid >= right) {
		return check(id * 2, left, right);
	} else if (mid < left) {
		return check(id * 2 + 1, left, right);
	}
	return check(id * 2, left, mid) + check(id * 2 + 1, mid + 1, right);
}
 
int main(int argc, char const *argv[]) {
	// 重定向IO
	freopen("shulie.in", "r", stdin);
	freopen("shulie.out", "w", stdout);
 
	// 数据输入
	cin >> numCount;
	for (int i = 0; i < numCount; ++i) {
		cin >> nativeArray[i];
	}
	// 树构建
	build(1, 0, numCount - 1);
 
	// // 测试输出
	// for (int i = 0; i < 4 * numCount; ++i) {
	// 	cout << lineingTree[i].sum << " ";
	// } cout << endl << endl;
 
	// cout << check(1, 1, 3) << endl;
 
	// // 测试输出
	// for (int i = 0; i < 4 * numCount; ++i) {
	// 	cout << lineingTree[i].sum << " ";
	// } cout << endl << endl;
	
	// 处理请求
	int req = 0;
	string reqType = "NUL";
	int arg[2] = {0, 0};
	cin >> req;
	for (int i = 0; i < req; ++i) {
		cin >> reqType >> arg[0] >> arg[1];
		if (reqType == "SUM") {
			cout << check(1, arg[0] - 1, arg[1] - 1) << endl;
		} else {
			add(1, arg[0], arg[1]);
		}
	}
 
	return 0;
}