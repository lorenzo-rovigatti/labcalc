def func(arg1,arg2):
    s=''
    for i in range(0,3):
        s=s+arg1+arg2
    return s
a='a'
b='b'
print('>>>'+func(arg2=b,arg1=a))
#o equivalentemente
print('>>>'+func(a,b))
