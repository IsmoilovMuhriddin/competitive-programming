// Excel Sheet Column Number

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        unordered_map<char, int> columns;
        for (int i = 65; i < 65 + 26; i++)
        {
            char key = i;
            columns[key] = i - 64;
        }
        int count = 0;
        int size = s.size();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            count += columns[s[i]] * pow(26, size-1-i);
        }
        return count;
    }
};

int main()
{

    cout << Solution().titleToNumber("FXSHRXW");
}