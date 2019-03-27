#include <bits/stdc++.h>
using namespace std;
#define fin '\n'

string backwards (string s) {

    if(s.length()>1) backwards(s.substr(1,s.length()-1));
    cout<<s.substr(0,1);
}
void mystery(int n) {
    cout<<n%10;
    if(!n/10) mystery(n/10); cout<<n%10;
}
int factorial (int n) {
    if(n==1) return 1;
    else if(n>1) return n*factorial(n-1);
}
int recurPow (int a, int b) {
    if(b==1) return a;
    else {

        return a*recurPow(a,--b);
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s; cin>>s; backwards(s);
    //int n; cin>>n; cout<<factorial(n)<<fin;
    //int a,b; cin>>a>>b;
    //cout<<recurPow(a,b);
    //int k; cin>>k; mystery(k);
}

/*
#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int arr[100]; unordered_map<int,int> mp; unordered_set<int> st;
vector<int> ans;
int main()
{
  int n; cin>>n;
  for(int i=0; i<n; i++) {
    int tmp; cin>>tmp; mp[tmp]++;
    if(!st.count(tmp)) ans.push_back(tmp);
    st.insert(tmp);
  }
  sort(ans.begin(),ans.end());
  for(int i=0; i<ans.size(); i++) {
    cout<<ans[i]<<" "<<mp[ans[i]]<<fin;
  }

}
*/

