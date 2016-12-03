#include "../Sculptor.h"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main() {
  POS_3D <int> pos (1, 0, 0);
  AXIS axis = Y;

  cout << RotationMatriz(M_PI_2, axis).transform(pos) << endl;
}
