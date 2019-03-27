#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
#define INF 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pi;
typedef long long ll;
pi c[5001];
ll d[5001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n; for(int i=0; i<n; i++) {cin>>c[i].first>>c[i].second;}
    memset(d,INF,sizeof(d)); d[0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=n-1; j>=i; j--) if(j+c[i].second < n) d[j+c[i].second] = min(d[j+c[i].second], d[j]+c[i].first);
        else d[n-1] = min(d[j]+c[i].first,d[n-1]);
    }
    //for(int i=0; i<=n; i++) cout<<d[i]<<" ";
    cout<<d[n-1]<<fin;
}

