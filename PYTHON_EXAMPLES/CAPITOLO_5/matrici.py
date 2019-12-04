import numpy as np
A=np.array([[1,2,3],[3,1,-2],[3,4,5]])
B=np.array([[1,3,-1],[-2,0,4],[3,-3,6]])
print('A=',A)
print('\nB=',B)
M=np.dot(A,B)
print('\nA*B=',M)
M=np.linalg.inv(A)
print('L''inversa di A è=',M, 'infatti \n', 'A*M=',np.dot(A,M))
print('\nA=',A);
b=[1,2,3]
print('\nb=',b)
x=np.linalg.solve(A,b)
print('\nLa soluzione del sistema lineare A*x=b è x=',x)
print('infatti A*x=',np.dot(A,x))
