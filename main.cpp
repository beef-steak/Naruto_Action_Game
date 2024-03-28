#include<windows.h>
#include"iGraphics.h"
#include"bar.h"
#include"bullet.h"


/*.............................................PREPROSESSORS......................................*/

#define HOME 0
#define PLAY 1
#define LEFT 2
#define RIGHT 1
#define OFF 3
#define ON 4
#define NULL 0
#define TRUE 1
#define SHOW 5
#define END 0



/*..............................................VARIABLE DECLARATION..............................*/







int i=1,j=0;
int enemy_mode_l=LEFT, enemy_mode_r=RIGHT;
int level=1;

int temp_sc, num_position, position;
int blast=0,blast_position_l,blast_position_r;
int level_count=NULL;





int musicMode=ON;
int homeMode= NULL;

int musicCount=NULL;
int instructionCount=NULL;
int highScoreCount=NULL;
int exitCount=NULL;
int exitMode=OFF;
int highScoreMode=OFF;
int instructionMode=OFF,instructionMode_1=OFF;







char naruto_run_R[6][30]= {"image//right//naruto_run1.bmp","image//right//naruto_run2.bmp","image//right//naruto_run3.bmp","image//right//naruto_run4.bmp","image//right//naruto_run5.bmp","image//right//naruto_run6.bmp"};
char naruto_run_L[6][30]= {"image//left//naruto_run1.bmp","image//left//naruto_run2.bmp","image//left//naruto_run3.bmp","image//left//naruto_run4.bmp","image//left//naruto_run5.bmp","image//left//naruto_run6.bmp"};



char life_pic[9][30] = {"image//life//life0.bmp","image//life//life1.bmp","image//life//life2.bmp","image//life//life3.bmp","image//life//life4.bmp","image//life//life5.bmp","image//life//life6.bmp","image//life//life7.bmp","image//life//life8.bmp"};
char level_pic[10][30]= {"image//0.bmp","image//1.bmp","image//2.bmp","image//3.bmp","image//4.bmp","image//5.bmp","image//6.bmp","image//7.bmp","image//8.bmp","image//9.bmp"};
char score_pic[10][30]= {"image//0.bmp","image//1.bmp","image//2.bmp","image//3.bmp","image//4.bmp","image//5.bmp","image//6.bmp","image//7.bmp","image//8.bmp","image//9.bmp"};



int naruto_side_speed;

int enemy_l_x=0,enemy_l_y=50,enemy_r_x=1000,enemy_r_y=50;




/*...............................................DRAWING ON SCREEN........................*/


void iDraw()
{
    iClear();

    if(gameMode==PLAY)
    {

//............................................SHOWING LIFE AND SCORE PIC....

        iShowBMP(0,550,life_pic[life]);
        iShowBMP(560,550,"image//sc.bmp");
        iShowBMP(330,550,"image//lv.bmp");
        iShowBMP(480,550,level_pic[level]);



//..............................................SHOWING SCORE.....
        temp_sc = sc;
        position = NULL;
        while(temp_sc != 0)
        {
            num_position = position*50;
            iShowBMP(950-num_position,550,score_pic[(temp_sc%10)]);
            position++;
            temp_sc = temp_sc/10;
        }


//..............................................SHOWING BARS...

        iSetColor(123,122,123);
        iFilledRectangle(bar_x1, bar_y1, bar_length, 10);
        iFilledRectangle(bar_x2, bar_y2, bar_length, 10);
        iFilledRectangle(bar_x3, bar_y3, bar_length, 10);


//..............................................SHOWING FIRE ON TOP AND BOTTOM........

        iShowBMP(0,500,"image//khach2.bmp");
        iShowBMP(0,0,"image//khach3.bmp");


//..............................................showing naruto on screen.......
        if(naruto_mood==RIGHT)
            iShowBMP(naruto_cordinate_x,naruto_cordinate_y,naruto_run_R[i]);
        if(naruto_mood==LEFT)
            iShowBMP(naruto_cordinate_x,naruto_cordinate_y,naruto_run_L[i]);



//..............................................SHOWING BULLETS...

        for(j=0; j<bullet_count_a; j++)
        {
            if(bullets[j].bulletmode == 1)
            {
                iShowBMP(bullets[j].x,bullets[j].y,"image//bl.bmp");

            }

            if(bullets[j].bulletmode == 2)
                iShowBMP(bullets[j].x,bullets[j].y,"image//br.bmp");

        }



//..............................................SHOWING ENEMY...

        if(enemy_mode_l == LEFT)
        {
            iShowBMP(0,enemy_l_y,"image//kurama.bmp");

        }
        if(enemy_mode_r ==RIGHT)
        {
            iShowBMP(1000-40,enemy_r_y,"image//kurama.bmp");
        }


        if(blast == 1)
        {
            iShowBMP(5,blast_position_l,"image//boom.bmp");
            blast=0;
        }
        if(blast == 2)
        {
            iShowBMP(955,blast_position_r,"image//boom.bmp");
            blast=0;
        }
        if(enemy_mode_l==END)
        {
            enemy_l_y=-100;
            enemy_mode_l=LEFT;
        }

        if(enemy_mode_r==END)
        {
            enemy_r_y=-100;
            enemy_mode_r=RIGHT;
        }


    }





    /*................................................Home Page.....................................*/



    else
    {




//....................................................when game is over.....


        if(mode == SHOW)
        {

            char yourScore[100] = {0};

            itoa(sc, yourScore,10);


            iShowBMP(0,0,"image//gameover.bmp");
            iText(450,50,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,25,yourScore,GLUT_BITMAP_TIMES_ROMAN_24);
        }



//....................................................Starting Page........

        else
        {
            iShowBMP(0,0,"image//home1.bmp");

            iShowBMP(0,550, "image//play_game.bmp");
            iShowBMP(190, 550, "image//instructions1.bmp");
            iShowBMP(600,550,"image//highscore.bmp");
            iShowBMP(830,550,"image//exit_1.bmp");


            if(musicMode == ON)
                iShowBMP(400,550,"image//sound_on.bmp");
            else
                iShowBMP(400,550,"image//sound_off.bmp");

            if(instructionMode == ON)
            {
                iShowBMP(0,0,"image//in_1.bmp");
                iShowBMP(500,0,"image//in_naruto.bmp");
            }
            else if(instructionMode == SHOW)
            {
                iShowBMP(500,0,"image//in_2.bmp");
                iShowBMP(0,0,"image//in_naruto.bmp");
            }

            else if(exitMode == ON)
            {
                iShowBMP(0,0,"image//quit_pic.bmp");
                iShowBMP(0,0,"image//quit.bmp");

            }

            else if(highScoreMode == ON)
            {
                iSetColor(0,0,0);
                iFilledRectangle(400, 200, 200, 200 );
                iSetColor(255,0,0);
                iText(430, 370, "1 : ", GLUT_BITMAP_TIMES_ROMAN_24);
                iText(430, 290, "2 : ", GLUT_BITMAP_TIMES_ROMAN_24);
                iText(430, 210, "3 : ", GLUT_BITMAP_TIMES_ROMAN_24);




//.................................................Showing Highscore...



                int place[3];
                char scores[3][100];
                int l;
                FILE *f;
                f=fopen("top3.txt","r");
                for(l=0; l<3; l++)
                {
                    fscanf(f,"%d %s",&place[l],scores[l]);
                }

                fclose(f);

                iText(460, 370, scores[0], GLUT_BITMAP_TIMES_ROMAN_24);
                iText(460, 290, scores[1], GLUT_BITMAP_TIMES_ROMAN_24);
                iText(460, 210, scores[2], GLUT_BITMAP_TIMES_ROMAN_24);
            }

            else
            {
                iShowBMP(0,0,"image//home1.bmp");
            }


        }
    }
}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{

}



/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {


        if(exitMode!=ON && mx>=0 && mx<=175 && my>=550 && my<=600)
        {
            gameMode = PLAY;
            musicMode=OFF;
        }
        if(exitMode!=ON && mx>=190 && mx<=190+175 && my>=550 && my<=600)
        {
            instructionMode = ON;
            instructionCount++;
            highScoreMode = OFF;

        }
        if(exitMode!=ON && mx>=190 && mx<=190+175 && my>=550 && my<=600 && instructionCount==2)
        {
            instructionMode = OFF;
            instructionCount=NULL;

        }

        if(exitMode!=ON && mx>=400 && mx<=400+175 && my>=550 && my<=600 && musicCount==0)
        {
            if(musicMode == OFF)
                musicMode =ON;
            else
                musicMode=OFF;

            if(musicMode == OFF)
                PlaySound(0,0,0);

            else
            {
                musicMode=ON;
                PlaySound("music\\home.wav", NULL, SND_LOOP | SND_ASYNC);
            }

        }




        if( mx>=830 && mx<=830+175 && my>=550 && my<=600)
        {
            exitMode=ON;
            instructionMode = OFF;
            instructionMode_1 = OFF;

        }

        if(exitMode==ON && mx>=10 && mx<=200 && my>=10 && my<=90)
        {
            exit(0);
        }
        if(exitMode==ON && mx>=200 && mx<=400 && my>=10 && my<=90)
        {
            exitMode=OFF;
        }

        if(mx>= 600 && mx<= 600+175 && my>= 550 && my<= 600 )
        {
            if(highScoreMode == ON)
                highScoreMode = OFF;
            else
                highScoreMode =ON;
            instructionMode = OFF;
            instructionMode_1 = OFF;
        }

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{

    //place your codes for other keys here



//.........................................................PLAY/PAUSE......

    if(key == 'p' || key == 'P')
    {
        mode = HOME;
        musicMode=OFF;

    }
    if(key == '\r')
    {
        mode = PLAY;
        instructionMode=SHOW;
    }

    if(key == 'q' || key == 'Q')
    {
        if(musicMode == OFF)
            musicMode =ON;
        else
            musicMode=OFF;
    }
    if(musicMode == OFF)
        PlaySound(0,0,0);

    else
    {
        musicMode=ON;
        PlaySound("music\\home.wav", NULL, SND_LOOP | SND_ASYNC);
    }
//..........................................................BULLET THROW...

    if(key == 'a' || key == 'A')
    {
        bullets[bullet_count_a].bulletmode = 1;
        bullets[bullet_count_a].x=naruto_cordinate_x;
        bullets[bullet_count_a].y=naruto_cordinate_y+20;
        bullet_count_a++;
        if(bullet_count_a==100)
            bullet_count_a=NULL;
    }
    if(key == 's' || key == 'S')
    {
        bullets[bullet_count_a].bulletmode = 2;
        bullets[bullet_count_a].x=naruto_cordinate_x+50;
        bullets[bullet_count_a].y=naruto_cordinate_y+20;
        bullet_count_a++;
        if(bullet_count_a==100)
            bullet_count_a=NULL;

    }

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{




//............................................................NARUTO MOVEMENT...

    if(mode ==PLAY)
    {
        if(key == GLUT_KEY_RIGHT && naruto_cordinate_x<900)
        {
            naruto_mood=RIGHT;
            i++;
            naruto_cordinate_x += naruto_side_speed;
            if(i==6)
                i=0;


        }
        if(key == GLUT_KEY_LEFT && naruto_cordinate_x > 0)

        {
            naruto_mood=LEFT;
            i++;
            naruto_cordinate_x -= naruto_side_speed;
            if(i==6)
                i=0;

        }

    }



    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
}










/*...........................................FOR ENEMY....................................*/


void enemy()
{
    if(mode == PLAY && gameMode==PLAY)
    {
        enemy_l_y += 5;
        enemy_r_y += 5;

        if(enemy_l_y > 500)
        {
            enemy_l_y = rand()%100 - 100;
        }
        if(enemy_r_y > 500)
        {
            enemy_r_y = rand()%200 - 200;
        }


//..............................................BLASTING.....


        int h;
        for(h=0; h<100; h++)
        {
            if( bullets[h].bulletmode == 1 && bullets[h].x<40 && bullets[h].x>0 && bullets[h].y >= enemy_l_y && bullets[h].y <= enemy_l_y+40)
            {
                enemy_mode_l=END;
                blast_position_l=enemy_l_y;
                blast=1;
                sc+=10;
            }
        }
        h=0;
        for(h=0; h<100; h++)
        {
            if( bullets[h].bulletmode == 2 && bullets[h].x>960 && bullets[h].x<1000 && bullets[h].y >= enemy_r_y && bullets[h].y <= enemy_r_y+40)
            {
                enemy_mode_r=END;
                blast_position_r=enemy_r_y;
                blast=2;
                sc+=10;
            }


        }

    }

}


/*............................................FOR SCORING...........................*/


void scoring()
{
    if(mode == PLAY && gameMode==PLAY )
    {
        int n,len=0,i;
        if(!(abs(naruto_cordinate_y - bar_y1)<12 && naruto_cordinate_x+80>=bar_x1 && naruto_cordinate_x<=bar_x1+bar_length) ||
                (abs(naruto_cordinate_y - bar_y2)<12 && naruto_cordinate_x+80>=bar_x2 && naruto_cordinate_x<=bar_x2+bar_length) ||
                abs(naruto_cordinate_y - bar_y3)<12 && naruto_cordinate_x+80>=bar_x3 && naruto_cordinate_x<=bar_x3+bar_length)
        {
            sc++;
        }


//.........................................LEVEL CHANGING....


        level_count++;
        if(level_count==100)
        {
            level++;
            level_count=0;
            mode = HOME;
        }


        if(level==2)
        {
            bar_speed = 2;
            bar_length = 250;
            naruto_side_speed = 15;

        }

        if(level==3)
        {
            bar_speed = 3;
            bar_length = 200;
            naruto_side_speed = 20;

        }

        if(level==4)
        {
            bar_speed = 4;
            bar_length = 200;
            naruto_side_speed = 25;
        }

        if(level == 5)
        {
            level_count = 0;
        }

    }

}




int main()
{

    mode = HOME;
    naruto_mood = RIGHT;
    naruto_speed = 1;
    naruto_side_speed = 10;
    gameMode = HOME;


    iSetTimer(1, barchange);
    iSetTimer(1000,bar_random);
    iSetTimer(1,bulletchange);
    iSetTimer(40,enemy);
    iSetTimer(300, scoring);

    if(gameMode==HOME)
        PlaySound("music\\home.wav", NULL, SND_LOOP | SND_ASYNC);

    iInitialize(1000, 600, "Rapid Action");


    return 0;
}
