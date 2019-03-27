#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n; unordered_set <int> s;
    for(int i=0,in; i<n; i++) {cin>>in; if(in!=0)s.insert(in);}
    cout<<n-s.size()<<fin;
}
