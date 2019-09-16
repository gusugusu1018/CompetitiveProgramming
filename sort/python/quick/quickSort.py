import matplotlib.pyplot as plt
import matplotlib.animation as animation
from random import shuffle

COLOR_PINK = '#ffc0cb'
COLOR_GOSSIP = '#cbffc0'

steps = []

def draw_bar(li, color=COLOR_PINK):
  x_axis = list(range(1, len(li) + 1))
  plt.bar(x_axis, li, tick_label=li, align='center', width=0.4, color=color)

def draw_frame(frame, sorted_li, steps):
  plt.clf()
  li = steps[frame]
  options = {'color': COLOR_GOSSIP} if li == sorted_li else {}
  draw_bar(steps[frame], **options)

def quick_sort_sub(lst, left, right):
  l = left
  r = right
  pivot = lst[int((left+right)/2)]
  while l <= r:
    while lst[l] < pivot:
      l += 1
    while lst[r] > pivot:
      r -= 1
    if l <= r:
      lst[l],lst[r] = lst[r],lst[l]
      steps.append(list(lst))
      l += 1
      r -= 1
  if r > left:
    quick_sort_sub(lst, left, r)
  if l < right:
    quick_sort_sub(lst, l, right)
 
def quick_sort(li):
  v = list(li)
  quick_sort_sub(v, 0, len(v)-1)
  return v

if __name__ == '__main__':
  li = list(range(1, 51))
  shuffle(li)

  sorted_li = quick_sort(li)
  fig = plt.figure(figsize=(6.0, 6.0))
  steps = steps + [steps[-1]] * 5 # for result
  anim = animation.FuncAnimation(fig, draw_frame,fargs=(sorted_li, steps), frames=len(steps))
  #plt.show()
  anim.save('quickSort.gif', writer='imagemagick', fps=5)
