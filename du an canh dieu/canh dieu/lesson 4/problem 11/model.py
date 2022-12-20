#GIAIPHB1 - Hàm giải phương trình bậc nhất 
def giaiptb1(a, b): 
    return -b/a 
 
a, b = input().split() 
a = int(a) 
b = int(b) 
 
nghiem = giaiptb1(a, b) 
 
print(f'{nghiem:.{2}f}') 