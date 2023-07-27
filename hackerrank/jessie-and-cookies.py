#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'cookies' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY A
#
'''

제시는 쿠키를 좋아하며, 일부 쿠키의 단맛을 값 K보다 크게하고 싶어합니다. 이를 위해 가장 단맛이 적은 두 개의 쿠키를 반복해서 섞습니다. 이로써 특별한 혼합 쿠키가 생성되는데, 그 단맛은 다음과 같이 계산됩니다:

단맛 = (1 * 가장 단맛이 적은 쿠키 + 2 * 두 번째로 단맛이 적은 쿠키)

이 과정은 모든 쿠키의 단맛이 K 이상이 될 때까지 반복됩니다.

주어진 쿠키의 단맛을 기준으로, 필요한 최소한의 작업 수를 결정하세요. 불가능한 경우 -1을 반환하세요.'''
from heapq import *

def cookies(k, A):
    # Write your code here
    heapify(A)
    s = sum(A)
    c = 0
    while len(A) >= 2 and A[0] < k:
        first = heappop(A)
        second = heappop(A) 
        new = first + 2 * second
        c += 1
        heappush(A, new)
    if A[0] < k :
         return -1
    else:
         return c
print(cookies(9,[2,7,3,6,4,6]))