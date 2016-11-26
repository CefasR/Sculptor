#include "Solids.h"
using namespace std;

void Box::sculpt(Canvas& c) const
{
  for (int i = (pos.x - width / 2); i < (pos.x + width / 2); i++) {
    for (int j = (pos.y - length / 2); j < (pos.y + length / 2); j++) {
      for (int k = (pos.z - height / 2); k < (pos.z + height / 2); k++) {
        // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
        /*Surte o mesmo efeito que o código comentado acima
          funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
          que converte *this (da classe Solid) em um elemento do tipo voxel)*/
        c.at(i, j, k) = *this;
      }
    }
  }
}


unsigned int Box::getMaxX() const {

}
unsigned int Box::getMaxY() const {

}
unsigned int Box::getMaxZ() const {

}
unsigned int Box::getMinX() const {

}
unsigned int Box::getMinY() const {

}
unsigned int Box::getMinZ() const {

}


// void Sphere::sculpt(Canvas& c) const
// {
//   for (int i = pos.x - radius; i < pos.x + radius; i++) {
//     for (int j = pos.y - radius; j < pos.y + radius; j++) {
//       for (int k = pos.z - radius; k < pos.z + radius; k++) {
//         if ((pow(int(i - pos.x), 2) + pow(int(j - pos.y), 2) + pow(int(k - pos.z), 2)) <= pow(radius, 2)){
//           Voxel v(R, G, B, alpha, is_on);
//           c.at(i, j, k) = v;
//         }
//       }
//     }
//   }
// }
//
//
// unsigned int Sphere::getMaxX() const {
//
// }
// unsigned int Sphere::getMaxY() const {
//
// }
// unsigned int Sphere::getMaxZ() const {
//
// }
// unsigned int Sphere::getMinX() const {
//
// }
// unsigned int Sphere::getMinY() const {
//
// }
// unsigned int Sphere::getMinZ() const {
//
// }

void Cylinder::sculpt(Canvas& c) const
{
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio
    for (int i = int(pos.x - radius); i < int(pos.x + radius); i++) {
        for (int j = int(pos.y - radius); j < int(pos.y + radius); j++) {
            for (int k = int(pos.z - height); k < int(pos.z + height); k++) {

                // Verifica se o ponto faz parte do cilindro
                if ((pow(int(i - pos.x), 2) + pow(int(j - pos.y), 2)) <= pow(radius, 2)){
                  // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
                  /*Surte o mesmo efeito que o código comentado acima
                    funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
                    que converte *this (da classe Solid) em um elemento do tipo voxel)*/
                  c.at(i, j, k) = *this;;
                }
            }
        }
    }
}


unsigned int Cylinder::getMaxX() const {

}
unsigned int Cylinder::getMaxY() const {

}
unsigned int Cylinder::getMaxZ() const {

}
unsigned int Cylinder::getMinX() const {

}
unsigned int Cylinder::getMinY() const {

}
unsigned int Cylinder::getMinZ() const {

}

void Ellipsoid::sculpt(Canvas& c) const{
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio
  for (int i = int(pos.x - x_radius); i < int(pos.x + x_radius); i++) {
    for (int j = int(pos.y - y_radius); j < int(pos.y + y_radius); j++) {
      for (int k = int(pos.z - z_radius); k < int(pos.z + z_radius); k++) {
        // Verifica se o ponto faz parte do elipsoide
        if (
          pow(i - pos.x, 2) / pow(x_radius, 2) +
          pow(j - pos.y, 2) / pow(y_radius, 2) +
          pow(k - pos.z, 2) / pow(z_radius, 2) <= 1
        ){
          // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
          /*Surte o mesmo efeito que o código comentado acima
            funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
            que converte *this (da classe Solid) em um elemento do tipo voxel)*/
          c.at(i, j, k) = *this;
        }
      }
    }
  }
}

unsigned int Ellipsoid::getMaxX() const {

}
unsigned int Ellipsoid::getMaxY() const {

}
unsigned int Ellipsoid::getMaxZ() const {

}

unsigned int Ellipsoid::getMinX() const {

}
unsigned int Ellipsoid::getMinY() const {

}
unsigned int Ellipsoid::getMinZ() const {

}
