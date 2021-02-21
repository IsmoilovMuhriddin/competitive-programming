#include<iostream>

#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)

typedef long long ll;

using namespace std;
ll find_i(ll i){
    return 1+i*(i-1);
}
int main(){ 
    IOS;
    long long sum = 0;
    ll n; 
    cin>>n;
    rep(t,1,n){
        ll all = t*t*(t*t-1)/2;
        ll threaten = 4*(t-1)*(t-2);
        cout<<all-threaten<<"\n";
    }

    return 0;
}