import csv
import random
import time


##################### 2000 DATOS #########################
start_time=time.time()
with open("File_1000.txt") as csvfile:
    for i in csv.reader(csvfile):
        longitud=len(i);
        
d=i;
for i in range(0,longitud):
    d[i]=int(filter(str.isdigit, d[i]));
print d;

###########

def merge_sort(lista):
    if len(lista) > 1:
        mitad = len(lista) // 2
        primera_mitad = lista[:mitad]
        segunda_mitad = lista[mitad:]

        merge_sort(primera_mitad)
        merge_sort(segunda_mitad)
        i = 0
        j = 0
        k = 0

        while i < len(primera_mitad) and j < len(segunda_mitad):
            if primera_mitad[i] < segunda_mitad[j]:
                lista[k] = primera_mitad[i]
                i += 1
            else:
                lista[k] = segunda_mitad[j]
                j += 1
            k += 1
        
        while i < len(primera_mitad):
            lista[k] = primera_mitad[i]
            i += 1
            k += 1
        
        while j < len(segunda_mitad):
            lista[k] = segunda_mitad[j]
            j += 1
            k += 1


merge_sort(d)

##########
print d;
print("--- %s seconds ---" % (time.time() - start_time));
