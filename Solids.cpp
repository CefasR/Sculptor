#include "Solids.h"

using namespace std;

POS_3D <int> round (POS_3D <float> pos) {
  // POS_3D <int> tmp = pos;
  //
  // POS_3D <float> distance = pos - tmp;
  // float d = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
  //
  //
  // cout << distance << " o ";
  // if (d > sqrt(3) ){
  //   distance.x /= d;
  //   distance.y /= d;
  //   distance.z /= d;
  // }
  // //
  // // cout << "Antigo " << tmp << " | " << distance << endl;
  // //
  // // if ( pow(distance.x, 2) + pow(distance.y, 2) > 2 ) {
  // //   tmp.x += round(distance.x);
  // //   tmp.y += round(distance.y);
  // // }
  // //
  // // if ( pow(distance.z, 2) + pow(distance.y, 2) > 2 ) {
  // //   tmp.z += round(distance.x);
  // //   tmp.y += round(distance.y);
  // // }
  // //
  // // cout << "Novo " << tmp << endl;
  // //
  // cout << tmp << " -- " << distance.x << " " << distance.y << " " << (distance.z) << " | " << pos << " | ";

  return POS_3D <int> ( round(pos.x), round(pos.y), round(pos.z));
}

void Box::sculpt(Canvas& c) const
{
  cout << "Sculpting Box..." << endl;
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i <= maxP.x; i += 0.5) {
    for (float j = minP.y; j <= maxP.y; j += 0.5) {
      for (float k = minP.z; k <= maxP.z; k += 0.5) {
          POS_3D <int> p = round( TM.transform(POS_3D <float>(i,j,k)) );
          c.at(c.getNormalPos(p.x, p.y, p.z )) = (*this);
      }
    }
  }
}

int Box::getMaxX() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  int max;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) max = current.x;
        if (current.x > max) max = current.x;
      }
    }
  }
  return max + 1;
}

int Box::getMaxY() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  int max;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) max = current.y;
        if (current.y > max) max = current.y;
      }
    }
  }
  return max + 1;
}
int Box::getMaxZ() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  int max;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) max = current.z;
        if (current.z > max) max = current.z;
      }
    }
  }
  return max + 1;
}
int Box::getMinX() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) min = current.x;
        if (current.x < min) min = current.x;
      }
    }
  }
  return min;
}
int Box::getMinY() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
       if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) min = current.y;
        if (current.y < min) min = current.y;
      }
    }
  }
  return min;
}
int Box::getMinZ() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));

        if (i == pos.x - (width / 2.0) && j == pos.y - (length / 2.0) && k == pos.y - (length / 2.0)) min = current.z;
        if (current.z < min) min = current.z;
      }
    }
  }
  return min;
}

inline POS_3D <int> Box::getLimMin() const {
  return POS_3D <int> ( pos.x - (width / 2.0), pos.y - (length / 2.0), pos.z - (height / 2.0) );
}

inline POS_3D <int> Box::getLimMax() const {
  return POS_3D <int> ( pos.x + (width / 2.0), pos.y + (length / 2.0), pos.z + (height / 2.0) );
}

void Cylinder::sculpt(Canvas& c) const
{
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio

  cout << "Sculpting a Cylinder..." << endl;
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i <= maxP.x; i += 0.5) {
    for (float j = minP.y; j <= maxP.y; j += 0.5) {
      for (float k = minP.z; k <= maxP.z; k += 0.5) {
        // Verifica se o ponto faz parte do cilindro
          if ((pow(float(i) - pos.x, 2) + pow(float(k) - pos.z, 2)) < pow(radius, 2)){
              POS_3D <int> p = round( TM.transform(POS_3D <float>(i,j,k)) );
              c.at(c.getNormalPos(p.x, p.y, p.z )) = (*this);
                }
            }
        }
    }
}


int Cylinder::getMaxX() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - radius && j == pos.y - (height / 2.0) && k == pos.z - radius) max = current.x;
            if (current.x > max) max = current.x;
          }
        }
      }
  return max + 1;
}

int Cylinder::getMaxY() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - radius && j == pos.y - (height / 2.0) && k == pos.z - radius) max = current.y;
            if (current.y > max) max = current.y;
          }
        }
      }
  return max + 1;
}

int Cylinder::getMaxZ() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - radius && j == pos.y - (height / 2.0) && k == pos.z - radius) max = current.z;
            if (current.z > max) max = current.z;
          }
        }
      }
  return max + 1;
}
int Cylinder::getMinX() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - radius && j == pos.y - (height / 2.0) && k == pos.z - radius) min = current.x;
        if (current.x < min) min = current.x;
      }
    }
  }
  return min;
}

int Cylinder::getMinY() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - radius && j == pos.y - (height / 2.0) && k == pos.z - radius) min = current.y;
        if (current.y < min) min = current.y;
      }
    }
  }
  return min;
}

int Cylinder::getMinZ() const {

  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - radius && j == pos.y - (height / 2.0) && k == pos.z - radius) min = current.z;
        if (current.z < min) min = current.z;
      }
    }
  }
  return min;
}

inline POS_3D <int> Cylinder::getLimMax() const {
  return POS_3D <int> ( pos.x + radius, pos.y + (height / 2.0), pos.z + radius );
}

inline POS_3D <int> Cylinder::getLimMin() const {
  return POS_3D <int> ( pos.x - radius, pos.y - (height / 2.0), pos.z - radius );
}


void Cone::sculpt(Canvas& c) const
{
  // Varia i, j, k das respctivas posições do centro (X, Y, Z) menos o respectivo raio (RX, RY, RZ)
  // até as respectivas posições do centro acrescidas ao respectivo raio
POS_3D <int> minP = getLimMin(), maxP = getLimMax();
  cout << "Sculpting a Cone..." << endl;
    for (float i = minP.x; i <= maxP.x; i += 0.5) {
      for (float j = minP.y; j <= maxP.y; j += 0.5) {
        for (float k = minP.z; k <= maxP.z; k += 0.5) {
            // Verifica se o ponto faz parte do cilindro
            if ( pow(i - pos.x, 2) + pow(j - pos.y, 2) < pow((height - (k - minP.z )) * (x_radius / height), 2) ) {
                POS_3D <float> p = TM.transform(POS_3D <float>(i,j,k));
                c.at(c.getNormalPos(p.x, p.y, p.z)) = (*this);
            }
        }
      }
    }
}


int Cone::getMaxX() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - x_radius && k == pos.z - height / 2.0) max = current.x;
            if (current.x > max) max = current.x;
          }
        }
      }
  return max + 1;
}
int Cone::getMaxY() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - x_radius && k == pos.z - height / 2.0) max = current.y;
            if (current.y > max) max = current.y;
          }
        }
      }
  return max + 1;
}
int Cone::getMaxZ() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - x_radius && k == pos.z - height / 2.0) max = current.z;
            if (current.z > max) max = current.z;
          }
        }
      }
  return max + 1;
}
int Cone::getMinX() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int min;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - x_radius && k == pos.z - height / 2.0) min = current.x;
            if (current.x < min) min = current.x;
          }
        }
      }
  return min;
}
int Cone::getMinY() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int min;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - x_radius && k == pos.z - height / 2.0) min = current.y;
            if (current.y < min) min = current.y;
          }
        }
      }
  return min;
}
int Cone::getMinZ() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int min;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - x_radius && k == pos.z - height / 2.0) min = current.z;
            if (current.z < min) min = current.z;
          }
        }
      }
  return min;
}

inline POS_3D <int> Cone::getLimMax() const {
  return POS_3D <int> ( pos.x + x_radius, pos.y + y_radius, pos.z + height / 2.0 );
}

inline POS_3D <int> Cone::getLimMin() const {
  return POS_3D <int> ( pos.x - x_radius, pos.y - y_radius, pos.z - height / 2.0 );
}


void Ellipsoid::sculpt(Canvas& c) const{

  cout << "Sculpting a Ellipsoid..." << endl;
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i <= maxP.x; i += 0.5) {
    for (float j = minP.y; j <= maxP.y; j += 0.5) {
      for (float k = minP.z; k <= maxP.z; k += 0.5) {
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

int Ellipsoid::getMaxX() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - y_radius && k == pos.z - z_radius) max = current.x;
            if (current.x > max) max = current.x;
          }
        }
      }
  return max + 1;
}

int Ellipsoid::getMaxY() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - y_radius && k == pos.z - z_radius) max = current.y;
            if (current.y > max) max = current.y;
          }
        }
      }
  return max + 1;
}

int Ellipsoid::getMaxZ() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - x_radius && j == pos.y - y_radius && k == pos.z - z_radius) max = current.z;
            if (current.z > max) max = current.z;
          }
        }
      }
  return max + 1;
}

int Ellipsoid::getMinX() const {
  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - x_radius && j == pos.y - y_radius && k == pos.z - z_radius) min = current.x;
        if (current.x < min) min = current.x;
      }
    }
  }
  return min;
}
int Ellipsoid::getMinY() const {

  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - x_radius && j == pos.y - y_radius && k == pos.z - z_radius) min = current.y;
        if (current.y < min) min = current.y;
      }
    }
  }
  return min;
}
int Ellipsoid::getMinZ() const {

  POS_3D <int> minP = getLimMin(), maxP = getLimMax();
  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
        if (i == pos.x - x_radius && j == pos.y - y_radius && k == pos.z - z_radius) min = current.z;
        if (current.z < min) min = current.z;
      }
    }
  }
  return min;
}


inline POS_3D <int> Ellipsoid::getLimMax() const {
  return POS_3D <int> (pos.x + x_radius, pos.y + y_radius, pos.z + z_radius );
}

inline POS_3D <int> Ellipsoid::getLimMin() const {
  return POS_3D <int> (pos.x - x_radius, pos.y - y_radius, pos.z - z_radius );
}





void Toroid::sculpt(Canvas& c) const{
    cout << "Sculpting Toroid..." << endl;
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();

      for (float i = minP.x; i <= maxP.x; i += 0.5) {
        for (float j = minP.y; j <= maxP.y; j += 0.5) {
          for (float k = minP.z; k <= maxP.z; k += 0.5) {
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

int Toroid::getMaxX() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - p_radius - t_radius && j == pos.y - p_radius - t_radius && k == pos.z - p_radius - t_radius) max = current.x;
            if (current.x > max) max = current.x;
          }
        }
      }
  return max + 1;
}
int Toroid::getMaxY() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - p_radius - t_radius && j == pos.y - p_radius - t_radius && k == pos.z - p_radius - t_radius) max = current.y;
            if (current.y > max) max = current.y;
          }
        }
      }
  return max + 1;
}
int Toroid::getMaxZ() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int max;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - p_radius - t_radius && j == pos.y - p_radius - t_radius && k == pos.z - p_radius - t_radius) max = current.z;
            if (current.z > max) max = current.z;
          }
        }
      }
  return max + 1;

}
int Toroid::getMinX() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int min;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - p_radius - t_radius && j == pos.y - p_radius - t_radius && k == pos.z - p_radius - t_radius) min = current.x;
            if (current.x < min) min = current.x;
          }
        }
      }
  return min;

}
int Toroid::getMinY() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int min;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - p_radius - t_radius && j == pos.y - p_radius - t_radius && k == pos.z - p_radius - t_radius) min = current.y;
            if (current.y < min) min = current.y;
          }
        }
      }
  return min;
}
int Toroid::getMinZ() const {
    POS_3D <int> minP = getLimMin(), maxP = getLimMax();
    int min;
      for (int i = minP.x; i <= maxP.x; i++) {
        for (int j = minP.y; j <= maxP.y; j++) {
          for (int k = minP.z; k <= maxP.z; k++) {
            POS_3D <float> current = round(TM.transform(POS_3D <float> (i, j, k)));
            if (i == pos.x - p_radius - t_radius && j == pos.y - p_radius - t_radius && k == pos.z - p_radius - t_radius) min = current.z;
            if (current.z < min) min = current.z;
          }
        }
      }
  return min;
}

inline POS_3D <int> Toroid::getLimMax() const {
  return POS_3D <int> (pos.x + p_radius + t_radius, pos.y + p_radius + t_radius, pos.z + p_radius + t_radius);
}

inline POS_3D <int> Toroid::getLimMin() const {
  return POS_3D <int> (pos.x - p_radius - t_radius, pos.y - p_radius - t_radius, pos.z - p_radius - t_radius);
}
