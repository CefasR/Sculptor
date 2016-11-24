#include "Escultor.h"
#include <cmath>
using namespace std;


unsigned int Caixa::esculpir(Voxel ***matriz) const
{
  unsigned int qtd = 0;
  int pos_x = pos.x - (x_size / 2), pos_y = pos.y - (y_size / 2), pos_z = pos.z - (z_size / 2);

  for (int i = pos_x; i < pos_x + x_size; i++) {
    for (int j = pos_y; j < pos_y + y_size; j++) {
      for (int k = pos_z; k < pos_z + z_size; k++) {
        if (i >= 0 && j >= 0 && k >= 0){
          if (! matriz[i][j][k].is_on) qtd++;
          Voxel v(R, G, B, alpha, is_on);
          matriz[i][j][k] = v;
        }
      }
    }
  }

  return qtd;
}


unsigned int Caixa::getMaxX() const {

}
unsigned int Caixa::getMaxY() const {

}
unsigned int Caixa::getMaxZ() const {

}

unsigned int Caixa::getMinX() const {

}
unsigned int Caixa::getMinY() const {

}
unsigned int Caixa::getMinZ() const {

}


unsigned int Esfera::esculpir(Voxel ***matriz) const
{
  unsigned int qtd = 0;
  for (int i = pos.x - raio; i < pos.x + raio; i++) {
    for (int j = pos.y - raio; j < pos.y + raio; j++) {
      for (int k = pos.z - raio; k < pos.z + raio; k++) {
        if (i >= 0 && j >= 0 && k >= 0 && (pow(int(i - pos.x), 2) + pow(int(j - pos.y), 2) + pow(int(k - pos.z), 2)) <= pow(raio, 2)){
          Voxel v(R, G, B, alpha, is_on);
          if (! matriz[i][j][k].is_on) qtd++;
          matriz[i][j][k] = v;
        }
      }
    }
  }
  return qtd;
}


unsigned int Esfera::getMaxX() const {

}
unsigned int Esfera::getMaxY() const {

}
unsigned int Esfera::getMaxZ() const {

}

unsigned int Esfera::getMinX() const {

}
unsigned int Esfera::getMinY() const {

}
unsigned int Esfera::getMinZ() const {

}

unsigned int Cilindro::esculpir(Voxel ***matriz) const
{
  unsigned int qtd = 0;
  for (int i = int(pos.x - raio); i < int(pos.x + raio); i++) {
    for (int j = int(pos.y - raio); j < int(pos.y + raio); j++) {
      for (int k = int(pos.z - altura); k < int(pos.z + altura); k++) {
        if (i >= 0 && j >= 0 && k >= 0 && (pow(int(i - pos.x), 2) + pow(int(j - pos.y), 2)) <= pow(raio, 2)){
          if (! matriz[i][j][k].is_on) qtd++;
          Voxel v(R, G, B, alpha, is_on);
          matriz[i][j][k] = v;
        }
      }
    }
  }
  return qtd;
}


unsigned int Cilindro::getMaxX() const {

}
unsigned int Cilindro::getMaxY() const {

}
unsigned int Cilindro::getMaxZ() const {

}

unsigned int Cilindro::getMinX() const {

}
unsigned int Cilindro::getMinY() const {

}
unsigned int Cilindro::getMinZ() const {

}
