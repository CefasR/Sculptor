#include "Solids.h"

using namespace std;

void Box::sculpt(Canvas& c) const
{
  cout << "Sculpting Box..." << endl;
  for (int i = pos.x - (width / 2.0); i < pos.x + (width / 2.0); i++) {
    for (int j = pos.y - (length / 2.0); j < pos.y + (length / 2.0); j++) {
      for (int k = pos.z - (height / 2.0); k < pos.z + (height / 2.0); k++) {
        // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
        /*Surte o mesmo efeito que o código comentado acima
          funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
          que converte *this (da classe Solid) em um elemento do tipo voxel)*/

          POS_3D <float> p = TM.transform(POS_3D <float>(i,j,k));
          cout << p << endl;
          c.at(c.getNormalPos(p.x, p.y, p.z)) = (*this);
      }
    }
  }
}

//tá aqui ainda?
inline int Box::getMaxX() const {
  int max;
  for (int i = pos.x - (width / 2.0); i <= pos.x + (width / 2.0); i++){
    for (int j = pos.y - (length / 2.0); j <= pos.y + (length / 2.0); j++){
      for (int k = pos.z - (height / 2.0); k <= pos.z + (height / 2.0); k++){
        POS_3D <float> current = TM.transform(POS_3D <float> (i, j, k));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) max = current.x;
        if (current.x > max) max = current.x;
      }
    }
  }
  return max + 1;
}

// essa e a de y mas tem x y e z isso e irrelevante e so para verificar se o forr ta na primeira iteracao ok e ta errado
inline int Box::getMaxY() const {
  int max;
  for (int i = pos.x - (width / 2.0); i <= pos.x + (width / 2.0); i++){
    for (int j = pos.y - (length / 2.0); j <= pos.y + (length / 2.0); j++){
      for (int k = pos.z - (height / 2.0); k <= pos.z + (height / 2.0); k++){
        POS_3D <float> current = TM.transform(POS_3D <float> (i, j, k));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) max = current.y;
        if (current.y > max) max = current.y;
      }
    }
  }
  return max + 1;
}
inline int Box::getMaxZ() const {
  int max;
  for (int i = pos.x - (width / 2.0); i <= pos.x + (width / 2.0); i++){
    for (int j = pos.y - (length / 2.0); j <= pos.y + (length / 2.0); j++){
      for (int k = pos.z - (height / 2.0); k <= pos.z + (height / 2.0); k++){
        POS_3D <float> current = TM.transform(POS_3D <float> (i, j, k));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) max = current.z;
        if (current.z > max) max = current.z; //cefas , oi ali né x n? aqui e para pegar o maximo de z mas olha lá em x
      }
    }
  }
  return max + 1;
}
inline int Box::getMinX() const {
  int min;
  for (int i = pos.x - (width / 2.0); i <= pos.x + (width / 2.0); i++){
    for (int j = pos.y - (length / 2.0); j <= pos.y + (length / 2.0); j++){
      for (int k = pos.z - (height / 2.0); k <= pos.z + (height / 2.0); k++){
        POS_3D <float> current = TM.transform(POS_3D <float> (i, j, k));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) min = current.x;
        if (current.x < min) min = current.x;
      }
    }
  }
  return min;
}
inline int Box::getMinY() const {
  int min;
  for (int i = pos.x - (width / 2.0); i <= pos.x + (width / 2.0); i++){
    for (int j = pos.y - (length / 2.0); j <= pos.y + (length / 2.0); j++){
      for (int k = pos.z - (height / 2.0); k <= pos.z + (height / 2.0); k++){
        POS_3D <float> current = TM.transform(POS_3D <float> (i, j, k));
       if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) min = current.y;
        if (current.y < min) min = current.y;
      }
    }
  }
  return min;
}
inline int Box::getMinZ() const {
  int min;
  for (int i = pos.x - (width / 2.0); i <= pos.x + (width / 2.0); i++){
    for (int j = pos.y - (length / 2.0); j <= pos.y + (length / 2.0); j++){
      for (int k = pos.z - (height / 2.0); k <= pos.z + (height / 2.0); k++){
        POS_3D <float> current = TM.transform(POS_3D <float> (i, j, k));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) min = current.z;
        if (current.z < min) min = current.z;
      }
    }
  }
  return min;
}


// void Sphere::sculpt(Canvas& c) constv
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
// int Sphere::getMaxX() const {
//
// }
// int Sphere::getMaxY() const {
//
// }
// int Sphere::getMaxZ() const {
//
// }
// int Sphere::getMinX() const {
//
// }
// int Sphere::getMinY() const {
//
// }
// int Sphere::getMinZ() const {
//
// }

void Cylinder::sculpt(Canvas& c) const
{
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio

  cout << "Sculpting a Cylinder..." << endl;

    for (int i = getMinX(); i < getMaxX(); i++) {
      for (int j = getMinY(); j < getMaxY(); j++) {
        for (int k = getMinZ(); k < getMaxZ(); k++) {
            // Verifica se o ponto faz parte do cilindro
            if ((pow(float(i) - pos.x, 2) + pow(float(j) - pos.y, 2)) < pow(radius, 2)){
              // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
              /*Surte o mesmo efeito que o código comentado acima
                funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
                que converte *this (da classe Solid) em um elemento do tipo voxel)*/
                POS_3D <float> p = TM.transform(POS_3D <float>(i,j,k));
                c.at(c.getNormalPos(p.x, p.y, p.z)) = (*this);
            }
        }
      }
    }
}


inline int Cylinder::getMaxX() const {
  return (pos.x + radius);
}
inline int Cylinder::getMaxY() const {
  return (pos.y + radius);
}
inline int Cylinder::getMaxZ() const {
  return (float(pos.z) + (height / 2.0));
}
inline int Cylinder::getMinX() const {
  return (pos.x - radius);
}
inline int Cylinder::getMinY() const {
  return (pos.y - radius);
}
inline int Cylinder::getMinZ() const {
  return (float(pos.z) - (height / 2.0));
}

void Ellipsoid::sculpt(Canvas& c) const{

  cout << "Sculpting a Ellipsoid..." << endl;
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio
  for (int i = getMinX(); i < getMaxX(); i++) {
    for (int j = getMinY(); j < getMaxY(); j++) {
      for (int k = getMinZ(); k < getMaxZ(); k++) {
        // Verifica se o ponto faz parte do elipsoide
        if (
          pow(float(i) - pos.x, 2) / pow(x_radius, 2) +
          pow(float(j) - pos.y, 2) / pow(y_radius, 2) +
          pow(float(k) - pos.z, 2) / pow(z_radius, 2) < 1
        ){
          // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
          /*Surte o mesmo efeito que o código comentado acima
            funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
            que converte *this (da classe Solid) em um elemento do tipo voxel)*/
            POS_3D <float> p = TM.transform(POS_3D <float>(i,j,k));
            c.at(c.getNormalPos(p.x, p.y, p.z)) = (*this);
          }
      }
    }
  }
}

inline int Ellipsoid::getMaxX() const {
  return (pos.x + x_radius);
}
inline int Ellipsoid::getMaxY() const {
  return (pos.y + y_radius);
}
inline int Ellipsoid::getMaxZ() const {
  return (pos.z + z_radius);
}
inline int Ellipsoid::getMinX() const {
  return (pos.x - x_radius);
}
inline int Ellipsoid::getMinY() const {
  return (pos.y - y_radius);
}
inline int Ellipsoid::getMinZ() const {
  return (pos.z - z_radius);
}
