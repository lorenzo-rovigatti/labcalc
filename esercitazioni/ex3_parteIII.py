import matplotlib.pyplot as plt
import numpy as np
plt.title('Nzeri vs N')
plt.xlabel('Nzeri')
plt.ylabel('N')
x, y = np.loadtxt('Nzeri_vs_N.dat', usecols=(0,1), unpack=True)
plt.plot(x,y, '-x',label='Loaded from file!')
plt.show()
