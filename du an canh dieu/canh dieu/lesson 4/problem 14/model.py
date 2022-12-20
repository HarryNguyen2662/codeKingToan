# DIENTICHTG - Hàm tính diện tích tam giác bằng công thức Heron 
import math 
 
def dientich(a, b, c): 
    p = (a + b + c)/2 
    area = math.sqrt(p * (p - a) * (p - b) * (p - c)) 
    return area 
 
a, b, c = input().split() 
a = float(a) 
b = float(b) 
c = float(c) 
dientichtg = dientich(a, b, c) 
 
print('Dien tich tam giac:', f'{dientichtg:.{2}f}') 