def func1(arg):
    arg=arg+' ciao'
def func2(arg):
    arg=arg.append('ciao')
a='hallo'    
print('prima a=',a)
func1(a)
print('dopo a=',a)
l=['ciao']
print('prima l=',l)
func2(l)
print('dopo l=',l)
