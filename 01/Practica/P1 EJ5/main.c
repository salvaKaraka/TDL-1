#include <stdio.h>
int main(){

for (int i=0 ; i<=50 ; i++){

        if ((i % 5)==0){
            printf("a=%d\n",i);
        }
}

for (int i=0 ; i<=50 ; i+=5){

    printf("b=%d\n",i);

}

return 0;
}
