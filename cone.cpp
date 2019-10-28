#include "cone.h"
#include "disk.h"
#include "cmath"

Cone::Cone(int nbVertices, int ndisk) : TriMesh()
{
    _name = "Cone";
    //vertices
        for (int i=0;i<ndisk-1;++i) {
            float z = 1-i*2/((float)ndisk-1);
            float radius = 1-i/((float)ndisk-1);
            this->addVertex(0,0,z);
            for (float i=0; i<2*M_PI ; i+=(2/(float)nbVertices)*M_PI)
                this->addVertex(radius*cos(i),radius*sin(i),z);
        }
        this->addVertex(0,0,-1);
        //bottom disk
        for (int j=1; j<nbVertices+1; ++j)
            this->addTriangle(0,j,j%nbVertices+1);


        //side triangles
        for(int i=0;i<ndisk-2;++i) {
            for (int j=1; j<nbVertices+1; ++j)
                this->addTriangle(1+j%nbVertices+i*(nbVertices+1),
                                  j+i*(nbVertices+1),
                                  j+1+nbVertices+i*(nbVertices+1));
            for (int j=1; j<nbVertices+1; ++j)
                this->addTriangle(j%nbVertices+2+nbVertices+i*(nbVertices+1),
                                  j%nbVertices+1+i*(nbVertices+1),
                                  nbVertices+j+1+i*(nbVertices+1));
        }
        for (int j=1; j<nbVertices+1; ++j)
            this->addTriangle(1+j%nbVertices+(ndisk-2)*(nbVertices+1),
                              j+(ndisk-2)*(nbVertices+1),
                              (ndisk-1)*(nbVertices+1));

    computeNormalsT();
    computeNormalsV();
}
