#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

plt.title('Traiettoria')
plt.xlabel('x')
plt.ylabel('y')
m= np.loadtxt('ex2_3.dat', comments=['#'], usecols=(0,1,2), unpack=True)
print('data=',m)
[n,x,y]=m
plt.plot(x, y, 'x',label='Traiettoria')
plt.show()

