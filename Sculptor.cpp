#include "Sculptor.h"
#include <fstream>
using namespace std;


void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);

  fout << "OFF" << endl;
  fout << (dimX + 1) * (dimY + 1) * (dimZ + 1) << " " << x.capacity() * 6 << " " << 0 << endl;
}
