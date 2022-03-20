import pandas as pd
from matplotlib import pyplot as plt
import numpy as np
import seaborn as sns

df = pd.read_csv("result3.txt",sep="\t")


print(df)
meanDf = pd.read_csv("result4.txt",sep="\t")
print(meanDf)

meanDf.plot(kind="bar")
plt.show()
# df.plot(x="List_Size",y=["BubbleSort",	"QuickSort",	"MergeSort",	"CountSort"],kind="line")
# plt.xlabel('List Size')
# plt.ylabel('Time in sec')
# plt.legend(title = 'Algorithms',loc = 'upper left')
# plt.title('Execution time Comparision')
# plt.savefig('p1.png')
# plt.show()

# df.plot(x="List_Size",y=["MergeSort",	"CountSort"],kind="bar")
# plt.xlabel('List Size')
# plt.xticks(rotation=45)
# plt.ylabel('Time in sec')
# plt.legend(title = 'Algorithms',loc = 'upper left')
# plt.title('Merge Sort VS Count Sort')
# plt.savefig('p2.png')
# plt.show()

# plt.figure(figsize=(15,60))
# plt.title("Value distribution in the lists")
# plt.tight_layout()
# for i in range(1,11):
#     file = "d"+str(i)+".txt"
#     with open(file) as f:
#         lines = [line.rstrip('\n') for line in f]
#     data = [i.split('\t') for i in lines][0]
#     data.pop()
#     data = [int(i) for i in data]
#     data = np.array(data)
#     plt.subplot(5,2,i)
#     plt.subplots_adjust(hspace = .34,wspace=0.137,bottom=0.079)
#     plt.hist(data,bins=500)
#     plt.xlabel("values")
#     plt.ylabel("count")

# plt.savefig("p3.png")
# plt.show()
