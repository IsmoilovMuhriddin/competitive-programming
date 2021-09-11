#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<cmath>
#include <bitset>
#include <limits>

using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}

typedef long long int ll;
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<=b; i++)
#define all(x) x.begin(), x.end()
#define nl cout<<endl
#define print(v) for_each(v.begin(), v.end(), [](ll &x){cout<<x<<" ";}); nl;
#define seev(v,n) rep(i,1,n){ ll t; cin>>t; v.push_back(t);}
#define sees(s,n) rep(i,1,n){ ll t; cin>>t; v.insert(t);}
#define see(x) cin>>x


#define pii pair<ll,ll>
#define vii vector<pii>
#define vi vector<ll>

const ll min_inf = numeric_limits<ll>::min();
const ll inf = numeric_limits<ll>::infinity();

bool compare_second(const pii &a, const pii &b){
    return a.S > b.S;
}
struct Node{
    ll val;
    Node* next;
    Node* prev;
};

void solve(){
    int n; see(n);
    unsigned long long int b; see(b);
    // k = k%n;
    int k;
    vi nums;
    Node *start = new Node();
    start->val = 0;
    start->next = start;
    Node *current = start;
    rep(i,1,n){
        Node* new_n = new Node();
        new_n->val = i;
        new_n->next = current->next;
        new_n->prev = current;
        current->next = new_n;
        current = new_n;
    }
    current->next = start->next;
    start ->next ->prev = current;
    current = start->next;
    if (n>1){
        k = (int)(b%n);
        if (k>0){

            rep(i,1,k){
                current = current->next;
            }
        }
    }
    while(n>0){
        if (current -> next == current){
            put(current->val);
            break;
        }
        n--;
        Node * temp = current;
        current = current->next;
        if (current -> next != temp){
            current -> prev = temp->prev;
            temp->prev -> next = current;
            put(temp->val);
            free(temp);
            k=(int)(b%n);
            if (k>0){
                rep(i,1,k){
                current = current->next;
                
                }
            }
        }
        else{
            put(temp->val);
            free(temp);
            // k=k%n;
            current -> next = current;
            current -> prev = current;
        }
        
        
    }
   
    
} 
int main(){ 
    IOS;
    solve();
    return 0;
}