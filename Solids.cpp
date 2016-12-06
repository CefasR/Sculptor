#include "Solids.h"

using namespace std;

inline POS_3D <int> round (POS_3D <float> pos) {
  return POS_3D <int> ( round(pos.x), round(pos.y), round(pos.z) );
}

void Box::sculpt(Canvas& c) const
{
  cout << "Sculpting Box..." << endl;
  POS_3D <float> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i < maxP.x; i += 0.5) {
    for (float j = minP.y; j < maxP.y; j += 0.5) {
      for (float k = minP.z; k < maxP.z; k += 0.5) {

          POS_3D <int> p = round( TM.transform(POS_3D <float>(i,j,k)) );
          c.at(c.getNormalPos(p.x, p.y, p.z )) = (*this);
      }
    }
  }
}

int Solid::getMaxX() const {
  POS_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();
  int max;

  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));

        if (POS_3D <int> (i, j, k) == minP ) max = round(current.x);
        if (current.x > max) max = round(current.x);
      }
    }
  }
  return max + 1;
}

int Solid::getMaxY() const {
  POS_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int max;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));

        if (POS_3D <int> (i, j, k) == minP ) max = round(current.x);
        if (current.y > max) max = round(current.y);
      }
    }
  }
  return max + 1;
}
int Solid::getMaxZ() const {
  POS_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int max;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));

        if (POS_3D <int> (i, j, k) == minP ) max = round(current.x);
        if (current.z > max) max = round(current.z);
      }
    }
  }
  return max + 1;
}


int Solid::getMinX() const {
  POS_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));

        if (POS_3D <int> (i, j, k) == minP ) min = round(current.x);
        if (current.x < min) {
          min = round(current.x);
        }
      }
    }
  }

  return min;
}
int Solid::getMinY() const {
  POS_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));

        if (POS_3D <int> (i, j, k) == minP ) min = round(current.x);
        if (current.y < min) min = round(current.y);
      }
    }
  }
  return min;
}
int Solid::getMinZ() const {
  POS_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));

        if (POS_3D <int> (i, j, k) == minP ) min = round(current.x);
        if (current.z < min) min = round(current.z);
      }
    }
  }
  return min;
}

inline POS_3D <float> Box::getLimMin() const {
  return POS_3D <float> ( pos.x - (width / 2.0), pos.y - (length / 2.0), pos.z - (height / 2.0) );
}

inline POS_3D <float> Box::getLimMax() const {
  return POS_3D <float> ( pos.x + (width / 2.0), pos.y + (length / 2.0), pos.z + (height / 2.0) );
}

void Cylinder::sculpt(Canvas& c) const
{
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio

  cout << "Sculpting a Cylinder..." << endl;
  POS_3D <float> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i < maxP.x; i += 0.5) {
    for (float j = minP.y; j < maxP.y; j += 0.5) {
      for (float k = minP.z; k < maxP.z; k += 0.5) {
        // Verifica se o ponto faz parte do cilindro
          if ((pow(float(i) - pos.x, 2) + pow(float(k) - pos.z, 2)) < pow(radius, 2)){
              POS_3D <int> p = round( TM.transform(POS_3D <float>(i,j,k)) );

              c.at(c.getNormalPos(p.x, p.y, p.z )) = (*this);
                }
            }
        }
    }
}

inline POS_3D <float> Cylinder::getLimMax() const {
  return POS_3D <int> ( pos.x + radius, pos.y + (height / 2.0), pos.z + radius );
}

inline POS_3D <float> Cylinder::getLimMin() const {
  return POS_3D <int> ( pos.x - radius, pos.y - (height / 2.0), pos.z - radius );
}


void Cone::sculpt(Canvas& c) const
{
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio
POS_3D <float> minP = getLimMin(), maxP = getLimMax();
  cout << "Sculpting a Cone..." << endl;
    for (float i = minP.x; i < maxP.x; i += 0.5) {
      for (float j = minP.y; j < maxP.y; j += 0.5) {
        for (float k = minP.z; k < maxP.z; k += 0.5) {
            // Verifica se o ponto faz parte do cilindro
            if ( pow(i - pos.x, 2) + pow(j - pos.y, 2) < pow((height - (k - minP.z )) * (x_radius / height), 2) ) {
                POS_3D <float> p = TM.transform(POS_3D <float>(i,j,k));
                c.at(c.getNormalPos(p.x, p.y, p.z)) = (*this);
            }
        }
      }
    }
}

inline POS_3D <float> Cone::getLimMax() const {
  return POS_3D <int> ( pos.x + x_radius, pos.y + y_radius, pos.z + height / 2.0 );
}

inline POS_3D <float> Cone::getLimMin() const {
  return POS_3D <int> ( pos.x - x_radius, pos.y - y_radius, pos.z - height / 2.0 );
}


void Ellipsoid::sculpt(Canvas& c) const{

  cout << "Sculpting a Ellipsoid..." << endl;
  POS_3D <float> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i < maxP.x; i += 0.5) {
    for (float j = minP.y; j < maxP.y; j += 0.5) {
      for (float k = minP.z; k < maxP.z; k += 0.5) {
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
            POS_3D <int> p = round( TM.transform(POS_3D <float>(i,j,k)) );
            c.at(c.getNormalPos(p.x, p.y, p.z )) = (*this);
          }
      }
    }
  }
}

inline POS_3D <float> Ellipsoid::getLimMax() const {
  return POS_3D <int> (pos.x + x_radius, pos.y + y_radius, pos.z + z_radius );
}

inline POS_3D <float> Ellipsoid::getLimMin() const {
  return POS_3D <int> (pos.x - x_radius, pos.y - y_radius, pos.z - z_radius );
}





void Toroid::sculpt(Canvas& c) const{
    cout << "Sculpting Toroid..." << endl;
    POS_3D <float> minP = getLimMin(), maxP = getLimMax();

      for (float i = minP.x; i < maxP.x; i += 0.5) {
        for (float j = minP.y; j < maxP.y; j += 0.5) {
          for (float k = minP.z; k < maxP.z; k += 0.5) {
        // Verifica se o ponto faz parte do toróide
            if (
              pow( t_radius - sqrt( pow(i - pos.x, 2) + pow(j - pos.y, 2) ), 2) + pow(k - pos.z, 2) < pow(p_radius, 2)
            ){
              POS_3D <int> p = round( TM.transform(POS_3D <float>(i,j,k)) );
              c.at(c.getNormalPos(p.x, p.y, p.z )) = (*this);
            }
          }
        }
      }
}

inline POS_3D <float> Toroid::getLimMax() const {
  return POS_3D <int> (pos.x + p_radius + t_radius, pos.y + p_radius + t_radius, pos.z + p_radius + t_radius);
}

inline POS_3D <float> Toroid::getLimMin() const {
  return POS_3D <int> (pos.x - p_radius - t_radius, pos.y - p_radius - t_radius, pos.z - p_radius - t_radius);
}
