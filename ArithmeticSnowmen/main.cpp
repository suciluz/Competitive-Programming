#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
vector<int>arr;
bool have[100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n, ans =0;; cin>>n;
    for(int i=0,tmp; i<n; i++) {cin>>tmp; arr.pb(tmp); have[tmp]=1;}
    int d= 0;
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            d = arr[i]-arr[j];
            if(i>j && d>0) {
                if(have[arr[i]+d] && arr[i]+d <= 100000) ans = max(ans,arr[i]+arr[j]+arr[i]+d);
            }
        }
    }
    cout<<ans<<fin;
}
