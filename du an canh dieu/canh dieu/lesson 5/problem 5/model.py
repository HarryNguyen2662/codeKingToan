#SUBSTR2 - Xác định xâu con từ chỉ số L đến R 
s = input() 
n = int(input()) 
while n!=0: 
    L, R = input().split() 
    L = int(L) 
    R = int(R) 
    substring = s[L:R] 
    print(substring) 
    n = n - 1 