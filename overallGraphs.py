import matplotlib.pyplot as plt
from numpy.random import rand
import matplotlib.gridspec as gridspec
import pandas as pd 
import re
import sys

def map(x, in_min, in_max, out_min, out_max):
    return abs((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
directory = '/home/linaro/BostonHacks/data/night_data_'
savedir = '/home/linaro/BostonHacks/plots/'
extension = ".txt"

num_nights = sys.argv[1]



data = pd.DataFrame()
for name in range(0, num_nights):
    app = pd.read_csv(directory+ str(name)+extension,header=None)
    print(directory+ str(name)+extension)
    data = data.append(app) 
print(data)


#print(list(data.columns.values))
data.columns = ["time","light" , "temp", "moisture", "acceleration"]
sleepRate = data['moisture']*.3 + data['acceleration']*.7
sleepRate = [map(i,0,200, 100,0) for i in sleepRate]
data['sleep'] = sleepRate
print(data)
lightFrame = data.sort_values(by=["light"])
light = lightFrame['light'] 
sleepLight = lightFrame['sleep']

tempFrame = data.sort_values(by=['temp'])
temp = tempFrame['temp']
sleepTemp = tempFrame['sleep']
 


gs = gridspec.GridSpec(2, 2)
fig = plt.figure(figsize=(12, 12))

fig.suptitle('Overall Sleep Patterns', fontsize=14)

ax1 = fig.add_subplot(gs[0, :])      
ax1.set_title("Light")
ax1.set_ylabel("Light(percentile)")
x_axis = ax1.xaxis
x_axis.set_visible(False)
ax1.plot(sleepLight, light, marker='s',markersize=3)


ax2 = fig.add_subplot(gs[1, :])     
ax2.set_title("Temperature")
ax2.set_ylabel("Temperature(C)")
ax2.plot(sleepTemp,temp, marker='s',markersize=3, color="orange")



plt.show()
plt.savefig(savedir+str(num_nights) + "Aggregated.pdf")



