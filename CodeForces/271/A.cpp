#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x;
    cin >> x;

    while (true)
    {
        x += 1;
        unordered_set<char> ss;
        for (auto c : to_string(x))
        {
            ss.insert(c);
        }

        if (ss.size() == 4)
        {
            break;
        }
    }
    cout << x;

    return 0;
}