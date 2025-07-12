#include <stdio.h>

struct point{
    int x; //x座標
    int y; //y座標
};

int main(void){
    struct point table[5][100];
    int top[5] = {0}; //top[0]-top[4]の5要素の配列を初期化する
    int x, y;
    int total = 0; //総入力数を判断
    while(total < 100 && scanf("%d %d", &x, &y) != EOF){
        struct point p = {x, y};
        if(x * y == 0){ //座標軸上の点
            table[0][top[0]] = p;
            top[0]++;         
        }
        else if(x > 0 && y > 0){ //第1象限
            table[1][top[1]] = p;
            top[1]++;
        }
        else if(x < 0 && y > 0){ //第2象限
            table[2][top[2]] = p;
            top[2]++;
        }
       else if(x < 0 && y < 0){ //第3象限
            table[3][top[3]] = p;
            top[3]++;
        }
       else if(x > 0 && y < 0){ //第4象限
            table[4][top[4]] = p;
            top[4]++;
        }
        total++;
    }
    printf("The number of I quadrant (RUQ) > %d\n", top[1]);
    for (int i = 0; i < top[1]; i++){
        printf("(%d, %d)\n", table[1][i].x, table[1][i].y);
    }
    printf("The number of II quadrant (LUQ) > %d\n", top[2]);
    for (int i = 0; i < top[2]; i++){
        printf("(%d, %d)\n", table[2][i].x, table[2][i].y);
    }
    printf("The number of III quadrant (LLQ) > %d\n", top[3]);
    for (int i = 0; i < top[3]; i++){
        printf("(%d, %d)\n", table[3][i].x, table[3][i].y);
    }
    printf("The number of IV quadrant (RLQ) > %d\n", top[4]);
    for (int i = 0; i < top[4]; i++){
        printf("(%d, %d)\n", table[4][i].x, table[4][i].y);
    }
}