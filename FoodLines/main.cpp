#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n,m,arr[100];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0; i<m; i++) {
        cout<<arr[0]<<fin; arr[0]++;
        sort(arr,arr+n);
    }
}

