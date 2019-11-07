import matplotlib.pyplot as plt
import numpy as np
plt.title('Sin(x)/x')
plt.xlabel('x')
plt.ylabel('y')
x = np.linspace(-15.0, 15.0, 2)
y = 0.0*x
plt.plot(x,y,label='y=x')
x, y = np.loadtxt('sinxx.dat', usecols=(0,1), unpack=True)
x2, y2 = np.loadtxt('mesh.dat', usecols=(0,1),  unpack=True)
plt.savefig('sinx.png')
plt.plot(x,y, '-x',label='Loaded from file!')
plt.plot(x2,y2, '-x',label='Loaded from file!')
plt.show()
