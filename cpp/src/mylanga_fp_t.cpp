#include <string>
using namespace std;

#include "mylanga_fp_t.h"

const fp_t FP_T_PI = 3.14159265358979323846264338327950288419716939937510L;

fp_t stofp_t(const string& str)
{
  return stold(str);
}