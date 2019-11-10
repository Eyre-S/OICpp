// #include <iostream>
#include <cstdlib>
#include <cstdio>
// #include <algorithm>

using namespace std;

long long an;
// int num[4] = {2,1,2,2};
long long p;
// int templ[10000];

long long countPull (long long tn) {

	long long num0 = 2;
	long long num1 = 1;
	long long num2 = 2;
	long long num3 = 2;


	if (tn==1) {
		return 1;
	} else if (tn==2) {
		return 2;
	}

	for ( ; num0 < tn; num0++) {
		num3 = (num2 * (long long)2 + num1)%32767;
		num1 = num2%32767;
		num2 = num3%32767;
	}
	return num3 % (long long)32767;
}

int main()
{
	
	scanf("%d",&an);

	for (int i = 0; i < an; ++i) {
		scanf("%lli", &p);
		printf("%lli\n", countPull(p));
		
	}

	return 0;
}

// int main(int argc, char const *argv[]) {
	
// 	scanf("%d",&n);

// 	for (int i = 0; i < n; ++i) {
// 		scanf("%d",&templ[i]);
// 		// cin >> templ[i];
// 	}

// 	// sort(templ, templ + n);

// 	for (int i = 0; i < n; ++i) {

// 		if (templ[i]==1) {
// 			printf("1\n");
// 			// cout << 1 << endl;
// 			continue;
// 		} else if (templ[i]==2) {
// 			// cout << 2 << endl;
// 			printf("2\n");
// 			continue;
// 		}

// 		for ( ; num[0] < templ[i]; num[0]++) {
// 			num[3] = 2 * num[2] + num[1];
// 			num[1] = num[2];
// 			num[2] = num[3];
// 		}
		
// 		printf("%d\n",num[3]%32767);
// 		// cout << num[3] << endl;
// 	}

// 	return 0;
// }