from mpl_toolkits.axes_grid1 import host_subplot
from mpl_toolkits import axisartist
import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.size'] = 12

x_data = ['Extended-DSH + SA (28nm)', 'Extended-DSH + SA (32nm)', 'Extended-DSH + SA (40nm)',
          'Extended-DSH + Adam (28nm)', 'Extended-DSH + Adam (32nm)', 'Extended-DSH + Adam (40nm)',
          'Our model + Adam (28nm)', 'Our model + Adam (32nm)', 'Our model + Adam (40nm)']
          #'Data-driven model (28nm)', 'Data-driven model (32nm)', 'Data-driven model (40nm)']

ax_data = [15329, 15000, 15327,
           1500, 1500, 1500,
           150, 300, 150]
           #0, 0, 0] # epoch

ax1_data_1 = [0.99, 0.44, 0.93,
              0.93, 0.20, 0.81,
              0.99, 0.98, 0.99]
              #0.99, 0.94, 0.98]    # dishing r2

for i in range(len(ax1_data_1)):
    ax1_data_1[i] += 1

ax1_data_2 = [0.66, -0.33, 0.06,
              0.76, 0.33, 0.68,
              0.81, 0.77, 0.86]
              #0.72, 0.93, 0.86] # erosion r2

for i in range(len(ax1_data_2)):
    ax1_data_2[i] += 1

ax2_data_1 = [4.83, 79.7, 21.22,
              13.54, 95.22, 34.77,
              3.97, 16.68, 9.50]
              #4.10, 30.49, 12.57]    # dishing RMSE
ax2_data_2 = [30.34, 73.74, 49.93 ,
              25.87, 52.49, 29.27,
              22.63, 30.77, 19.41]
              #30.44, 22.77, 26.38] # erosion RMSE

bar_width = 0.1

plt.figure(figsize=(40, 10))

ax=host_subplot(111, axes_class=axisartist.Axes)
plt.subplots_adjust(right=0.75)

ax1 = ax.twinx()
ax2 = ax.twinx()

ax2.axis["right"] = ax2.new_fixed_axis(loc="right", offset=(60, 0))

ax1.axis["right"].toggle(all=True)
ax2.axis["right"].toggle(all=True)

########################################## ax

ax.set_ylim([100,16000])
ax.set_yticks=np.arange(100,16000)
ax.set_yticklabels=np.arange(100,16000,1000)
#ax2.set_ylabel('this is y3',fontsize=18,fontweight='bold')

lns1=ax.bar(x=np.arange(len(x_data)), width=bar_width, height=ax_data,label='Epoch',fc = 'red',alpha=0.8)

for a,b in enumerate(ax_data):
    plt.text(a,b+0.0005,'%s' % b,ha='center')

########################################## ax1
ax1.set_ylim([0,3])
ax1.set_yticks=np.arange(0,3)
ax1.set_yticklabels=np.arange(0,3)
#ax1.set_ylabel('this is y2',fontsize=18,fontweight='bold')

lns11=ax1.bar(x=np.arange(len(x_data))+bar_width*1, width=bar_width, height=ax1_data_1,label='Dishing R2',fc = 'green',alpha=0.8)
lns12=ax1.bar(x=np.arange(len(x_data))+bar_width*2, width=bar_width, height=ax1_data_2,label='Erosion R2', fc = 'blue', alpha=0.8)

######################################## ax
ax2.set_ylim([0,100])
ax2.set_yticks=np.arange(0,100)
ax2.set_yticklabels=np.arange(0,100)
#ax.set_ylabel('this is y1',fontsize=18,fontweight='bold')

lns21=ax2.bar(x=np.arange(len(x_data))+bar_width*3, width=bar_width, height=ax2_data_1, label='Dishing RMSE', fc = 'purple',alpha=0.8)
lns22=ax2.bar(x=np.arange(len(x_data))+bar_width*4, width=bar_width, height=ax2_data_2, label='Erosion RMSE', fc = 'black',alpha=0.8)

##########################################

ax.set_xlabel("Model")

ax.set_ylabel("Epoch")
ax1.set_ylabel("R2 + 1")
ax2.set_ylabel("RMSE(Å)")

plt.xticks(np.arange(len(x_data))+bar_width*2, x_data)

ax.legend()

plt.savefig('28nm.svg',bbox_inches='tight')
plt.show()
plt.plot()