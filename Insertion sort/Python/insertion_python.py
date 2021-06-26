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
    d[i]=int(filter(str.isdigit, d[i]))
print d;

    
for j in range(0, len(d)):
    x=d[j]
    i=j-1
    while i>=0 and d[i]>x:
        d[i+1]=d[i]
        i=i-1
    d[i+1]=x

print d
print("--- %s seconds ---" % (time.time() - start_time))
print longitud

