#include <iostream>

using namespace std;
string ans = "";
string answ(string &x)
{
    if (x.length() == 0)
    {
        return ans;
    }

    if (x.substr(0, 1) == ".")
    {
        ans.append("0");
        x.erase(0, 1);
    }
    else if (x.substr(0, 2) == "-.")
    {
        ans.append("1");
        x.erase(0, 2);
    }
    else if (x.substr(0, 2) == "--")
    {
        ans.append("2");
        x.erase(0, 2);
    }
    return answ(x);
}

int main()
{
    string x, answer;
    cin >> x;
    cout << answ(x);
    return 0;
}