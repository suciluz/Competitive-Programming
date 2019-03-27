#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
const int maxn = 2000001;
typedef long long ll;
bool sieve [maxn];

void doSieve () {
    memset(sieve,0, sizeof(sieve));
    sieve[0] = sieve[1] = 0;
    for(int i=2; i<=maxn; i++) sieve[i] = 1;
    for(int i=2; i*i <=maxn; i++) {
        if(sieve[i] == 1) {
            for(int j=i*2; j<=maxn; j+=i) sieve[j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t; cin>>t; doSieve();
    for(int k=0; k<t; k++) {
        int n; cin>>n;
        for(int i=0; i<n; i++) {
            if(sieve[i] && sieve[2*n-i]) { cout<<i<<" "<<(2*n-i)<<fin; break; }
        }
    }
}


