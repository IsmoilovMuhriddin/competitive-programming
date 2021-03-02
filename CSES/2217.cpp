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
#define print_v(v) for_each(all(v), [](ll &x){cout<<x<<" ";}); nl
#define print_m(m) for_each(all(m), [](const pair<ll,ll> &x){cout<<x.F<<" : "<<x.S<<endl;}); nl
#define seev(v,n) rep(i,1,n){ ll t; cin>>t; v.push_back(t);}
#define sees(s,n) rep(i,1,n){ ll t; cin>>t; v.insert(t);}
#define see(x) cin>>x


#define pii pair<ll,ll>
#define vii vector<pii>
#define vi vector<ll>

const ll min_inf = numeric_limits<ll>::min();
const ll inf = numeric_limits<ll>::infinity();

void round_(unordered_map<ll,ll> &m, const ll n){
    ll end=0, count=0;
    for (int i=1; i<=n; i++){
        if (m[i]>m[end]){
            end=i;
        }else{
            end=i;
            count+=1;
        }
    }
    cout<<count+1<<endl;
}

void solve(){
    int n,m;    
    see(n);
    see(m);
    vii nums;
    unordered_map <ll,ll> nums_location;
    unordered_map <ll,ll> nums_order;
    rep(i,1,n){ 
        ll t; cin>>t; 
        nums_location.insert({i,t});
        nums_order.insert({t,i});
        }
    sort(all(nums));
    
    int a,b;
    ll xa,xb;
    // print_m(nums_order);
    rep(i,1,m){
        cin>>a>>b;
        xa=nums_location[a];
        xb=nums_location[b];
        swap(nums_location[a],nums_location[b]);
        swap(nums_order[xa],nums_order[xb]);
        round_(nums_order,n);
        // print_m(nums_order);
    }
    
    
} 
int main(){ 
    IOS;
    solve();
    return 0;
}