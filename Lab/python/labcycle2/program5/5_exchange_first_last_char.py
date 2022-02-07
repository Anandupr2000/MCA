def rearrange(string):	
	l = []
	l.append(string[0])
	l.append(string[len(string)-1])
	s = ""
	s = s+l[1]
	for i  in range(1,len(string)-1):
		s  = s+string[i]
	s=s+l[0]
	return s

print(rearrange(input("Enter a string : ")))
