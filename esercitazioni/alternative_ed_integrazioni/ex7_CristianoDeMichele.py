#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

plt.title('Morra cinese')
plt.xlabel('getto')
plt.ylabel('punteggio')
x, y = np.loadtxt('punteggio.dat', usecols=(0,1),unpack=True)
x1,y1= np.loadtxt('punteggio.dat', usecols=(0,2),unpack=True)
plt.plot(x, y, label='Giocatore A')
plt.plot(x1, y1, label='Giocatore B')
plt.xlim(1, 21)
plt.ylim(0, 21)
plt.yticks(range(0,21))
plt.xticks(range(1,21))
plt.show()
