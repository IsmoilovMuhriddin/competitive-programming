
def sub_string_counts(key, map_substr, start, end, word):
    # print(key, start, end)
    if key in map_substr:
        return map_substr[key]
    
    if start == end:
        map_substr[key] = (0, key)
        return map_substr[key]
    one_step_before = sub_string_counts(key[:-1], map_substr, start, end-1, word)
    curr = 0
    latest = ""
    f = 'F'
    if one_step_before[1] != f and word[end] != f and word[end] != one_step_before[1]:
        curr = 1
        latest = word[end]
    else:
        if word[end] != f and word[end] != one_step_before[1]:
            latest = word[end]
        else:
            latest = one_step_before[1]
    value = one_step_before[0] + curr
    map_substr[key] = (value, latest)
    return map_substr[key]

def sub_problem():
    n = int(input())
    word = input()
    num  = 10 ** 9 +7
    map_substr = {}
    count = 0
    for i in range(n):
        for j in range(i,n):
            curr=sub_string_counts(word[i:j+1], map_substr, i, j, word)
            count = (count + curr[0])% num
    print(count)

def main():
    n = int(input())
    for i in range(1,n+1):
        print(f"Case #{i}: ", end="")

        sub_problem()

main()