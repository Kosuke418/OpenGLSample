//
//  polygon.cpp
//  main
//
//  Created by 西川功佑 on 2019/12/15.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#define PI 3.141592
#include "polygon.hpp"
#include <math.h>
#include <GLUT/GLUT.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// 多角形を描画するための関数 Nは頂点の数
void Polygon(int N)
{
    glColor3d(1.0, 1.0, 0.0);
    for(int i=0;i<2*N;i+=2)
    {
        glVertex2d(cos(PI/180*(90+i*360/N))*0.9, sin(PI/180*(90+i*360/N))*0.9);
    }
}
