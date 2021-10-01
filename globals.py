c = 10
#reset()

def reset():
    global c
    c -= 10
    not_reset()
    print c


def not_reset():
    global c
    c -= 5
    print c
    
#not_reset()
reset()
print c

def gcd(x, y): 
   while y: 
       x, y = y, x % y 
   return x 

def nthUglyNumber(n: int, a: int, b: int) -> int:
        low = 1
        high = 2 * 10 ** 9
        ab = (a * b) / gcd(a, b)
        while low < high:
            mid = (low + high) / 2
            count = mid / a + mid / b - mid / ab
            if (count < n):
                low = mid + 1
            else:
                high = mid
        return int(low)

print(nthUglyNumber(5, 2, 4))
