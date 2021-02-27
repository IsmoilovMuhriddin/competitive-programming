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
    ll n;
    ll m= pow(10,9)+7;
    ll answer = 1;
    ll base = pow(2,32);
    cin>>n;
    while(n){
        if (n>32){
            answer *= base%m;
            answer %= m;
            n -= 32;
        }
        else{
            ll base = pow(2,n);
            answer *= base%m;
            answer %= m;
            n -=n;
        }
    }
    cout<<answer;

    
}
int main(){ 
    IOS;
    solve();
    return 0;
}