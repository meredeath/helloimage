#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  //opening image file
  int f = open("tuhua.ppm", O_WRONLY | O_CREAT | O_TRUNC);

  //error handling
  if(f == -1){
    printf("Error. Opening file did not work\n");
    exit(0);
  }

  //write to image file header
  char buffer[1000];
  sprintf(buffer, "%s", "P3\n500 500\n255\n");
  write(f, buffer, strlen(buffer));
  
  //generate the image
  int rgb[3];
  for (int l = 0; l < 500; l++){ 
    for (int r = 0; r < 500; r++){
      rgb[0] = r % 255;      
      rgb[1] = 255;
      rgb[2] = r % 255;
    sprintf(buffer, "%d %d %d ", rgb[0], rgb[1], rgb[2]);
    write(f, buffer, strlen(buffer));
    }
  sprintf(buffer, "%s", "\n");
  write(f, buffer, strlen(buffer));
  }
  
  return 0;
}
