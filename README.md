# dq3d
[![PyPI version](https://badge.fury.io/py/dq3d.svg)](https://badge.fury.io/py/dq3d)

Dual quaternion for 3d geometric operations.

## Installation
Running `pip install transformations dq3d` should work. 

### macOS
On macOS, if you get an error `ld: library not found for -lstdc++` do the following. Go to `/Library/Developer/CommandLineTools/Packages/` and install the package `macOS_SDK_headers_for_macOS_10.14.pkg`. They try installing again.

## examples

### Skinning
This example is a demonstration of skinning with Dual quaternion Linear Blending.

![skinning](images/skinning.gif)

### Sclerp
This example is a demonstration that interpolates between two randomly generated dual quaternions with ScLerp.

![sclerp](images/sclerp.gif)

## References
* [Skinning with Dual Quaternions](https://www.cs.utah.edu/~ladislav/dq/index.html)
