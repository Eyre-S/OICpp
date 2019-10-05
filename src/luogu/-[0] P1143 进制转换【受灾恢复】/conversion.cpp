// #define SUKAYO

// #ifdef SUKAYO

// 	#include <iostream>
// 	#include <cstdio>

// 	using namespace std;

// 	int sour = 0;
// 	int conv = 0;
// 	int num = 0;

// 	char cic(int x){
    
// 		if (x < 10) {
// 			return x+48;
// 		}
    
// 		return x - 10 + 'A';
// 	}

// 	void otp (int k) {
        
// 		if (!k) return;
// 		otp(k / conv);
// 		putchar(cic(k % conv));
// 	}

// 	int main() {

// 		cin >> sour;
// 		getchar();

// 		while (true) {
// 			register int T = 0;
// 			register unsigned char C = getchar();

// 			if (C >= 'A' && C <= 'F') {
// 				T = C - 55;
// 			} else if (C > 47 && C < 58) {
// 				T = C - 48;
// 			} else {
// 				break;
// 			}

// 			num *= sour;
// 			num += T;
// 		}

// 		cin >> conv;

// 		otp(num);

// 		#ifdef debug
// 			cout << num;
// 		#endif


        
// 		return 0;
// 	}
// #endif

// #ifdef kIG7Z8oP
// 	#include<cstdio>
// 	int n,x,m;
// 	inline int isint(char c)
// 	{
// 	    if(c>='A'&&c<='F')
// 	        return c-55;
// 	    if(c>47&&c<58)
// 	        return c-48;
// 	    return -1;
// 	}
// 	inline int read()
// 	{
// 	    int x=0;
// 	    while(~isint(c)) x*=n,x+=isint(c),c=getchar();
// 	    return x;
// 	}
// 	inline char cic(int x){
// 	    if(x<10)
// 	        return x+48;
// 	    return x-10+'A';
// 	}
// 	void otp(int k)
// 	{
// 	    if(!k) return;
// 	    otp(k/m);
// 	    putchar(cic(k%m));
// 	}
// 	int main()
// 	{
// 	    scanf("%d",&n);
// 	    x=read();
// 	    scanf("%d",&m);
// 	    otp(x);
// 	    putchar('\n');
// 	}
// #endif

// #ifdef nignore
//  if(c>='A'&&c<='F')
//         return c-55;//'A'=65,10=10;
//     if(c>47&&c<58)
//         return c-48;
//     return -1;

//     if(!k) return;
//     otp(k/m);
//     putchar(cic(k%m));
// void otp (int k) {

// 	if (!k) return;
// 	otp(k / m);
// 	putchar(cic(k % m));
// }

// char cic(int x){

// 	if (x < 10) {
// 		return x+48;
// 	}

// 	return x - 10 + 'A';
// }

// #endif























// #include <iostream>
#include <cstdio>

using namespace std;

int sour = 0;
int conv = 0;
int num = 0;

void otp (register int k) {
    
    if (!k) return;
    otp(k / conv);

    register int n = k % conv;
    if (n < 10) {
        putchar(n + 48);
    } else {
        putchar(n - 10 + 'A');
    }
}

int main() {
    
    scanf("%d", &sour);
    getchar();
    while (true) {
        register int T = 0;
        register char C = getchar();
        if (C >= 'A' && C <= 'F') {
            T = C - 55;
        } else if (C > 47 && C < 58) {
            T = C - 48;
        } else {
            break;
        }
        num *= sour;
        num += T;
    }

    scanf("%d", &conv);
    otp(num);
    
    return 0;
}
