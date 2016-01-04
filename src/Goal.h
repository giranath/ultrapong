//
//  Goal.h
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#ifndef __GameTest__Goal__
#define __GameTest__Goal__

#include <iostream>
#include "Entity.h"
class Goal {
public:
    Goal();
    ~Goal();
    
    void render(sf::RenderTarget &target);
    
    void setPosition(float x, float y) {_position.x = x; _position.y = y; _shape.setPosition(_position);}
    void setPosition(sf::Vector2f position) {_position = position; _shape.setPosition(_position);}
    
    sf::Vector2f position() {return _position;}
    
    void setLife(int life) {_life = life; if(_life < 0) _life = 0;}
    int life() const {return _life;}
    
    void setLength(float length) {_length = length;}
    float length() const {return _length;}
    
    void setColor(sf::Color color);
    
private:
    sf::Vector2f _position;
    float _length;
    
    int _life;
    
    sf::RectangleShape _shape;
    sf::Color _fillColor;
};

#endif /* defined(__GameTest__Goal__) */
