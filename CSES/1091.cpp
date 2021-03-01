#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include <bitset>
typedef long long ll;
#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)
#define all(x) x.begin(), x.end()
#define nl cout<<endl
#define print(v) for_each(v.begin(), v.end(), [](ll &x){cout<<x<<" ";}); nl;



using namespace std;

void solve(){
    int n,m;
    
    cin>>n>>m;

    multiset<ll> h;
    ll t;
    rep(i,0,n-1){
        
        cin>>t; h.insert(t);
    }
    rep(i,1,m){
        cin>>t;
        auto upper = h.upper_bound(t);
        if (upper == h.begin()){
            cout<< -1<<endl;
        }
        else{
            cout<<*(--upper)<<endl;
            h.erase(upper);
        }
        
    }
} 
int main(){ 
    IOS;
    solve();
    return 0;
}