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
    b = dualquat.zeros()
    for w, d in zip(ws, dqs):
        b = b + w * d
    b.normalize()
    return b

def dib(ws, dqs, p=(1.0e-4, 1.0e-4)):
    """
    Dual quaternion Iterative Blending
    """
    b = dlb(ws, dqs)
    while True:
        x = dualquat.zeros()
        for w, d in zip(ws, dqs):
            x = x + w * (b * q).log()
        b = b * x.exp()
        rn, dn = x.norm()
        if rn < p[0] and dn < p[1]:
            break
    return b