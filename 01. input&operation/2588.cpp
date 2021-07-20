#include <stdio.h>
int main(){
    int x,y;
    int fir,sec,thi;

    scanf("%d",&x);
    scanf("%d",&y);
    
    fir = y / 100;
    sec = (y / 10) % 10;
    thi = y % 10;
    
    printf("%d\n", x*thi);
    printf("%d\n", x*sec);
    printf("%d\n", x*fir);
    printf("%d", x*y);

    return 0;
}