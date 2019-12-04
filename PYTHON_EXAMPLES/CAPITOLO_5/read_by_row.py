#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
#ogni riga è un commesso (in tutto sono 10)
data = np.loadtxt('read_by_row.dat', unpack=False)
cc=1
for l in data:
    print('row #'+str(cc)+'=', l)
    cc+=1;
plt.plot(data[0],data[1],label="by row")
plt.show()
