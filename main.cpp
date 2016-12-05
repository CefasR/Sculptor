#include "Sculptor.h"
#include <fstream>
using namespace std;
//Cefas, esse codigo é o mais atual?

int main(){

  Sculptor sculptor;

  // MINION MENINO

  // Borda do óculo
  sculptor.setColor(169/255.0, 169/255.0, 169/255.0, 1.0);
  sculptor.putCylinder(0,8, -22,2, 8);
  sculptor.getSolidAt(0).rotate(M_PI_2,X);

  // // Anel do óculo em volta da cabeça
  sculptor.setColor(0.0,0.0,0.0, 1.0);
  sculptor.putCylinder(0, 0, 23, 27, 21);
  //
  // // Olho
  sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  sculptor.putCylinder(0, 8, -22, 2, 6);
  sculptor.getSolidAt(2).rotate(M_PI_2,X);

  // // íris marrom
  sculptor.setColor(121/255.0, 85/255.0, 72/255.0, 1.0);
  sculptor.putCylinder(0, 8, -22, 2, 2);
  sculptor.getSolidAt(3).rotate(M_PI_2,X);
  //sculptor.setColor(0.0,0.0,0.0, 1.0);
  //sculptor.putCylinder(0, 8, -22, 2, 1);
  //sculptor.getSolidAt(4).rotate(M_PI_2,X);

  // // Corpo
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(0, 0, 10, 30 , 20);
  //
  // //Crânio
  sculptor.putEllipsoid(0,30,0, 20, 15, 20);

  // //Roupa
  sculptor.setColor(0/255.0, 0/255.0, 255.0, 1.0);
  sculptor.putCylinder(0, 0, 0, 10 , 20);
  sculptor.putEllipsoid(0,0, 0, 20, 14, 20);
  //sculptor.putBox(-20, 20, 0, 8, -14, 14);
  //sculptor.cutBox(-20, 20, 0, 8, -14, 14);
  //sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  //sculptor.putCylinder(0, 0, 0, 10 , 19);

  // //Pernas

  sculptor.setColor(0/255.0, 0/255.0, 255.0, 1.0);
  sculptor.putCylinder(-8, 0, -12, -19, 5);
  sculptor.putCylinder(8, 0, -12, -19, 5);

  sculptor.putCylinder(0, 0, 0, 10 , 21);

  // //Sapatos
  sculptor.setColor(0.0,0.0,0.0, 1.0);
  sculptor.putEllipsoid(-8, -22 ,2, 5, 4, 9);
  sculptor.putEllipsoid(8, -22 ,2, 5, 4, 9);

  // MINION MENINA

  // Borda do óculos
  sculptor.setColor(169/255.0, 169/255.0, 169/255.0, 1.0);
  sculptor.putCylinder(60, 8, -22 , 2, 8);
  sculptor.getSolidAt(13).rotate(M_PI_2,X);

  // // Anel do óculo em volta da cabeça
  sculptor.setColor(0.0,0.0,0.0, 1.0);
  sculptor.putCylinder(60, 0, 23, 27, 21);
  //
  // // Olho
  sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  sculptor.putCylinder(60, 8, -22, 2, 6);
  sculptor.getSolidAt(15).rotate(M_PI_2,X);

  // // íris marrom
  sculptor.setColor(121/255.0, 85/255.0, 72/255.0, 1.0);
  sculptor.putCylinder(60, 8, -22, 2, 2);
  sculptor.getSolidAt(16).rotate(M_PI_2,X);
  sculptor.setColor(0.0,0.0,0.0, 1.0);
  sculptor.putCylinder(0, 8, -22, 2, 1);
  sculptor.getSolidAt(17).rotate(M_PI_2,X);

  // // Corpo
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(60, 0, 10, 30 , 20);
  //
  // //Crânio
  sculptor.putEllipsoid(60, 30 , 0, 20, 15, 20);

  // //Roupa
  sculptor.setColor(255.0, 20/255.0, 147/255.0, 1.0);
  sculptor.putCylinder( 60, 0, 0 , 10 , 20);
  sculptor.setColor(250/255.0,128/255.0,114/255.0, 1.0);
  sculptor.putCylinder( 60, 0, 0 , -10 , 20);
  //sculptor.putBox(-20, 20, 0, 8, -14, 14);
  //sculptor.cutBox(-20, 20, 0, 8, -14, 14);
  //sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  //sculptor.putCylinder(0, 0, 0, 10 , 19);

  // //Pernas

  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(50, 0, -11, -18, 5);
  sculptor.putCylinder(70, 0, -11, -18, 5);

  // //Sapatos
  sculptor.setColor(0.0,0.0,0.0, 1.0);
  sculptor.putEllipsoid(50, -21 ,2, 5, 4, 9);
  sculptor.putEllipsoid(70, -21 ,2, 5, 4, 9);


  /*
  sculptor.getSolidAt(0).rotate(M_PI_2 / 10, X);
  sculptor.getSolidAt(0).rotate(M_PI_2 / 2, Y);

  sculptor.getSolidAt(1).rotate(M_PI_2 / 10, X);
  sculptor.getSolidAt(1).rotate(M_PI_2 / 2, Y);

  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  */
  //sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  //sculptor.putBox(10, 40, 10, 40, 10, 40);
  //sculptor.putCylinder(0, 0, 14, 24, 10);
  //sculptor.getSolidAt(0).translate(2,2,2);
  //sculptor.getSolidAt(2).rotate(M_PI_2 / 2, Y);
  // Toriode
  // sculptor.putToriod(20, 10, 2, 30, 10);

  cout << "Mínimo: " << sculptor.getMinXYZ() << endl;
  cout << "Máximo: " << sculptor.getMaxXYZ() << endl;

  sculptor.write("as.off");
}
