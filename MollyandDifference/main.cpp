#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n; int arr[1000000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n; int ans = INT_MAX;
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=1; i<n-1; i++) {
        ans = min(ans,abs(arr[i]-arr[i-1]));
        ans = min(ans,abs(arr[i]-arr[i+1]));
    }
    cout<<ans;
}
