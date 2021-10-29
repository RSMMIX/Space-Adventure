#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<time.h>
#include<cmath>

using namespace std;
using namespace sf;


extern int currentScene;

inline float lenght(Vector2f vec)
{
    return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

inline Vector2f normalize(Vector2f vec)
{
    float len = sqrtf(vec.x * vec.x + vec.y * vec.y);
    if (len != 0)
        return vec / len;
    return vec;
}

#define PI 3.14159265
inline Vector2f rotateVector(Vector2f dir, float angle)
{
    if (dir == Vector2f(0, 0))
        return Vector2f(0, 0);
    float nx = dir.x * cos((angle)*PI / 180) - dir.y * sin((angle)*PI / 180);
    float ny = dir.x * sin((angle)*PI / 180) + dir.y * cos((angle)*PI / 180);
    return Vector2f(nx, ny);
}
