import random as ra
import time as ti
#ra.seed(0)
ra.seed(ti.time())
print('sequenza di 10 numeri casuali double tra 0 (incluso) e 1 (escluso):')
for i in range(0,10):
    r=ra.random()
    print('Ho generato il numero {:18.16f}'.format(r))
