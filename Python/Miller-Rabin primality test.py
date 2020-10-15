primes = ( 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 )

def isPrime(n):
    # Limits the value of n to odd numbers more than 3
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if not n & 1:
        return False
    
    # Write n as 2^r·d + 1 with d odd (by factoring out powers of 2 from n − 1)
    r, d = 0, n - 1
    while not d & 1:
        r, d = r + 1, d >> 1
    
    for a in primes:
        # pick a integer a in the range [2, n − 2]
        if not 2 <= a <= n - 2:
            break

        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        
        for i in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

print(isPrime(int(input())))