#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import (MultipleLocator, FormatStrFormatter)
plt.title('Confronto',size='18',color='green')
ax = plt.gca()
ax.xaxis.set_major_formatter(FormatStrFormatter('%.0f'))
ax.xaxis.set_major_locator(MultipleLocator(2))
ax.xaxis.set_minor_locator(MultipleLocator(1))
ax.yaxis.set_minor_locator(MultipleLocator(0.01))
plt.xlabel('k',size='18',color='blue')
plt.ylabel('P(k)',size='18',color='blue')
x, y = np.loadtxt('istogramma.dat', unpack=True)
plt.plot(x,y, 'bx',label='istogramma')
x, y = np.loadtxt('bernoulli_20.dat', unpack=True)
plt.plot(x,y, 'r-.',label='bernoulli')
plt.legend()
plt.savefig('isto_bern.png')
plt.show()
