import numpy as np
a=float(input('Immetti un numero: '))
print('sin('+str(a)+')=',np.sin(a))
print('cos(',a,')=',np.cos(a))
print('sqrt(',a,')=',np.sqrt(a))
print('exp({:.3f})={:8.5f} ln({:.3f})={:8.5f}'.format(a,np.exp(a),a,np.log(a)))
