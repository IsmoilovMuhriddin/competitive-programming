from collections import Counter


class SunShroom:
    def produceSun(self, n_times, query):
        coun = Counter(n_times)
        sm = 15
        lg = 25
        diff = 24
        longdif = 120
        result = 0
        for item in coun:
            lim = query - item
            if lim < 24:
                continue
            if lim < 120:
                result += coun[item]*sm*lim//24
            else:
                lim = lim-119
                result += 60*coun[item] + (lim//24 + 1)*coun[item]*lg
        return result


def main():
    Test = (
        (([10], 33), 0),
        (([10], 34), 15),
        (([47], 200), 110),

        (([47]*6, 200), 660),
        (([10, 100, 20, 200, 30, 300, 40, 400], 123456), 1027230)
    )   

    for item in Test:
        assert SunShroom().produceSun(item[0][0], item[0][1]) == item[1]


main()
