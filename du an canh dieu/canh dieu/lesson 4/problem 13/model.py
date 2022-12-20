# BCNN - Hàm tìm bội số chung nhỏ nhất 
import math 
 
def UCLN(a, b): 
    return math.gcd(a, b) 
 
def BCNN(a, b): 
    return (a * b) // (UCLN(a, b)) 
 
n = int(input()) 
m = int(input()) 
 
print('Boi chung nho nhat cua', n, 'va', m, 'la', BCNN(n, m)) 