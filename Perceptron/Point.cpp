#include "Point.h"

Point::Point(double coefficientX, double coefficientY, double coefficientB)
{
   RandomGenerator& randomGenerator = RandomGenerator::getInstance();
   this->x = randomGenerator.getInteger(0, RANGE) - RANGE;
   this->y = randomGenerator.getInteger(0, RANGE) - RANGE;

   double a = coefficientX * x + coefficientY * y + coefficientB;

   if (a >= 0.0)
   {
      this->t = 1;
   }
   else
   {
      this->t = 0;
   }
}