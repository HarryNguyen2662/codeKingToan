#MTIME - Thời gian gặp nhau 
def mtime(d, v1, v2): 
    t = (v1 + v2) 
    return d/t 
 
d = float(input()) 
v1 = float(input()) 
v2 = float(input()) 
timem = mtime(d, v1, v2) 
 
print('Hai xe gap nhau sau', f'{timem:.{1}f}', 'gio.') 