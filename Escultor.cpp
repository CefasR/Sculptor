#include "Escultor.h"
#include <cmath>
using namespace std;


void Box::sculpt(Canvas& c) const
{
  int pos_x = pos.x - (x_size / 2), pos_y = pos.y - (y_size / 2), pos_z = pos.z - (z_size / 2); //Cefas, vc t� usando essas vari�veis em outros lugares mas declarou localmente

  for (int i = pos_x; i < pos_x + x_size; i++) {
    for (int j = pos_y; j < pos_y + y_size; j++) {
      for (int k = pos_z; k < pos_z + z_size; k++) {
          Voxel v(R, G, B, alpha, is_on);
          c.at(i, j, k) = v;
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

void Sphere::sculpt(Canvas& c) const
{
  for (int i = pos.x - raio; i < pos.x + raio; i++) {
    for (int j = pos.y - raio; j < pos.y + raio; j++) {
      for (int k = pos.z - raio; k < pos.z + raio; k++) {
        if ((pow(int(i - pos.x), 2) + pow(int(j - pos.y), 2) + pow(int(k - pos.z), 2)) <= pow(raio, 2)){
          Voxel v(R, G, B, alpha, is_on);
          c.at(i, j, k) = v;
        }
      }
    }
  }
}


unsigned int Sphere::getMaxX() const {

}
unsigned int Sphere::getMaxY() const {

}
unsigned int Sphere::getMaxZ() const {

}
unsigned int Sphere::getMinX() const {

}
unsigned int Sphere::getMinY() const {

}
unsigned int Sphere::getMinZ() const {

}

void Cylinder::sculpt(Canvas& c) const
{
    for (int i = int(pos.x - raio); i < int(pos.x + raio); i++) {
        for (int j = int(pos.y - raio); j < int(pos.y + raio); j++) {
            for (int k = int(pos.z - altura); k < int(pos.z + altura); k++) {
                if ((pow(int(i - pos.x), 2) + pow(int(j - pos.y), 2)) <= pow(raio, 2)){
                  Voxel v(R, G, B, alpha, is_on);
                  c.at(i, j, k) = v;
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
  for (int i = int(pos.x - raio1); i < int(pos.x + raio1); i++) {
    for (int j = int(pos.y - raio2); j < int(pos.y + raio2); j++) {
      for (int k = int(pos.z - raio3); k < int(pos.z + raio3); k++) {
        //if (i >= 0 && j >= 0 && k >= 0 && (pow(int(i - pos.x), 2) + pow(int(j - pos.y), 2)) <= pow(raio, 2)){
          /*if (! matriz[i][j][k].is_on) qtd++;
          Voxel v(R, G, B, alpha, is_on);
          matriz[i][j][k] = v;*/
        //}
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
