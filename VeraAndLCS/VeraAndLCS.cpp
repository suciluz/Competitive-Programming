#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int n,k; string a,b;
int freq[26];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k>>a;
    if(k>n) {cout<<"WRONGANSWER"<<fin; return 0;}
    for(int i=0; i<a.length(); i++) freq[a[i]-'a']++;
    char tmp; int mn = INT_MAX;
    for(int i=0; i<26; i++) {
        if(mn > freq[i]) {tmp = i+'a'; mn = freq[i]; }
    } if(mn > k) { cout<<"WRONGANSWER"<<fin; return 0;}
    for(int i=0; i<n-k; i++) cout<<tmp;
    for(int i=0; i<k; i++) cout<<a[i];

    cout<<fin;
}

