#pragma once
#ifndef CANBO_H
#define CANBO_H
#include <iostream>
#include <string>
using namespace std;

class CanBo {
protected:
  string Name;
  int Age;
  string Gender;

public:
  void readInfo();
  void showInfo();
};

class CongNhan : public CanBo {
private:
  int Rank;

public:
  void readInfo();
  void showInfo();
};

class KySu : public CanBo {
private:
  string NganhDaoTao;

public:
  void readInfo();
  void showInfo();
};

class NhanVien : public CanBo {
private:
  string CongViec;

public:
  void readInfo();
  void showInfo();
};
#endif
