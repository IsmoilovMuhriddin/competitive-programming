#include <iostream>

using namespace std;
int main(){
    long long n;
    cin>>n;

    while(true){
        cout<<n<<" ";
        if(n==1) break;
        if(n%2==1) n=n*3+1;
        else n/=2;
    }
    cout<<"\n";

    return 0;
}