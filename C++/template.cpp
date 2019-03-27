#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod;j%=mod;return i*fpow(j,mod-2,mod)%mod;}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

}






