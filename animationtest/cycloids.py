
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig = plt.figure()
ax = fig.add_subplot(121)
ax2 = fig.add_subplot(122)

def update(num):
    if len(round_circles) > 0:
        round_circles.pop().remove()
        epicycloids.pop().remove()
        points.pop().remove()
        round_circles2.pop().remove()
        epicycloids2.pop().remove()
        points2.pop().remove()

    round_circle, = ax.plot(x_move[num]+xm, y_move[num]+ym, 'b-', lw=2)
    epicycloid, = ax.plot(x[:num+1] ,y[:num+1], 'g-', lw=2)
    point, = ax.plot(x[num], y[num], 'ko', markersize=4)
    round_circles.append(round_circle)
    epicycloids.append(epicycloid)
    points.append(point)

    round_circle2, = ax2.plot(x_move2[num]+xm2, y_move2[num]+ym2, 'b-', lw=2)
    epicycloid2, = ax2.plot(x2[:num+1] ,y2[:num+1], 'g-', lw=2)
    point2, = ax2.plot(x2[num], y2[num], 'ko', markersize=4)
    round_circles2.append(round_circle2)
    epicycloids2.append(epicycloid2)
    points2.append(point2)

    theta_str = r'$\theta=$'
    fig.suptitle(theta_str + str(theta[num]/np.pi)[:4] + str(r' $\pi$'),fontsize=20)

ax.grid()
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_aspect('equal')
ax.set_xlim(-3.1,3.1)
ax.set_ylim(-3.1,3.1)
ax.set_title('rc=1, rm=1')

ax2.grid()
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_aspect('equal')
ax2.set_xlim(-4.1,4.1)
ax2.set_ylim(-4.1,4.1)
ax2.set_title('rc=2, rm=1')

#plot data

theta = np.linspace(0, 2*np.pi,100)
phi= np.linspace(0,2*np.pi,100)

rc=1
rm=1
rc2=2
rm2=1

x = (rc+rm)*np.cos(theta)-rm*np.cos(theta*((rc+rm)/rm))
y = (rc+rm)*np.sin(theta)-rm*np.sin(theta*((rc+rm)/rm))
x2 = (rc2+rm2)*np.cos(theta)-rm2*np.cos(theta*((rc2+rm2)/rm2))
y2 = (rc2+rm2)*np.sin(theta)-rm2*np.sin(theta*((rc2+rm2)/rm2))

epicycloids=[]
epicycloids2=[]
points=[]
points2=[]

xm = rm*np.cos(phi)
ym = rm*np.sin(phi)
xm2 = rm2*np.cos(phi)
ym2 = rm2*np.sin(phi)
round_circles =[]
round_circles2 =[]

xc = rc*np.cos(phi)
yc = rc*np.sin(phi)
xc2 = rc2*np.cos(phi)
yc2 = rc2*np.sin(phi)


ax.plot(xc, yc, 'k-', lw=2)#center_circle
ax2.plot(xc2, yc2, 'k-', lw=2)#center_circle

x_move = (rc+rm)*np.cos(theta)
y_move = (rc+rm)*np.sin(theta)
x_move2 = (rc2+rm2)*np.cos(theta)
y_move2 = (rc2+rm2)*np.sin(theta)

ani = animation.FuncAnimation(fig, update, 100, interval=100)
dpi=100
ani.save('episaikuroid_2subplot.gif', writer="imagemagick",dpi=dpi)
