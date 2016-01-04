//
//  Entity.h
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#ifndef __GameTest__Entity__
#define __GameTest__Entity__

#include <iostream>
#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity() {};
    ~Entity() {};
    
    virtual void render(sf::RenderTarget &target);
    
    void setVelocity(float x, float y);
    void setVelocity(sf::Vector2f velocity);
    
    sf::Vector2f extrapolatedPosition() {return _position + _velocity * _speed;}
    sf::Vector2f position() const {return _position;}
    void setPosition(float x, float y) {this->setPosition(sf::Vector2f(x,y));}
    void setPosition(sf::Vector2f position) {_position = position; _shape.setPosition(_position);}
    
    float radius() const {return _radius;}
    void setRadius(float value);
    
    void setFillColor(sf::Color color) {_fillColor = color; _shape.setFillColor(_fillColor);}
    void setOutlineColor(sf::Color color) {_outlineColor = color; _shape.setOutlineColor(_outlineColor);}
    
    virtual void updatePosition();
    
    sf::Vector2f velocity() const {return _velocity;}
    float actualSpeed();
    
    void setSpeed(float speed) {_speed = speed;}
    float speed() const {return _speed;}
protected:
    float _radius;
    sf::CircleShape _shape;
    sf::Vector2f _position;
    sf::Vector2f _velocity;
    
    sf::Color _fillColor, _outlineColor;
    float _speed, _maxSpeed;
};

#endif /* defined(__GameTest__Entity__) */
