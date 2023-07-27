from math import gcd
def getTotalX(a, b):
    # Write your code here
    lcd_of_a = a[0]
    for i in range(1, len(a)):
        lcd_of_a = lcd_of_a*a[i] // gcd(lcd_of_a,a[i])
    candidates = []
    for i in range(1, b[0]+1):
        div = lcd_of_a * i
        if div > b[0] :
            break
        if b[0] % div == 0 :
            candidates.append(div)
    #print(candidates)
    cnt = 0
    for candidate in candidates :
        ok = True
        for b_elem in b:
            if b_elem % candidate != 0 :
                ok = False
                break
        if ok :
            cnt += 1
    return cnt

print(getTotalX([1],[100]))