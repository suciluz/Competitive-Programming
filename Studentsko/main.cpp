#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef pair<int,int> pi;
vector<pi> arr;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,k;cin>>n>>k;
    for(int i=0; i<n; i++) {
        int tmp; cin>>tmp;
        arr.push_back({tmp,i});
    }
    sort(arr.begin(), arr.end());
    vector<int> group(n), d(n);
    for(int i=0; i<n; i++) {
        group[arr[i].second] = i/k;
    }
    for (int i=0; i<n; i++) {
        d[i] = 1;
        for (int j=0; j<i; j++) {
            if (group[j] <= group[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
            }
        }
    }
    cout<<n - *max_element(d.begin(),d.end());
}


