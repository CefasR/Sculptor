#include "Sculptor.h"
#include <fstream>
using namespace std;


void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);

  fout << "OFF" << endl;
  fout << getNVertices() << " " << getNEdges() << " " << 0 << endl;
}
