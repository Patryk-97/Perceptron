#pragma once

#ifndef __POINT_H__
#define __POINT_H__

#include "RandomGenerator.h"

class Point
{

public:

   Point() = default;

   Point(double coefficientX, double coefficientY, double coefficientB);

   static const int RANGE = 100;
   int x;
   int y;
   int t;
};

#endif