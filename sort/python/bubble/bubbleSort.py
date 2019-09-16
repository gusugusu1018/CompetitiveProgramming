import matplotlib.pyplot as plt
import matplotlib.animation as animation
from random import shuffle

COLOR_PINK = '#ffc0cb'
COLOR_GOSSIP = '#cbffc0'

def draw_bar(li, color=COLOR_PINK):
  x_axis = list(range(1, len(li) + 1))
  plt.bar(x_axis, li, tick_label=li, align='center', width=0.4, color=color)

def draw_frame(frame, sorted_li, steps):
  plt.clf()
  li = steps[frame]
  options = {'color': COLOR_GOSSIP} if li == sorted_li else {}
  draw_bar(steps[frame], **options)

def bubble_sort(li):
  v = list(li)
  steps = []
  for i in range(0, len(v)):
    for j in range(1, len(v) - i):
      if v[j-1] > v[j]:
        v[j], v[j-1] = v[j-1], v[j]
      if len(steps) == 0 or steps[-1] != v:
        steps.append(list(v))
  return v, steps

if __name__ == '__main__':
  li = list(range(1, 26))
  shuffle(li)

  sorted_li, steps = bubble_sort(li)
  fig = plt.figure(figsize=(6.0, 6.0))
  steps = steps + [steps[-1]] * 5 # for result
  anim = animation.FuncAnimation(fig, draw_frame,fargs=(sorted_li, steps), frames=len(steps))
  #plt.show()
  anim.save('bubbleSort.gif', writer='imagemagick', fps=5)
