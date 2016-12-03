#include "Sculptor.h"
#include <fstream>
using namespace std;

int main(){
  Sculptor sculptor;

  // Toriode
  sculptor.putToriod(20, 10, 2, 30, 10);

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

  // // // Marrom
  // sculptor.setColor(121/255.0, 85/255.0, 72/255.0, 1.0);
  // // // íris
  //
  // sculptor.putEllipsoid(21, -22, 0, 4, 4, 2);
  //
  // // Azul
  // sculptor.setColor(21/255.0, 31/255.0, 200/255.0, 1.0);
  //
  // // Macacão
  // sculptor.putEllipsoid(0, -54, 0, 21, 10, 21);
  // sculptor.putCylinder(0, -54, 0, -38, 21);
  //
  // sculptor.cutBox(21, -16, -21, -50, -40, 16);
  //
  // // Amarelo do meio
  // sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  // sculptor.putCylinder(0, -50, 0, -40, 20);
  //
  // //sculptor.putEllipsoid(0, 0, -44, 25, 15, 10);
  //
  // // Box
  // // sculptor.setColor(21/255.0, 31/255.0, 200/255.0, 1.0);
  // // sculptor.putBox(-7, 7, -20, 20, -50, -40);
  //
  // //Amarelo
  // sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  //
  // //sculptor.putSphere(0, 0, -20, 20);
  // //Crânio
  // sculptor.putEllipsoid(0, -15, 0, 20, 10, 20);
  // //Corpo
  // sculptor.putCylinder(0, -15, 0, -38, 20);
  //
  // //Preto
  // sculptor.setColor(0.0, 0.0, 0.0, 1.0);
  //
  // // Anel do óculo em volta da cabeça
  // sculptor.putCylinder(0, -19, 0, -24, 21);
  //
  // // Borda do óculo
  // sculptor.putEllipsoid(19, -22, 0, 2, 8, 8);
  //
  // //Olho
  // sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  // sculptor.putEllipsoid(16, -22, 0, 6, 8, 8);

  cout << "Mínimo: " << sculptor.getMinXYZ() << endl;
  cout << "Máximo: " << sculptor.getMaxXYZ() << endl;

  sculptor.write("as.off");
}
