//
//  font.hpp
//  SenbEngine
//
//  Created by 西川功佑 on 2019/12/15.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#ifndef font_hpp
#define font_hpp

#define FONT_DEFAULT_SIZE (100.f)
void fontBegin();
void fontEnd();

void fontSetPosition(float _x, float _y);
void fontSetSize(float _size);
float fontGetSize();
void fontSetColor(unsigned char _red, unsigned char _green, unsigned char _blue);
void fontDraw(const char *_format, ...);

#endif /* font_hpp */
