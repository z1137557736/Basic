#include <cstdio>

void a() {
    for(int i = 0; i<10; i++) {
        printf("%d", i);
        if(i==5){
            break;
        }
    }
}

int main() {
    a();
    printf("after break or return");
    return 0;
}