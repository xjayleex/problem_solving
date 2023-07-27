#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'weightedUniformStrings' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER_ARRAY queries
#

def weightedUniformStrings(s, queries):
    # Write your code here
    d = dict()
    for e in range(0, 26):
        d[chr(e+97)] = e + 1
    
    l = []
    prev_char, count = s[0], 1
    for e in s[1:] :
        if e == prev_char :
            count += 1
        else:
            l.append((prev_char, count))
            prev_char, count = e, 1
    else:
        l.append((prev_char, count))

    s = set()
    for e in l:
        a, c = e
        for i in range(c):
            #print(d[a],i, d[a]*i)
            s.add(d[a] * (i+1))
    
    return ["Yes" if q in s else "No" for q in queries]


        

print(weightedUniformStrings('abccddde', [1,3,12,5,9,10]))