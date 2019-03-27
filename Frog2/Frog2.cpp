#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[100101], h[100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>h[i];
//if(i>1) { d[i] = abs(h[i]-h[i-1]);}
    }
    /*
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            d[i] =
        }
    }
*/  memset(d,0x3f,sizeof(d)); d[1] = 0;
    for(int i=1; i<=n; i++) {
        int tmp = INT_MAX;
        for(int j=1; j<=k; j++) {
            d[i+j] = min(d[i+j],d[i]+abs(h[i+j]-h[i]));
        }
    }
    cout<<d[n]<<fin;

}
