#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include <bitset>
#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)

typedef long long ll;


using namespace std;


void solve(){
   ll n;
   cin>>n;
   for (int i=0;i<(1<<n);i++){
       int val = i^(i>>1);
       bitset<32> r(val);
       string s = r.to_string();
       cout<<s.substr(32-n)<<endl;
   } 
}
int main(){ 
    IOS;
    solve();
    return 0;
}