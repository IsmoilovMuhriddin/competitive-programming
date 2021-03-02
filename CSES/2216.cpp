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
#define F first
#define S second
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
    vii nums;
    
    rep(i,0,n-1){ ll t; cin>>t; nums.push_back({t,i});}
    sort(all(nums));
    
    ll end=0, count=0;
    for (int i=1; i<n; i++){
        if (nums[i].second>nums[end].second){
            end=i;
        }else{
            end=i;
            count+=1;
        }
    }
    cout<<count+1<<endl;
    
} 
int main(){ 
    IOS;
    solve();
    return 0;
}