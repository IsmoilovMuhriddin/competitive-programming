#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)

typedef long long ll;


using namespace std;


void solve(){
    ll a,b,t;
    cin>>t;
    while(t--){
    cin>>a>>b;
    if ((2*a-b)>=0 && (2*b-a)>=0 &&(
        (2*a-b)%3==0 || (2*b-a)%3==0)
        )
         cout<<"YES\n";
    else cout<<"NO\n";
    }
    
}
int main(){ 
    IOS;
    solve();
    return 0;
}