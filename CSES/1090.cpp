#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<algorithm>
#include<cmath>
#include <bitset>
typedef long long ll;
#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)
#define print(v) for_each(v.begin(), v.end(), [](ll &x){cout<<x<<" ";})



using namespace std;

void solve(){
    int n;
    ll x;
    cin>>n>>x;

    vector<ll> p(n),b(n);
    deque<ll> d;
    rep(i,0,n-1){
        cin>>p[i];
    }
    
    int count = 0;
    if (b.size() == 1) {
        count +=1;
        cout<<count<<endl;
        return ;
    }
    
    sort(p.begin(),p.end(), greater<ll>());
    
    for(auto i:p){
        d.push_back(i);
    }

    while(!d.empty()){
        
        ll first = d.front(); d.pop_front();
        if (!d.empty() && x-first >= d.back()){
            d.pop_back();
        }
        count+=1; 
    }


    cout<<count<<endl;
} 
int main(){ 
    IOS;
    solve();
    return 0;
}