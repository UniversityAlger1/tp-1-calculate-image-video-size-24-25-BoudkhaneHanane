#include <stdio.h>
#include <string.h>
#include "config/video.h"

// Function to calculate the size of a video in the desired unit
float video(int w, int h, int durationMovie, int durationCredits, int fps, char *unit)
{
   // Validate input dimensions and parameters
   if (w <= 0 || h <= 0 || durationMovie < 0 || durationCredits < 0 || fps <= 0)
   {
      printf("Error: Invalid parameters.\n");
      return 0;
   }

   // Frame sizes
   float coloredFrameSize = w * h * 3.0; // Each pixel = 3 bytes for RGB
   float bwFrameSize = w * h * 1.0;      // Each pixel = 1 byte for grayscale

   // Total frames for movie and credits
   int totalMovieFrames = durationMovie * fps;
   int totalCreditsFrames = durationCredits * fps;

   // Total size in bytes
   float totalSizeBytes = (coloredFrameSize * totalMovieFrames) + (bwFrameSize * totalCreditsFrames);

   // Convert to the desired unit
   if (strcmp(unit, "bt") == 0)
   {
      return totalSizeBytes;
   }
   else if (strcmp(unit, "ko") == 0)
   {
      return totalSizeBytes / 1024.0;
   }
   else if (strcmp(unit, "mo") == 0)
   {
      return totalSizeBytes / (1024.0 * 1024.0);
   }
   else if (strcmp(unit, "go") == 0)
   {
      return totalSizeBytes / (1024.0 * 1024.0 * 1024.0);
   }
   else
   {
      return 0;
   }
}
