#ifndef _SCULPTOR_H_
#define _SCULPTOR_H_

#include <list>
#include "Solids.h"
#include "Canvas.h"
using namespace std;

typedef list <pSolid>::iterator pSolidIterator;

class Sculptor : protected Canvas {
private:
    list <pSolid> l;
    float R, G, B, alpha;
public:

    //inline Sculptor() : Canvas::Canvas(), Solid::Solid() {}

    void setColor(float R, float G, float B, float A) { this->R = R; this->G = G; this->B = B; alpha = A; };
    void putVoxel(int X, int Y, int Z);
    void cutVoxel(int X, int Y, int Z);
    void putBox(int X0, int X1,
                int Y0, int Y1,
                int Z0, int Z1);
    void cutBox(int X0, int X1,
                int Y0, int Y1,
                int Z0, int Z1);
    void putSphere(int Xc, int Yc, int Zc, int R);
    void cutSphere(int Xc, int Yc, int Zc, int R);
    void putEllipsoid(int Xc, int Yc, int Zc,
                      int Rx, int Ry, int Rz);
    void cutEllipsoid(int Xc, int Yc, int Zc,
                      int Rx, int Ry, int Rz);
    void putCylinder(int Xc, int Yc, int Zc,
                     int R, int height);
    void cutCylinder(int Xc, int Yc, int Zc,
                     int R, int height);
    void cleanVoxels(void);
    void write(const char *Arq);

    // Retorna a extremidade mínima
    POS_3D <int> getMinXYZ();

    // Retorna a extremidade máxima
    POS_3D <int> getMaxXYZ();

    // Desenha as formas no canvas
    void draw();

};

#endif //_SCULPTOR_H_
