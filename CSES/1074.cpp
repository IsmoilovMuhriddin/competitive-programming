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
#define seev(v,n) rep(i,1,n){ ll t; cin>>t; v.push_back(t);}
#define sees(s,n) rep(i,1,n){ ll t; cin>>t; v.insert(t);}
#define see(x) cin>>x


#define pii pair<ll,ll>
#define vii vector<pii>
#define vi vector<ll>

const ll min_inf = numeric_limits<ll>::min();
const ll inf = numeric_limits<ll>::infinity();


void solve(){
    int n;    
    see(n);
    vi nums;
    seev(nums,n);
    sort(all(nums));


    ll mid_val = nums[n/2];
    ll sum1 = 0,sum2=0;
    rep(i,0,n-1){
        sum1 += abs(mid_val-nums[i]);
    }
    if (!(n&1)){
        ll mid_val = nums[(n-1)/2];
        rep(i,0,n-1){
        sum2 += abs(mid_val-nums[i]);
    }
    cout<<max(sum1,sum2)<<endl;
    }




    
} 
int main(){ 
    IOS;
    solve();
    return 0;
}