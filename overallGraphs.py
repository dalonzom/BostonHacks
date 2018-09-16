import matplotlib.pyplot as plt
from numpy.random import rand
import matplotlib.gridspec as gridspec
import pandas as pd 
import re

def map(x, in_min, in_max, out_min, out_max):
    return abs((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
directory = '/home/linaro/BostonHacks/night_data_'
extension = ".txt"

num_nights = 1
#savedir = '/Users/Marissa/Documents/Research/powercap_exps/plots/exp1/'

data = pd.DataFrame()
for name in range(0, num_nights):
    app = pd.read_csv(directory+ str(name)+extension,header=None)
    print(directory+ str(name)+extension)
    #print(app)
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
#ax1.set_ylabel("Sleep (Breaths/Min)")
ax1.set_ylabel("Light(lumens)")
ax1.plot(sleepLight, light, marker='s',markersize=3)


ax2 = fig.add_subplot(gs[1, :])     
ax2.set_title("Temperature")
#ax2.set_ylabel("Sleep (Breaths/Min)")
ax2.set_ylabel("Temperature(F)")
ax2.plot(sleepTemp,temp, marker='s',markersize=3, color="orange")



plt.show()



