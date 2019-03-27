#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int sum=0, ans=INT_MAX;
bool d[701];
int v[701];

int main() {
    ios_base::sync_with_stdio(0); int n; cin>>n;
    for(int i=0; i<n; i++) {cin>>v[i]; sum+=v[i];}
    d[0] =1;
    for(int i=0; i<n; i++) {
        for(int j=sum/2; j>=v[i]; j--) {
            if(!d[j]) d[j] = d[j-v[i]];
        }
    }
    for (int i=sum/2; i>=0; i--) {
        if (d[i]) { ans = sum-2*i; break; }
    }
    cout<<ans<<fin;
}
