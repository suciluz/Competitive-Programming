#include <bits/stdc++.h>
using namespace std;
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    int f [1001];
    memset(f,0,sizeof(f));
    for(int i=0, tmp; i<n; i++) {
        cin>>tmp; f[tmp]++;
    }
    int v1 = 0, v11 = INT_MAX, f1 = 0, v2=INT_MAX, f2 = 0;
    for(int i=1; i<=1000; i++) {
        if(f[i] >= f1 && f[i]>0) {

            if(f[i] == f1) {
                v1 = max(v1, i);
                v11 = min(v11,i);
            }
            else v1 = i;
            f1 = f[i];
        }
        if(f[i] < f1 && f[i] >= f2 && f[i]>0) {

            if(f[i] == f2) v2 = min(v2,i);
            else v2 = i;
             f2 = f[i];
        }

    }

    cout<<v1<<" "<<v11<<" "<<v2;
}


