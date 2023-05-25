#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
  #include<windows.h>
#endif


int main()
{

    printf("Hello world!\n");
while(1){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif

    printf("Hello world!\n");

}
    return 0;
}
