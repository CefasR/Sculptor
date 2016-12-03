#include "Sculptor.h"
#include <fstream>
using namespace std;

int main(){
  Sculptor sculptor;

  // Toriode
  // sculptor.putToriod(20, 10, 2, 30, 10);

  // Borda do óculo
  sculptor.setColor(0.0, 0.0, 0.0, 1.0);
  sculptor.putEllipsoid(0, -22, 20, 8, 8, 2);

  // Anel do óculo em volta da cabeça
  sculptor.putCylinder(0, 0, -19, -24, 21);

  // Olho
  sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  sculptor.putEllipsoid(0, -22, 16, 8, 8, 7);

  // íris marrom
  sculptor.setColor(121/255.0, 85/255.0, 72/255.0, 1.0);
  sculptor.putEllipsoid(0, -22, 21, 3, 3, 2);

  // Corpo
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(0, 0, -15, -38, 20);

  //Crânio
  sculptor.putEllipsoid(0, -15, 0, 20, 15, 20);

  cout << "Mínimo: " << sculptor.getMinXYZ() << endl;
  cout << "Máximo: " << sculptor.getMaxXYZ() << endl;

  sculptor.write("as.off");
}
