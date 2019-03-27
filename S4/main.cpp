#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
const int maxn = 1000001;
ll arr[maxn];
ll d[maxn];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=n; i++) {
        for(int j=i; j>=i-k; j--) {
            if(j>=1) {
                d[i] = max(d[i], d[j] + *max_element(arr+j, arr+i+1 ));
            }
        }
    }
    for(int i=0; i<=n; i++) {
        cout<<d[i]<<" ";
    } cout<<fin;
    cout<<d[n]<<fin;

}



/*
5 3
2 5 7 1 4

12
*/
