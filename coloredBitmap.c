#include <stdio.h>
#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' (bits), 'ko' (kilobits), 'mo' (megabits), 'go' (gigabits)
// Return value:
//   Colored image size Bitmap (based on the unit passed as parameter)
float coloredBitmap(int w, int h, char *unit)
{
   // Calculate the size of the bitmap in bits
   int bitsPerPixel = 24; // 24 bits per pixel for a colored image
   long long totalBits = (long long)w * h * bitsPerPixel;

   // Convert the total bits based on the unit provided
   if (strcmp(unit, "bt") == 0)
   {
      // Return size in bits
      return (float)totalBits;
   }
   else if (strcmp(unit, "ko") == 0)
   {
      // Return size in kilobits
      return totalBits / 1024;
   }
   else if (strcmp(unit, "mo") == 0)
   {
      // Return size in megabits
      return totalBits / (1024 * 1024);
   }
   else if (strcmp(unit, "go") == 0)
   {
      // Return size in gigabits
      return totalBits / (1024 * 1024 * 1024);
   }
   else
   {
      // Invalid unit, return 0
      return 0;
   }
}