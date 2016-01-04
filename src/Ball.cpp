//
//  Ball.cpp
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Ball.h"

Ball::Ball()
:Entity(){
    
    _speed = 5.5f;
    _radius = 15;
    
    _shape.setRadius(_radius);
    _shape.setFillColor(sf::Color(255,255,255));
    _shape.setOutlineColor(sf::Color(255,255,255));
    _shape.setOutlineThickness(1);
    _shape.setOrigin(_radius, _radius);
    
    _shape.setPosition(0, 0);
}

Ball::~Ball() {
    
}