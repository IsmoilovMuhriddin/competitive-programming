#include<iostream>

#define IOS ios::sync_with_stdio(0)
#define rep(i,a,b) for(int i=a; i<=b; i++)


using namespace std;

int main(){ 
    IOS;
    long long sum = 0;
    int n; 
    cin>>n;
    int prev = 0; 
    rep(i, 0, n-1){
        int x ;
        cin>>x;
        if (prev==0){
            
            prev = x;
            continue;
        }
        else {
            if (x>=prev) {
                prev = x;
                continue;
            }
            sum+=prev-x;
        }
            
    }

    cout << sum;
    return 0;
}