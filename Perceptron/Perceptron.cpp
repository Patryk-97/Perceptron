#include <iostream>
#include <vector>
#include "Point.h"
#include "RandomGenerator.h"

#define WX 0.5
#define WY 0.5
#define WB 0.0

#define LEARNING_SIZE 80
#define TEST_SIZE 20
#define EPOCHS 10

int main()
{
   //PRZYGOTOWANIE ZBIOROW
   std::vector<Point> learningData(LEARNING_SIZE);
   std::vector<Point> testData(TEST_SIZE);

   for (size_t i = 0; i < LEARNING_SIZE; i++)
   {
      learningData[i] = Point(WX, WY, WB);
   }

   for (size_t i = 0; i < TEST_SIZE; i++)
   {
      testData[i] = Point(WX, WY, WB);
   }

   //LOSOWANIE WSPOLCZYNNIKOW
   RandomGenerator& randomGenerator = RandomGenerator::getInstance();
   double paramWX = randomGenerator.getDouble(0.0, 1.0);
   double paramWY = randomGenerator.getDouble(0.0, 1.0);
   double paramWB = randomGenerator.getDouble(0.0, 1.0);

   double learningFactor = 0.6;

   std::cout << paramWX << " " << paramWY << " " << paramWB << "\n";

   for (size_t i = 0; i < testData.size(); i++)
   {
      std::cout << "X: " << testData[i].getX() << ", Y: " << testData[i].getY() << "\n";
   }

   //EPOKI
   for (int i = 0; i < EPOCHS; i++) {

      int errorsCounter = 0;

      //TESTOWANIE
      for (size_t j = 0; j < testData.size(); j++) {

         Point p = testData[j];
         int y;

         double sum = paramWX * p.getX() + paramWY * p.getY() + paramWB;

         if (sum >= 0) {
            y = 1;
         }
         else {
            y = 0;
         }

         int e = p.getT() - y;

         if (e != 0) {
            errorsCounter++;
         }
      }

      std::cout << "Errors: " << errorsCounter << "\n";

      //UCZENIE
      for (size_t j = 0; j < learningData.size(); j++) {

         Point p = learningData[j];
         int t = p.getT();
         int y;

         double sum = paramWX * p.getX() + paramWY * p.getY() + paramWB;

         if (sum >= 0) {
            y = 1;
         }
         else {
            y = 0;
         }

         int e = t - y;

         if (e != 0) {
            paramWX = paramWX + e * p.getX() * learningFactor;
            paramWY = paramWY + e * p.getY() * learningFactor;
            paramWB = paramWB + e * learningFactor;
         }
      }

      learningFactor /= 1.2;

   }

   std::cout << "Wx = " << paramWX << "\n";;
   std::cout << "Wy = " << paramWY << "\n";;
   std::cout << "Wb = " << paramWB << "\n";;
}