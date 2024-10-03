# include "iGraphics.h"
# include "gl.h"
#include<math.h>


double ball_x,dx,ball_y, ball_y1,ball_y2,ball_y3;
double amp=1.7,freq=.92;
bool home=0,show=1,b1=1,b2=1,b3=1,b=1;

void iDraw()
{
    iClear();
    if(home==0)
    {
        iShowBMP(180, 40, "help.bmp");
        iSetColor(0, 0, 0);
        iText(500, 600, "Toggle Help/Main Page : F1");
        iText(500, 560, "Toggle curve show/hide : s/S");
        iText(500, 520, "Toggle tracer show/hide : <curve_No>");
        iText(500, 480, "Pause animation : p/P");
        iText(500, 440, "Resume animation : r/R");
        iText(500, 400, "Increase Amplitude : a");
        iText(500, 360, "Decrease  Amplitude : A");
        iText(500, 320, "Increase Frequency : f");
        iText(500, 280, "Decrease Frequency : F");
        iText(500, 240, "Increase Speed : +");
        iText(500, 200, "Decrease Speed : -");
        iText(500, 160, "Exit : END");

    }

    else if(home==1)
    {
        if(show==1)
        {
            iSetColor(255, 255, 255);
            iLine(0, 350, 1360, 350);
            for(double i=0; i<1360; i+=2)
            {
                double j1=amp*65*sin(90+(.01*i*freq))+350;
                double j2=amp*73*sin(.02*i*freq)+350;
                double j3=amp*82*sin(.03*i*freq)+350;
                double j=j1+j2+j3-700;
                iPoint(i, j1, 0);
                iPoint(i, j2, 0);
                iPoint(i, j3, 0);
                iPoint(i, j, 0);
            }
        }
if(b1==1)
        {iSetColor(255,0,0);
        iFilledCircle(ball_x, ball_y1, 4);}
if(b2==1)
       {iSetColor(0,255,0);
        iFilledCircle(ball_x, ball_y2, 4);}
if(b3==1)
        {iSetColor(0,0,255);
        iFilledCircle(ball_x, ball_y3, 4);}
if(b==1)
        {iSetColor(255, 255, 0);
        iFilledCircle(ball_x, ball_y, 4);}

        iSetColor(255, 255, 255);
        iText(10, 10, "Press P/p for pause,R/r for resume,End for exit");
    }

}


void iMouseMove(int mx, int my)
{
}
void iMouse(int button, int state, int mx, int my)
{
}
void iKeyboard(unsigned char key)
{
    if(key == 'p' || key=='P')
        iPauseTimer(0);
    if(key == 'r' || key=='R')
        iResumeTimer(0);
    if(key=='s'|| key=='S')
    {
        if(show==0)
            show=1;
        else
            show =0;
    }
    if(key == 'a')
        amp+=.03;
    if(key == 'A')
        amp-=.03;
    if(key == 'f')
        freq+=.1;
    if(key == 'F')
        freq-=.1;
     if(key == '+')
        dx*=2.0;
    if(key == '-')
        dx/=2.0;

    if(key == '1')
    {
        if(b1==0)
            b1=1;
        else
            b1 =0;
    }
    if(key == '2')
    {
        if(b2==0)
            b2=1;
        else
            b2=0;
    }
    if(key == '3')
    {
        if(b3==0)
            b3=1;
        else
            b3=0;
    }
    if(key == '4')
    {
        if(b==0)
            b=1;
        else
            b=0;
    }

}
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_F1)
    {
        if(home==0)
        {
            home=1;
            iResumeTimer(0);
        }
        else
        {
            home =0;
            iPauseTimer(0);
        }
    }
}


void ballChange()
{
    ball_x += dx;
    if(ball_x >=1360 || ball_x <= 0)
        dx = -dx;
    ball_y1=amp*65*sin(90+(.01*ball_x*freq))+350;
    ball_y2=amp*73*sin(.02*ball_x*freq)+350;
    ball_y3=amp*82*sin(.03*ball_x*freq)+350;
    ball_y=ball_y1+ball_y2+ball_y3-700;
}


int main()
{
    iSetTimer(20, ballChange);
    iPauseTimer(0);
    dx=4;
    iInitialize(1360, 750, "MyProject-1905056");
    return 0;
}
