//
//  main.cpp
//  main
//
//  Created by 西川功佑 on 2019/12/13.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "polygon.hpp"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

using namespace std;

// この中に描画したいものを入れる
void display()
{
    // (GLfloat angle, GLfloat x, GLfloat y, GLfloat z) 指定した軸方向にangle度回転する関数
    glRotatef(1, 1, 1, 0);
    // (GLbitfield mask)ウィンドウを塗りつぶす maskは塗りつぶすためのバッファを指定する
    glClear(GL_COLOR_BUFFER_BIT);
    
    // ▼図形を描くためのプログラム▼
    // (GLdouble r, GLdouble g, GLdouble b)これから描画するものの色を指定する
    glColor3d(1.0, 0.0, 0.0);
    // (GLnum mode)modeに図形タイプを入力 LINE_LOOPは折れ線を描く
    glBegin(GL_LINE_LOOP);
    // (GLdouble x, GLdouble y)二次元の座標値を設定する
    Polygon(5);
    // (void)Begin~Endまでに図形の各頂点の座標値を指定する
    glEnd();
    // ▲図形を描くためのプログラム▲
    
    // (void)まだ実行されていないOpenGLの命令を実行
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case 'q':
  case 'Q':
  case '\033':  /* '\033' は ESC の ASCII コード */
    exit(0);
  default:
    break;
  }
}

// 初期化処理を行う関数
void init(void)
{
    // (GLclampf R, GLclampf G, GLclampf B, GLclampf A)glclearでウィンドウを塗りつぶす際の色の指定
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void idle()
{
    // 再描画の関数 glutDisplayFunc()が実行される．
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    // (int *argcp, char **argv)GLUTとOpenGL環境の初期化
    glutInit(&argc, argv);
    // (unsigned int mode)ディスプレイの表示モードを設定 GLUT_RGBAを指定すると色の指定を三原色で行える
    glutInitDisplayMode(GLUT_DOUBLE);
    // (char *name)ウィンドウを開く関数
    glutCreateWindow("Title");
    // (void (*func)(void))ウィンドウが開かれたり再描画の際に実行
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    // (void (*func)(void))暇なときに呼ばれる関数．暇になるたび実行
    glutIdleFunc(idle);
    // (void)無限ループの関数，イベント待ち状態
    glutMainLoop();
    return 0;
}
