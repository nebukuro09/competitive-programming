a, b, c = (int(raw_input()) for i in range(3))
print max(a+b+c, (a+b)*c, a*b+c, a*b*c)
