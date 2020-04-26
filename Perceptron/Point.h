#pragma once

#ifndef __POINT_H__
#define __POINT_H__

#include "RandomGenerator.h"

class Point
{

public:

   Point() = default;

   Point(double wx, double wy, double wb)
   {
      RandomGenerator& randomGenerator = RandomGenerator::getInstance();
      x = randomGenerator.getInteger(0, SIZE) - SIZE / 2;
      y = randomGenerator.getInteger(0, SIZE) - SIZE / 2;

      double sum = (double)(x)*wx + (double)(y)*wy + wb;
      if (sum >= 0.0) {
         t = 1;
      }
      else {
         t = 0;
      }
   }

   double getX() {
      return (double)x;
   }

   double getY() {
      return (double)y;
   }

   int getT() {
      return t;
   }

private:

   static const int SIZE = 10;
   int x;
   int y;
   int t;
};

#endif