#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
const int maxn = 200001;
int n,Q;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef pair<int,ll> piii;
vector<pi> arr; vector<pii> qry; vector<piii> ans;
ll BIT[maxn], psum[maxn];

ll getSum (int ind) {
    ll sum = 0;
    while(ind) {
        sum+=BIT[ind];
        ind-=ind&(-ind);
    }
    return sum;
}

ll qSum (int l, int r) {
    return getSum(r) - getSum(l-1);
}

void updateBIT (int ind, ll val) {
    while(ind<=maxn) {
        BIT[ind]+=val;
        ind+=ind&-ind;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>Q;
    for(int i=1; i<=n; i++) {int tmp; cin>>tmp; arr.push_back({tmp,i}); psum[i] = psum[i-1] + tmp; }
    sort(arr.begin(), arr.end()); reverse(arr.begin(), arr.end());
    for(int i=0; i<Q; i++) {
        int a,b,q; cin>>a>>b>>q;
        qry.push_back({{q,i},{a,b}});
    }
    sort(qry.begin(),qry.end()); reverse(qry.begin(),qry.end()); int j=0;
    for(int i=0; i<qry.size(); i++) {
        int h = qry[i].first.first, qind = qry[i].first.second,
        l = qry[i].second.first, r = qry[i].second.second;
        for(; arr[j].first >= h && j<=n; j++) {updateBIT(arr[j].second, arr[j].first); }
        ll kk = qSum(l,r);
        ans.push_back({qind,kk - (psum[r]-psum[l-1]-kk)});
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i].second<<fin;
    }
}




