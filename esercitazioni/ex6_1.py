#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import (MultipleLocator, FormatStrFormatter)
import matplotlib.font_manager as font_manager
plt.title('Distribuzione Binomiale',size='18',color='blue')
ax = plt.gca()
ax.xaxis.set_major_formatter(FormatStrFormatter('%.0f'))
ax.yaxis.set_minor_locator(MultipleLocator(0.01))
ax.xaxis.set_major_locator(MultipleLocator(2))
ax.xaxis.set_minor_locator(MultipleLocator(1))
plt.xlabel('k',size='18',color='blue')
plt.ylabel('P(k)',size='18',color='blue')
x, y = np.loadtxt('bernoulli_20.dat', unpack=True)
plt.plot(x,y, 'b-',label='bernoulli')
plt.savefig('bernoulli_20.png')
plt.show()
