#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
unordered_map <string,int> rn;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s; cin>>s;
    int ans =0;
    rn["V"] = 5; rn["I"] = 1; rn["X"] = 10; rn["L"] = 50; rn["C"]=100; rn["D"]=500; rn["M"] = 1000;
    for(int i=0; i<s.length(); i+=2) {
        if(i < s.length()-2) {
            if(rn[s.substr(i+1,1)] < rn[s.substr(i+3,1)]) ans -= stoi(s.substr(i,1))*rn[s.substr(i+1,1)];
            else ans += stoi(s.substr(i,1))*rn[s.substr(i+1,1)];
        }
        else ans += stoi(s.substr(i,1))*rn[s.substr(i+1,1)];
    }
    cout<<ans<<fin;
}
