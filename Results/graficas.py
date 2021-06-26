import matplotlib.pyplot as plt
import numpy as np

#'''
# Los rangos de las X se definen :

#data de bubbleSort(aleatorios)
x = [.1,.5,1,2,3,4,5,6,7,8,9,20,30,40,50,60,70,80,90,100]
y = [0,0,0,4,10,18,29,47,58,74,93,451,1028,1821,2881,4088,5523,7507,9303,11711]
y2= [0,1,2,6,12,23,37,50,68,90,113,492,1027,1768,2906,4154,5734,7400,9296,11492]

# Se imprime el gráfico
plt.plot(x, y,'r')
plt.title("selection sort en C++")
plt.xlabel("datos / 1000")
plt.ylabel("tiempo de procesamiento(milisegundos)")
plt.plot(x, y, 'o')
plt.show()

plt.plot(x, y2,'r')
plt.title("bubble sort en C++")
plt.xlabel("datos / 1000")
plt.ylabel("tiempo de procesamiento(milisegundos)")
plt.plot(x, y2, 'o')
plt.show()


fig, ax = plt.subplots()
ax.plot(x, y)
ax.plot(x, y2,'r')
plt.title("selection vs bubble sort en C++")
plt.xlabel("datos / 1000")
plt.ylabel("tiempo de procesamiento(milisegundos)")
plt.show()
