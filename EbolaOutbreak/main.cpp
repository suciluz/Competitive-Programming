#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn INT_MAX
int n,m,p[100001];vector<int> ans;

int Find (int d) {
    if(p[d]!=d) p[d]=Find(p[d]);
    return p[d];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) p[i]=i;
    for(int i=0; i<m; i++) {
        int k,a,b; cin>>k>>a;
        for(int j=1; j<k; j++) {
            cin>>b;
            int fa = Find(a), fb = Find(b);
            if(fa!=fb)p[fa]=fb;
        }
    }
    for(int i=1; i<=n; i++) {
        if(Find(i)==Find(1)) ans.pb(i);
    }
    cout<<ans.size()<<end;
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" "; cout<<end;
}
