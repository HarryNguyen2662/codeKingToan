a, b ,c = map(int, input().split())
s = max(a,b,c)
s1 = 0
s2= 0
if a < s: 
	s1 = s1 + 1
	s2 = max(s2,a)
if c < s: 
	s1 = s1 + 1
	s2 = max(s2,c)
if b < s:
	s1 = s1 + 1
	s2 = max(s2,b)
if s1 == 1:
	if (s-s2)%2 == 0:
		print((s-s2)//2)
	else: print((s-s2+1)//2+1)
else :
	s3 = 0
	if a < s2: 
		s3 = max(s3,a)
	if c < s2: 
		s3 = max(s3,c)
	if b < s2:
		s3 = max(s3,b)
	ans = s - s2
	if (s-s3)%2 == 0:
		print((s-s3)//2+ans)
	else: print((s-s3+1)//2+1+ans)
