import matplotlib.pyplot as plt
import matplotlib.animation as animation

if __name__ == "__main__":
    #figオブジェクトを作る
    fig = plt.figure()
    #空のリストを作る
    ims = []
    #10個の画像を繋げたアニメーションにする
    for i in range(10):
        #1枚1枚のグラフを描き、appendしていく
        im = plt.plot([0, i], [0, i])
        ims.append(im)
    #アニメーション作成
    ani = animation.ArtistAnimation(fig, ims, interval=200, repeat_delay=1000)
    ani.save("test.gif",writer="imagemagick")
