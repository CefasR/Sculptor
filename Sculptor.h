#ifndef _SCULPTOR_H_
#define _SCULPTOR_H_

#
#include <list>
#include "Solids.h"
#include "Canvas.h"
using namespace std;


class Sculptor : protected Canvas{
private:
    list<pSolid> l;
public:
    void setColor(float R, float G, float B, float A);
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
};

#endif //_SCULPTOR_H_
