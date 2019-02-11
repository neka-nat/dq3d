from functools import reduce
from ._eigen_dq import quat
from ._eigen_dq import dualquat

def sclerp(dq1, dq2, t):
    """
    Screw lerp
    """
    return (dq2 * dq1.conjugate()).pow(t) * dq1

def dlb(ws, dqs):
    """
    Dual quaternion Linear Blending
    """
    return reduce(lambda x, p: x + p[0] * p[1],
                  zip(ws, dqs),
                  dualquat.zeros()).normalized()

def dib(ws, dqs, p=(1.0e-4, 1.0e-4)):
    """
    Dual quaternion Iterative Blending
    """
    b = dlb(ws, dqs)
    while True:
        x = reduce(lambda x, p: x + p[0] * (b * p[1]).log(),
                   zip(ws, dqs),
                   dualquat.zeros())
        b = b * x.exp()
        rn, dn = x.norm()
        if rn < p[0] and dn < p[1]:
            break
    return b
