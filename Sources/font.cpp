//
//  font.cpp
//  SenbEngine
//
//  Created by 西川功佑 on 2019/12/15.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>
#include "font.hpp"
#include "glm.hpp"
#include <GLUT/GLUT.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

using namespace glm;

static vec2 position;
static float size = FONT_DEFAULT_SIZE;
static unsigned char color[3];

void fontBegin()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    // (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
    gluOrtho2D(0, viewport[2], viewport[3], 0);
    // (GLfloat angle, GLfloat x, GLfloat y, GLfloat z) 指定した軸方向にangle度回転する関数
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}

void fontEnd()
{
    glPopMatrix();
    glPopAttrib();
}

void fontSetPosition(float _x, float _y)
{
    position = vec2(_x, _y);
}

void fontSetSize(float _size)
{
    size = _size;
}

float fontGetSize()
{
    return size;
}

void fontSetColor(unsigned char _red, unsigned char _green, unsigned char _blue)
{
    color[0] = _red;
    color[1] = _green;
    color[2] = _blue;
}

void fontDraw(const char *_format, ...)
{
    va_list argList;
    va_start(argList, _format);
    char str[256];
    vsprintf(str, _format, argList);
    va_end(argList);
    
    glColor3ub(color[0], color[1], color[2]);
    glPushMatrix();
    {
        glTranslatef(position.x, position.y + size, 0);
        float s = size / FONT_DEFAULT_SIZE;
        glScalef(s, -s, s);
        for(char* p= str; *p!='\0';p++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    }
    //printf("%s\n",str);
}
