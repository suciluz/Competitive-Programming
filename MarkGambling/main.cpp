#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int arr[100000], arr2[100000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0,in; i<n; i++) {
        cin>>in;
        if(i!=0)arr[i] = arr[i-1]+in;
        else arr[i] = in;
        arr2[i] = in;
    }
    double avg = arr[n-1] / (double)n ;
    int cnt =0;
    for(int i=0; i<n; i++) {
        if(arr2[i]>avg) cnt++;
    }
    if(cnt>n/2) cout<<"Winnie should take the risk"<<fin;
    else cout<<"That's too risky"<<fin;
}
