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
#define V 26
#define INF INT_MAX
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

ull sub(ull r, ull c, ull x)
{
    ull a = x % r == 0 ? r : x % r;
    ull b = ceil(float(x) / r);
    ull ans = (a - 1) * c + b;
    return ans;
}

int min_cost_path(char u, char dest, unordered_map<char, bool> &visited, unordered_map<char, map<char, int>> &cost_graph)
{
    // put("calculating", u, dest);
    // nl;
    if (cost_graph[u][dest] != INF)
    {
        // put("end of calculating", u, dest, cost_graph[u][dest]); nl;
        return cost_graph[u][dest];
    }
    if (u == dest)
    {
        // put("end of calculating", u, dest, 0);
        // nl;
        cost_graph[u][u]=0;
        return 0;
    }
    
    visited[u] = 1;
    int ans = INF;

    // DFS
    
    for (auto it = cost_graph[u].begin(); it != cost_graph[u].end(); it++)
    {
        if (it->second != INF and !visited[it->first])
        {
            int cost = min_cost_path(it->first, dest, visited, cost_graph); // (*it).second.second != INF && !visited[it->second->first]
            if (cost < INF)
            {

                // Taking the minimum cost path
                ans = min(ans, cost_graph[u][it->first] + cost);
            }
        }
    }
    cost_graph[u][dest] = ans;
    visited[u] = 0;
    // put("end of calculating", u, dest, ans);
    // nl;
    return ans;
}

int find_min_substitute(
    unordered_map<char, map<char, int>> &cost_graph,
    map<char, int> &word_frequency,
    unordered_set<char> &used_char)
{
    int ans = -1;
    int min_cost = INF;
    int len_used_words = used_char.size();
    for (auto e : used_char)
    {
        int current = 0;
        bool broken = false;
        for (auto j : word_frequency)
        {
            int val = cost_graph[j.F][e];
            if (val == INF)
            {
                broken = true;
                break;
            }
            else
            {
                current += j.S * val;
            }
        }
        if (!broken)
        {
            min_cost = min(min_cost, current);
        }
    }
    if (min_cost == INF)
    {
        ans = -1;
    }
    else
    {
        ans = min_cost;
    }
    return ans;
}
void sub_problem()
{
    unordered_map<char, map<char, int>> cost_graph;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        for (char i = 'A'; i <= 'Z'; i++)
        {
            cost_graph[c][i] = INF;
        }
    }
    string word;
    see(word);
    int n;
    see(n);
    char source, dest;
    unordered_set<char> used_chars;
    map<char, int> word_frequency;
    for (auto e : word)
    {
        word_frequency[e] += 1;
        used_chars.insert(e);
    }
    // get values of each cave
    Node *root;
    rep(i, 1, n)
    {
        ll temp;
        see(source);
        see(dest);
        cost_graph[source][dest] = 1;
        used_chars.insert(source);
        used_chars.insert(dest);
    }
    unordered_map<char, bool> visited;
    // put("Word Freq ---", word);
    // nl;
    // for (auto e : word_frequency)
    // {
    //     put(e.F, "--", e.S);
    //     nl;
    // }
    // for (auto e : used_chars)
    // {
    //     put(e, " ");
    //     cost_graph[e][e] = 0;
    // }
    // nl;
    // put(INF);nl;
    for (auto c : used_chars)
    {
        // put(e.F, ": ", e.S);
        // nl;
        for (auto e : word_frequency)
        {
          
            cost_graph[e.first][c] = min_cost_path(e.first, c, visited, cost_graph);
          
        }
    }
    int ans = find_min_substitute(cost_graph, word_frequency, used_chars);
    cout << ans << endl;
    // put("cost_graph ---");
    // nl;

    // for (auto e : used_chars)
    // {
    //     for (auto j : word_frequency)
    //     {
    //         ;
    //         nl;
    //         {
    //             put("FROM- ", j.first, "-> ", e, " ==", cost_graph[j.F][e]);
    //             nl;
    //         }
    //     }
    // }
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