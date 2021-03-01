#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<cmath>
#include <bitset>
#include <limits>

using namespace std;

typedef long long ll;

#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)
#define all(x) x.begin(), x.end()
#define nl cout<<endl
#define print(v) for_each(v.begin(), v.end(), [](ll &x){cout<<x<<" ";}); nl;
#define pii pair<ll,ll>
#define vii vector<pii>
#define vi vector<ll>

const ll min_inf = numeric_limits<ll>::min();
const ll inf = numeric_limits<ll>::infinity();


void solve(){
    int n;
    
    cin>>n;

    
    ll t;
    cin>>t;
    ll  current_sum=t,  max_sum = t; 
    
    rep(i,1,n-1){
        cin>>t;
        current_sum = max(current_sum+t, t);
        max_sum = max(max_sum, current_sum);
    }
    cout<<max_sum<<endl;

    
} 
int main(){ 
    IOS;
    solve();
    return 0;
}