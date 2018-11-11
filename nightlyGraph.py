import matplotlib.pyplot as plt
from numpy.random import rand
import matplotlib.gridspec as gridspec
import pandas as pd 
import re

directory = '/Users/Marissa/Documents/BostonHacks/output.txt'
#experiment = '.dat'

#savedir = '/Users/Marissa/Documents/Research/powercap_exps/plots/exp1/'

app = pd.read_csv(directory)
#print(app)

light = app.iloc[:,0]; 
temp = app.iloc[:,1];
time = list(range(0, len(light)))
 
acceleration = app.iloc[:,2]

 

gs = gridspec.GridSpec(3, 3)
fig = plt.figure(figsize=(12, 12))

fig.suptitle('Sleep for Tonight', fontsize=14)

ax1 = fig.add_subplot(gs[0, :])      
ax1.set_title("Breaths")
ax1.set_ylabel("Sleep (Breaths/Min)")
x_axis = ax1.xaxis
x_axis.set_visible(False)
ax1.plot(time, acceleration, marker='s',markersize=3)


ax2 = fig.add_subplot(gs[1, :])     
ax2.set_title("Temperature")
ax2.set_ylabel("Temperature (F)")
x_axis = ax2.xaxis
x_axis.set_visible(False)
ax2.plot(time, temp, marker='s',markersize=3, color="orange")

ax3 = fig.add_subplot(gs[2, :])     
ax3.set_title("Light")
ax3.set_ylabel("Light (lumens)")
ax3.set_xlabel("Time (ms)")
#ax1.ticklabel_format(axis='y', label='scientific',scilimits=(0,0))
ax3.plot(time, light, marker='s',markersize=3, color="purple")

plt.show()
