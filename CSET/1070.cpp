#include<iostream>

#define IOS ios::sync_with_stdio(0)
#define rep(i,a,b) for(int i=a; i<=b; i++)


using namespace std;

int main(){ 
    IOS;
    long long sum = 0;
    int n; 
    cin>>n;
    if (n<=3 && n>1) {
        cout<<"NO SOLUTION";
        return 0;
    }
    rep(i, 1, n/2){
        int x=2;
        cout<<(x*i)<<" ";
    }
    for(int i=1; i<=n;i+=2){
        cout<<i<<" ";
    }
    return 0;
}