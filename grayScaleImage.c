#include <stdio.h>
#include "config/grayScaleImage.h"

// Function to calculate the size of a grayscale image in bytes
float grayScaleImage(int w, int h)
{
   // Validate input dimensions
   if (w <= 0 || h <= 0)
   {
      printf("Error: Width and Height must be positive integers.\n");
      return 0;
   }

   // Calculate the size in bytes
   float sizeInBytes = w * h * 1.0; // Each pixel = 1 byte

   return sizeInBytes;
}