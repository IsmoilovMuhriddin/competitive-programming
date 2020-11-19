#include <iostream>
#include <vector>

using namespace std;

bool pin(vector<int> &v, int n, int x)
{
    int odds = 0, evens = 0;
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        (*i%2!=0)?evens++:odds++;
    }
    if (x<=odds){
        return true;
    }
    else if (odds==0){
        return false;
    }
    else if (oddsw)
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int line;
    cin >> line;

    while (line > 0)
    {
        std::vector<int> numbers;

        std::copy(std::istream_iterator<int>(std::cin),
                  std::istream_iterator<int>(),
                  std::back_inserter(numbers));

        line--;
    }

    return 0;
}