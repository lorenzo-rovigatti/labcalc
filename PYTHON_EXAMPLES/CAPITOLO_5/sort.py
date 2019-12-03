import operator as op
a=[1,3,8,9,6,5,2,7,4]
print('a=',a)
a.sort()
print('a sorted=', a)
print()
a=['bicicletta','armadio','sala','casa']
print('a=',a)
a.sort()
print('a sorted=', a)
print()
a=[['gino',23],['pino',10],['rino',22]]
print('a=',a)
a.sort(key=op.itemgetter(1))
print('a sorted=', a)
