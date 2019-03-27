#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 1e5;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,m,k; pi arr[maxn];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k; ll sum = 0;
    for(int i=0; i<n; i++) {
        cin>>arr[i].second>>arr[i].first; sum+=arr[i].second;
    }
    sort(arr,arr+n); ll cut = (ll) k*n, hrs= 0;
    if(sum>=cut) {cout<<0<<fin; return 0; }
    for(int i=0; i<n; i++) {
        if(sum+m-arr[i].second <= cut) {
            sum += (m-arr[i].second);
            hrs += arr[i].first * (m-arr[i].second);
        } else {
            hrs += (cut-sum)*arr[i].first; break;
        }
    }
    cout<<hrs<<fin;
}
