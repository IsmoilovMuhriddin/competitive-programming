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
#define prints(v)                                                    \
    for_each(v.begin(), v.end(), [](bool &x) { cout << x << " "; }); \
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
struct info_l
{
    int value = 0;
    char latest_val = '0';
};
info_l sub_string_counts( unordered_map<int, char> &index_bits, unordered_map<int, unordered_map<int, info_l>> &map_sub, int start, int end)
{
    if (map_sub.count(start) > 0 and map_sub[start].count(end) > 0)
    {
        //exists
        return map_sub[start][end];
    }

    if (start == end)
    {
        info_l b;
        map_sub[start][end] = b;
        map_sub[start][end].latest_val = index_bits[start];
        return map_sub[start][end];
    }

    info_l one_step_before = sub_string_counts(index_bits, map_sub, start, end - 1);
    info_l ans;
    char f= 'F';
    int curr = 0;
    bool alternated = false;
    char new_latest_val;
    if (one_step_before.latest_val != f && index_bits[end] != f && index_bits[end] != one_step_before.latest_val)
    {
        curr = 1;
        ans.latest_val = index_bits[end];
    }
    else
    {   
        if (index_bits[end] != f and index_bits[end] != one_step_before.latest_val){
            ans.latest_val = index_bits[end];
        }
        else{
            ans.latest_val = one_step_before.latest_val;
        }
        
    }
    ans.value = one_step_before.value + curr;
    map_sub[start][end] = ans;
    // put(start, end, ans.value, curr, ans.latest_val);
    // nl;
    return map_sub[start][end];
}
void sub_problem()
{
    int modulo = pow(10, 9) + 7;
    int n;
    string word;
    see(n);
    see(word);
    int count = 0;
    char latest = '0';
    char f = 'F', x = 'X', o = 'O';
    vector<bool> bits;
    unordered_map<int, char> index_bits;
    unordered_map<int, unordered_map<int, info_l>> map_sub;
    string bit_string = "";
    int bit_string_size = word.length();
    int word_size = 0;
    for (auto e : word){
        index_bits[word_size] = e;
        word_size +=1;
    }
    count = 0;
    if (bit_string_size > 1)
    {
        for (int i = 0; i < bit_string_size; i++)
        {
            for (int j = i; j < bit_string_size; j++)
            {

                info_l temp = sub_string_counts(index_bits, map_sub, i, j);
                count = (count + temp.value) % modulo;
            }
        }
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