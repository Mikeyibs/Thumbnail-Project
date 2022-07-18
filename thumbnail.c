#include <stdlib.h>
#include <stdio.h>

int main()
{
   int width, height, max, pixels, resized;
   int width2, height2;
   int ch, i, n, div, count, index;
   char *img, *thumbnail;

   scanf("P5 %d %d %d", &width, &height, &max);

   div = width/600; // TA mentioned that the scaling would be better set to 600 pixels, which ended up working better for the eniac example.
   width2 = width/div;
   height2 = height/div;

   pixels = height * width;
   resized = height2 * width2;

   img = (char*) malloc(pixels * sizeof(char));
   thumbnail = (char*) malloc(resized * sizeof(char));

   if(img == NULL || thumbnail == NULL)
   {
      return 0;
   }

   char buff[width];

   while((ch = getchar()) != EOF && n < pixels)
   {
      *(img + n) = ch;
      n++;
   }

   fprintf(stdout, "P5\n%d %d\n%d\n", width2, height2, max);

   for(i = 0; i < n; i++)
   {
      count++;
      if(count == div)
      {
         *(thumbnail + index) = *(img + i);
         index++;
         count =0;
      }
   }

   for(i = 0; i < index; i++)
   {
      putchar(*(thumbnail + i));
   }

   return 0;
}
