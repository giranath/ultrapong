//
//  Game.cpp
//  UltraPong
//
//  Created by Nathan on 2013-02-16.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Game.h"

Game::Game(sf::RenderWindow &window)
:_window(window), _nbPlayer(1)
{}

Game::~Game() {
    
}

bool Game::loadResources() {
    _bufHit_01.loadFromFile("hit_ball.wav");
    _bufHit_02.loadFromFile("hit_ball_02.wav");
    _bufHit_03.loadFromFile("hit_ball_03.wav");
    
    _bufHurt_01.loadFromFile("goal_hurt_03.wav");
    _bufHurt_02.loadFromFile("goal_hurt_02.wav");
    
    _bufBoostEmpty.loadFromFile("Boost_beep.wav");
    _beepSnd.setBuffer(_bufBoostEmpty);
    
    _backMus_01.openFromFile("Background_01.ogg");
    _backMus_01.setVolume(75);
    
    _boostBar2.setSize(sf::Vector2f(400, 50));
    _boostBar2.setPosition(100, 10);
    _boostBar2.setFillColor(sf::Color(0,0,255, 160));
    
    _boostBar1.setSize(sf::Vector2f(400, 50));
    _boostBar1.setPosition(_window.getSize().x - 500, 10);
    _boostBar1.setFillColor(sf::Color(255,0,0, 160));
    
    _lifeGoal1.resize(10);
    _lifeGoal2.resize(10);
    
    return true;
}

void Game::changeHurtBuffer() {
    
    _hurtBufIndex++;
    
    if(_hurtBufIndex > 1) {
        _hurtBufIndex = 0;
    }
    
    switch (_hurtBufIndex) {
        case 0:
            _hurtSnd.setBuffer(_bufHurt_01);
            break;
        case 1:
            _hurtSnd.setBuffer(_bufHurt_02);
            break;
    }
    
}

void Game::changeHitBuffer() {
    _hitBufIndex++;
    
    if(_hitBufIndex > 2) {
        _hitBufIndex = 0;
    }
    
    switch (_hitBufIndex) {
        case 0:
            _hitSnd.setBuffer(_bufHit_01);
            break;
        case 1:
            _hitSnd.setBuffer(_bufHit_02);
            break;
        case 2:
            _hitSnd.setBuffer(_bufHit_03);
            break;
    }
}

void Game::playHitSnd() {
    if(_hitSnd.getStatus() == sf::Sound::Stopped) {
        changeHitBuffer();
        _hitSnd.play();
    }
}

bool Game::initMatch() {
    
    _goal1.setPosition(_window.getSize().x - 10, _window.getSize().y/2);
    _goal1.setColor(sf::Color(255,0,0));
    
    _goal2.setPosition(10, _window.getSize().y/2);
    _goal2.setColor(sf::Color(0,0,255));
    
    _p1.setPosition(_window.getSize().x - 100, _window.getSize().y / 2);
    _p1.setFillColor(sf::Color(255,0,0));
    _p1.setOutlineColor(sf::Color(0,0,255));
    
    _p2.setPosition(100,_window.getSize().y / 2);
    _p2.setFillColor(sf::Color(0,0,255));
    _p2.setOutlineColor(sf::Color(255,0,0));
    
    _ball.setPosition(_window.getSize().x/2, _window.getSize().y/2);
    
    _p1.setQueue(_window.getSize().x/2, _window.getSize().y/2);
    _p2.setQueue(_window.getSize().x/2, _window.getSize().y/2);
    
    
    _p1.setBoostValue(100);
    _p2.setBoostValue(100);
    
    _ball.setVelocity(0, 0);
    
    return true;
}

bool Game::run()  {
    _pause = false;
    _running = true;
    
    _backMus_01.play();
    
    _backMus_01.setLoop(true);
    
    for(int i = 0; i < _lifeGoal1.size(); i++) {
        _lifeGoal1[i].setSize(sf::Vector2f(10,30));
        _lifeGoal1[i].setPosition(_window.getSize().x - 210 + i*20, _window.getSize().y - 40);
        _lifeGoal1[i].setFillColor(sf::Color(255,0,0,155));
    }
    
    for(int i = 0; i < _lifeGoal2.size(); i++) {
        _lifeGoal2[i].setSize(sf::Vector2f(10,30));
        _lifeGoal2[i].setPosition(10 + i*20, _window.getSize().y - 40);
        _lifeGoal2[i].setFillColor(sf::Color(0,0,255,155));
    }
    
    while(_running) {
        
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                _backMus_01.stop();
                return false;
            }
        }
        
        if(!_pause) {
            _p1.setVelocity(0, 0);
            _p2.setVelocity(0, 0);
            
            this->manageInputs();
            this->physicUpdate();
        }
    
        _boostBar1.setSize(sf::Vector2f(_p1.boostValue() * 4, 50));
        _boostBar2.setSize(sf::Vector2f(_p2.boostValue() * 4, 50));
        
        this->renderAll();
    }
    
    _backMus_01.stop();
    
    return true;
}

void Game::manageInputs() {
    // Player 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _p1.setVelocity(_p1.velocity().x, -1);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _p1.setVelocity(-1, _p1.velocity().y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _p1.setVelocity(1, _p1.velocity().y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _p1.setVelocity(_p1.velocity().x, 1);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _p1.boost();
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false) {
        _p1.chargeBoost();
    }
    
    if(_nbPlayer == 2) {
        // Player 2
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            _p2.setVelocity(_p2.velocity().x, -1);
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            _p2.setVelocity(-1, _p2.velocity().y);
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            _p2.setVelocity(1, _p2.velocity().y);
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            _p2.setVelocity(_p2.velocity().x, 1);
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            _p2.boost();
            
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == false) {
            _p2.chargeBoost();
        }
        
    } else { // Sinon, c'est une ia
        
        if(_iaUpdateClock.getElapsedTime().asSeconds() >= 0.25f) {
            sf::Vector2f dep = _ball.extrapolatedPosition() - _p2.position();
            float dist = distance(_p2.position().x, _p2.position().y, _ball.extrapolatedPosition().x, _ball.extrapolatedPosition().y);
        
            dep/=dist;
        
            _p2.setVelocity(dep);
            _iaUpdateClock.restart();
            _oldDep = dep;
            
        } else {
            _p2.setVelocity(_oldDep);
        }
        
        sf::Vector2f p1_ball, p2_ball;
        
        p1_ball = _ball.position() - _p1.position();
        
        p2_ball = _ball.position() - _p2.position();
        
        if(vectDotProduct(_goal2.position() - _ball.position(), _ball.velocity()) > 0
           && _ball.position().x - 30 < _p2.position().x && _ball.position().x >= 50 && vectLength(_ball.velocity()) != 0) {
            _p2.setVelocity(vectNormalize(_goal2.position() - _p2.position()));
        } else if(_ball.position().x < 50) {
            _p2.setVelocity(_oldDep);
        }
        // ==========================================
        
        if(_p2.boostValue() > 0 && _boostP2 && distance(_p2.position(), _ball.position()) > 100)
            _p2.boost();
        else 
            _p2.chargeBoost();
        
        if(_p2.boostValue() <= 0 && _boostP2) {
            _boostP2 = false;
        }
        
        if(_boostP2 == false && _p2.boostValue() == 100) {
            _boostP2 = true;
        }
    }
}

void Game::physicUpdate() {
    if(collisionContour(_p1.extrapolatedPosition(), _p1.radius(), _window.getSize().x, _window.getSize().y)) {
        _p1.setVelocity(0, 0);
    }
    
    if(collisionContour(_p2.extrapolatedPosition(), _p2.radius(), _window.getSize().x, _window.getSize().y)) {
        _p2.setVelocity(0, 0);
    }
    
    _p1.updatePosition();
    _p2.updatePosition();
    
    sf::Vector2f normal(0,0);
    
    if(collisionCercles(_ball.extrapolatedPosition(), _ball.radius(), _p1.position(), 25, normal)) {
        
        _ball.setSpeed(_ball.speed() + _p1.actualSpeed());
        _ball.setVelocity(normal);
        
        playHitSnd();
        
    } else if(collisionCercles(_ball.extrapolatedPosition(), _ball.radius(), _p2.position(), _p2.radius(), normal)) {
        _ball.setSpeed(_ball.speed() + _p2.actualSpeed());
        _ball.setVelocity(normal);
        
        playHitSnd();
    }
    
    if(collisionHautBas(_ball.extrapolatedPosition(), _ball.radius(), _window.getSize().y)) {
        _ball.setVelocity(_ball.velocity().x, _ball.velocity().y * -1);
        
        playHitSnd();
    }
    
    if(collisionGaucheDroit(_ball.extrapolatedPosition(), _ball.radius(), _window.getSize().x)) {
        _ball.setVelocity(_ball.velocity().x * -1, _ball.velocity().y * 1);
        
        playHitSnd();
    }
    
    if(collisionBallGoal(_ball, _goal1)) {
        _ball.setSpeed(5);
        _ball.setVelocity(-1, _ball.velocity().y * 1);
        
        _goal1.setLife(_goal1.life() - 1);
        _goal1.setLength(30 * _goal1.life());
        
        _lifeGoal1[_goal1.life()].setFillColor(sf::Color(0,0,0,0));
        
        changeHurtBuffer();
        _hurtSnd.play();
        
        this->initMatch();
        
        _ball.setPosition(_window.getSize().x - 200, _window.getSize().y/2);
    }
    
    if(collisionBallGoal(_ball, _goal2)) {
        _ball.setSpeed(5);
        _ball.setVelocity(1, _ball.velocity().y * 1);
        
        _goal2.setLife(_goal2.life() - 1);
        _goal2.setLength(30 * _goal2.life());
        
        _lifeGoal2[_goal2.life()].setFillColor(sf::Color(0,0,0,0));
        
        changeHurtBuffer();
        _hurtSnd.play();
        
        this->initMatch();
        
        _ball.setPosition(200, _window.getSize().y/2);
    }
    
    if(_ball.speed() > 15) {
        _ball.setSpeed(15);
    }
    
    _ball.updatePosition();
    _ball.setSpeed(_ball.speed() - 0.1f);
    
    if(_ball.speed() < 0)
        _ball.setSpeed(0);
}

void Game::renderAll() {
    _window.clear();
    
    _goal1.render(_window);
    _goal2.render(_window);
    
    _p1.render(_window);
    _p2.render(_window);
    
    _ball.render(_window);
    
    _window.draw(_boostBar1);
    _window.draw(_boostBar2);
    
    for(int i = 0; i < _lifeGoal1.size(); i++) {
        _window.draw(_lifeGoal1[i]);
        _window.draw(_lifeGoal2[i]);
    }
    
    _window.display();
}

void Game::exit() {
    _window.close();
}