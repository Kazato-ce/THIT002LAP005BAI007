// CVector.cpp
#include "CVector.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

CVector::CVector() {}

CVector::CVector(int Chieu, double TonTai) {
    data = std::vector<double>(Chieu, TonTai); // Đổi tên
}

void CVector::nhap() {
    int n;
    std::cout << "Nhap so chieu cua vector: ";
    std::cin >> n;
    data.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap gia tri tai chieu thu " << i + 1 << ": ";
        std::cin >> data[i];
    }
}

void CVector::xuat() const {
    std::cout << "(";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i != data.size() - 1) std::cout << ", ";
    }
    std::cout << ")\n";
}

int CVector::layChieu() const {
    return data.size(); // Đổi tên
}

double CVector::doDai() const {
    double tong = 0;
    for (double x : data) {
        tong += x * x;
    }
    return std::sqrt(tong);
}

double CVector::tichVoHuong(const CVector& other) const {
    if (data.size() != other.data.size())
        throw std::length_error("Hai vector khong cung so chieu");

    double tong = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        tong += data[i] * other.data[i];
    }
    return tong;
}

CVector CVector::operator+(const CVector& other) const {
    if (data.size() != other.data.size())
        throw std::length_error("Hai vector khong cung so chieu");

    CVector result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

CVector CVector::operator-(const CVector& other) const {
    if (data.size() != other.data.size())
        throw std::length_error("Hai vector khong cung so chieu");

    CVector result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

bool CVector::operator==(const CVector& other) const {
    return data == other.data;
}
