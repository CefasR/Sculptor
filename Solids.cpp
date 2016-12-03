#include "Solids.h"
using namespace std;

void Box::sculpt(Canvas& c) const
{

  cout << "Sculpting Box..." << endl;
  for (int i = getMinX(); i < getMaxX(); i++) {
    for (int j = getMinY(); j < getMaxY(); j++) {
      for (int k = getMinZ(); k < getMaxZ(); k++) {
        // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
        /*Surte o mesmo efeito que o código comentado acima
          funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
          que converte *this (da classe Solid) em um elemento do tipo voxel)*/

        c.at(c.getNormalPos(i, j, k)) = (*this);

      }
    }
  }
}


inline int Box::getMaxX() const {
  return (pos.x + width / 2.0);
}
inline int Box::getMaxY() const {
  return (pos.y + length / 2.0);
}
inline int Box::getMaxZ() const {
  return (pos.z + height / 2.0);
}
inline int Box::getMinX() const {
  return (pos.x - width / 2.0);
}
inline int Box::getMinY() const {
  return (pos.y - length / 2.0);
}
inline int Box::getMinZ() const {
  return (pos.z - height / 2.0);
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
            if ((pow(float(i) - pos.x, 2) + pow(float(k) - pos.z, 2)) < pow(radius, 2)){
              // c.at(i, j, k) = Voxel(R, G, B, alpha, is_on);
              /*Surte o mesmo efeito que o código comentado acima
                funciona porque Solid herda da struct Voxel, assim o C++ faz um "casting",
                que converte *this (da classe Solid) em um elemento do tipo voxel)*/
              c.at(c.getNormalPos(i, j, k)) = (*this);
            }
        }
      }
    }
}


inline int Cylinder::getMaxX() const {
  return (pos.x + radius);
}
inline int Cylinder::getMaxY() const {
  return (float(pos.y) + (height / 2.0));
}
inline int Cylinder::getMaxZ() const {
  return (pos.z + radius);
}
inline int Cylinder::getMinX() const {
  return (pos.x - radius);
}
inline int Cylinder::getMinY() const {
  return (float(pos.y) - (height / 2.0));
}
inline int Cylinder::getMinZ() const {
  return (pos.z - radius);
}

void Ellipsoid::sculpt(Canvas& c) const{
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
          c.at(c.getNormalPos(i, j, k)) = (*this);
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


void Toroid::sculpt(Canvas& c) const{
  for (int i = getMinX(); i < getMaxX(); i++) {
    for (int j = getMinY(); j < getMaxY(); j++) {
      for (int k = getMinZ(); k < getMaxZ(); k++) {
        // Verifica se o ponto faz parte do toróide
        if (
          pow( t_radius - sqrt( pow(i - pos.x, 2) + pow(j - pos.y, 2) ), 2) + pow(k - pos.z, 2) < pow(p_radius, 2)
        ){
          c.at(c.getNormalPos(i, j, k)) = (*this);
        }
      }
    }
  }
}

inline int Toroid::getMaxX() const {
  return (pos.x + p_radius + t_radius);
}
inline int Toroid::getMaxY() const {
  return (pos.y + p_radius + t_radius);
}
inline int Toroid::getMaxZ() const {
  return (pos.z + p_radius + t_radius);
}
inline int Toroid::getMinX() const {
  return (pos.x - p_radius - t_radius);
}
inline int Toroid::getMinY() const {
  return (pos.y - p_radius - t_radius);
}
inline int Toroid::getMinZ() const {
  return (pos.z - p_radius - t_radius);
}
