//
//  Player.cpp
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Player.h"
#include "Utils.h"

Player::Player()
:Entity(){

    _speed = 5.0f;
    _radius = 25;
    
    _shape.setRadius(_radius);
    _shape.setFillColor(sf::Color(255,255,255));
    _shape.setOutlineColor(sf::Color(255,255,255));
    _shape.setOrigin(_radius, _radius);
    
    _shape.setPosition(0, 0);
    
    _boost = 100;
    
    _traine.resize(25);
    
    for(int i = 0; i < _traine.size(); i++) {
        _traine[i].setRadius(_radius - i * 1);
        _traine[i].setOrigin(_radius - i * 1, _radius - i * 1);
    }
    
    _res = 0.45f;
}

Player::~Player() {
    
}

void Player::render(sf::RenderTarget &target) {
    target.draw(_shape);
    
    for(int i = (int)_traine.size() - 1; i >= 0; i--) {
        _traine[i].setFillColor(sf::Color(_fillColor.r, _fillColor.g, _fillColor.b, 255 - (i * 10)));
        
        target.draw(_traine[i]);
    }
}

void Player::updatePosition() {
    _position += _velocity * _speed;
    
    _shape.setPosition(_position);
    
    _traine[0].setPosition(_position);
    
    for(int i = 1; i < _traine.size(); i++) {
        sf::Vector2f stretch = _traine[i].getPosition() - _traine[i - 1].getPosition();
        sf::Vector2f force = -_res * stretch - 1.0f * _velocity;
        
        sf::Vector2f acceleration = force / 1.0f;
        
        _traine[i].setPosition(_traine[i].getPosition() + acceleration);
    }
}

void Player::setQueue(float x, float y) {
    for(int i = 0; i < _traine.size(); i++) {
        _traine[i].setPosition(x, y);
    }
}

void Player::boost() {
    if(_boost > 0)
        _speed = 10.0f;
    else
        _speed = 5.0f;
    
    _boost -= 1;
    
    if(_boost <= 0)
        _boost = 0;
    
    if(_boostActivated == true) {
        _boostActivated = false;
        _boostClock.restart();
    }
}

void Player::chargeBoost() {
    _speed = 5.0f;
    
    if(_boostClock.getElapsedTime().asSeconds() > 3) {
        _boostActivated = true;
    }
    
    if(_boostActivated) {
        _boost++;
    }
    
    if(_boost >= 100)
        _boost = 100;
}
