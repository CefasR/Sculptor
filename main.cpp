#include "Sculptor.h"
#include <fstream>
using namespace std;
//Cefas, esse codigo é o mais atual?
int main(){
  Sculptor sculptor;

  sculptor.setColor(10/255.0, 30/255.0, 200/255.0, 1.0);
  // sculptor.putBox(0, 50, 0, 50, 0, 50);
  // sculptor.cutBox(1, 49, 1, 49, 1, 49);
  //
  //
  // sculptor.getSolidAt(0).rotate(M_PI_2 / 10, X);
  // sculptor.getSolidAt(0).rotate(M_PI_2 / 2, Y);
  //
  //
  // sculptor.getSolidAt(1).rotate(M_PI_2 / 10, X);
  // sculptor.getSolidAt(1).rotate(M_PI_2 / 2, Y);
  //
  // sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  //
  // sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  // sculptor.putBox(10, 40, 10, 40, 10, 40);
  //
  // sculptor.getSolidAt(2).rotate(M_PI_2 / 10, X);
  // sculptor.getSolidAt(2).rotate(M_PI_2 / 2, Y);

  sculptor.putCone(0, 0, 0, 10, 20);



  // Toriode
  // sculptor.putToriod(20, 10, 2, 30, 10);

  // Borda do óculo
  // sculptor.setColor(0.0, 0.0, 0.0, 1.0);
  // sculptor.putEllipsoid(0, -22, 20, 8, 8, 2);
  //
  // // Anel do óculo em volta da cabeça
  // sculptor.putCylinder(0, 0, -19, -24, 21);
  //
  // // Olho
  // sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  // sculptor.putEllipsoid(0, -22, 16, 8, 8, 7);
  //
  // // íris marrom
  // sculptor.setColor(121/255.0, 85/255.0, 72/255.0, 1.0);
  // sculptor.putEllipsoid(0, -22, 21, 3, 3, 2);
  //
  // // Corpo
  // sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  // sculptor.putCylinder(0, 0, -15, -38, 20);
  //
  // //Crânio
  // sculptor.putEllipsoid(0, -15, 0, 20, 15, 20);

  cout << "Mínimo: " << sculptor.getMinXYZ() << endl;
  cout << "Máximo: " << sculptor.getMaxXYZ() << endl;

  sculptor.write("as.off");
}
