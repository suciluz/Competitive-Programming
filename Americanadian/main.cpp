#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s; cin>>s;
    while(s!="quit!") {
        int l = s.length();
        if(s.length() >4) {
            if(s.at(l-3) != 'a' && s.at(l-3) != 'e' && s.at(l-3) != 'i' && s.at(l-3) != 'o' && s.at(l-3) != 'u') {
                if(s.at(l-2) == 'o' && s.at(l-1) == 'r') {
                    cout<<s.substr(0,l-2)+"our"<<fin;
                } else cout<<s<<fin;
            } else cout<<s<<fin;
        }
        else cout<<s<<fin;
        cin>>s;
    }
}


