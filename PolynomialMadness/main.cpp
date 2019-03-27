#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
ll d, num;
ll roots[301];
vector<ll> rts;

ll ipow(ll base, ll exp) {
    ll result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

bool valid (ll *coef,ll x) {
    ll sum=0;
    for(ll i=0; i<d; i++) sum = sum + coef[i]*ipow(x,d-i);
    sum+=coef[d];
    if(sum==0) return 1;
    else return 0;
}

bool nvalid (ll *coef,ll x, ll s) {
    ll sum=0;
    for(ll i=0; i<s-1; i++) sum = sum + coef[i]*ipow(x,s-1-i);
    sum+=coef[s-1];
    if(sum==0) return 1;
    else return 0;
}
ll order (ll *coef, ll x) {
    queue<ll> ccoef; for(ll i=0; i<d; i++) ccoef.push(coef[i]);
    ll ord = 1;
    for(ll i=0; i<d-1; i++) {
        ll ncoef[d-i];
        for(ll j=0; j<d-i; j++) {
            ncoef[j]=ccoef.front()*(d-i-j); ccoef.pop();
        }
        if(nvalid(ncoef,x,d-i)) ord++;
        for(ll j=0; j<d-i; j++) ccoef.push(ncoef[j]);
    }
    return ord;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>num;
    for(ll k=0; k<num; k++) {
        cin>>d; ll craze=0;
        for(ll i=0; i<301; i++) roots[i]=i-150;
        ll coef[d+1];
        for(ll i=0; i<=d; i++) cin>>coef[i];//binarySearch(coef,0,300);
        for(ll i=0; i<301; i++) {
            if(valid(coef,roots[i])) {
                    if(order(coef,roots[i])>1)craze=roots[i];
                for(ll j=0; j<order(coef,roots[i]); j++) rts.pb(roots[i]);
            }
        }
        sort(rts.begin(),rts.end());
        if(rts.size()<d) {
            for(ll i=0; i<rts.size(); i++) cout<<rts[i]<<" ";
            for(int q = 0; q<d-rts.size(); q++) cout<<craze<<" ";
        } else {
        for(ll i=0; i<rts.size(); i++) cout<<rts[i]<<" ";
        }
        cout<<'\n';
        rts.clear();
    }
}
