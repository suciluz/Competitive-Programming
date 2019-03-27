#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[1001][10001],mod = 1000000007;
/*
Can use merge sort / BIT
*/

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,c; cin>>n>>c; d[0][0] =1;
    for(int i=1; i<=n; i++) {
        d[i][0] = 1;
        for(int j=1; j<=c; j++) {
            if(j >= i) d[i][j] = (mod+d[i-1][j]-d[i-1][j-i]) % mod; //prefix sum
            else d[i][j] = d[i-1][j];
            d[i][j] = (d[i][j]+d[i][j-1])%mod;
        }
    }
    cout<<d[n][c]<<fin;
}
