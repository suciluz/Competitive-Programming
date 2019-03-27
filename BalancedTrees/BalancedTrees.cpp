#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
unordered_map <int,ll> d;
ll solve(ll n) {
    if(d[n]) return d[n];
    ll sum=0;
    for(int k = n;k>=2;) { //# of subtrees
        int w = (int) n/k;
        int rev = n/(w+1);
        sum += solve(w)*(k-rev);
        k = rev;
    }
    d[n] = sum;
    return d[n];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    d[1] = 1; d[2] = 1;
    cout<<solve(n)<<fin;
}
