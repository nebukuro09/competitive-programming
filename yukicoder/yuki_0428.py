S = '0.1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950515253545556575859606162636465666768697071727374757677787980818283848586878889909192939495969798991'[::-1]
N = input()
ans = ''
c = 0

for s in S:
    if s == '.':
        ans += '.'
        continue
    d = int(s)*N+c
    c = d/10
    d -= c*10
    ans += str(d)
if c > 0:
    ans += str(c)
print ans[::-1]
