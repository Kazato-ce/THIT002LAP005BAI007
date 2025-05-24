// main.cpp
#include <iostream>
#include "CMatrix.h"
#include "CVector.h"

int main() {
    CMatrix A, B;
    CVector v;

    std::cout << "Nhap ma tran A:\n";
    A.nhap();

    std::cout << "Nhap ma tran B:\n";
    B.nhap();

    std::cout << "Nhap vector v:\n";
    v.nhap();

    std::cout << "\nA:\n"; A.xuat();
    std::cout << "\nB:\n"; B.xuat();
    std::cout << "\nVector v: "; v.xuat();

    try {
        std::cout << "\nA * B = \n";
        CMatrix C = A * B;
        C.xuat();

        std::cout << "\nA * v = ";
        CVector kq = A.nhanVoiVector(v);
        kq.xuat();
    } catch (std::exception& e) {
        std::cerr << "Loi: " << e.what() << "\n";
    }

    return 0;
}
