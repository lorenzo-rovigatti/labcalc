#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

plt.title('Traiettoria')
plt.xlabel('x')
plt.ylabel('y')
m= np.loadtxt('temp.dat', comments=['#'], usecols=(1,2), unpack=True)
print('data=',m)
[x,y]=m
plt.plot(x, y, 'x',label='Traiettoria')
plt.savefig('traiettoria.png')
plt.show()

