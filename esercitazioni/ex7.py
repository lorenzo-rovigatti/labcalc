import matplotlib.pyplot as plt
import numpy as np

plt.figure(1)
plt.title('Coordinate')
plt.xlabel('x')
plt.ylabel('z')
x, z = np.loadtxt('coordinate.dat', usecols=(0,2), delimiter=' ', unpack=True)
plt.plot(x,z,'x',label="punti")
plt.ylim(-2,2)
plt.xlim(-2,2)

plt.savefig('coordinate.png')


plt.legend()
plt.show()
