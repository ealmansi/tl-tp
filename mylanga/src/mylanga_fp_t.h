#ifndef MYLANGA_FP_T_H
#define MYLANGA_FP_T_H

#include <string>
using namespace std;

typedef long double fp_t;

extern const fp_t FP_T_PI;

fp_t stofp_t(const string& str);

struct maybe_fp_t
{
  maybe_fp_t() : is_valid(false) {}
  maybe_fp_t(fp_t value) : is_valid(true), value(value) {}
  bool is_valid;
  fp_t value;
};

#endif /* MYLANGA_FP_T_H */