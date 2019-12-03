#!/usr/bin/python3
print('while () ....')
i=0
while i < 3:
    print('i=', i)
    i+=1
print('')
for i in range(0,3):
    print('i=', i)

# uso di break (si può usare in tutti i costrutti per iterazioni)
# while () ....
print('')
print('break in ciclo while () ....')
i=0
while True:
    print('i=', i)
    i+=1
    if i == 3:
        break
    
# uso di continue
print('\ncontinue in ciclo while () ....')
i=0
while i < 3:
    if i==1:
        i+=1
        continue
    print('i=', i)
    i+=1
