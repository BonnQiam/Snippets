# 去除周边空白，使图片紧凑

一般情况下，我们按照如下方式生成的图片周围会有一片空白区域，不利于应用，比如放在论文里面很不方便。

```python
# coding=utf-8
import matplotlib.pyplot as plt
import math

x = range(10)
y = range(10, 20)

plt.plot(x, y)
plt.savefig("./new_result.png", dpi=120, bbox_inches='tight')
plt.show()
```

# 修改字体

```python
plt.rcParams['font.size'] = 12 # 全局

# 代码中的“...”代表省略的其他参数
ax = plt.subplot(111)
# 设置刻度字体大小
plt.xticks(fontsize=20)
plt.yticks(fontsize=20)
# 设置坐标标签字体大小
ax.set_xlabel(..., fontsize=20)
ax.set_ylabel(..., fontsize=20)
# 设置图例字体大小
ax.legend(..., fontsize=20)
```