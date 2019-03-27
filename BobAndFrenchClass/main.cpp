#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int a[100000], b[100000], d[3][100005];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++) {
        d[0][i] = max(d[0][i-1],max(d[1][i-1],d[2][i-1]))+b[i];
        d[1][i] = d[0][i-1]+a[i];
        d[2][i] = d[1][i-1]+a[i];
    }
    cout<<max(d[0][n],max(d[1][n],d[2][n]));
}

