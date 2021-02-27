#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include <bitset>
#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)

typedef long long ll;


using namespace std;


void solve(){
   string n;
   cin>>n;
   sort(n.begin(),n.end());
   vector<string>ans;
   do{
       ans.push_back(n);
   }while(next_permutation(n.begin(),n.end()));
    cout<<ans.size()<<"\n";
    for (auto s: ans) cout<<s<<"\n";
} 
int main(){ 
    IOS;
    solve();
    return 0;
}