#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)

typedef long long ll;


using namespace std;


void solve(){
    string s, ans="";
    cin>>s;
    map<char,int> freq;
    for (char c: s){
        if (freq.find(c) == freq.end()){
            freq[c] = 1;
        }
        else freq[c] +=1;
    }
    int odd_keys_counts = 0;
    for(pair<char,int> k : freq){
        if (k.second %2 ==1 ) odd_keys_counts+=1;
    }
    if (odd_keys_counts>1) {
        cout<<"NO SOLUTION";
        return;
    }
    char temp ;
    
    for(pair<char,int> k : freq){
        if (k.second %2 ==1 ) {temp = k.first;}
        rep(i,1,k.second/2){
            ans+=k.first;
        }
    }
    string ans_rev=ans;
    reverse(ans_rev.begin(),ans_rev.end());
    if (odd_keys_counts) ans += temp;
    ans +=ans_rev;
    cout<<ans<<endl;
    
}
int main(){ 
    IOS;
    solve();
    return 0;
}