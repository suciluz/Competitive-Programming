#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
unordered_set <char> st;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s1, s2; cin>>s1>>s2;
    /*for(int i=0; i<s2.length(); i++) {
        st.insert(s2.at(i));
    }
    for(int i=0; i<s1.length(); i++) {
        auto it = st.find(s1.at(i));
        if(it == st.end()) { cout<<s1.at(i)<<fin; return 0;}
    }*/
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] != s2[i]) {cout<<s1[i]<<fin; return 0;}
    }
}


