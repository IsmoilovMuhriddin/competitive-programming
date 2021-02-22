#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)

typedef long long ll;


using namespace std;


void solve(){
    ll n;
    ll current=5;
    ll answer = 0;
    vector<int> powerFive;
    cin>>n;
    while(n>=current){
        answer += n/current;
        current *=5;
    }
    cout<<answer;
    
}
int main(){ 
    IOS;
    solve();
    return 0;
}