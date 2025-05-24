// CVector.h
#ifndef CVECTOR_H
#define CVECTOR_H

#include <vector>

class CVector {
private:
    std::vector<double> data;

public:
    CVector();
    CVector(int Chieu, double TonTai = 0); // Đổi tên

    void nhap();
    void xuat() const;
    int layChieu() const;             // Đổi tên
    double doDai() const;
    double tichVoHuong(const CVector& other) const;

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    bool operator==(const CVector& other) const;
};

#endif
