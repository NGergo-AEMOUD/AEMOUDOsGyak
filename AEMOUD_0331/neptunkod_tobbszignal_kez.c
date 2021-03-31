#include <stdio.h>
#include <signal.h>
#include <unistd.h>

 void signalHandler(int num);
 int y = 0;
    int main(void){

        void(*SInterupt)(int);
        void(*SQuit)(int);
        void(*SReturn)(int);
        SInterupt=signalHandler;
        SQuit =signalHandler;
        SReturn = signal(SIGINT, SQuit);
    if(SReturn == SIG_ERR){
        printf("HIBA");
        return 1;
    }
    SReturn=signal(SIGQUIT,SQuit);
    if(SReturn == SIG_ERR){
        printf("HIBA");
        return 1;
    }
    while(1){
        if(y==2){
            break;
        }else if(y==0){
            printf("Kilépés:\n");
            printf("1)Terminál megnyitása\n");
            if(y==0){
                printf("2) kill %d parancs kiadása(Windows esetén Ctrl + 4) vagy Ctrl + C (2x)\n", getpid());
            }else if(y==1){
                printf("2) Ctrl + C \n");
            }
            sleep(10);
        }
    }
    return 0;
  }



 void signalHandler(int num){
    switch(num){
    case SIGINT:
        printf("\nCtrl+c = visszatérés\n");
        signal(SIGINT, SIG_DFL);
        y=1;
        break;
    case SIGQUIT:
        printf("\nKilépés folyamatban...");
        y=2;
        break;
    default:
        printf("Fogadott jelek száma: %d", num);
        break;

    }

 }

