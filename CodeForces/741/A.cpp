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

typedef long long int ll;
typedef unsigned long long int ull;
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
struct Node{
    ll val;
    Node* next;
    Node* prev;
};

ull sub(ull r, ull c, ull x){
    ull a= x%r == 0?r:x%r;
    ull b= ceil(float(x)/r);
    ull ans = (a-1)*c+b;
    return ans;
}
void solve(){
    int t; see(t);
    ull m, n, x;
    rep(i,1,t){
        cin>>n>>m>>x;
        put(sub(n,m,x)); nl;
    }
} 
int main(){ 
    IOS;
    solve();
    return 0;
}