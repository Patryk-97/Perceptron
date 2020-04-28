#include <iostream>
#include <vector>
#include "Point.h"
#include "RandomGenerator.h"

#define BASIC_COEFFICIENT_X 1
#define BASIC_COEFFICIENT_Y -1
#define BASIC_COEFFICIENT_B 0

#define LEARNING_DATA_SIZE 80
#define TEST_DATA_SIZE 20
#define EPOCHS 10

int main()
{
   std::vector<Point> learningData(LEARNING_DATA_SIZE);
   std::vector<Point> testData(TEST_DATA_SIZE);
   std::vector<double> learningDataCorrectClassCoefficients(EPOCHS);
   std::vector<double> testDataCorrectClassCoefficients(EPOCHS);

   for (size_t i = 0; i < LEARNING_DATA_SIZE; i++)
   {
      learningData[i] = Point(BASIC_COEFFICIENT_X, BASIC_COEFFICIENT_Y, BASIC_COEFFICIENT_B);
   }

   for (size_t i = 0; i < TEST_DATA_SIZE; i++)
   {
      testData[i] = Point(BASIC_COEFFICIENT_X, BASIC_COEFFICIENT_Y, BASIC_COEFFICIENT_B);
   }

   RandomGenerator& randomGenerator = RandomGenerator::getInstance();
   double coefficientX = randomGenerator.getDouble(0.0, 1.0);
   double coefficientY = randomGenerator.getDouble(0.0, 1.0);
   double coefficientB = randomGenerator.getDouble(0.0, 1.0);

   double factor = 0.8;

   for (int i = 0; i < EPOCHS; i++)
   {
      
      int testDataCorrectClassCounter = 0;
      int learningDataCorrectClassCounter = 0;

      for (size_t j = 0; j < testData.size(); j++)
      {

         Point p = testData[j];
         int y;

         double sum = coefficientX * p.x + coefficientY * p.y + coefficientB;

         if (sum >= 0)
         {
            y = 1;
         }
         else 
         {
            y = 0;
         }

         int e = p.t - y;

         if (e == 0)
         {
            testDataCorrectClassCounter++;
         }
      }

      testDataCorrectClassCoefficients[i] = 100.0 * testDataCorrectClassCounter / TEST_DATA_SIZE;

      for (size_t j = 0; j < learningData.size(); j++) {

         Point p = learningData[j];
         int t = p.t;
         int y = 0;

         double sum = coefficientX * p.x + coefficientY * p.y + coefficientB;

         if (sum >= 0)
         {
            y = 1;
         }
         else
         {
            y = 0;
         }

         int e = t - y;

         if (e == 0)
         {
            learningDataCorrectClassCounter++;
         }
         else
         {
            coefficientX += e * p.x * factor;
            coefficientY += e * p.y * factor;
            coefficientB += e * factor;
         }
      }

      learningDataCorrectClassCoefficients[i] = 100.0 * learningDataCorrectClassCounter / LEARNING_DATA_SIZE;

      factor -= 0.05;

   }

   std::cout << "Test data correct class coefficients:\n";
   for (int i = 0; i < EPOCHS; i++)
   {
      std::cout << testDataCorrectClassCoefficients[i] << "\n";
   }

   std::cout << "\n\nLearning data correct class coefficients:\n";
   for (int i = 0; i < EPOCHS; i++)
   {
      std::cout << learningDataCorrectClassCoefficients[i] << "\n";
   }

   return 0;
}