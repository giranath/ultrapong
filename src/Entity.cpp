//
//  Entity.cpp
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Entity.h"
#include "Utils.h"


void Entity::render(sf::RenderTarget &target) {
    target.draw(_shape);
}

void Entity::setVelocity(float x, float y) {
    float dist = distance(0, 0, x, y);
    
    if(x != 0)
        x/= dist;
    else
        x = 0;
    
    if(y != 0)
        y/= dist;
    else
        y = 0;
    
    _velocity = sf::Vector2f(x,y);
}

void Entity::setVelocity(sf::Vector2f velocity) {
    this->setVelocity(velocity.x, velocity.y);
}


void Entity::updatePosition() {
    _position += _velocity * _speed;
    
    _shape.setPosition(_position);
}

void Entity::setRadius(float value) {
    _radius = value;
    
    _shape.setRadius(_radius);
    _shape.setOrigin(_radius, _radius);
}

float Entity::actualSpeed() {
    if(_velocity.x == 0 && _velocity.y == 0) {
        return 0;
    }
    
    return _speed;
}