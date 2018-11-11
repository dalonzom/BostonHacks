import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import pandas as pd 
import sys 

def map(x, in_min, in_max, out_min, out_max):
    return abs((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);



directory = '/home/linaro/BostonHacks/data/night_data_'+sys.argv[1]
extension = '.txt' 
savedir = '/home/linaro/BostonHacks/plots/'+sys.argv[1]

app = pd.read_csv(directory+extension)

time = (app.iloc[:,0]*.001)/60; 
light = app.iloc[:,1]; 
temp = app.iloc[:,2];
moisture = app.iloc[:,3]
acceleration = app.iloc[:,4]
sleepRate = moisture*.3 + acceleration*.7
sleepRate = [map(i,0,200, 100,0) for i in sleepRate]

 

gs = gridspec.GridSpec(3, 3)
fig = plt.figure(figsize=(12, 12))

fig.suptitle('Sleep for Tonight', fontsize=14)

ax1 = fig.add_subplot(gs[0, :])      
ax1.set_title("Sleep Quality")
ax1.set_ylabel("Sleep Quality")
x_axis = ax1.xaxis
x_axis.set_visible(False)
ax1.plot(time, sleepRate, marker='s',markersize=3)


ax2 = fig.add_subplot(gs[1, :])     
ax2.set_title("Temperature")
ax2.set_ylabel("Temperature (C)")
x_axis = ax2.xaxis
x_axis.set_visible(False)
ax2.plot(time, temp, marker='s',markersize=3, color="orange")

ax3 = fig.add_subplot(gs[2, :])     
ax3.set_title("Light")
ax3.set_ylabel("Light (percentile)")
ax3.set_xlabel("Time (min)")
#ax1.ticklabel_format(axis='y', label='scientific',scilimits=(0,0))
ax3.plot(time, light, marker='s',markersize=3, color="purple")

plt.show()

plt.savefig(savedir+ ".pdf")
