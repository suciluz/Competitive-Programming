#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    set<int> st;
    for(int i=0; i<n; i++) {
        auto it = st.lower_bound(a[i]);
        if(it!=st.end()) st.erase(it);
        st.insert(a[i]);
        /*for( it = st.begin(); it!= st.end(); it++) {
        cout<<*it<<" ";
    } cout<<fin;*/
    }
    cout<<st.size()<<fin;
}
