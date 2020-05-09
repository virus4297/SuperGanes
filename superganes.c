#include<stdio.h>
#include <SDL/SDL.h>
#include<GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<string.h>

float i=0.0;    //movement of ganesh
float j=10.0;    //movement of ganesh
float m=0.0;    //movement of clouds
int jump=0,flag=0,count=0;
int win=0,loose=0;

float angle = 0.0;
const int triangle = 1;
GLfloat x=0.5;


unsigned int loadTexture(const char* filename)
{
	SDL_Surface* img = SDL_LoadBMP(filename);
	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SDL_FreeSurface(img);
	return id;
}

void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
	int l;

	//sky
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,160);
	glVertex2f(0,700);
	glVertex2f(1100,700);
	glVertex2f(1100,160);
	glEnd();

	//moon

		for(l=0;l<=35;l++)
		{
			glColor3f(1.0,1.0,1.0);
			draw_circle(100,625,l);
		}

	
	//cloud1

		for(l=0;l<=20;l++)
		{
			glColor3f(1.0,1.0,1.0);
			draw_circle(160+m,625,l);

		}


		for(l=0;l<=35;l++)
		{
			glColor3f(1.0,1.0,1.0);
			draw_circle(200+m,625,l);
			draw_circle(225+m,625,l);
		}

		for(l=0;l<=20;l++)
		{
			glColor3f(1.0,1.0,1.0);
			draw_circle(265+m,625,l);
		}

	//cloud2


		for(l=0;l<=20;l++)
		{
			glColor3f(1.0,1.0,1.0);
			draw_circle(370+m,615,l);
		}




		for(l=0;l<=35;l++)
		{

			glColor3f(1.0,1.0,1.0);
			draw_circle(410+m,615,l);
			draw_circle(435+m,615,l);
			draw_circle(470+m,615,l);
		}

	for(l=0;l<=20;l++)
		{
			glColor3f(1.0,1.0,1.0);
			draw_circle(500+m,615,l);
		}

	//star1

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(575,653);
	glVertex2f(570,645);
	glVertex2f(580,645);
	glVertex2f(575,642);
	glVertex2f(570,650);
	glVertex2f(580,650);
	glEnd();

	//star2
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(975,643);
	glVertex2f(970,635);
	glVertex2f(980,635);
	glVertex2f(975,632);
	glVertex2f(970,640);
	glVertex2f(980,640);
	glEnd();

	//star3
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(875,543);
	glVertex2f(870,535);
	glVertex2f(880,535);
	glVertex2f(875,532);
	glVertex2f(870,540);
	glVertex2f(880,540);
	glEnd();

	//star4
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(375,598);
	glVertex2f(370,590);
	glVertex2f(380,590);
	glVertex2f(375,587);
	glVertex2f(370,595);
	glVertex2f(380,595);
	glEnd();

	//star5
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(750,628);
	glVertex2f(745,620);
	glVertex2f(755,620);
	glVertex2f(750,618);
	glVertex2f(745,625);
	glVertex2f(755,625);
	glEnd();

	//star6
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200,628);
	glVertex2f(195,620);
	glVertex2f(205,620);
	glVertex2f(200,618);
	glVertex2f(195,625);
	glVertex2f(205,625);
	glEnd();

	//star7
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(500,543);
	glVertex2f(495,535);
	glVertex2f(505,535);
	glVertex2f(500,532);
	glVertex2f(495,540);
	glVertex2f(505,540);
	glEnd();

	//star8

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(575,453);
	glVertex2f(570,445);
	glVertex2f(580,445);
	glVertex2f(575,442);
	glVertex2f(570,450);
	glVertex2f(580,450);
	glEnd();

	//star9
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(975,443);
	glVertex2f(970,435);
	glVertex2f(980,435);
	glVertex2f(975,432);
	glVertex2f(970,440);
	glVertex2f(980,440);
	glEnd();

	//star10
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(875,343);
	glVertex2f(870,335);
	glVertex2f(880,335);
	glVertex2f(875,332);
	glVertex2f(870,340);
	glVertex2f(880,340);
	glEnd();

	//star11
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(375,398);
	glVertex2f(370,390);
	glVertex2f(380,390);
	glVertex2f(375,387);
	glVertex2f(370,395);
	glVertex2f(380,395);
	glEnd();

	//star12
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(750,428);
	glVertex2f(745,420);
	glVertex2f(755,420);
	glVertex2f(750,418);
	glVertex2f(745,425);
	glVertex2f(755,425);
	glEnd();

	//star13
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200,428);
	glVertex2f(195,420);
	glVertex2f(205,420);
	glVertex2f(200,418);
	glVertex2f(195,425);
	glVertex2f(205,425);
	glEnd();

	//star14
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(500,343);
	glVertex2f(495,335);
	glVertex2f(505,335);
	glVertex2f(500,332);
	glVertex2f(495,340);
	glVertex2f(505,340);
	glEnd();


	//Grass
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,100);
	glVertex2f(0,250);
	glVertex2f(1100,250);
	glVertex2f(1100,100);
	glEnd();

	//road
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,150);
	glVertex2f(1100,150);
	glVertex2f(1100,0);
	glEnd();


	//pond
	glColor3f(0.0,0.0,0.4);
	glBegin(GL_POLYGON); //x->310,424  y->155,217
	glVertex2f(310,183);	//x->367 y->186
	glVertex2f(310,193);
	glVertex2f(320,203);
	glVertex2f(330,207);
	glVertex2f(340,211);
	glVertex2f(380,217);
	glVertex2f(390,215);
	glVertex2f(400,205);
	glVertex2f(410,199);
	glVertex2f(420,193);
	glVertex2f(424,183);
	glVertex2f(420,171);
	glVertex2f(410,163);
	glVertex2f(400,161);
	glVertex2f(390,159);
	glVertex2f(380,157);
	glVertex2f(370,155);
	glVertex2f(360,155);
	glVertex2f(350,155);
	glVertex2f(340,159);
	glVertex2f(330,163);
	glVertex2f(320,167);
	glEnd();

	//DeadPoint   x->758 y->190    x->367 y->186
	glColor3f(0.0,0.0,0.0);
	draw_pixel(758,190);
	draw_pixel(367,186);	

	//tree
	glColor3f(0.9,0.2,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(750,160);
	glVertex2f(750,220); //x->758 y->190
	glVertex2f(765,220);
	glVertex2f(765,160);
	glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(740,225,l);
		draw_circle(780,225,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(750,265,l);
		draw_circle(770,265,l);
	}

	

	//ganesh
	for(l=0;l<20;l++)
	   {
		glColor3f(1.0,0.5,0.0);
		draw_circle(82+i,260+j,l);
	   }
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(65+i,180+j);
	glVertex2f(65+i,240+j);
	glVertex2f(100+i,240+j);
	glVertex2f(100+i,180+j);
	glEnd();
	//right arm
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(100+i,230+j);
	glVertex2f(110+i,250+j);
	glVertex2f(115+i,250+j);
	glVertex2f(100+i,230+j);
	glEnd();
	//left arm
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(65+i,230+j);
	glVertex2f(55+i,250+j);
	glVertex2f(60+i,250+j);
	glVertex2f(65+i,230+j);
	glEnd();
	//left leg
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(50+i,160+j);
	glVertex2f(60+i,180+j);
	glVertex2f(65+i,180+j);
	glVertex2f(55+i,160+j);
	glEnd();
	//right leg
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(110+i,160+j);
	glVertex2f(100+i,180+j);
	glVertex2f(105+i,180+j);
	glVertex2f(115+i,160+j);
	glEnd();

	//signal
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();


	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();



glFlush();
}


void idle()
{
	if(win==1)
	{
		printf("\n\n################################################################################################################\n\n\t\t\t\t\t\t\t\tYOU WIN  !!\n\n################################################################################################################\n\n");	
	exit(0);
	}
	
	if(loose==1)
	{
		printf("\n\n################################################################################################################\n\n\t\t\t\t\t\t\t\tYOU LOOSE !!\n\n################################################################################################################\n\n");
	printf("\n\nx=%f y=%f\n\n",i,j);
		exit(0);
	}
	
	//x->367 y->186
	//i->292 j->26
	if(j<=26&&i==292)
		loose=1;
		
	//x->758 y->190
	//i->683 j->30
	if(j<=30&&i==683)
		loose=1;
		
	//jumping ganesh
	if(jump==1&&j<200&&flag==0)
	{
		j=j+0.5;
		if(j==200)
		{
			flag=1;
			count=50;
		}
	}
	if(flag==1)
	{
		count--;
		if(count<=0)
		{
			if(j==200)
				jump=0;
			if(j>0)
				j--;
			if(j==0)
				flag=0;
		}
	}
	

     	i+=0.25;
     	++m;

	if(i>1100)
		 win=1;
	if(m>1100)
		 m=0.0;

	glutPostRedisplay();

}


void keyboardFunc( unsigned char key, int x, int y )
{
	switch( key )
	    {
	case 'j':
	case 'J':
		jump=1;
		break;

	    };

}

unsigned int mario;

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1100.0,0.0,700.0);
	
	
   	glEnable(GL_BLEND);
    	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluPerspective(45,640.0/480.0,1.0,600.0);
	// glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	
	mario = loadTexture("mario.bmp");
}


void display()
{
    


	glClear(GL_COLOR_BUFFER_BIT);
	draw_object();
	
	
	glPushMatrix();
   	GLint startx=0,starty=0; 
   	glBindTexture(GL_TEXTURE_2D, mario);
   	glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(startx,starty+168,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(startx,starty+168+64,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(startx+64,starty+168+64,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(startx+64,starty+168,0.0);
    glEnd();
    glPopMatrix();
	x+=1;
	
	
	glFlush();
}



int main(int argc,char** argv)
{
	int c_menu;
		printf("Press 'r' or 'R' to change the signal light to red \n");
		printf("Press 'g' or 'G' to change the signal light to green \n");

		printf("Press 'd' or 'D' to make it day \n");
		printf("Press 'n' or 'N' to make it night \n");

		printf("Press RIGHT MOUSE BUTTON to display menu \n");
		printf("Press LEFT MOUSE BUTTON to quit the program \n");

		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(1100.0,700.0);
		glutInitWindowPosition(0,0);
		glutCreateWindow("Advance Traffic Signal");
		glutDisplayFunc(display);
		glutIdleFunc(idle);
		glutKeyboardFunc(keyboardFunc);
		myinit();

		glutMainLoop();
		return 0;
}
