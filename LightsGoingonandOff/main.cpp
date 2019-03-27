#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int r,c;string arr[29];
set <string> ans;
string button (string prev, string cur) {
    string tmp;
    for(int i=0; i<prev.length(); i++) {
        if(prev.at(i)==cur.at(i)) tmp=tmp+"0";
        else tmp=tmp+"1";
    } return tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            string tmp; cin>>tmp;
            arr[i]=arr[i]+tmp;
        }
    }
    string t = arr[0], b = arr[1],news="";
    for(int i=1; i<r; i++) {
        news = button(t,b);
        for(int j=i+1; j<r; j++) {
            t = news; b = arr[j];
            news = button(t,b);
        }
        ans.insert(news);
        t = arr[i]; b = arr[i+1];
    }
    ans.insert(arr[r-1]);
    cout<<ans.size()<<fin;
}
