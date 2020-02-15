def int2hex(x):
    return hex(x)

def int2bin(x):
    return bin(x)

def hex2bin(x):
    res = bin(int(x, 16))
    length = len(res) - 2
    return res, length

def bin2hex(x):
    res = hex(int(x, 2))
    length = len(res) - 2
    return res, length