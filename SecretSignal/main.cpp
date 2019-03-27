#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
int n,k,cnt=0; ll arr[200000],rem[50000];
/*
5 4
60 2 7 1 2
*/
void solve() {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum = (((sum + arr[i])%k)+k)%k;
        cnt+=rem[sum];
        rem[sum]++;
    }
    cnt+=rem[0];
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    for(int i=0,tmp; i<n; i++) cin>>arr[i];
    solve();
    cout<<cnt<<fin;
}
