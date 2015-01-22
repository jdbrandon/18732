#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv){
   int i, j;
   size_t len;
   if(argc < 2){
      fprintf(stderr, "Usage: ascii2hex <string>\n");
      exit(1);
   }

   for(i = 1; i<argc; i++){
      len = strlen(argv[i]);
      for(j = 0; j<len; j++)
         printf("%02x ",argv[i][j]);
   }
   printf("\n");
   exit(0);
}
