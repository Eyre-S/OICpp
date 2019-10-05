// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

int gcd (int, int);
int mini (int, int);

void work(int n, int a[], long long b[]) {
	for (register int i = 0; i < n; i++) {
		std::cout << b[i] << ' ';
	} std::cout << std::endl;
	register int gcdr = 0;
	register int minin = 0;
	for (register int i = 1; i < n + 1; i++) {
		for (register int j = i + 1; j < n + 1; j++) {
			std::cout << "Running " << a[i] << " and " << a[j] << std::endl;
			gcdr = gcd(a[i], a[j]);
			minin = mini(a[i], a[j]);
			if (gcdr == minin) {
				std::cout << "Changeing  from " << i << " to " << j << " as " << minin << std::endl;
				for (register int n = i; n < j + 1; n++) {
					b[n] += minin;
				}
			}
		}
	}

	for (register int i = 0; i < n; i++) {
		std::cout << b[i] << ' ';
	} std::cout << std::endl;
}

int main()
{
    using namespace std;
    static int a[1000007];
    static long long b[1000007];
    int n, m; scanf("%d%d", &n, &m);
    mt19937_64 rng; rng.seed(m);
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int i = 2; i <= n; i++) swap(a[i], a[rng() % (i - 1) + 1]);

    work(n, a, b);

    typedef unsigned long long ull;
    ull ans = 0;
    for(int i = 1; i <= n; i++) ans ^= (ull) i * (ull) b[i];
    cout << ans << endl;
    return 0;
	// cout << mini(15, 35) << endl;
}

int gcd(int m, int n) {
	while (m * n) {
		if (m > n) {
			m %= n;
		} else if(m < n) {
			n %= m;
		}
	}
	return m > n ? m : n;
}

int mini (int m, int n) {
	if (m > n) {
		return n;
	} else {
		return m;
	}
}