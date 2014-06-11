#include <iostream>
using namespace std;

#define $(a) $##a

int main(int argc, char const *argv[])
{
  int $2 = 10;
  cout << $(2, id) << endl;
  return 0;
}