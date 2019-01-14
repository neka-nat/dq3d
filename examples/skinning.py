import numpy as np
import transformations as tf
from dq3d import quat, dualquat
from dq3d import op

link1 = dualquat(quat.identity(), quat(0.0, 0.0, 0.0, 0.0))
link2 = dualquat(quat(*tf.quaternion_from_euler(0.0, 0.0, np.deg2rad(30.0))),
                 quat(1.0, 0.0, 0.0, 0.0))

b12 = op.sclerp(link1, link2, 0.5)
print(b12)
