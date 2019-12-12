//
//  main.cpp
//  main
//
//  Created by 西川功佑 on 2019/12/13.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

// この中に描画したいものを入れる
void Display()
{
}

int main(int argc, char *argv[])
{
    // GLUTとOpenGL環境の初期化
    glutInit(&argc, argv);
    // ウィンドウを開く関数
    glutCreateWindow(argv[0]);
    // ウィンドウが開かれたり再描画の際に実行
    glutDisplayFunc(Display);
    // 無限ループの関数，イベント待ち状態
    glutMainLoop();
    return 0;
}
