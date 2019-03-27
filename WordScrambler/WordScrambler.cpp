#include <bits/stdc++.h>
using namespace std;
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s; cin>>s;
    sort(s.begin(), s.end());
    do cout<<s<<fin;
    while(next_permutation(s.begin(),s.end()));
}


