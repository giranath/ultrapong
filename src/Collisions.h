//
//  Collisions.h
//  UltraPong
//
//  Created by Nathan on 2013-02-16.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#ifndef __UltraPong__Collisions__
#define __UltraPong__Collisions__

#include "Ball.h"
#include "Player.h"
#include "Goal.h"

bool collisionBallGoal(Ball ball, Goal goal);

bool collisionContour(sf::Vector2f position, float rayon, int w, int h);

bool collisionHautBas(sf::Vector2f position, float rayon, int h);

bool collisionGaucheDroit(sf::Vector2f position, float rayon, int w);

#endif /* defined(__UltraPong__Collisions__) */
