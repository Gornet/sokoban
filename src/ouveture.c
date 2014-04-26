#include <stdio.h>
#include <string.h>

main()
{
  FILE *fp;
  // char buff[255];
  char tab[255];
  int j;
  int k;

  int i = 0;
  int m =0;
  fp = fopen("level1.map", "r");
  if( fp != NULL )
  {
    while ( !feof(fp ) )
    {
      memset(tab, '\0', sizeof( tab) );
      fscanf("%d" , &j );
      fscanf("%d",&k);
        //fgets(buff, 255, (FILE*)fp);
    //    j = fgetc(fp);
      //  k = fgetc(fp);
      //  printf("%d",j);

       /* while(i < 255)
        {
          printf("%d",tab[i]);
          i++;
        }
          printf("%c", tab[6]);
         printf("%s",tab);*/
      fseek(fp, 2, SEEK_CUR);
      for(i = 0; i < j; i += 1)
      {
        for(j = 0; m < k; j += 1)
        {
          tab[i * j + m] = fgetc(fp);
        }
        fseek(fp, 2, SEEK_CUR);
      }
    }
  }
  fclose(fp);
}

