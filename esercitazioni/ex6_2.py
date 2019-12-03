#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import (MultipleLocator,FormatStrFormatter)
import matplotlib.font_manager as font_manager
plt.title('Istogramma',color='green',size='18')
ax = plt.gca()
ax.xaxis.set_major_formatter(FormatStrFormatter('%.0f'))
ax.yaxis.set_minor_locator(MultipleLocator(0.01))
ax.xaxis.set_major_locator(MultipleLocator(2))
ax.xaxis.set_minor_locator(MultipleLocator(1))
plt.xlabel('k',color='green',size='18')
plt.ylabel('P(k)',color='green',size='18')
x, y = np.loadtxt('istogramma.dat', unpack=True)
plt.plot(x,y, 'b-',label='istogramma')
plt.savefig('istogramma.png')
plt.show()
