#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
const int maxn = 1e5 + 5;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef pair<int,ll> piii;
vector<pi> arr; vector<pii> qry; vector<piii> ans;
int BIT[maxn];
int n;

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
    while(ind<=maxn-5) {
        BIT[ind]+=val;
        ind+=ind&-ind;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=1,tmp; i<=n; i++) { cin>>tmp; arr.push_back({tmp,i}); }
    sort(arr.begin(), arr.end()); reverse(arr.begin(), arr.end());
    int Q; cin>>Q;
    for(int i=0; i<Q; i++) {
        int a,b,q; cin>>a>>b>>q;
        qry.push_back({{q,i},{a+1,b+1}});
    }
    sort(qry.begin(),qry.end()); reverse(qry.begin(),qry.end()); int j=0;
    for(int i=0; i<qry.size(); i++) {
        int h = qry[i].first.first, qind = qry[i].first.second,
        l = qry[i].second.first, r = qry[i].second.second;
        for(; arr[j].first >= h && j<=n; j++) updateBIT(arr[j].second, arr[j].first);
        ans.push_back({qind,qSum(l,r)});
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++) cout<<ans[i].second<<fin;
}




