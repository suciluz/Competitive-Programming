#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
int n, a, b; ll d[10000]; vector<int> lc {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>a>>b>>n;
    for(int i=0,tmp; i<n; i++) {
        cin>>tmp; lc.pb(tmp);
    }
    sort(lc.begin(), lc.end());
    d[0] = 1;
    ll ans =0 ;
    for(int i=0;;i++) {

        for(int j=0; j<lc.size(); j++) {
            if(i>j && lc[i]-lc[j] >= a && lc[i]-lc[j] <=b) {
                d[i] += d[j];
            }
        }
        if(lc[i] == 7000) { ans = d[i]; break; }
    }
    for(int i=1; i<=n+13; i++) ans = max(ans,d[i]);
    cout<<ans<<fin;
}
