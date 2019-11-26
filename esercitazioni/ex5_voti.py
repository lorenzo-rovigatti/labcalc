#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
plt.title('Esercizio 5')
plt.xlabel('trimestri')
plt.ylabel('voti')
for cc in range(1,11):
    x,y = np.loadtxt('voti_2016.dat', usecols=(0,cc), unpack=True)
    plt.xlim(-1,4.2)
    plt.plot(x, y, label='venditore #'+str(cc))
plt.xticks(range(1,5),('T1','T2','T3', 'T4'))
plt.legend()    
plt.savefig('voti_2016.png')
plt.show()
