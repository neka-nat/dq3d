#include <vector>
#define EIGEN_QUATERNION_PLUGIN <quaternion_plugin.h>
#include <Eigen/Dense>
#define private public
#include "DualQuaternion.h"
#undef private
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/operators.h>

namespace py = pybind11;
using namespace Eigen;
typedef double Float;

PYBIND11_MODULE(_eigen_dq, m) {
    py::class_<Quaternion<Float> >(m, "Quaternion")
      .def(py::init<Float, Float, Float, Float>())
      .def_property("coeffs", &Quaternion<Float>::getCoeffs, &Quaternion<Float>::setCoeffs)
      .def_property("w", &Quaternion<Float>::getW, &Quaternion<Float>::setW)
      .def_property("x", &Quaternion<Float>::getX, &Quaternion<Float>::setX)
      .def_property("y", &Quaternion<Float>::getY, &Quaternion<Float>::setY)
      .def_property("z", &Quaternion<Float>::getZ, &Quaternion<Float>::setZ)
      .def_property("vec", &Quaternion<Float>::getVec, &Quaternion<Float>::setVec)
      .def_static("identity", &Quaternion<Float>::Identity)
      .def("set_identity", &Quaternion<Float>::setIdentity)
      .def("squared_norm", &Quaternion<Float>::squaredNorm)
      .def("norm", &Quaternion<Float>::norm)
      .def("normalize", &Quaternion<Float>::normalize)
      .def("normalized", &Quaternion<Float>::normalized)
      .def("angular_distance", &Quaternion<Float>::angularDistance<Quaternion<Float>>)
      .def("dot", &Quaternion<Float>::dot<Quaternion<Float>>)
      .def("slerp", &Quaternion<Float>::slerp<Quaternion<Float>>)
      .def("to_rotation_matrix", &Quaternion<Float>::toRotationMatrix)
      .def("conjugate", &Quaternion<Float>::conjugate)
      .def("inverse", &Quaternion<Float>::inverse)
      .def(py::self * py::self);

    py::class_<DualQuaternion<Float> >(m, "DualQuaternion")
      .def(py::init<Quaternion<Float>&, Quaternion<Float>&>())
      .def_readwrite("real", &DualQuaternion<Float>::m_real)
      .def_readwrite("dual", &DualQuaternion<Float>::m_dual)
      .def_static("zeros", &DualQuaternion<Float>::zeros)
      .def_static("identity", &DualQuaternion<Float>::identity)
      .def(py::self + py::self)
      .def(py::self - py::self)
      .def(py::self * Float())
      .def(Float() * py::self)
      .def(py::self * py::self)
      .def("from_screw", &DualQuaternion<Float>::fromScrew)
      .def("conjugate", &DualQuaternion<Float>::conjugate)
      .def("norm", &DualQuaternion<Float>::norm)
      .def("normalize", &DualQuaternion<Float>::normalize)
      .def("normalized", &DualQuaternion<Float>::normalized)
      .def("transform_point", &DualQuaternion<Float>::transformPoint)
      .def("transform_vector", &DualQuaternion<Float>::transformVector)
      .def("exp", &DualQuaternion<Float>::exp)
      .def("log", &DualQuaternion<Float>::log)
      .def("roatation", &DualQuaternion<Float>::rotation)
      .def("translation", &DualQuaternion<Float>::translation)
      .def("translation_quaternion", &DualQuaternion<Float>::translationQuaternion)
      .def("to_matrix", &DualQuaternion<Float>::toMatrix);

    m.def("expq", &expq<Float>);
    m.def("logq", &logq<Float>);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
