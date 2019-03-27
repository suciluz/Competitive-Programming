#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int arr[10001],n,ans;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0,tmp; i<n; i++) {cin>>tmp; arr[tmp]++;}
    for(int i=1,mx=-1; i<=10001; i++) {
        if(mx<arr[i]) {
            mx = arr[i]; ans = i;
        }
    }
    cout<<ans<<fin;
}
