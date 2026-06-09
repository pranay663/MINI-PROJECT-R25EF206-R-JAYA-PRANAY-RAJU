#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void clearCanvas()
{
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            canvas[i][j]=' ';
}

void displayCanvas()
{
    printf("\n");
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
            printf("%c",canvas[i][j]);
        printf("\n");
    }
}

void drawRectangle(int x,int y,int w,int h)
{
    for(int i=y;i<y+h && i<ROWS;i++)
    {
        for(int j=x;j<x+w && j<COLS;j++)
        {
            canvas[i][j]='*';
        }
    }
}

void drawLine(int x1,int y1,int x2,int y2)
{
    if(y1==y2)
    {
        for(int x=x1;x<=x2 && x<COLS;x++)
            canvas[y1][x]='*';
    }
    else if(x1==x2)
    {
        for(int y=y1;y<=y2 && y<ROWS;y++)
            canvas[y][x1]='*';
    }
}

void drawTriangle(int x,int y,int h)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(y+i<ROWS && x+j<COLS)
                canvas[y+i][x+j]='*';
        }
    }
}

void drawCircle(int cx,int cy,int r)
{
    for(int y=0;y<ROWS;y++)
    {
        for(int x=0;x<COLS;x++)
        {
            int dx=x-cx;
            int dy=y-cy;

            if(dx*dx + dy*dy <= r*r)
                canvas[y][x]='*';
        }
    }
}

void deleteArea(int x,int y,int w,int h)
{
    for(int i=y;i<y+h && i<ROWS;i++)
    {
        for(int j=x;j<x+w && j<COLS;j++)
        {
            canvas[i][j]=' ';
        }
    }
}

int main()
{
    int choice;

    clearCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Canvas\n");
        printf("7. Clear Canvas\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,w,h;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);
                drawRectangle(x,y,w,h);
                break;
            }

            case 2:
            {
                int x1,y1,x2,y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                drawLine(x1,y1,x2,y2);
                break;
            }

            case 3:
            {
                int x,y,h;
                printf("Enter x y height: ");
                scanf("%d%d%d",&x,&y,&h);
                drawTriangle(x,y,h);
                break;
            }

            case 4:
            {
                int x,y,r;
                printf("Enter centerX centerY radius: ");
                scanf("%d%d%d",&x,&y,&r);
                drawCircle(x,y,r);
                break;
            }

            case 5:
            {
                int x,y,w,h;
                printf("Enter x y width height to delete: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);
                deleteArea(x,y,w,h);
                break;
            }

            case 6:
            {
                displayCanvas();
                break;
            }

            case 7:
            {
                clearCanvas();
                printf("Canvas Cleared!\n");
                break;
            }

            case 8:
            {
                printf("Exiting...\n");
                return 0;
            }

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}