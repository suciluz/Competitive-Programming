#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 1000002;
int arr[maxn];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n, q; cin>>n;
    for(int i=0,tmp;i<n; i++) {
        if(i==0) cin>>arr[i];
        else  {cin>>tmp;
        arr[i] = arr[i-1] + tmp; }
    }
    cin>>q;
    for(int i=0,iz,f; i<q; i++)  {
        cin>>iz>>f;
        cout<<arr[f]-arr[iz-1]<<fin;
    }

}

