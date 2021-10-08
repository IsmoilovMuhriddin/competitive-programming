from collections import Counter, defaultdict


class EllysKeys:
    def getMax(self, keys):
        row = len(keys)
        col = len(keys[0])
        current = list(range(row))
        conflicts = defaultdict(set)
        for i in range(row):
            for j in range(row):
                if i != j:
                    conflicts[i].add(j)
          
        degress = {
           {"in": row, "out": row} for i in range(row)
        }
        # print(conflicts)
        for c in range(col):
            for con in conflicts:
                for node in conflicts[con]:
                    if keys[con][c] == keys[node][c] and keys[node][c] == "^":
                        conflicts[con].remove(node)
                        conflicts[node].remove(con)
                        degress[con]["in"] -=1
                        degress[node]["in"] -=1
            print(conflicts)
        return max(len(item) for item in conflicts.values()) +1



def main():
    can = "can"
    cannot = "cannot"
    Test = (
        (["..^.^^.^", "^.^^...^", "^.....^."], 2),
        (["^..^...^", ".^^.....", ".^..^...", "..^...^.", "...^^.^."], 3),
    )

    for item in Test:
        assert EllysKeys().getMax(item[0]) == item[1]


main()
