import numpy as np
import transformations as tf
from dq3d import quat, dualquat
from dq3d import op
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3
import matplotlib.animation as animation

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
mids = []
euler1 = np.random.rand(3) * 2.0 * np.pi - np.pi
euler2 = np.random.rand(3) * 2.0 * np.pi - np.pi
dq1 = dualquat(quat(*tf.quaternion_from_euler(*euler1)), np.random.rand(3))
dq2 = dualquat(quat(*tf.quaternion_from_euler(*euler2)), np.random.rand(3))
def update_anim(i):
    plt.cla()
    t = i * 0.01
    mid = op.sclerp(dq1, dq2, t)
    pts = np.array([dq1.translation(), dq2.translation()])
    mids.append(mid.translation())
    mids_arr = np.array(mids)
    ax.scatter(pts[:, 0], pts[:, 1], pts[:, 2])
    ax.scatter(mids_arr[:, 0], mids_arr[:, 1], mids_arr[:, 2])
    ax.set_xlim(0, 1)
    ax.set_ylim(0, 1)
    ax.set_zlim(0, 1)

ani = animation.FuncAnimation(fig, update_anim, interval=10, frames=100, repeat=False)
# ani.save('sclerp.gif', writer="imagemagick")
plt.show()