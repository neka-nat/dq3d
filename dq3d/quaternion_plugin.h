EIGEN_DEVICE_FUNC inline const Coefficients getData() const{
    return (Matrix<Scalar, 4, 1>() << this->coeffs()[3], this->coeffs()[0], this->coeffs()[1], this->coeffs()[2]).finished();}
EIGEN_DEVICE_FUNC inline void setData(const Coefficients& other) {
    this->coeffs()[3] = other[0]; this->coeffs()[0] = other[1]; this->coeffs()[1] = other[2]; this->coeffs()[2] = other[3];}
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
