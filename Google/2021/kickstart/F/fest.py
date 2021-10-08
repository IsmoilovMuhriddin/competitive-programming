import sys

def solve():
    # mm = 10
    d, n, k = [int(x) for x in input().split()]
    # arr = []
    line = []
    for i in range(n):
        val, start, end = [int(x) for x in input().split()]
        line.append([start, +val, i])
        line.append([end+1, -val, i])
        # arr.append([val, start, end, i])
    
    # sorted_arr = sorted(arr, key = lambda x: (x[1], x[2], x[0]))
    
    line = sorted(line, key=lambda x: (x[0], -x[1]))
    res = []
    curr_max = 0
    for item in line:
        if item[1]>0:
            res.append(item[1])
        else:
            res.remove(-item[1])
        # print(item, res)
        curr_max = max(curr_max, sum(sorted(res[:k])))
    
    
    print(curr_max)
def main():
    t = int(input())
    for i in range(t):
        print(f"Case #{i+1}: ", end="")
        solve()    
main()