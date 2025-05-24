// CMatrix.h
#ifndef CMATRIX_H
#define CMATRIX_H

#include <vector>
#include "CVector.h"

class CMatrix {
private:
    std::vector<std::vector<double>> data;

public:
    CMatrix();
    CMatrix(int hang, int cot, double giaTri = 0);

    void nhap();
    void xuat() const;

    int soHang() const;
    int soCot() const;

    CVector nhanVoiVector(const CVector& v) const;
    CMatrix operator*(const CMatrix& other) const;
};

#endif
