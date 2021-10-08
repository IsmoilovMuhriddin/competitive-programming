// https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/A1
//
//
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <limits>

using namespace std;

template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }

typedef int ll;
typedef unsigned long long int ull;
#define F first
#define S second
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
    cout.tie(NULL);
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define nl cout << endl
#define print(v)                                                   \
    for_each(v.begin(), v.end(), [](ll &x) { cout << x << " "; }); \
    nl;
#define seev(v, n)      \
    rep(i, 1, n)        \
    {                   \
        ll t;           \
        cin >> t;       \
        v.push_back(t); \
    }
#define sees(s, n)   \
    rep(i, 1, n)     \
    {                \
        ll t;        \
        cin >> t;    \
        v.insert(t); \
    }
#define see(x) cin >> x

#define pii pair<ll, ll>
#define vii vector<pii>
#define vi vector<ll>
const ll max_num = numeric_limits<ll>::max();
const ll min_inf = numeric_limits<ll>::min();
const ll inf = numeric_limits<ll>::infinity();

bool compare_second(const pii &a, const pii &b)
{
    return a.S < b.S;
}

struct Node
{
    int index;
    ll current_max = -1;
    ll self_val;
    Node *parent;
    vector<Node *> childs;
};
bool compare_node(Node *a, Node *b)
{
    return a->current_max > b->current_max;
}

void sub_problem()
{
    int n;
    string word;
    see(n);
    see(word);
    int count = 0;
    char latest='0';
    char f = 'F', x = 'X', o = 'O';

    for (auto e : word)
    {
        if (e == f)
        {
            continue;
        }
        if (latest == '0')
        {
            latest = e;
        }
        else if (latest != e)
        {
            count += 1;
            latest = e;
        }
        // put(e, count, latest); nl;
    }
    cout << count << endl;
}


void solve()
{
    int t, k;
    see(t);
    rep(i, 1, t)
    {
        cout << "Case #" << i << ": ";
        sub_problem();
    }
}
int main()
{
    IOS;
    solve();
    return 0;
}