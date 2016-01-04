//
//  Utils.cpp
//  GameTest
//
//  Created by Nathan on 2013-02-15.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Utils.h"

float distance(float x1, float y1, float x2, float y2) {
    return (float)(sqrt(pow((x2 - x1),2) + pow((y2 - y1),2)));
}

float distance(sf::Vector2f v1, sf::Vector2f v2) {
    return distance(v1.x, v1.y, v2.x, v2.y);
}

float vectLength(sf::Vector2f v) {
    return distance(sf::Vector2f(0,0), v);
}

bool collisionCercles(sf::Vector2f centre1, float rayon1, sf::Vector2f centre2, float rayon2, sf::Vector2f &normal) {
    float dist = distance(centre1.x, centre1.y, centre2.x, centre2.y);
    
    sf::Vector2f p = centre1 - centre2;
    
    if(dist <= rayon1 + rayon2) {
        normal = p;
        
        normal.x /= dist;
        normal.y /= dist;
        
        if(p.y == 0) {
            normal.y = 0;
        }
        
        if(p.x == 0) {
            normal.x = 0;
        }
        
        return true;
    }
    
    return false;
}

float vectDotProduct(sf::Vector2f vect1, sf::Vector2f vect2) {
    return (vect1.x * vect2.x) + (vect1.y * vect2.y);
}

sf::Vector2f vectNormalize(sf::Vector2f vect) {
    float dist = vectLength(vect);
    return vect/dist;
}

sf::Vector2f vectCrossProduct(sf::Vector2f vect) {
    return sf::Vector2f(-vect.y, vect.x);
}