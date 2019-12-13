//
//  main.cpp
//
//  Created by 西川功佑 on 2019/12/13.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#define PI 3.141592

using namespace std;

// 多角形を描画するための関数 Nは頂点の数
void Polygon(int N)
{
    glColor3d(1.0, 0.0, 0.0);
    for(int i=0;i<N;i++)
    {
        glVertex2d(cos(PI/180*(90+i*360/N))*0.9, sin(PI/180*(90+i*360/N))*0.9);
    }
}

// この中に描画したいものを入れる
void Display()
{
    // (GLbitfield mask)ウィンドウを塗りつぶす maskは塗りつぶすためのバッファを指定する
    glClear(GL_COLOR_BUFFER_BIT);
    
    // ▼図形を描くためのプログラム▼
    //
    glColor3d(1.0, 0.0, 0.0);
    // (GLnum mode)modenに図形タイプを入力 LINE_LOOPは折れ線を描く
    glBegin(GL_POLYGON);
    // (GLdouble x, GLdouble y)二次元の座標値を設定する
    Polygon(100);
    // (void)Begin~Endまでに図形の各頂点の座標値を指定する
    glEnd();
    // ▲図形を描くためのプログラム▲
    
    /*
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    Polygon(6);
    glEnd();
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    Polygon(7);
    glEnd();
    */
    
    // (void)まだ実行されていないOpenGLの命令を実行
    glFlush();
}

// 初期化処理を行う関数
void init(void)
{
    // (GLclampf R, GLclampf G, GLclampf B, GLclampf A)glclearでウィンドウを塗りつぶす際の色の指定
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
    // (int *argcp, char **argv)GLUTとOpenGL環境の初期化
    glutInit(&argc, argv);
    // (unsigned int mode)ディスプレイの表示モードを設定 GLUT_RGBAを指定すると色の指定を三原色で行える
    glutInitDisplayMode(GLUT_RGBA);
    // (char *name)ウィンドウを開く関数
    glutCreateWindow("Title");
    // (void (*func)(void))ウィンドウが開かれたり再描画の際に実行
    glutDisplayFunc(Display);
    init();
    // (void)無限ループの関数，イベント待ち状態
    glutMainLoop();
    return 0;
}
