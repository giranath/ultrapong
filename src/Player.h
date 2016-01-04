//
//  Player.h
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#ifndef __GameTest__Player__
#define __GameTest__Player__

#include "Entity.h"
#include <vector>

class Player : public Entity{
public:
    
    Player();
    ~Player();
    
    virtual void render(sf::RenderTarget &target);
    virtual void updatePosition();
    
    void boost();
    void chargeBoost();
    
    int boostValue() const {return _boost;}
    void setBoostValue(int v) {_boost = v;}
    
    void setQueue(float x, float y);
    
    void setSpring(float v) {_res = v;}
    
private:
    int _boost, _maxBoost;
    bool _boostActivated;
    sf::Clock _boostClock;
    std::vector<sf::CircleShape> _traine;
    float _res;
};

#endif /* defined(__GameTest__Player__) */
