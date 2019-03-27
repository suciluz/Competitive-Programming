#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<(1<<n); i++) {


    }
}


/*
Bitwise operations:
check bit-p 0/1: (x&(1<<p))
set bit-p to 1: (x|(1<<p))
get a length of bits: ((1<<len)-1)<<start pos
x = x | ... => change the original
Exclusive or ^: 0 if same, 1 if diff
A^0 = A / A^A = 0
Swap two values:
a = a^b
b = a^b
a = a^b
(x&(x-1)) == 0 => check if an int is pow of 2.
Keep doing &(x-1)) => # of 1 in the binary representation of an integer

for(int i=0; i<(1<<n); i++) {
    if(i&(i<<1)) not valid
}
d[row i][k kings][mask j]
d[i][k][mask j] += d[i-1][k-cnt(mask j)][mask p]
*/
