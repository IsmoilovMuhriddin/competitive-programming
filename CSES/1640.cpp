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
using namespace std;

void solve(){
    int n,x;
    
    cin>>n>>x;
    vii vals;

    ll t;
    rep(i,1,n){
        cin>>t;
        vals.push_back({t,i});
    }
    sort(all(vals));

    ll i = 0, j= n-1;
    while (i<j){
        ll summa = vals[i].first + vals[j].first;
        if (summa == x){
            cout<<vals[i].second <<" "<< vals[j].second<<endl;
            return;
        } else if (summa > x){
            j--;
        }
        else {i++;}
    }

    string ERROR = "IMPOSSIBLE";
    cout<<ERROR<<endl;    
} 
int main(){ 
    IOS;
    solve();
    return 0;
}