#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int p[100002],m,n; vector<int> edge;

int fd (int d) {
    if(d!=p[d]) p[d] = fd(p[d]);
    return p[d];
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) p[i]=i;
    for(int i=1,u,v; i<=m; i++) {
        scanf("%d %d", &u, &v);
        int fu = fd(u), fv = fd(v);
        if(fu!=fv) {p[fu] =fv; edge.pb(i);}
        if(edge.size()==n-1)break;
    }
    if(edge.size()!=n-1) printf("Disconnected Graph\n");
    else {
        for(int x: edge) printf("%d\n",x);
    }
}



/*

4 4
1 2
1 3
2 3
3 4
*/
