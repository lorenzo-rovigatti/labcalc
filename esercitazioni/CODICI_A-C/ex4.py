import matplotlib.pyplot as plt
import numpy as np

nbins=36

plt.figure(1)
plt.title('isto.dat')
plt.xlabel('numeri')
plt.ylabel('occorrenza')
x, y = np.loadtxt('isto.dat', usecols=(0,1), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True)
plt.savefig('isto1.png')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('istoN-10.dat', usecols=(0,1), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,label='N=10')


plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('istoN-100.dat', usecols=(0,1), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,color='magenta',label='N=100')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('istoN-10000.dat', usecols=(0,1), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,color='green',label='N=10000')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('istoN-100000.dat', usecols=(0,1), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,color='red',label='N=100000')


plt.figure(2)
x = np.linspace(0, nbins+1, 2)
y = 0.0*x+(1./nbins)
plt.plot(x,y,'--',label='expected value',color='black')
plt.savefig('isto2.png')


plt.legend()
plt.show()
