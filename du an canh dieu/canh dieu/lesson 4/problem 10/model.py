#SWAP - Hàm tráo đổi giá trị hai số 
def swap(a, b): 
    temp = a 
    a = b 
    b = temp 
    return a, b 
 
n, m = input().split() 
n, m = swap(n, m) 
 
print(n, m) 