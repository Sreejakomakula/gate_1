import numpy as np
import matplotlib.pyplot as plt

# Read data from the "out.dat" file
data = np.genfromtxt("out.dat")

# Split the data into x, p_x, y, and p_y
x = data[:10, 2]
p_x = data[100000:100010, 2]
y = data[200000:200010, 2]
p_y = data[300000:300010, 2]
 
# Create plots
plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(x, p_x)
plt.xlabel('x')
plt.ylabel('p_x')
plt.title('PMF of X')

plt.subplot(1, 2, 2)
plt.plot(y, p_y)
plt.xlabel('y')
plt.ylabel('p_y')
plt.title('PMF of Y')

plt.tight_layout()
plt.savefig("../figs/fig.png")
plt.show()
