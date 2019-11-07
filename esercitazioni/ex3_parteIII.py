import matplotlib.pyplot as plt
import numpy as np
plt.title('Nzeri vs N')
plt.xlabel('N')
plt.ylabel('Nzeri')
x, y = np.loadtxt('Nzeri_vs_N.dat', usecols=(0,1), unpack=True)
plt.plot(x,y, '-x',label='Loaded from file!')
plt.xticks(np.arange(min(x), max(x)+1, 1.0))
plt.show()
