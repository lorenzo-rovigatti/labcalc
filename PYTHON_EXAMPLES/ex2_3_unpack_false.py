#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

plt.title('Traiettoria')
plt.xlabel('x')
plt.ylabel('y')
m= np.loadtxt('temp.dat', comments=['#'], usecols=(1,2), unpack=False)
print('data=',m)
#x,y,z,w=m
#plt.plot(x, y, 'x',label='Traiettoria')
#plt.savefig('traiettoria.png')
#plt.show()

