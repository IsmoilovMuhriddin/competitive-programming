// https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/C1
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

typedef long long int ll;
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
#define print(v)                                                    \
    for_each(v.begin(), v.end(), [](int &x) { cout << x << " "; }); \
    nl;

#define printvii(v)                           \
    for_each(v.begin(), v.end(), [](pii &x) { \
        cout << x.F << " " << x.S;            \
        nl;                                   \
    });                                       \
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
bool compare_key(pair<int, ll> a, pair<int, ll> b)
{
    return a.S < b.S;
}
struct Node
{
    int add_ons = 0;
    int index;
    ll current_max = -1;
    ll self_val;
    Node *parent;
    vector<Node *> childs;
    vector<int> max_child_indexes;
};
bool compare_node(Node *a, Node *b)
{
    return a->current_max > b->current_max;
}

ull sub(ull r, ull c, ull x)
{
    ull a = x % r == 0 ? r : x % r;
    ull b = ceil(float(x) / r);
    ull ans = (a - 1) * c + b;
    return ans;
}

void update_thechild_values(Node *current)
{
    // put("calling for Node", current->index);
    // nl;
    if (current->childs.size() == 0)
    {
        current->current_max = current->self_val;
    }
    else if (current->current_max == -1)
    {
        for (auto elem : current->childs)
        {
            update_thechild_values(elem);
        }

        if (current->index != 1)
        {
            ll max_val = min_inf;
            Node *max_elem;
            for (auto elem : current->childs)
            {
                max_val = max(max_val, elem->current_max);
                if (max_val == elem->current_max)
                {
                    max_elem = elem;
                }
            }
            current->max_child_indexes = max_elem->max_child_indexes;
            current->max_child_indexes.push_back(max_elem->index);
            current->current_max = current->self_val + max_val;
        }
    }
    sort(current->childs.begin(), current->childs.end(), compare_node);
    // put("calling for Node", current->index, "current_max", current->current_max);
    // nl;
}
void remove_duplicates(unordered_map<int, unordered_set<int>> &map_edges, int index, vector<Node *> values)
{
    auto t = map_edges[index];
    for (auto it = t.begin(); it != t.end(); it++)
    {
        auto val = *it;
        map_edges[val].erase(index);
        values[val - 1]->parent = values[index - 1];
        values[index - 1]->childs.push_back(values[val - 1]);
        remove_duplicates(map_edges, val, values);
    }
}
void sub_problem()
{
    vector<Node *> values;
    multimap<ll, int, greater<ll>> max_value_index;
    int n, k;
    char c;
    see(n);
    see(k);

    // get values of each cave
    Node *root;
    rep(i, 1, n)
    {

        ll temp;
        see(temp);
        Node *node = new Node();
        node->self_val = temp;
        node->index = i;
        values.push_back(node);
        if (i == 1)
        {
            root = node;
        }
    }
    vii edges;
    unordered_map<int, unordered_set<int>> map_edges;
    rep(i, 1, n - 1)
    {
        int a, b;
        see(a);
        see(b);
        map_edges[a].insert(b);
        map_edges[b].insert(a);
    }
    remove_duplicates(map_edges, 1, values);
    rep(i, 1, n)
    {
        auto it = map_edges[i];
        put("for index:", i); nl;
        for(auto elem: it){
            cout<<elem<<" ";
        }
        nl;
    }
    update_thechild_values(root);
    for (auto elem : values)
    {
        if (elem->index != 1)
        {
            max_value_index.insert({elem->current_max, elem->index});
        }
    }

    ll answer = root->self_val;
    put("root_val -> ", answer);
    nl;
    if (root->childs.size() >= 1 && k >= 1)
    {   
        if (root->childs.size() > 1)
            {
                Node * cur = root->childs[1];
                
                auto it = max_value_index.find(cur->current_max);
                put("nearest neigh", it->F, it->S);
                for (auto index : cur->max_child_indexes)
                {
                    ll temp = values[index-1]->current_max;
                    auto child_it = max_value_index.find(temp);
                    max_value_index.erase(child_it);
                }
                max_value_index.erase(it);
                answer += cur->current_max;
            }

        rep(i, 1, k)
        {
            if (max_value_index.empty())
            {
                break;
            }

            auto it = max_value_index.begin();
            Node *cur = values[it->S - 1];
            // put("Removing index:", cur->index);
            // nl;
            for (auto index : cur->max_child_indexes)
            {
                ll temp = values[index - 1]->current_max;
                auto child_it = max_value_index.find(temp);
                max_value_index.erase(child_it);
            }
            answer += cur->current_max;
            max_value_index.erase(it);

            
        }
    }
    cout << answer << endl;

    // printvii(edges);
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