#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

plt.title('Traiettoria')
plt.xlabel('alpha')
plt.ylabel('G')
x, y = np.loadtxt('gittata.dat', comments=['#'], usecols=(0,1), unpack=True)
plt.plot(x, y, 'x',label='Gittatta')
plt.savefig('traiettoria.png')
plt.show()
