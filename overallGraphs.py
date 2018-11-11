import matplotlib.pyplot as plt
from numpy.random import rand
import matplotlib.gridspec as gridspec
import pandas as pd 
import re

directory = '/Users/Marissa/Documents/Fall 2018/BostonHacks/FakeData.xlsx'


#savedir = '/Users/Marissa/Documents/Research/powercap_exps/plots/exp1/'

app = pd.read_excel(directory, sheet_name=None)

data = pd.DataFrame()
xls = pd.ExcelFile(directory)
names= xls.sheet_names
for name in names:
    #print(xls.parse(name))
    data = data.append(xls.parse(name)) 


lightFrame = data.sort_values(by=['Light'])
print(lightFrame)
tempFrame = data.sort_values(by=['Temp'])
light = lightFrame['Light'] 
breathLight = lightFrame['Breath']
temp = tempFrame['Temp']
breathTemp = tempFrame['Breath'] 
 


gs = gridspec.GridSpec(2, 2)
fig = plt.figure(figsize=(12, 12))

fig.suptitle('Overall Sleep Patterns', fontsize=14)

ax1 = fig.add_subplot(gs[0, :])      
ax1.set_title("Light")
ax1.set_ylabel("Sleep (Breaths/Min)")
ax1.set_xlabel("Light(lumens)")
ax1.plot(light, breathLight, marker='s',markersize=3)


ax2 = fig.add_subplot(gs[1, :])     
ax2.set_title("Temperature")
ax2.set_ylabel("Sleep (Breaths/Min)")
ax2.set_xlabel("Temperature(F)")
ax2.plot(temp, breathTemp, marker='s',markersize=3, color="orange")



plt.show()



