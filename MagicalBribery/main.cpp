#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
/*
Unlimited knapsack
*/
int d[1001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=1,tmp; i<=n; i++) {
        cin>>tmp;
        for(int j=i; j<=n; j++)
            d[j] = max(d[j],d[j-i]+tmp);
    }
    cout<<d[n]<<fin;
}
