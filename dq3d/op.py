from ._eigen_dq import quat
from ._eigen_dq import dualquat

def sclerp(dq1, dq2, t):
    return (dq2 * dq1.conjugate()).pow(t) * dq1
