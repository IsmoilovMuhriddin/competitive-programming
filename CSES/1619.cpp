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
#define pii pair<ll,ll>
#define vii vector<pii>

using namespace std;

void solve(){
    int n;
    
    cin>>n;

    vii h;
    ll a,b;
    rep(i,0,n-1){
        cin>>a>>b; 
        h.push_back({a, 1});
        h.push_back({b, -1});
    }
    sort(all(h));
    ll count = 0, max_count = 0;
    for (auto p: h){
        if (p.second == -1){
            count -=1;
        }
        else{
            count +=1;
        }
        max_count = max(max_count,count);
    }
    cout<<max_count<<endl;
} 
int main(){ 
    IOS;
    solve();
    return 0;
}