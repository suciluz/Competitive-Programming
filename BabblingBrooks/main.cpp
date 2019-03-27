#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n; vector<double> s(n+1);
    for(int i=1, tmp; i<=n; i++) cin>>s[i];
    for(int tmp;tmp!=77;) {
        cin>>tmp;
        if(tmp==99) {
            int str, per; cin>>str>>per;
            double l = s[str]*((double)per)/100, r = s[str] - l;
            s.insert(s.begin()+str,l);
            s[str+1] = r;
        }
        else if (tmp==88) {
            int str; cin>>str;
            s[str] += s[str+1];
            s.erase(s.begin()+(str+1));
        }
    }
    for(int i=1; i<s.size(); i++) cout<<(int)round(s[i])<<" ";
    cout<<fin;
}
