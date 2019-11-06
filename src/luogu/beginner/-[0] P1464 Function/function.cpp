/**
 *     __   _____       __                              __
 *    / /  / ___/__  __/ /______ _____  __  ______     / /
 *   / /   \__ \/ / / / //_/ __ `/_  / / / / / __ \   / / 
 *  /_/   ___/ / /_/ / ,< / /_/ / / /_/ /_/ / /_/ /  /_/  
 * (_)   /____/\__,_/_/|_|\__,_/ /___/\__, /\____/  (_)   
 *                                   /____/               
 * 
 * 
 * 洛谷 - P1464 Function
 * <https://www.luogu.org/problem/P1464>
 * 
 * 作者：Cookie Sukazyo Eyre
 * 
 */

#include <iostream>
#include <cstdio>

using namespace std;
typedef long long int ll;
// using ll = register long long int;

ll func(ll , ll , ll);

int main () {
	
	ll ina, inb, inc;
	cin >> ina >> inb >> inc;
	do {
		printf("w(%lld, %lld, %lld) = %lld\n", ina, inb, inc, func(ina,inb,inc));
		cin >> ina >> inb >> inc;
	} while (ina!=-1 || inb!=-1 || inc!=-1);
	
	return 0;
	
}

ll func (register ll pa,register ll pb,register ll pc) {
	return (
		(pa<=0 || pb <=0 || pc<=0)?
		1
		:(
			pa>20 || pb> 20 || pc>20?
			func(20, 20, 20)
			:(
				(pa<pb && pb<pc)?
				(func(pa, pb, pc-1) + func(pa, pb-1, pc-1) - func(pa, pb-1, pc))
				:(func(pa-1,pb,pc)+func(pa-1,pb-1,pc)+func(pa-1,pb,pc-1)-func(pa-1,pb-1,pc-1))
			)
		)
	);
}