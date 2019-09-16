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

def merge_sort(lst, low, high):
  if low >= high:
    return
  mid = int((low+high)/2)
  merge_sort(lst, low, mid)
  merge_sort(lst, mid+1, high)
  for i in range(low, mid+1):
    tmp_array[i] = lst[i]
  j = high
  for i in range(mid+1, high+1):
    tmp_array[i] = lst[j]
    j -= 1
  i = low
  j = high
  for k in range(low, high+1):
    if tmp_array[i] <= tmp_array[j]:
      lst[k] = tmp_array[i]
      i += 1
    else:
      lst[k] = tmp_array[j]
      j -= 1
  steps.append(list(lst))

if __name__ == '__main__':
  lst = list(range(1, 51))
  shuffle(lst)
  MAX_ELEMENTS = len(lst)
  tmp_array = [None for _ in range(MAX_ELEMENTS)]
  merge_sort(lst, 0, len(lst)-1)
  fig = plt.figure(figsize=(6.0, 6.0))
  steps = steps + [steps[-1]] * 5  # for result
  anim = animation.FuncAnimation(fig, draw_frame, fargs=(lst, steps), frames=len(steps))
  # plt.show()
  anim.save('mergeSort.gif', writer='imagemagick', fps=5)
