#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void clearCanvas() {
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            canvas[i][j]=' ';
}

void displayCanvas() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++)
            printf("%c",canvas[i][j]);
        printf("\n");
    }
}

void drawRectangle(int x,int y,int w,int h) {
    for(int i=y;i<y+h;i++) {
        for(int j=x;j<x+w;j++) {
            canvas[i][j]='*';
        }
    }
}

int main() {
    clearCanvas();

    drawRectangle(5,5,10,4);

    displayCanvas();

    return 0;
}