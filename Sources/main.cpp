//
//  main.cpp
//  SenbEngine
//
//  Created by 西川功佑 on 2019/12/13.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "glm.hpp"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "font.hpp"
#include "Rect.hpp"

using namespace glm;

ivec2 windowSize = { 800 , 600 };

bool keys[256];

Rect rect1 = Rect(vec2(100,100),vec2(100,200));
Rect rect2 = Rect(vec2(windowSize.x/2,windowSize.y/2),vec2(200,100));

vec2 tempvec;

// この中に描画したいものを入れる
void display()
{
    // (GLbitfield mask)ウィンドウを塗りつぶす maskは塗りつぶすためのバッファを指定する
    glClear(GL_COLOR_BUFFER_BIT);
    // (GLenum mode)
    glMatrixMode(GL_PROJECTION);
    //
    glLoadIdentity();
    // (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
    gluOrtho2D(0, windowSize.x, windowSize.y, 0);
    // (GLfloat angle, GLfloat x, GLfloat y, GLfloat z) 指定した軸方向にangle度回転する関数
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    fontBegin();
    fontSetColor(0,0xff,0);
    fontSetPosition(0, windowSize.y - fontGetSize()*1.5);
    fontSetSize(FONT_DEFAULT_SIZE/2);
    fontEnd();
    
    tempvec = rect1.m_position;
    if(rect1.intersect(rect2))
    {
        glColor3ub(0xff,0x00,0x00);
    }
    else glColor3ub(0x00,0x00,0xff);
    rect1.draw();
    
    glColor3ub(0x00,0xff,0x00);
    rect2.draw();
    // (void)まだ実行されていないOpenGLの命令を実行
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key==0x1b) exit(0);
    //printf("keyboad: '%c'(%#x)\n",key,key);
    keys[key] = true;
}


void keyboardup(unsigned char key, int x, int y)
{
    //printf("keyboard: '%c'(%#x)\n",key,key);
    keys[key] = false;
}

// 初期化処理を行う関数
void init(void)
{
    // (GLclampf R, GLclampf G, GLclampf B, GLclampf A)glclearでウィンドウを塗りつぶす際の色の指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void idle()
{
    float f = 5;
    if(keys['w']) rect1.m_position.y -= f;
    if(keys['s']) rect1.m_position.y += f;
    if(keys['a']) rect1.m_position.x -= f;
    if(keys['d']) rect1.m_position.x += f;
    if(rect1.intersect(rect2))
    {
        rect1.m_position = tempvec;
        printf("rect1.m_position: %f,%f\n",rect1.m_position.x,rect1.m_position.y);
    }

    // 再描画の関数 glutDisplayFunc()が実行される．
    glutPostRedisplay();
}

void reshape(int width, int height)
{
    //printf("reshape: width:%d height:%d\n",width,height);
    glViewport(0, 0, width, height);
    windowSize = ivec2(width,height);
}

int main(int argc, char *argv[])
{
    // (int *argcp, char **argv)GLUTとOpenGL環境の初期化
    glutInit(&argc, argv);
    // (unsigned int mode)ディスプレイの表示モードを設定 GLUT_RGBAを指定すると色の指定を三原色で行える
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(windowSize.x, windowSize.y);
    // (char *name)ウィンドウを開く関数
    glutCreateWindow("Title");
    // (void (*func)(void))ウィンドウが開かれたり再描画の際に実行
    glutDisplayFunc(display);
    // (void (*func)(unsigned char key, int x, int y))
    glutKeyboardFunc(keyboard);
    // (int gnore)
    glutIgnoreKeyRepeat(GL_TRUE);
    // ((void (*func)(unsigned char key, int x, int y)))
    glutKeyboardUpFunc(keyboardup);
    init();
    // (void (*func)(void))暇なときに呼ばれる関数．暇になるたび実行
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    // (void)無限ループの関数，イベント待ち状態
    glutMainLoop();
    return 0;
}
