def tinhtoan(N):
    k = N // 2
    if(N%2==0):
      return k;
    return k-N;
N = int(input())
result = tinhtoan(N)
print(result)