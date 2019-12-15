//
//  Rect.hpp
//  SenbEngine
//
//  Created by 西川功佑 on 2019/12/15.
//  Copyright © 2019 西川功佑. All rights reserved.
//

#ifndef Rect_hpp
#define Rect_hpp

#include "glm.hpp"

using namespace glm;

struct Rect
{
    vec2 m_position;
    vec2 m_size;
    
    Rect(vec2 const& _position, vec2 const& _size);
    void draw();
    bool intersect(vec2 const& _point);
    bool intersect(Rect const& _rect);
};

#endif /* Rect_hpp */
