#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int arr[4];
bool rise () {
    bool b = 1;
    for(int i=0; i<3; i++) {
        if(arr[i+1] <= arr[i]) b = 0;
    }
    return b;
}
bool dive () {
    bool b = 1;
    for(int i=0; i<3; i++) {
        if(arr[i+1] >= arr[i]) b = 0;
    }
    return b;
}
bool cons () {
    bool b = 1;
    for(int i=0; i<3; i++) {
        if(arr[i] != arr[i+1]) b = 0;
    }
    return b;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<4; i++) cin>>arr[i];
    if(rise()) cout<<"Fish Rising"<<fin;
    else if(dive()) cout<<"Fish Diving"<<fin;
    else if(cons()) cout<<"Fish At Constant Depth"<<fin;
    else cout<<"No Fish"<<fin;
}


