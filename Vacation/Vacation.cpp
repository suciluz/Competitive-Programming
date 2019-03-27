#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[3][100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0,a,b,c; i<n; i++) {
        cin>>a>>b>>c;
        if(i==0) {d[0][0] = a; d[1][0] = b; d[2][0] = c;}
        if(i>0) {
            d[0][i] = max(d[1][i-1],d[2][i-1])+a;
            d[1][i] = max(d[2][i-1],d[0][i-1])+b;
            d[2][i] = max(d[0][i-1],d[1][i-1])+c;
        }
    }
    int ans = -1;
    ans = max(max(d[0][n-1],d[1][n-1]),d[2][n-1]);
    cout<<ans<<fin;
}
