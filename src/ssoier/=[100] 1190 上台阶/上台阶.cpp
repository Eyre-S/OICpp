#include <cstdlib>
#include <cstdio>

using namespace std;

long long floorStep (long long);

int main () {
	
	long long floor = 0;

	while (true) {
		scanf("%lld", &floor);
		if (floor == 0) { break; }
		long long result = floorStep(floor);
		printf("%lli\n", result);
		// cout << floorStep(floor) << endl;
	}
	
	return 0;

}

long long floorStep (long long floor) {
	
	long long first = 1;
	long long second = 1;
	long long third = 2;

	if (floor == 1) {
		return second;
	} else if (floor == 2) {
		return third;
	} else {
		long long result;
		for (long long i = 2; i < floor; ++i)
		{
			result = first + second + third;
			first = second;
			second = third;
			third = result;
		}
		return result;
	}
}
