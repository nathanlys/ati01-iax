#include <stdio.h>

int main(){
int c='3333';
char* tab;
tab=(char*)&c;
printf("%s\n",tab);

return 0;
}
