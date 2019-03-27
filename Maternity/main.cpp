#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
string dad,mom; int n;
bool solve(string s) {
    bool valid = 1;
    int d[5];
    for(int i=0,cnt=0; i<9; i+=2) {
        if(dad.at(i)<70 && dad.at(i+1)<70 || mom.at(i)<70 && mom.at(i+1)<70) {
            d[cnt] = 1; cnt++;
        } else if(dad.at(i)>90 && dad.at(i+1)>90 && mom.at(i)>90 && mom.at(i+1)>90) {d[cnt] = 2; cnt++;}
        else {d[cnt] = 0; cnt++; }
    }
    for(int i=0; i<5; i++) {
        if(d[i]==1 && s.at(i)>90) valid = 0;
        else if(d[i]==2 && s.at(i)<70) valid = 0;
    }
    return valid;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>dad>>mom>>n;
    for(int i=0; i<n; i++) {string tmp; cin>>tmp; if(solve(tmp)) cout<<"Possible baby."<<fin; else cout<<"Not their baby!"<<fin;}
}

