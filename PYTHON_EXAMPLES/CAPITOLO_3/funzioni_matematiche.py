import numpy as np
a=float(input('Immetti un numero: '))
print('sin('+str(a)+')=',np.sin(a))
print('cos(',a,')=',np.cos(a))
print('sqrt(',a,')=',np.sqrt(a))
#il numero prima dei due punti indica quale argomento stampare tra quelli
#forniti con format(...)
#se si omette la prima stringa di forattazione {...} corrisponde al primo 
#argomento di format, la seconda al secondo e così via.
print('exp({2:.3f})={1:8.5f} ln({0:.3f})={3:8.5f}'.format(a,np.exp(a),a,np.log(a)))
print('7/3={:3d}'.format(int(7/3)))
