#include <iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sum = 0;
    int x;
    for (int i=1; i<n; i++){
        cin>>x;
        sum+=x;
    }
   cout<<n*(n+1)/2 - sum;
   return 0;
}