#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int in, arr[3];
    for(int i=0; i<3; i++) cin>>arr[i];
    sort(arr,arr+3);
    cout<<arr[1]<<fin;
}
