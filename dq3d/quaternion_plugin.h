static Quaternion<Scalar> create(Scalar x, Scalar y, Scalar z, Scalar w) {return Quaternion<Scalar>(w, x, y, z);}
EIGEN_DEVICE_FUNC inline const Coefficients& getCoeffs() {return m_coeffs;}
EIGEN_DEVICE_FUNC inline void setCoeffs(const Coefficients& other) {this->coeffs() = other;}
EIGEN_DEVICE_FUNC inline Scalar getW() {return this->w();}
EIGEN_DEVICE_FUNC inline void setW(Scalar w) {this->w() = w;}
EIGEN_DEVICE_FUNC inline Scalar getX() {return this->x();}
EIGEN_DEVICE_FUNC inline void setX(Scalar x) {this->x() = x;}
EIGEN_DEVICE_FUNC inline Scalar getY() {return this->y();}
EIGEN_DEVICE_FUNC inline void setY(Scalar y) {this->y() = y;}
EIGEN_DEVICE_FUNC inline Scalar getZ() {return this->z();}
EIGEN_DEVICE_FUNC inline void setZ(Scalar z) {this->y() = z;}
EIGEN_DEVICE_FUNC inline const Matrix<Scalar,3,1>& getVec() {return this->vec();}
EIGEN_DEVICE_FUNC inline void setVec(const Matrix<Scalar,3,1>& vec) {this->vec() = vec;}
