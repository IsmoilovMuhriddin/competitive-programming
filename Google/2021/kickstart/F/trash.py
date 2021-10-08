import sys

def solve():
    mm = 10
    n = int(input())
    s = input()
    ans = []
    count = 0
    for i,j in enumerate(s):
        if j=="1":
            ans.append(i)
            count+=1
    res = 0
    # print(ans, s)
    for i in range(count):
        if i == count - 1 and ans[i] < n-1:
            x = n-1-ans[i]
            res += x*(x+1)/2
            # print("right", i, ans[i], res)
        if i==0 and ans[i] > 0:
            res += ans[i]*(ans[i]+1)/2
            # print("left", i, ans[i], res)
        if i+1<count:
            x = ans[i+1] - ans[i]-1
            a = x//2
            res += a*(a+1)
            if x%2:
                res+= 1+a
            # print("mid", i, ans[i], res)
        # print(ans[i], res)
    
    print(int(res))
def main():
    t = int(input())
    for i in range(t):
        print(f"Case #{i+1}: ", end="")
        solve()    
main()