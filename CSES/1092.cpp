#include<iostream>
#include<vector>
#include<algorithm>

#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)

typedef long long ll;


using namespace std;


void solve(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;

    if (sum%2==1){
        cout<<"NO";
        return;
    }
    sum /= 2;
    vector<int> t1,t2;
    while(n){
        if(sum>=n){
            t1.push_back(n);
            sum-=n;
        }
        else t2.push_back(n);
        
        n--;
    }
    cout<<"YES\n"<<t1.size()<<"\n";
    auto lambda = [](ll i) {cout << i<<" ";};
    for_each(t1.begin(),t1.end(),lambda);
    cout<<"\n"<<t2.size()<<"\n";
    for_each(t2.begin(),t2.end(),lambda);
    cout<<"\n";
}
int main(){ 
    IOS;
    solve();
    return 0;
}