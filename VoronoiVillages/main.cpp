#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int arr[100];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);
    double ans = (double) INT_MAX;
    for(int i=1; i<n-1; i++) {
        double n1 = (arr[i]-arr[i-1]) / 2.0, n2 = (arr[i+1]-arr[i]) / 2.0;
        ans = min (ans,n1+n2);
    }
    cout<<fixed;
    cout<<setprecision(1);
    cout<<ans<<fin;
}

