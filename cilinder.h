//#ifndef _CILINDER_H_ TODO
#define CILINDER_H

#include "triMesh.h"

class Cilinder : public TriMesh
{
public:
    Cilinder(int nbVertices, int ndisk);
    virtual ~Cilinder(){};
};
