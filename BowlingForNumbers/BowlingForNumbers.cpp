#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
ll b[30000], d[501][300001];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t,n,k,w; cin>>t;
    for(int q=0; q<t; q++) {
        cin>>n>>k>>w;
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=1; i<=k; i++) {


        }
        ans.pb(d[k][n]);
    }
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<fin;
}
