#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
plt.title('Esercizio 5')
plt.xlabel('trimestri')
plt.ylabel('medie orarie')
#ogni colonna è un commesso (in tutto sono 10)
for cc in range(1,11):
    x,y = np.loadtxt('medie_2016.dat', usecols=(0,cc), unpack=True)
    plt.plot(x, y, label='venditore #'+str(cc))
plt.legend()    
plt.savefig('medie_2016.png')
plt.xticks(np.arange(4),('T1','T2','T3', 'T4'))
plt.show()
