// https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
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
#define word "Impossible"
const ll max_num = numeric_limits<ll>::max();
const ll min_inf = numeric_limits<ll>::min();
const ll inf = numeric_limits<ll>::infinity();

bool compare_second(const pii &a, const pii &b)
{
    return a.S < b.S;
}
struct Node
{
    ll val;
    Node *next;
    Node *prev;
};

ull sub(ull r, ull c, ull x)
{
    ull a = x % r == 0 ? r : x % r;
    ull b = ceil(float(x) / r);
    ull ans = (a - 1) * c + b;
    return ans;
}
void sub_problem()
{
    int n;
    char c;
    cin >> n;
    int min_ways = max_num;
    int count_ways = 0;
    vector<vector<int>> nums;
    unordered_map<int, pair<int, int>> rows, cols;           // row/col index, used_num, sum
    vector<pair<int, int>> actionable_rows, actionable_cols; // row index, min x to fill
    map<int, vector<int>> map_row, map_col;
    rep(r, 0, n - 1)
    {
        rows[r] = {0, 0};
        rows[c] = {0, 0};
    }
    // vector<int, int> rows; // row, sum, used vals;
    // vector<int, int> cols; // col, sum, used vals;
    rep(r, 0, n - 1)
    {
        nums.push_back({});
        rep(j, 0, n - 1)
        {
            cin >> c;
            int num;
            bool used = true;
            if (c == 'X')
            {
                num = 1;
            }
            else if (c == '.')
            {
                num = 0;
                used = false;
            }
            else
            {
                num = -1;
            }
            nums[r].push_back(num);
            if (used)
            {
                rows[r].F = rows[r].F + 1;
                cols[j].F = cols[j].F + 1;
            }

            rows[r].S = rows[r].S + num;
            cols[j].S = cols[j].S + num;
        }
        if (rows[r].S == rows[r].F and rows[r].F < n)
        {
            int action  = n - rows[r].F;
            actionable_rows.push_back({r, action});
            min_ways = min(min_ways, action);
            map_row[action].push_back(r);
        }
    }
    // sort(actionable_rows.begin(), actionable_rows.end(), compare_second);
    // for_each(actionable_rows.begin(), actionable_rows.end(), [](pair<int, int> &x)
    //          { cout << x.F << " " << x.S << endl; });
    // nl;
   
    rep(r, 0, n - 1)
    {
        // put("for col:", r, "sum", cols[r].F, "used", cols[r].S);
        
        
        if (cols[r].S == cols[r].F && cols[r].F < n)
        {
            // put("inside if"); nl;
            int action = n - cols[r].F;
            if (action == 1)
            {
                // put("inside 1 case"); nl;
                bool crossed = false;
                if (actionable_rows.size() > 0)
                {
                    for (auto it = actionable_rows.begin(); it != actionable_rows.end() && (*it).S == 1; it++)
                    {
                        if (nums[(*it).F][r] == 0)
                        {
                            crossed = true;
                        }
                    }
                }
                if (!crossed)
                {
                    actionable_cols.push_back({r, action});
                    
                    min_ways = min(min_ways, action);
                    map_col[action].push_back(r);
                }
            }
            else
            {
                actionable_cols.push_back({r, action});
                
                min_ways = min(min_ways, action);
                map_col[action].push_back(r);
            }
            
        }
    }

    int found_ways = 0;
    if (map_col.find(min_ways) != map_col.end()){
        found_ways += map_col[min_ways].size();
    }

    if (map_row.find(min_ways) != map_row.end()){
        found_ways += map_row[min_ways].size();
    }

    found_ways>0?(cout<<min_ways<<" "<<found_ways):cout<<word;
    nl;
}
void solve()
{
    int t, k;
    see(t);
    rep(i, 1, t)
    {
        cout<<"Case #"<<i<<": ";
        sub_problem();
    }
}
int main()
{
    IOS;
    solve();
    return 0;
}