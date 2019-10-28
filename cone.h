#ifndef CONE_H
#define CONE_H

#include "triMesh.h"
#include "disk.h"

class Cone : public TriMesh
{
public:
    Cone(int nbVertices, int ndisk);
    virtual ~Cone(){};
};

#endif // CONE_H
