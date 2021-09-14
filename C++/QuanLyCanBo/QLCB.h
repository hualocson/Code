#pragma once
#ifndef QLCB_H
#include "CanBo.h"
#include <vector>

class Qlcb {
private:
  vector<CanBo> list;
  int size();

public:
  void Add(CanBo);
  CanBo Find(string);
  void Show();
  void Quit();
};
#endif
