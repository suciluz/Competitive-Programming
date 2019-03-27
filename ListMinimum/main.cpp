#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n; vector<int> vec;
    for(int i=0,in; i<n; i++) {cin>>in; vec.pb(in);}
    sort(vec.begin(),vec.end());
    for(int i=0; i<n; i++) cout<<vec[i]<<fin;
}



