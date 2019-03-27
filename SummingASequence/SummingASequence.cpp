#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
ll d[2][1000001], arr[1000001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=0; i<=n; i++) {
        d[0][i+1] = max(d[0][i], d[1][i]);
        d[1][i+1] = arr[i+1]+d[0][i];
    }
    cout<<max(d[0][n],d[1][n])<<fin;
}
