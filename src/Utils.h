//
//  Utils.h
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#ifndef __GameTest__Utils__
#define __GameTest__Utils__

#include <iostream>
#include <cmath>
#include <SFML/System.hpp>

float distance(float x1, float y1, float x2, float y2);
float distance(sf::Vector2f v1, sf::Vector2f v2);

float vectLength(sf::Vector2f v);

bool collisionCercles(sf::Vector2f centre1, float rayon1, sf::Vector2f centre2, float rayon2, sf::Vector2f &normal);

float vectDotProduct(sf::Vector2f vect1, sf::Vector2f vect2);
sf::Vector2f vectNormalize(sf::Vector2f vect);
sf::Vector2f vectCrossProduct(sf::Vector2f vect);

#endif /* defined(__GameTest__Utils__) */
