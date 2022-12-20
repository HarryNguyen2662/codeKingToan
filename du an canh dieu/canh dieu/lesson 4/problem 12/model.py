#BMIFUNC - Hàm tính chỉ số sức khoẻ 
def bmi(w, h): 
    return w/(h/100)**2 
 
w, h = input().split() 
w = float(w) 
h = float(h) 
 
bmi_val = bmi(w, h) 
 
print('Chi so BMI: ', f'{bmi_val:.{2}f}') 