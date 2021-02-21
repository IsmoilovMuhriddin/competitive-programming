#include<iostream>

#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(int i=a; i<=b; i++)

typedef long long ll;

using namespace std;
ll find_i(ll i){
    return 1+i*(i-1);
}
int main(){ 
    IOS;
    long long sum = 0;
    int t; 
    cin>>t;
    while(t--){
        int y,x;
        cin>>y>>x;
        ll m = max(x,y);
        ll base = find_i(m);
        ll diff = abs(x-y);
        if ((m&1 && m==y) || (m%2==0 && m==x)) base -= diff;
        else if (m&1 && m==x || (m%2==0 && m==y)) base+=diff;
        cout<<base<<"\n";
    }

    return 0;
}