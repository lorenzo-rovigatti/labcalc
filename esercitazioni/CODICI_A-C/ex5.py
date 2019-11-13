#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np


plt.figure(1)
plt.title('Esercizio 5')
plt.xlabel('anno2016')
plt.ylabel('medie orarie')

#ogni colonna è un commesso (in tutto sono 8)
for cc in range(0,10):
    media= np.loadtxt('media.dat', usecols=(2*cc, ) ,comments=['#'], unpack=True)
    plt.plot(media,'-o',label='Commesso #'+str(cc+1))
    plt.xticks(range(0,len(media)),('T1','T2','T3', 'T4'))
    plt.legend()
plt.savefig('Mediatrimestri.png')    

plt.figure(2)
plt.title('Esercizio 5')
plt.xlabel('anno2016')
plt.ylabel('voti')

#ogni colonna è un trimestre (in tutto sono 8)
for cc in range(0,10):
    voto= np.loadtxt('media.dat', usecols=(2*cc+1, ),comments=['#'], unpack=True)
    plt.plot(voto,'-x',label='Commesso #'+str(cc+1))
    plt.xticks(range(0,len(voto)),('T1','T2','T3', 'T4'))
    plt.legend()
plt.savefig('VotiTrimestri.png')
plt.show()






