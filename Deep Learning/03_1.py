import numpy as np
import matplotlib.pylab as plt

def step_function(x):
    return np.array(x>0, dtype=np.int32)

def sigmoid(x):
    return 1/(1+np.exp(-x))

def relu(x):
    return np.maximum(0,x)

x=np.arange(-6.0,6.0,0.1)
y1=step_function(x)
y2=sigmoid(x)
y3=relu(x)
plt.plot(x,y1,'--',label='step_function')
plt.plot(x,y2,'b-',label='sigmoid_function')
plt.plot(x,y3,'r--',label='ReLU_function')
plt.legend()
plt.ylim(-1.0,5.0)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Compare activation function')
plt.show()



