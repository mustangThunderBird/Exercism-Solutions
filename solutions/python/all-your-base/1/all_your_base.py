import math
from itertools import dropwhile

def rebase(input_base, digits, output_base):
    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if output_base < 2:
        raise ValueError("output base must be >= 2")
    for d in digits:
        if d >= input_base or d < 0:
            raise ValueError("all digits must satisfy 0 <= d < input base")
    if input_base == output_base:
        return digits

    #remove leading zeros and return 0 if num = 0
    digits = list(dropwhile(lambda x: x == 0, digits))
    if not digits or digits == [0]:
        return [0]

    i = len(digits) - 1
    base_10_sum = 0
    while i >= 0:
        temp = digits[i] * math.pow(input_base, len(digits) - 1 - i)
        base_10_sum += temp
        i -= 1

    if output_base == 10:
        out = []
        for x in str(int(base_10_sum)):
            out.append(int(x))
        return out
    else:
        out = []
        base_10_sum = int(base_10_sum)
        while base_10_sum >= output_base:
            r = base_10_sum % output_base
            out.append(r)
            base_10_sum = base_10_sum // output_base
        if base_10_sum != 0:
            out.append(base_10_sum)
        return out[::-1]