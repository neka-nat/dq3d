#include <vector>
#include <Eigen/Dense>
#include "DualQuaternion.h"
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

namespace py = pybind11;
using namespace Eigen;
typedef double Float;

namespace pybind11 { namespace detail {
    template <typename T> struct type_caster<Quaternion<T> >
    {
    public:

        PYBIND11_TYPE_CASTER(Quaternion<T>, _("Quaternion<T>"));

        bool load(py::handle src, bool convert)
        {
	    if (!convert && !py::array_t<T>::check_(src)) return false;

	    auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);
	    if (!buf) return false;

	    auto dims = buf.ndim();
	    if (dims != 1) return false;

	    value = Quaternion<T>(buf.data()[0], buf.data()[1], buf.data()[2], buf.data()[3]);
	    return true;
	}

        static py::handle cast(const Quaternion<T>& src,
			       py::return_value_policy policy, py::handle parent)
        {
	    py::array a(std::move(std::vector<size_t>({4})), src.coeffs().data());
	    return a.release();
	}
    };
}}

PYBIND11_MODULE(_eigen_dq, m) {
    py::class_<Quaternion<Float> >(m, "Quaternion")
      .def(py::init<Float, Float, Float, Float>());

    py::class_<DualQuaternion<Float> >(m, "DualQuaternion")
      .def(py::init<Quaternion<Float>&, Quaternion<Float>&>())
      .def("exp", &DualQuaternion<Float>::exp)
      .def("log", &DualQuaternion<Float>::log)
      .def("real", &DualQuaternion<Float>::real)
      .def("dual", &DualQuaternion<Float>::dual)
      .def("to_matrix", &DualQuaternion<Float>::toMatrix);


    m.def("expq", &expq<Float>);
    m.def("logq", &logq<Float>);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
