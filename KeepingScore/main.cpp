#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
unordered_map <string, int> mp;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s; cin>>s;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    string s1,s2,s3,s4;
    int i = 1, cnt = 0;
    for(; s.at(i) != 'D'; i++) {
        cnt++;
        char t = s.at(i);
        if(t=='K') p1+=3;
        else if(t=='A') p1+=4;
        else if(t=='Q') p1+=2;
        else if(t=='J') p1+=1;
        s1 = s1 + s.substr(i,1)+" ";
    }
    if(!cnt) p1+=3;
    else if(cnt==1) p1+=2;
    else if(cnt==2) p1++;
    i++;
    cnt = 0;
    for(; s.at(i) != 'H'; i++) {
        cnt++;
        char t = s.at(i);
        if(t=='K') p2+=3;
        else if(t=='A') p2+=4;
        else if(t=='Q') p2+=2;
        else if(t=='J') p2+=1;
        s2 = s2 + s.substr(i,1)+" ";
    }
    if(!cnt) p2+=3;
    else if(cnt==1) p2+=2;
    else if(cnt==2) p2++;
    i++;
    cnt = 0;
    for(; s.at(i) != 'S'; i++) {
        cnt++;
        char t = s.at(i);
        if(t=='K') p3+=3;
        else if(t=='A') p3+=4;
        else if(t=='Q') p3+=2;
        else if(t=='J') p3+=1;
        s3 = s3 + s.substr(i,1)+" ";
    }
    if(!cnt) p3+=3;
    else if(cnt==1) p3+=2;
    else if(cnt==2) p3++;
    i++;

     cnt = 0;
    for(; i<s.length(); i++) {
        cnt++;
        char t = s.at(i);
        if(t=='K') p4+=3;
        else if(t=='A') p4+=4;
        else if(t=='Q') p4+=2;
        else if(t=='J') p4+=1;
        s4 = s4 + s.substr(i,1)+" ";
    }
    if(!cnt) p4+=3;
    else if(cnt==1) p4+=2;
    else if(cnt==2) p4++;

    cout<<"Cards Dealt Points"<<fin;
    cout<<"Clubs "<<s1<<p1<<fin;
    cout<<"Diamonds "<<s2<<p2<<fin;
    cout<<"Hearts "<<s3<<p3<<fin;
    cout<<"Spades "<<s4<<p4<<fin;
    cout<<"Total"<<" "<<(p1+p2+p3+p4)<<fin;
}


