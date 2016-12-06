#include "Sculptor.h"
#include <fstream>
using namespace std;
//Cefas, esse codigo é o mais atual?

int main(){

  Sculptor sculptor;
  // sculptor.setScale(2.0);

  // MINION MENINO

  // Borda do óculo
  sculptor.setColor(169/255.0, 169/255.0, 169/255.0, 1.0);
  sculptor.putCylinder(0, 17, 23, 29, 8);
  sculptor.getLastSolid().rotate(-M_PI_2,X);
  //sculptor.putToriod(0, 26, 18, 7, 1);

  // sculptor.cutCylinder(0, 17, 23, 29, 6);
  // sculptor.getLastSolid().rotate(-M_PI_2,X);

  // // Anel do óculo em volta da cabeça
  sculptor.setColor(0.0,0.0,0.0, 1.0);
  sculptor.putCylinder(0, 0, 25, 28, 19);
  //
  // // Olho
  sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  sculptor.putSphere(0, 26, 13, 8);
  // sculptor.getLastSolid().rotate(M_PI_2,X);

  sculptor.cutCylinder(0, 21, 25, 27, 6);
  sculptor.getLastSolid().rotate(-M_PI_2,X);

  // // íris marrom
  sculptor.setColor(121/255.0, 85/255.0, 72/255.0, 1.0);
  sculptor.putCylinder(0, 18, 25, 26, 2);
  sculptor.getLastSolid().rotate(M_PI_2,X);
  //sculptor.setColor(0.0,0.0,0.0, 1.0);
  //sculptor.putCylinder(0, 8, -22, 2, 1);
  //sculptor.getLastSolid().rotate(M_PI_2,X);

  // sculptor.setColor(0.0,0.0,0.0, 1.0);
  // sculptor.putBox(0, 10, 0, 10, 0, 10);
  // sculptor.getLastSolid().rotate(M_PI_4, X);
  //   sculptor.getLastSolid().rotate(M_PI_4, Y);
  //
  // // Corpo
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(0, 0, 0, 30 , 18);
  //
  // //Crânio
  sculptor.putEllipsoid(0,30,0, 18, 10, 18);

  // Boca
  sculptor.setColor(221/255.0,176/255.0,15/255.0,1);
  sculptor.cutToriod(0, 17, 5, 12, 1);
  sculptor.getLastSolid().rotate(M_PI_2, X);
  sculptor.getLastSolid().rotate(-M_PI_4 / 3, X);

  sculptor.setColor(236/255.0,240/255.0,241/255.0,1);
  sculptor.putToriod(0, 17, 3, 12, 1);
  sculptor.getLastSolid().rotate(M_PI_2, X);
  sculptor.getLastSolid().rotate(-M_PI_4 / 3, X);

  // //Roupa
  sculptor.setColor(10/255.0, 30/255.0, 200/255.0, 1.0);
  sculptor.putCylinder(0, 0, -4, 9 , 19);
  sculptor.putEllipsoid(0,-4, 0, 19, 7, 19);

  sculptor.cutBox(-20, 20, 1, 9, -14, 14);

  // Pernas
  sculptor.putEllipsoid(-7, -12, 0,  4, 6 , 4);
  sculptor.getLastSolid().rotate(M_PI_4 / 5, Z);

  sculptor.putEllipsoid(7, -12, 0,  4, 6 ,4);
  sculptor.getLastSolid().rotate(-M_PI_4 / 5, Z);

  // Botões
  sculptor.setColor(27/255.0, 28/255.0, 30/255.0, 1.0);

  sculptor.putCylinder(-10, 16, 5, 6, 2);
  sculptor.getLastSolid().rotate(M_PI_2, X);
  sculptor.getLastSolid().rotate(M_PI_4/ 3, Y);

  sculptor.putCylinder(10, 16, 5, 6, 2);
  sculptor.getLastSolid().rotate(M_PI_2, X);
  sculptor.getLastSolid().rotate(-M_PI_4/ 3, Y);

  sculptor.putCylinder(-9, -17, 5, 6, 2);
  sculptor.getLastSolid().rotate(M_PI_2, X);
  sculptor.getLastSolid().rotate(-M_PI_4/ 3, Y);

  sculptor.putCylinder(9, -17, 5, 6, 2);
  sculptor.getLastSolid().rotate(M_PI_2, X);
  sculptor.getLastSolid().rotate(M_PI_4/ 3, Y);



  // Sapato da esquerda
  sculptor.setColor(0.0,0.0,0.0, 1.0);
  //sculptor.putCylinder(-7, 0, -19 , -16, 3);
  sculptor.putEllipsoid(-7, -18, 2,  4, 3 ,6);
  sculptor.getLastSolid().rotate(M_PI_4 / 1.5, Y);


  // Sapato da direita
  //sculptor.putCylinder(7, 0, -19 , -16, 3);
  sculptor.putEllipsoid(7, -18, 2,  4, 3 ,6);
  sculptor.getLastSolid().rotate(-M_PI_4 / 1.5, Y);

  //sculptor.putCylinder(-4, 0, -15, -10, 5);

  // Corpo por dentro da roupa
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(0, 0, 1, 9 , 18);

  // Alça do macacão
  sculptor.setColor(10/255.0, 30/255.0, 200/255.0, 1.0);
  sculptor.putToriod(5, 7, 0, 15, 1);
  sculptor.getLastSolid().rotate(-M_PI_2, X);
  sculptor.getLastSolid().rotate(-M_PI_2 / 5, Z);

  sculptor.putToriod(-5, 7, 0, 14, 1);
  sculptor.getLastSolid().rotate(-M_PI_2, X);
  sculptor.getLastSolid().rotate( M_PI_2 / 5, Z);

  // Bolso
  sculptor.setColor(47/255.0, 75/255.0, 130/255.0, 1.0);
  sculptor.putCylinder(0, 17, 4, 5, 7);
  sculptor.getLastSolid().rotate( M_PI_2, X);


  // Correção do bolso
  sculptor.setColor(10/255.0, 30/255.0, 200/255.0, 1.0);
  sculptor.putBox(-7, 7, 4, 9, 18, 19);
  sculptor.cutBox(-7, 7, 9, 12, 18, 19);

  // Braço esquedo
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(-19, 0, -4, 24, 2);
  sculptor.getLastSolid().rotate(-M_PI_4 / 1.5, Z);

  // Braço direito
  sculptor.putCylinder(19, 0, -4, 24, 2);
  sculptor.getLastSolid().rotate(M_PI_4 / 1.5, Z);

  // Mão da direita
  sculptor.setColor(0/255.0, 0/255.0, 0/255.0, 1.0);
  sculptor.putEllipsoid(24, 20, 0, 3, 4, 3);
  sculptor.getLastSolid().rotate(M_PI_4 / 1.5, Z);

  sculptor.putEllipsoid(23, 20, 0, 2, 3, 2);
  sculptor.getLastSolid().rotate(-M_PI_4 / 1.5, Z);

  // Mão esquerda
  sculptor.setColor(0/255.0, 0/255.0, 0/255.0, 1.0);
  sculptor.putEllipsoid(-24, 20, 0, 3, 4, 3);
  sculptor.getLastSolid().rotate(-M_PI_4 / 1.5, Z);

  sculptor.putEllipsoid(-23, 20, 0, 2, 3, 2);
  sculptor.getLastSolid().rotate(M_PI_4 / 1.5, Z);


  sculptor.write("as.off");
}
