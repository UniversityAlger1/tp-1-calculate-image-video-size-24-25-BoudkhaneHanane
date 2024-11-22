#include <string.h>
#include <stdio.h>
#include "config/video.h"

// Function to calculate video size
float video(int w, int h, int durationMovie, int durationCredits, int fps, const char *unit)
{
   // Validate inputs
   if (w <= 0)
   {
      printf("Invalid input: width must be positive.\n");
      return -1; // Error code
   }
   if (h <= 0)
   {
      printf("Invalid input: height must be positive.\n");
      return -1;
   }
   if (durationMovie < 0 || durationCredits < 0)
   {
      printf("Invalid input: durations cannot be negative.\n");
      return -1;
   }
   if (fps <= 0)
   {
      printf("Invalid input: FPS must be positive.\n");
      return -1;
   }

   // Frame sizes
   float coloredFrameSize = w * h * 3.0; // RGB frames
   float bwFrameSize = w * h * 1.0;      // Black-and-white frames

   // Total frames
   int movieFrames = durationMovie * fps;
   int creditsFrames = durationCredits * fps;

   // Total size in bytes
   float totalSizeBytes = (coloredFrameSize * movieFrames) + (bwFrameSize * creditsFrames);

   // Convert to the desired unit
   if (strcasecmp(unit, "bt") == 0)
   {
      return totalSizeBytes;
   }
   else if (strcasecmp(unit, "ko") == 0)
   {
      return totalSizeBytes / 1024.0;
   }
   else if (strcasecmp(unit, "mo") == 0)
   {
      return totalSizeBytes / (1024.0 * 1024.0);
   }
   else if (strcasecmp(unit, "go") == 0)
   {
      return totalSizeBytes / (1024.0 * 1024.0 * 1024.0);
   }
   else
   {
      return -1;
   }
}
