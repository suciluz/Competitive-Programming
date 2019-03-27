#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n,d, arr[300000],carr[300000];
typedef long long ll;
ll sum=0; int cnt = 0;
unordered_map <int,int> mp;
void copya () {
    for(int i=0; i<n; i++) carr[i] = arr[i];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>d;
    for(int i=0; i<n; i++) {
        ll in; cin>>in;
        arr[i]=in; sum+=in;
        carr[i] = in;
    }
    sort(carr,carr+n);
    ll tsum = 0;
    for(int i=n-1; ; i--) {
        tsum += carr[i];
        cnt++;
        if(tsum>(double)sum/2.0) break;
    }
    cout<<cnt<<fin;
    for(int i=0; i<d; i++) {
        cnt = 0; tsum = 0;

        int v,c; cin>>v>>c;
        if(arr[v-1] > c) sum -= (arr[v-1]-c);
        else sum += (c-arr[v-1]);
        arr[v-1] = c;
        copya();
        sort(carr,carr+n);
        for(int i=n-1; ; i--) {
            tsum += carr[i];
            cnt++;
            if(tsum>(double)sum/2.0) break;
        }
        cout<<cnt<<fin;
    }
}

