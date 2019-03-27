#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
const int maxn = 1e5 + 5;
ll arr[maxn],cnt[maxn]; int n, m;

ll getSum (int ind) {
    ll sum = 0;
    while(ind) {
        sum+=arr[ind];
        ind-=ind&(-ind);
    }
    return sum;
}

ll qSum (int l, int r) {
    return getSum(r) - getSum(l-1);
}

ll q (int ind) {
    ll sum = 0;
    while(ind) {
        sum+=cnt[ind];
        ind-=ind&(-ind);
    }
    return sum;
}

void updateBIT (int ind, ll val) {
    while(ind<=maxn-5) {
        arr[ind]+=val;
        ind+=ind&-ind;
    }
}

void updateCnt (int ind, ll val) {
    while(ind<=maxn-5) {
        cnt[ind]+=val;
        ind+=ind&-ind;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=1,tmp; i<=n; i++) { cin>>tmp; updateBIT(i,tmp); updateCnt(tmp,1); }
    for(int i=0; i<m; i++) {
        char op; cin>>op;
        if(op=='C') {
            int x,v; cin>>x>>v;
            ll cur = qSum(x,x);
            updateBIT(x,v-cur);
            updateCnt(v,1); updateCnt(cur,-1);
        }
        else if(op=='S') {
            int l,r; cin>>l>>r;
            cout<<qSum(l,r)<<fin;
        }
        else {
            int v; cin>>v;
            cout<<q(v)<<fin;
        }
    }
    return 0;
}
