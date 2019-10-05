#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

int dot_count = 0;
int black_count = 0;
int white_count = 0;
int dot_next_line[100000];
int dot_color[100000];
int line_next[1000000];
int line_tag[1000000];

int main () {

	memset(dot_next_line, -1, sizeof(dot_next_line));
	memset(line_next, -1, sizeof(line_next));

	cin >> dot_count;
	for (register int i = 0, sta = 0, end = 0, tag = 0; i < dot_count - 1; i++) {
		cin >> sta >> end >> tag;
		if (dot_next_line[sta] != -1)
			line_next[i] = dot_next_line[sta];
		dot_next_line[sta] = i;
		line_tag[i] = tag;
	}
	cin >> black_count;
	for (register int i = 0, dot_id = 0; i < black_count; i++) {
		cin >> dot_id;
		dot_color[dot_id] = 1;
	}
	cin >> white_count;
	for (register int i = 0, id = 0;i < white_count; i++) {
		cin >> id;
		dot_color[id] = -1;
	}

	

	return 0;

}

