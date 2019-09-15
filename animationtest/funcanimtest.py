import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def update(i, x, y, ax1, ax2):
    if i != 0:
        plt.cla() #現在描写されているグラフを消去
    ax1.plot(x[0:i], y[0:i], "forestgreen")
    ax2.plot(x[0:i], -y[0:i], "darkred")
    ax1.set_xlim(0,10)
    ax1.set_ylim(0,100)
    ax2.set_xlim(0,10)
    ax2.set_ylim(-100,0)

def draw():
    fig = plt.figure() #figure objectを取得
    fig, (ax1, ax2) = plt.subplots(2,1)
    x = np.arange(0, 10, 1)
    y = x ** 2
    ani = animation.FuncAnimation(fig, update, fargs = (x, y, ax1, ax2), interval = 100, frames = 10)
    ani.save("test.gif", writer = 'imagemagick')

if __name__ == '__main__':
    draw()
