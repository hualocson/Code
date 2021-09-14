#include "CanBo.h"
void CanBo::readInfo() {
  cout << "Nhap ho ten: ";
  getline(cin, Name);
  cout << "Nhap tuoi: ";
  cin >> Age;
  cout << "Nhap gioi tinh: ";
  cin.ignore();
  getline(cin, Gender);
}

void CanBo::showInfo() {
  cout << "Ho va ten: " << Name << endl;
  cout << "Tuoi: " << Age << endl;
  cout << "Gioi tinh: " << Gender << endl;
}

void CongNhan::readInfo() {
  CanBo::readInfo();
  cout << "Nhap bac: ";
  cin >> Rank;
}
void CongNhan::showInfo() {
  CanBo::showInfo();
  cout << "Bac: " << Rank << endl;
}

void KySu::readInfo() {
  CanBo::readInfo();
  cout << "Nhap nganh dao tao: ";
  //  cin.ignore();
  getline(cin, NganhDaoTao);
}
void KySu::showInfo() {
  CanBo::showInfo();
  cout << "Nganh dao tao: " << NganhDaoTao << endl;
}

void NhanVien::readInfo() {
  CanBo::readInfo();
  cout << "Nhap cong viec: ";
  cin.ignore();
  getline(cin, CongViec);
}
void NhanVien::showInfo() {
  CanBo::showInfo();
  cout << "Cong viec: " << CongViec << endl;
}
