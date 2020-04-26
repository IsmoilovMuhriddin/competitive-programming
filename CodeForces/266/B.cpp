#include <iostream>

using namespace std;
string que(string &q, int n, int t);
void swap(string &s, int i, int j)
{
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    string q;
    cin >> n >> t;
    cin >> q;
    cout << que(q, n, t);

    return 0;
}

string que(string &q, int n, int t)
{
    if (t == 0)
        return q;
    for (int i = 0; i < n; i++)
    {
        if (q[i] == 'B')
        {
            int j = i + 1;
            if (j < n and q[j] == 'G')
            {
                swap(q, i, j);
                i += 1;
            }
        }
    }

    return que(q, n, t - 1);
}
