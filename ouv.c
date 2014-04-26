#include <stdio.h>
#include <string.h>

void recup_fichier("fichier")
{
   FILE *fp;
   char buff[255];

   fp = fopen("fichier", "r");
   if( fp != NULL ){
      while ( !feof(fp ) ){
         memset(buff, '\0', sizeof( buff) );
         fgets(buff, 255, (FILE*)fp);
         printf("%s", buff );
      }
      fclose(fp);
   }
}
