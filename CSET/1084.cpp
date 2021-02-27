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
   int n,m;
   ll k;
   cin>>n>>m>>k;
   vector<ll> a(n), b(m);
   rep(i,0,n-1){
       cin>>a[i];
   }
   rep(i,0,m-1){
       cin>>b[i];
   }
   int count = 0;
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
    int j = 0;
    
    for (int i=0; i<n; i++){
        
        for (; j<m; j++){
            if (b[j] < a[i]-k){
                continue;
            }
            if (b[j] >= a[i]-k && b[j]<= a[i]+k){
                count +=1;
                j++;
                break;
            }
            if (b[j] > a[i]+k){
                break;
            }
        }
    }

    cout<<count<<endl;
   


} 
int main(){ 
    IOS;
    solve();
    return 0;
}