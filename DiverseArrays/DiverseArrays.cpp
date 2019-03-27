#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
const int maxn = 1e6;
long long cnt=0;
int arr[maxn],freq[maxn+1],n,k,amor=0;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k; int l=0;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int r=0,amor=0; l<n || r<n; l++) {
        while(amor < k) {
            if(r==n) break;
            if( ++freq[arr[r]]==1 ) amor++; r++;
        }
        if(amor < k) break;
        if(!--freq[arr[l]]) amor--;
        cnt += (n-r);
    }
    cout<<cnt+l<<fin;
}


