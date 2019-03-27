#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
ll n,m,mx=-1; int cnt=0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m; ll arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j && arr[i]+arr[j]<=m) cnt++;
            else break;
        }
    }
    cout<<cnt<<fin;
    for(oint i=)
    ans+=pperbound(a,a+M,M-a[i])-a;
}
