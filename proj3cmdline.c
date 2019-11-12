#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char title[40];
  char *from_text;
  int port, i=0, let_count=0;

  if(argc == 3){
    puts("both");
    strcpy(title, argv[1]);
    while(!(title[1]=='\0')) //loop through each char
    {
      if(! (isdigit( title[i])))
      {
        let_count++;
      }
      i++;
    }

    if(let_count==0)
    {
      puts("this is a port");
      port=atoi(title);
      printf("The port number is: %d\n", port);
    }
    else
    {
      puts("this is a dictionary");
    }
  }else if(argc ==2){
    puts("one more");
  }else if(argc==1)
  {
    puts("none");
  }else{
    puts("way more");
  }
  return 0;
}