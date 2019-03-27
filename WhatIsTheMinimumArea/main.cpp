#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef pair<int,int> pi;
pi arr[100];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i].first>>arr[i].second;
    int ans = INT_MAX;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j) ans = min(ans, max(abs(arr[i].first - arr[j].first), abs(arr[i].second - arr[j].second)));
        }
    }
    cout<<ans*ans<<fin;
}



