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

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}

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

bool compare_second(const pii &a, const pii &b){
    return a.S > b.S;
}

void solve(){
    ll x; see(x);
    int n; see(n);
    set<ll> d = {x};
    unordered_map <ll,ll> mp;
    mp[x]=1;
    set<ll> up = {0,x};
    set<ll> low = {-x, 0};
    ll t,a,b;
    rep(i,0,n-1){
        cin>>t;
        a = *up.upper_bound(t);
        b = -*low.lower_bound(-t);
        up.insert(t); low.insert(-t);
        mp[a-b]--;
        if (mp[a-b]==0){
            d.erase(a-b);
        }
        d.insert(a-t); d.insert(t-b);
        mp[a-t]++; mp[t-b]++;
        put(*d.rbegin());
        }
    
    
} 
int main(){ 
    IOS;
    solve();
    return 0;
}