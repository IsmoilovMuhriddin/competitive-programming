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
   int n;
   cin>>n;
   vector<ll> v(n);
   rep(i,0,n-1){
       cin>>v[i];
   }
   if (n == 1){
       cout<<0<<endl;
       return;
   }
   sort(v.begin(),v.end());
   int count = 0;
   ll temp = v[0];
   
   rep(i,1, v.size()-1){
       if (v[i] != temp){
           count+=1;
           temp=v[i];
       } 
   }
   
   cout<<count+1<<endl;


} 
int main(){ 
    IOS;
    solve();
    return 0;
}