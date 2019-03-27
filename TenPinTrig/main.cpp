#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
string s;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
cin>>s;
if(s=="end of box") cout<<"y"<<fin;
    /*for(int i=0; i<1; i++) {
    int bl=0, gr=0, ye=0, pi=0, vi=0, br=0, re=0, ans=0;
    while (1) {
        cin>>s;
        if(s=="end of box") {
            ans += 13*(bl/7+1);
            ans += 13*(gr/7+1);
            ans += 13*(ye/7+1);
            ans += 13*(pi/7+1);
            ans += 13*(vi/7+1);
            ans += 13*(br/7+1);
            ans += 16*re;
            cout<<ans<<fin;
            break;
        }
        if(s=="blue") bl++;
        if(s=="green") gr++;
        if(s=="yellow") ye++;
        if(s=="pink") pi++;
        if(s=="violet") vi++;
        if(s=="brown") br++;
        if(s=="red") re++;
        break;
    }
    if(s=="end of box")
    cout<<s<<" "<<fin;
    }*/
}


