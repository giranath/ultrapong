//
//  Goal.cpp
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Goal.h"

Goal::Goal() {
    _length = 300;
    
    _shape.setSize(sf::Vector2f(10, _length));
    _shape.setOrigin(0, _length/2);
    _shape.setPosition(0,0);
    
    _life = 10;
}

Goal::~Goal() {
    
}

void Goal::render(sf::RenderTarget &Target) {
    _shape.setSize(sf::Vector2f(10, _length));
    _shape.setOrigin(5, _length/2);
    _shape.setPosition(_position);
    
    Target.draw(_shape);
}

void Goal::setColor(sf::Color color) {
    _fillColor = color;
    
    _shape.setFillColor(_fillColor);
}