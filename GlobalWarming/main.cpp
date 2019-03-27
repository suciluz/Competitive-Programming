#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int arr[21];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    while(n!=0) {
        int tmp; cin>>tmp;
        for(int i=1, tmp2; i<n; i++) {
            cin>>tmp2; arr[i] = tmp2 - tmp;
            tmp = tmp2;
        }
        if(n==1) { cout<<0<<fin; goto fi; }
        int i = 1;
        for(; i<n; i++) {
            bool b = 1;
            for(int j=i+1; j<n; j++) {
                if(arr[j-i] != arr[j]) b = 0;
            }
            if(b) break;
        }

        cout<<i<<fin;
        fi:;
        cin>>n;
    }
}
