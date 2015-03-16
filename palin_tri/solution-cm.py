
def is_palindrome(n):
    original = str(n)
    rev = original[::-1]
    return original == rev

def solve():

    palindromes = filter(is_palindrome, range(100, 1000))

    for m in palindromes:
        for n in palindromes:
            if m == n:
                continue
            for o in palindromes:
                if m == o or n == o:
                    continue
                if is_palindrome(m+n+o) and m+n+o < 1000:
                    # print str(m) + " " + str(n) + " " + str(o)
                    return m+n+o

print solve()
