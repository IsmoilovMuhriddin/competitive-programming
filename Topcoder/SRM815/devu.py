from collections import Counter


class DevuAndRabbitNumbering:
    def canRenumber(self, rabbitIds):
        can = "can"
        cannot = "cannot"

        coun = Counter(rabbitIds)
        unique = set(rabbitIds)
        un = sorted(set(rabbitIds))
        for item in un:
            if coun[item] > 3:
                return cannot
            elif coun[item] > 1:
                if item - 1 in unique and item + 1 in unique:
                    return cannot
                elif item - 1 not in unique:
                    unique.add(item-1)
                    coun[item] -= 1
                elif item + 1 not in unique:
                    unique.add(item+1)
                    coun[item] -= 1
        return can


def main():
    can = "can"
    cannot = "cannot"
    Test = (
        ([1, 2, 3], can),
        ([1, 2, 2], can),
        ([2, 4, 2, 2, 1, 2], cannot),
        ([1, 2, 4, 2, 6, 6, 7], can),
        ([960, 578, 296, 414, 352, 610, 872, 556, 113, 818, 194, 804,
         141, 859, 761, 887, 3, 952, 234, 667, 196, 693, 783], can),
        ([97, 64, 22, 17, 75, 97, 85, 68, 35, 82, 64, 10, 71, 11, 64, 64, 94, 52, 28, 40, 48, 46,
         5, 82, 39, 65, 2, 93, 43, 50, 44, 90, 69, 72, 94, 6, 62, 17, 12, 12, 84, 33, 38], cannot),


    )

    for item in Test:
        assert DevuAndRabbitNumbering().canRenumber(item[0]) == item[1]


main()
