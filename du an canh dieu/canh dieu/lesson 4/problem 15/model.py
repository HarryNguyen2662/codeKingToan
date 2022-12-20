#DIENTICHTG - Hàm tính diện tích tam giác bằng công thức Heron 
import math 
 
def dientich(a, b, c): 
    p = (a + b + c)/2 
    area = math.sqrt(p * (p - a) * (p - b) * (p - c)) 
    return area 
 
res = -1000000 
for i in range(1, 4): 
    a, b, c = input().split() 
    a = float(a) 
    b = float(b) 
    c = float(c) 
    dientichtg = dientich(a, b, c) 
    res = max(res, dientichtg) 
 
print('Dien tich tam giac lon nhat:', f'{res:.{2}f}') 