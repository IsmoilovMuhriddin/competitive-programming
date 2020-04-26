
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

struct Point
{
    int x;
    int y;
    Point(int a, int b) : x(a), y(b){};
};
int manhattan_distance(const Point &A, const Point &B);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int SIZE = 5;
    int lines = 0;
    int cur_x = -1, cur_y = -1;
    string line;

    while (lines < SIZE)
    {
        getline(cin, line);
        line.erase(remove_if(
                    line.begin(),
                    line.end(),
                    [](unsigned char x) { return std::isspace(x); }),
                line.end());
        if (cur_x < 0)
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '1')
                {
                    cur_x = lines;
                    cur_y = i;
                    break;
                }
            }
        }

        lines++;
    }
    Point mid(SIZE/2,SIZE/2);
    Point cur(cur_x,cur_y); 
    cout<<manhattan_distance(mid,cur);
    return 0;
}

int manhattan_distance(const Point &A, const Point &B)
{
    return abs(A.x - B.x) + abs(A.y - B.y);
}