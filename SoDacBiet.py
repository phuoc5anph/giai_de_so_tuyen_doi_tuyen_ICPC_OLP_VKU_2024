def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def find_gcd_of_list(numbers):
    current_gcd = numbers[0]
    for num in numbers[1:]:
        current_gcd = gcd(current_gcd, num)
    return current_gcd
def find_divisors(n):
    divisors = []
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:  
                divisors.append(n // i)
    if n > 1:
        divisors.append(n)  
    return sorted(divisors)
N = int(input())
A = []
for i in range(N):
    value = int(input())
    A.append(value)
A.sort()
B = []
for i in range(N-1):
  B.append(A[i+1]-A[i])

gcd_result = find_gcd_of_list(B)
divisors = find_divisors(gcd_result)
for divisor in divisors:
    print(divisor)
