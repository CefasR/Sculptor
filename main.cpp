#include "Sculptor.h"
#include <fstream>
using namespace std;

int main(){
  Sculptor sculptor;

  // // Marrom
  sculptor.setColor(121/255.0, 85/255.0, 72/255.0, 1.0);
  // // íris
  sculptor.putEllipsoid(0, 21, -22, 4, 2, 4);

  // Azul
  sculptor.setColor(21/255.0, 31/255.0, 200/255.0, 1.0);

  // Macacão
  sculptor.putEllipsoid(0, 0, -54, 21, 21, 10);
  sculptor.putCylinder(0, 0, -54, -38, 21);

  sculptor.cutBox(-21, 21, -16, 16, -50, -40);

  // Amarelo do meio
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);
  sculptor.putCylinder(0, 0, -50, -40, 20);

  //sculptor.putEllipsoid(0, 0, -44, 25, 15, 10);

  // Box
  // sculptor.setColor(21/255.0, 31/255.0, 200/255.0, 1.0);
  // sculptor.putBox(-7, 7, -20, 20, -50, -40);

  //Amarelo
  sculptor.setColor(241/255.0, 196/255.0, 15/255.0, 1.0);

  //sculptor.putSphere(0, 0, -20, 20);
  //Crânio
  sculptor.putEllipsoid(0, 0, -15, 20, 20, 15);
  //Corpo
  sculptor.putCylinder(0, 0, -15, -38, 20);

  //Preto
  sculptor.setColor(0.0, 0.0, 0.0, 1.0);

  // Anel do óculo em volta da cabeça
  sculptor.putCylinder(0, 0, -19, -24, 21);

  // Borda do óculo
  sculptor.putEllipsoid(0, 19, -22, 8, 2, 8);

  //Olho
  sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  sculptor.putEllipsoid(0, 16, -22, 8, 6, 8);

  cout << "Mínimo: " << sculptor.getMinXYZ() << endl;
  cout << "Máximo: " << sculptor.getMaxXYZ() << endl;

  sculptor.write("as.off");
/*
  Voxel ***matriz = new Voxel**[30];

  for (int i = 0; i < 30; i++)
  {
    matriz[i] = new Voxel*[30];
    for (int j= 0; j < 30; j++)
    {
      matriz[i][j] = new Voxel[30];
    }
  }

  ofstream arquivo("a.off");

  Esfera *a = new Esfera(10, 10, 15, 0.2, 0.0, 0.1, 1.0, true, 9);
  Caixa *b = new Caixa(10, 10, 15, 1.0, 1.0, 1.0, 1.0, true, 5, 5, 30);

  unsigned int q = a->sculpt(matriz);
  q += b->sculpt(matriz);
  // b->sculpt(matriz);

  arquivo << "OFF \n" << 8 * q << " " << 6 * q << " " << 0 << endl;

  for (int i = 0; i < 30; i++)
  {
    for (int j= 0; j < 30; j++)
    {
      for (int k= 0; k < 30; k++)
      {
        if (matriz[i][j][k].is_on){
            arquivo << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
            arquivo << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
            arquivo << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
            arquivo << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
            arquivo << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
            arquivo << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
            arquivo << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
            arquivo << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
          }
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < 30; i++)
  {
    for (int j= 0; j < 30; j++)
    {
      for (int k= 0; k < 30; k++)
      {
        if (matriz[i][j][k].is_on){
          arquivo << 4 << " " << 0 + (cnt * 8) << " " << 3 + (cnt * 8) << " " << 2 + (cnt * 8) << " " << 1 + (cnt * 8) << " " << matriz[i][j][k].R << " " << matriz[i][j][k].G << " " << matriz[i][j][k].B << " " << matriz[i][j][k].alpha << endl;
          arquivo << 4 << " " << 4 + (cnt * 8) << " " << 5 + (cnt * 8) << " " << 6 + (cnt * 8) << " " << 7 + (cnt * 8) << " " << matriz[i][j][k].R << " " << matriz[i][j][k].G << " " << matriz[i][j][k].B << " " << matriz[i][j][k].alpha << endl;
          arquivo << 4 << " " << 0 + (cnt * 8) << " " << 1 + (cnt * 8) << " " << 5 + (cnt * 8) << " " << 4 + (cnt * 8) << " " << matriz[i][j][k].R << " " << matriz[i][j][k].G << " " << matriz[i][j][k].B << " " << matriz[i][j][k].alpha << endl;
          arquivo << 4 << " " << 0 + (cnt * 8) << " " << 4 + (cnt * 8) << " " << 7 + (cnt * 8) << " " << 3 + (cnt * 8) << " " << matriz[i][j][k].R << " " << matriz[i][j][k].G << " " << matriz[i][j][k].B << " " << matriz[i][j][k].alpha << endl;
          arquivo << 4 << " " << 3 + (cnt * 8) << " " << 7 + (cnt * 8) << " " << 6 + (cnt * 8) << " " << 2 + (cnt * 8) << " " << matriz[i][j][k].R << " " << matriz[i][j][k].G << " " << matriz[i][j][k].B << " " << matriz[i][j][k].alpha << endl;
          arquivo << 4 << " " << 1 + (cnt * 8) << " " << 2 + (cnt * 8) << " " << 6 + (cnt * 8) << " " << 5 + (cnt * 8) << " " << matriz[i][j][k].R << " " << matriz[i][j][k].G << " " << matriz[i][j][k].B << " " << matriz[i][j][k].alpha << endl;
          cnt++;
        }
      }
    }
  }
*/
}
