import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import scipy.optimize as opt  

QTT_COMP = 0
QTT_SWAP = 1
SIZE = 2
TIME = 3

def quad_f(x, a, b, c):
    return a * ((x * b) ** 2) + c

def nlogn(x, a, b):
    return a *(x) * np.log2(x) + b

def lin(x, a, b):
    return a*x + b

DOMAIN = np.linspace(5, 100000, 1000)

methods_list = ['bubble', 'count', 'heap', 'insert', 'merge', 'quick', 'radix', 'select', 'shell']
methods_colors = {'bubble' : 'crimson',
                  'count' : 'darkblue',
                  'heap' : 'black',
                  'insert' : 'olive',
                  'merge' : 'green',
                  'quick' : 'indigo',
                  'radix' : 'orange',
                  'select' : 'slategrey',
                  'shell' : 'aqua'} 

methods_labels = {'bubble' : 'Bubble Sort',
                  'count' : 'Contagem dos Menores',
                  'heap' : 'Heap Sort',
                  'insert' : 'Insertion Sort',
                  'merge' : 'Merge Sort',
                  'quick' : 'Quick Sort',
                  'radix' : 'Radix Sort',
                  'select' : 'Selection Sort',
                  'shell' : 'Shell Sort'}

linear_methods = ['count', 'radix']
quad_methods = ['bubble', 'insert', 'shell', 'select']
nlogn_methods = ['heap', 'merge', 'quick']

params_creord = {}
params_decreord = {}
params_ran = {}

creord = {}
decreord = {}
ran = {}

for method in methods_list:
    creord_data = pd.read_csv('./dados/{}/creord.dat'.format(method), sep='\s+', header=None)   
    decreord_data = pd.read_csv('./dados/{}/decreord.dat'.format(method), sep='\s+', header=None) 
    ran_data = pd.read_csv('./dados/{}/ran.dat'.format(method), sep='\s+', header=None)

    creord.update({method : creord_data})
    decreord.update({method : decreord_data})
    ran.update({method : ran_data})

fig, ax = plt.subplots()

def opti_method(func, method : str, x : int, y : int, data_dict : dict, param_dict : dict):
    n, _ = opt.curve_fit(func, data_dict[method][x], data_dict[method][y])

    param_dict.update({method : n})

def ran_opti_methods(x, y, data_dict : dict, param_dict : dict):
    for method in linear_methods:
        opti_method(lin, method, x, y, data_dict, param_dict)
    
    for method in quad_methods:
        opti_method(quad_f, method, x, y, data_dict, param_dict)
    
    for method in nlogn_methods:
        opti_method(nlogn, method, x, y, data_dict, param_dict)

def plt_lin(x, y, data_dict : dict, param_dict : dict):
    for method in linear_methods:
        plt.plot(data_dict[method][x], data_dict[method][y], color=methods_colors[method], marker='o', linestyle='None', linewidth=1, markersize=2)
        plt.plot(DOMAIN, lin(DOMAIN, param_dict[method][0], param_dict [method][1]), color=methods_colors[method], label=methods_labels[method])

def plt_quad(x, y, data_dict : dict, param_dict : dict):
    for method in quad_methods:
        plt.plot(data_dict[method][x], data_dict[method][y], color=methods_colors[method], marker='o', linestyle='None', linewidth=1, markersize=2)
        plt.plot(DOMAIN, quad_f(DOMAIN, param_dict[method][0], param_dict[method][1], param_dict[method][2]), color=methods_colors[method], label=methods_labels[method])

def plt_nlogn(x, y, data_dict : dict, param_dict : dict):
    for method in nlogn_methods:
        plt.plot(data_dict[method][x], data_dict[method][y], color=methods_colors[method], marker='o', linestyle='None', linewidth=1, markersize=2)
        plt.plot(DOMAIN, nlogn(DOMAIN, param_dict[method][0], param_dict[method][1]), color=methods_colors[method], label=methods_labels[method])

#ran_opti_methods(SIZE, TIME, creord, params_creord)
#plt_lin(SIZE, TIME, creord, params_creord)
#plt_quad(SIZE, TIME, creord, params_creord)
#plt_nlogn(SIZE, TIME, creord, params_creord)

#ran_opti_methods(SIZE, TIME, decreord, params_decreord)
#plt_lin(SIZE, TIME, decreord, params_decreord)
#plt_quad(SIZE, TIME, decreord, params_decreord)
#plt_nlogn(SIZE, TIME, decreord, params_decreord)

ran_opti_methods(SIZE, TIME, ran, params_ran)
plt_lin(SIZE, TIME, ran, params_ran)
plt_quad(SIZE, TIME, ran, params_ran)
plt_nlogn(SIZE, TIME, ran, params_ran)

ax.set_xlabel("Quantidade de entradas")
ax.set_ylabel("Tempo de processamento em segundos")
plt.legend(loc="upper left")

plt.show()