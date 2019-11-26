#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
plt.title('Esercizio 5')
plt.xlabel('trimestri')
plt.ylabel('medie orarie')
#ogni colonna è un commesso (in tutto sono 10)
for cc in range(1,11):
    x,y = np.loadtxt('medie_2016.dat', usecols=(0,cc), unpack=True)
    plt.xlim(-1.1,4.2)
    plt.plot(x, y, label='venditore #'+str(cc))
plt.legend()    
plt.savefig('medie_2016.png')
plt.xticks(range(1,5),('T1','T2','T3', 'T4'))
plt.show()
