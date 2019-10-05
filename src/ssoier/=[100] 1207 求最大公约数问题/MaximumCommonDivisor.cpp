#include <cstdlib>
#include <cstdio>

using namespace std;

int a,b;
int conv2 = 0;
int result = 1;

int main(int argc, char const *argv[])
{
	
	scanf("%i%i", &a ,&b);

	while (a%2 == 0 && b%2 ==0) {
		a /= 2;b /= 2;
		conv2++;
	}

	while (a != b) {
		if (a > b) {
			a -= b;
			continue;
		} else if (a < b) {
			b -= a;
		}
	}

	for (int i = 0; i < conv2; ++i) {
		result *= 2;
	}

	printf("%d", result * a);

	return 0;
}