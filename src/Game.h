//
//  Game.h
//  UltraPong
//
//  Created by Nathan on 2013-02-16.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#ifndef __UltraPong__Game__
#define __UltraPong__Game__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"

#include <iostream>
#include <cmath>

#include "Utils.h"

#include "Player.h"
#include "Ball.h"
#include "Goal.h"

#include "Collisions.h"
#include "Randomizer.h"

class Game {
public:
    Game(sf::RenderWindow &window);
    ~Game();
    
    bool loadResources();
    bool initMatch();
    
    void setNBPlayer(int nb) {_nbPlayer = nb;};
    int nbPlayer() const {return _nbPlayer;}
    
    bool run();
    void exit();
    
private:
    bool _pause, _running;
    
    void changeHitBuffer();
    void changeHurtBuffer();
    
    void playHitSnd();
    
    void physicUpdate();
    void renderAll();
    
    void manageInputs();
    
    sf::SoundBuffer _bufHit_01, _bufHit_02, _bufHit_03, _bufHurt_01, _bufHurt_02, _bufBoostEmpty;
    sf::Music _backMus_01;
    
    sf::Sound _hitSnd, _hurtSnd, _beepSnd;
    
    sf::RenderWindow &_window;
    
    Player _p1, _p2;
    Goal _goal1, _goal2;
    Ball _ball;
    
    int _hitBufIndex, _hurtBufIndex;
    
    sf::RectangleShape _boostBar1, _boostBar2;
    
    std::vector<sf::RectangleShape> _lifeGoal1, _lifeGoal2;
    int _nbPlayer;
    
    // IA variables
    bool _boostP2;
    sf::Clock _iaUpdateClock;
    sf::Vector2f _oldDep;
};

#endif /* defined(__UltraPong__Game__) */
