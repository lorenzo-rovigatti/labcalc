import matplotlib.pyplot as plt
import numpy as np

t, x, y = np.loadtxt('traiettoria.dat', comments=['#'], usecols=(0,1,2), unpack=True)


plt.figure(1)
plt.title('Traiettoria')
plt.xlabel('x')
plt.ylabel('y')
plt.plot(x, y, 'o',label='Traiettoria')
plt.savefig('xy.png')

plt.figure(2)
plt.title('x in funzione del tempo')
plt.xlabel('t')
plt.ylabel('x')
plt.plot(t,x,'o',label='x infunzione di t')
plt.savefig('x.png')

plt.figure(3)
plt.title('y in funzione del tempo')
plt.xlabel('t')
plt.ylabel('y')
plt.plot(t,y,'o',label='y infunzione di t')
plt.savefig('y.png')

plt.show()
