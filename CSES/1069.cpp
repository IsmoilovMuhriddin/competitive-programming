#include<iostream>

#define IOS ios::sync_with_stdio(0)
#define rep(i,a,b) for(int i=a; i<=b; i++)


using namespace std;

int main(){ 
    IOS;

    string s; 
    cin>>s;
    int best = 0, current = 1; 
    rep(i, 0, s.size()-1){
        if(s[i]==s[i+1]){
            current+=1;
        }
        else {
            best = max(current,best);
            current = 1;
        }
    }

    cout << best;
    return 0;
}