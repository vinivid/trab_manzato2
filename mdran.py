import sys 
import pandas as pd

methods_list = ['bubble', 'count', 'heap', 'insert', 'merge', 'quick', 'radix', 'select', 'shell']
ranns = ['ran2.dat', 'ran3.dat', 'ran4.dat', 'ran5.dat']

for method in methods_list:
    with open('./dados/{}/ran.dat'.format(method), 'w') as file:
        for ran_dat in ranns:
            data = pd.read_csv('./dados/{}/{}'.format(method, ran_dat), sep='\s+', header=None)

            for i in range(0, 4):
                count = 0

                for j in range(0, 5):
                    count += data[i][j]
                
                if i == 3 :
                    file.write('{:f} '.format(count/5))
                else:
                    file.write('{:d} '.format(int(count/5)))
        
            file.write('\n')
