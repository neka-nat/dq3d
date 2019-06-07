import unittest
import numpy as np
import transformations as tf
from dq3d import quat, dualquat


class Dq3dTest(unittest.TestCase):
    def test_quat(self):
        euler1 = np.random.rand(3) * 2.0 * np.pi - np.pi
        euler2 = np.random.rand(3) * 2.0 * np.pi - np.pi
        q1 = tf.quaternion_from_euler(*euler1)
        q2 = tf.quaternion_from_euler(*euler2)
        q1q2_0 = tf.quaternion_multiply(q1, q2)
        q1q2_1 = (quat(*q1) * quat(*q2)).data
        self.assertTrue(np.allclose(q1q2_0, q1q2_1))

if __name__ == "__main__":
    unittest.main()