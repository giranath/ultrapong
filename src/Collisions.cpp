//
//  Collisions.cpp
//  UltraPong
//
//  Created by Nathan on 2013-02-16.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Collisions.h"

bool collisionContour(sf::Vector2f position, float rayon, int w, int h) {
    
    if(position.x + rayon >= w || position.x - rayon <= 0 ||
       position.y + rayon >= h || position.y - rayon <= 0)
        return true;
    
    return false;
}

bool collisionHautBas(sf::Vector2f position, float rayon, int h) {
    
    if(position.y + rayon >= h || position.y - rayon <= 0)
        return true;
    
    return false;
}

bool collisionGaucheDroit(sf::Vector2f position, float rayon, int w) {
    
    if(position.x + rayon >= w || position.x - rayon <= 0)
        return true;
    
    return false;
}


bool collisionBallGoal(Ball ball, Goal goal) {
    sf::IntRect rectBall;
    rectBall.left = ball.extrapolatedPosition().x - ball.radius();
    rectBall.top = ball.extrapolatedPosition().y - ball.radius();
    rectBall.width = 2 * ball.radius();
    rectBall.height = 2 * ball.radius();
    
    sf::IntRect rectGoal;
    rectGoal.left = goal.position().x;
    rectGoal.top = goal.position().y - goal.length()/2;
    rectGoal.width = 1;
    rectGoal.height = goal.length();
    
    if(rectBall.intersects(rectGoal))
        return true;
    
    return false;
}