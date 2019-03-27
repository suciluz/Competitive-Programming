#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int A[3010], B[110], d[3010][110][110][2], n, m;
int solve (int i, int l, int r, bool can) {
    int tmp = 0;
    if(l>r && i>n) return 0;
    if(d[i][l][r][can]) return d[i][l][r][can]; //memo
    if(l <= r) { //bag of pies
        tmp = max(tmp, solve(i, l+1, r, 0)); //not place
        if(!can) tmp = max(tmp, B[r] + solve(i,l,r-1,1)); //place
    }
    if(i <= n) {
        tmp = max(tmp, solve(i+1, l, r, 0)); //skip
        if(!can) tmp = max(tmp, A[i] + solve(i+1,l,r,1)); //take
    }
    return d[i][l][r][can]=tmp;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>A[i];
    cin>>m;
    for(int i=1; i<=m; i++) cin>>B[i]; //d[1] = A[1];
    sort(B+1,B+m+1);
    cout<<solve(1,1,m,0)<<fin;
}

/*
(1) Sort the m pies
(2) dp state
d[i][l][r][can] => max
i: current position
l,r: two pointers of B array
can: can take it or not
(3) compute

if(i<n) {ans = d[i+1][l][r][1]
    if(can) ans = max(ans,A[i]+d[i+1][l][r][0]
}
if(l<=r) {
    ans <- d[i][l+1][r][1]
    if(can) ans <- d[i][l][r-1][0] + B[r]
 }
*/
