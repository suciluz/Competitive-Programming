#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int n,q,p[100001]; string qry;

int Find (int d) {
    if(p[d]!=d) p[d]=Find(p[d]);
    return p[d];
}

int main()
{
    ios_base::sync_with_stdio(0); cin>>n>>q;
    for(int i = 1;i<=n;i++) p[i] = i;
    for(int i=0; i<q; i++) {
        int x,y;
        cin>>qry>>x>>y;
        if(qry=="A") { int fx = Find(x), fy= Find(y); if(fx!=fy) p[fx]=fy; }
        else {
            int fx = Find(x), fy = Find(y);
            if(fx!=fy) cout<<"N"<<end;
            else cout<<"Y"<<end;
        }
    }
}

