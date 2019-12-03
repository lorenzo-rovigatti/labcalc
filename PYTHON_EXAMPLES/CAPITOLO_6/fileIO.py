data=[[1.0, 1.0],[2.0, 4.0],[3.0,4.0],[10.0, 100.0]]
 
print('\ndati da scrivere')

print(data)

print('writing')
with open('myfile.dat','w') as f:
    for i in range(0,4):
        for j in range(0,2):
            f.write(str(data[i][j])+' ')
        f.write('\n')

print('reading')
with open('myfile.dat') as f:
    l=f.readlines()

print(l)
