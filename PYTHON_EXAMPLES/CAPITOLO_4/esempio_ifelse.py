a=int(input('Immetti un intero a: '))
if a > 0:
    print('a è maggiore di 0!')

if a < 0:
    print('a è negativo!')
else:
    print('a è positivo o 0!')

if a==1:
    print('a è proprio 1!')
else:   
    print('a non è 1')
    
print('a è {:s}'.format('positivo' if a > 0 else 'negativo'))
c='p' if a > 0 else 'n'
if a > 0:
    c='p'
else:
    c='n'
print('c =', c)   
