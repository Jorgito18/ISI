#ifndef TORUS_H
#define TORUS_H

#include "triMesh.h"

class Torus : public TriMesh
{
public:
    Torus(int nbCercles, int vertexCercle);
};

#endif // TORUS_H#include "torus.h"

#include <cmath>
#include <iostream>

Torus::Torus(int nbCercles, int vertexCercle)
{

    _name="Torus";
    _vertices.clear();
    double x,y,z;
    double circleStep=(2.*M_PI)/vertexCercle;
    double longStep=(2.*M_PI)/nbCercles;

    //Adding Vertex
    for(double i=0.;i<2.*M_PI;i+=longStep)
    {

        for(double j=0.;j<2.*M_PI;j+=circleStep)
        {
            x=((2./3.)+(1./3.)*cos(j))*cos(i);
            y=((2./3.)+(1./3.)*cos(j))*sin(i);
            z=(1./3.)*sin(j);
            addVertex(x,y,z);
        }

    }

    int nbVertex = nbCercles*vertexCercle;
    //Adding triangles
    for(int i=0;i<nbCercles;++i)
        for(int j=0;j<vertexCercle;++j)
        {
            addTriangle((i*vertexCercle+j+1)%(nbVertex),
                        (i*vertexCercle+j)%(nbVertex),
                        ((i+1)*vertexCercle+j)%(nbVertex));
            addTriangle(((i+1)*vertexCercle+j)%(nbVertex),
                        ((i+1)*vertexCercle+j+1)%(nbVertex),
                        (i*vertexCercle+j+1)%(nbVertex));
        }

    computeNormalsT();
    computeNormalsV();
}

