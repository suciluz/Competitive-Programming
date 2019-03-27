#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int n, s[1001],d[1001][1001];
int solve (int cur, int pre) {
    if(cur<1 || cur>n) return INT_MAX;
    if(cur==n) return s[n];
    if(d[cur][pre]!=-1) return d[cur][pre];
    return d[cur][pre] = min(solve(cur-pre,pre),solve(cur+pre+1,pre+1)) + s[cur];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n; memset(d,-1,sizeof(d));
    for(int i=1; i<=n; i++) cin>>s[i];
    cout<<solve(2,1) << fin;
}

