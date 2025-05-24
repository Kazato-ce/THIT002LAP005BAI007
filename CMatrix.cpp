// CMatrix.cpp
#include "CMatrix.h"
#include <iostream>
#include <stdexcept>

CMatrix::CMatrix() {}

CMatrix::CMatrix(int hang, int cot, double giaTri) {
    data = std::vector<std::vector<double>>(hang, std::vector<double>(cot, giaTri));
}

void CMatrix::nhap() {
    int hang, cot;
    std::cout << "Nhap so hang: ";
    std::cin >> hang;
    std::cout << "Nhap so cot: ";
    std::cin >> cot;
    data.resize(hang, std::vector<double>(cot));
    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            std::cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}

void CMatrix::xuat() const {
    for (const auto& row : data) {
        for (double val : row) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }
}

int CMatrix::soHang() const {
    return data.size();
}

int CMatrix::soCot() const {
    return data.empty() ? 0 : data[0].size();
}

// Ma trận * vector
CVector CMatrix::nhanVoiVector(const CVector& v) const {
    int hang = soHang(), cot = soCot();
    if (cot != v.layChieu())
        throw std::length_error("Khong the nhan ma tran va vector (sai kich thuoc)");

    CVector ketQua(hang);
    for (int i = 0; i < hang; ++i) {
        double tong = 0;
        for (int j = 0; j < cot; ++j) {
            tong += data[i][j] * v[j];  // cần thêm toán tử [] trong CVector
        }
        ketQua[i] = tong;  // cần thêm toán tử [] gán trong CVector
    }
    return ketQua;
}

// Ma trận * ma trận
CMatrix CMatrix::operator*(const CMatrix& other) const {
    int m = soHang();
    int n = soCot();
    int p = other.soCot();
    if (n != other.soHang())
        throw std::length_error("Khong the nhan hai ma tran (sai kich thuoc)");

    CMatrix ketQua(m, p);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                ketQua.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return ketQua;
}
