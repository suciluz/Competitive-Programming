#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
ll arr[200000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; ll m; cin>>n>>m;
    for(int i=0; i< n; i++) {
        cin>>arr[i];
    }
    ll ans = 0, sum=0, cnt=0;
    for(int i=0; i<n; i++) {
        if(sum + arr[i] < m) {
            sum += arr[i]; cnt++;
        }
        else {
            if(sum) sum = sum - arr[i-cnt] + arr[i];
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<fin;
}


