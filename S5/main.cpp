#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
ll g[3001][3001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,k;cin>>n>>k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin>>g[i][j];
        }
    }
    ll ans = 0;
    for(int i=1; i<=n-k+1; i++) {
        ll s = 0;
        for(int j=1; j<=i ;j++) {
            for(int k=i; k<=i+k-j; k++) {
                s += g[k][j];
            }
        }
    }
}

/*
4 2
3
1 2
4 2 1
6 1 4 2

23
*/
