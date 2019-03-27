#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int freq[2000], mxL[3999], ans =0, cnt=0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0, tmp; i<n; i++) {cin>>tmp; freq[tmp-1]++;}
    for(int i=2; i<4001; i++) {
        int l = 0;
        for(int j=1; j<2001 && j<=i-j; j++) {
            if(j>=i)break;
            if(i-2000>j) j = i-2000;
            if(j==i-j) l+=freq[j-1]/2;
            else if(freq[j-1]>0 && freq[i-j-1]>0) {
                if(freq[j-1]-freq[i-j-1] > freq[i-j-1]-freq[j-1]) l+= freq[i-j-1];
                else l+=freq[j-1];
            }
        }
        if(l>ans) {ans = l; cnt=1;}
        else if(l==ans) cnt++;
        mxL[i-2] = l;
    }
    cout<<ans<<" "<<cnt<<fin;
}
