#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>

/* Function to calculate orbit positions */
void planetMotion(int xrad, int yrad, int midx, int midy, int x[70], int y[70])
{
    int i, j = 0;
    for (i = 360; i > 0; i -= 6) {
        x[j] = midx + (int)(xrad * cos(i * 3.14159 / 180));
        y[j++] = midy + (int)(yrad * sin(i * 3.14159 / 180));
    }
}

/* Function to draw background stars */
void drawStars(int count)
{
    int i, x, y;
    for (i = 0; i < count; i++) {
        x = rand() % getmaxx();
        y = rand() % getmaxy();
        putpixel(x, y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    int midx, midy;
    int xrad[9], yrad[9];
    int x[9][70], y[9][70];
    int planet[9], pos[9];
    int speed[9] = {4, 3, 3, 2, 2, 1, 1, 1, 1};
    int i;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    /* Planet sizes */
    planet[0] = 4;
    for (i = 1; i < 9; i++)
        planet[i] = planet[i - 1] + 1;

    /* Initial positions */
    for (i = 0; i < 9; i++)
        pos[i] = i * 6;

    /* Orbit radii */
    xrad[0] = 60;  yrad[0] = 40;
    for (i = 1; i < 9; i++) {
        xrad[i] = xrad[i - 1] + 35;
        yrad[i] = yrad[i - 1] + 20;
    }

    /* Pre-calculate orbits */
    for (i = 0; i < 9; i++)
        planetMotion(xrad[i], yrad[i], midx, midy, x[i], y[i]);

    while (!kbhit())
    {
        cleardevice();

        /* Background stars */
        drawStars(120);

        /* Title */
        setcolor(WHITE);
        outtextxy(midx - 100, 20, "SOLAR SYSTEM SIMULATION");

        /* Orbits */
        for (i = 0; i < 9; i++) {
            setcolor(CYAN);
            ellipse(midx, midy, 0, 360, xrad[i], yrad[i]);
        }

        /* Sun */
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(midx, midy, 25);
        floodfill(midx, midy, YELLOW);
        setcolor(WHITE);
        outtextxy(midx - 10, midy + 30, "SUN");

        /* Mercury */
        setcolor(CYAN);
        setfillstyle(SOLID_FILL, CYAN);
        pieslice(x[0][pos[0]], y[0][pos[0]], 0, 360, planet[0]);
        outtextxy(x[0][pos[0]] + 8, y[0][pos[0]] + 8, "Mercury");

        /* Venus */
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        pieslice(x[1][pos[1]], y[1][pos[1]], 0, 360, planet[1]);
        outtextxy(x[1][pos[1]] + 8, y[1][pos[1]] + 8, "Venus");

        /* Earth */
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        pieslice(x[2][pos[2]], y[2][pos[2]], 0, 360, planet[2]);
        outtextxy(x[2][pos[2]] + 8, y[2][pos[2]] + 8, "Earth");

        /* Mars */
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        pieslice(x[3][pos[3]], y[3][pos[3]], 0, 360, planet[3]);
        outtextxy(x[3][pos[3]] + 8, y[3][pos[3]] + 8, "Mars");

        /* Jupiter */
        setcolor(BROWN);
        setfillstyle(SOLID_FILL, BROWN);
        pieslice(x[4][pos[4]], y[4][pos[4]], 0, 360, planet[4]);
        outtextxy(x[4][pos[4]] + 8, y[4][pos[4]] + 8, "Jupiter");

        /* Saturn */
        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        pieslice(x[5][pos[5]], y[5][pos[5]], 0, 360, planet[5]);
        outtextxy(x[5][pos[5]] + 8, y[5][pos[5]] + 8, "Saturn");

        setcolor(WHITE);
        ellipse(x[5][pos[5]], y[5][pos[5]], 0, 360,
                planet[5] + 8, planet[5] + 3);
        ellipse(x[5][pos[5]], y[5][pos[5]], 0, 360,
                planet[5] + 10, planet[5] + 4);

        /* Uranus */
        setcolor(LIGHTGREEN);
        setfillstyle(SOLID_FILL, LIGHTGREEN);
        pieslice(x[6][pos[6]], y[6][pos[6]], 0, 360, planet[6]);
        outtextxy(x[6][pos[6]] + 8, y[6][pos[6]] + 8, "Uranus");

        /* Neptune */
        setcolor(LIGHTBLUE);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        pieslice(x[7][pos[7]], y[7][pos[7]], 0, 360, planet[7]);
        outtextxy(x[7][pos[7]] + 8, y[7][pos[7]] + 8, "Neptune");

        /* Pluto */
        setcolor(LIGHTRED);
        setfillstyle(SOLID_FILL, LIGHTRED);
        pieslice(x[8][pos[8]], y[8][pos[8]], 0, 360, planet[8]);
        outtextxy(x[8][pos[8]] + 8, y[8][pos[8]] + 8, "Pluto");

        /* Revolution update */
        for (i = 0; i < 9; i++) {
            pos[i] -= speed[i];
            if (pos[i] < 0)
                pos[i] = 59;
        }

        delay(100);
    }

    closegraph();
    return 0;
}
