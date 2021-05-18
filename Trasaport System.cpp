#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265358979323846

float sr=133;///sky Color
float sg=204;
float sb=250;
float mr=255;///moon and sun
float mg=255;
float mb=0;
float br= 130;
float bg= 150;
float bb= 137;

GLfloat positionRL = 0.0f;
GLfloat speedRL = 0.05f;
GLfloat m = 0.0f;

void updateRL(int value) {

    if(positionRL <-2.0)
        positionRL = 1.0f;

    positionRL -= speedRL;

	glutPostRedisplay();


	glutTimerFunc(100, updateRL, 0);
}

GLfloat positionLR = 0.0f;
GLfloat speedLR = 0.05f;
void updateLR(int value) {

    if(positionLR >4.0)
        positionLR = -1.0f;

    positionLR += speedLR;
	glutPostRedisplay();

	glutTimerFunc(100, updateLR, 0);
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void tree()
{
    glPushMatrix();
    glTranslatef(-0.2,0,0);
    glPushMatrix();
    glScalef(0.4,0.4,0);

	glBegin(GL_POLYGON);
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.4f);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.08f, -0.5f);
	glVertex2f(0.08f, 0.4f);
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 179,44);//rgb color picker

    glVertex2f(-.2f, -0.01f);
	glVertex2f(+0.28f, -0.01f);
	glVertex2f(+.04f, 0.6f);
	glEnd();

	glBegin(GL_TRIANGLES);//
    glColor3ub(13,239, 66);

    glVertex2f(-.15f, .25f);
	glVertex2f(+0.22f,.25f);
	glVertex2f(+.04f, 0.8f);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}

void forest()
{
    tree();
	glPushMatrix();
	glScalef(0.5f,0.5f,0);
	glTranslatef(-0.6f,0.0f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.6f,0);
	glTranslatef(-0.2f,-0.1f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.8f,0);
	glTranslatef(-0.4f,0.0f,0);
	tree();
	glPopMatrix();
}

void railline()
{
    glPushMatrix();
    glTranslatef(0,-0.4,0);
    glPushMatrix();
    for(float i=-1;i<1;i+=0.06){
        glColor3ub(120,54,5);
        glBegin(GL_POLYGON);
        glVertex2f(0.02f+i,-0.33f);
        glVertex2f(0.02f+i,-0.31f);
        glVertex2f(0.06f+i,-0.31f);
        glVertex2f(0.06f+i,-0.33f);
        glEnd();

        glColor3ub(153,153,153);
        glBegin(GL_POLYGON);
        glVertex2f(0.029f+i,-0.33f);
        glVertex2f(0.051f+i,-0.33f);
        glVertex2f(0.051f+i,-0.42f);
        glVertex2f(0.029f+i,-0.42f);
        glEnd();

        glColor3ub(120,54,5);
        glBegin(GL_POLYGON);
        glVertex2f(0.02f+i,-0.44f);
        glVertex2f(0.02f+i,-0.42f);
        glVertex2f(0.06f+i,-0.42f);
        glVertex2f(0.06f+i,-0.44f);
        glEnd();

    }

glPopMatrix();
glPopMatrix();

}

void train()
{
    glPushMatrix();
    glTranslatef(positionLR,0.0f, 0.0f);
    glPushMatrix();
    glScalef(0.6,0.6,0);
    glTranslatef(-0.6,-0.4f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.5f,0.3f);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.1,-0.7);
    glVertex2f(0.1,-0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0.5f,0.3f);
    glVertex2f(-0.9,-0.5);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.1,-0.7);
    glVertex2f(-0.9,-0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f,0,0);
    glVertex2f(-0.5,-0.3);
    glVertex2f(-0.1,-0.3);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.5,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f,0,0);
    glVertex2f(-0.9,-0.1);
    glVertex2f(-0.5,-0.1);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.9,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-0.8,-0.2);
    glVertex2f(-0.6,-0.2);
    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.8,-0.4);
    glEnd();
////
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-1.0,0.0);
    glVertex2f(-0.4,0.0);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-1.0,-0.1);
    glEnd();

   glPushMatrix();

    glColor3ub(0,0,0);
    glTranslatef(-0.2f,-0.7f, 0.0f);
    glutSolidSphere(0.06, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-0.7f,-0.7f, 0.0f);
    glutSolidSphere(0.06, 50, 50);
    glPopMatrix();
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.97,0.0,0);
	glPushMatrix();
	glScalef(1.6,1.6,0);
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3ub(0,43,85);
                glVertex2f(-0.2f,-0.38f);
                glVertex2f(-0.57f,-0.38f);
                glVertex2f(-0.6f,-0.41f);
                glVertex2f(-0.2f,-0.41f);
        glEnd();
       glBegin(GL_POLYGON);
     glColor3ub(0,43,85);
                glVertex2f(-0.2f,-0.38f);
                glVertex2f(-0.57f,-0.38f);
                glVertex2f(-0.57f,-0.32f);
                glVertex2f(-0.2f,-0.32f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255,255,255);
                glVertex2f(-0.2f,-0.32f);
                glVertex2f(-0.57f,-0.32f);
                glVertex2f(-0.56f,-0.30f);
                glVertex2f(-0.2f,-0.30f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3ub(153,0,79);
        glVertex2f(-0.2f,-0.40f);
        glVertex2f(-0.2f,-0.385f);
        glVertex2f(-0.18f,-0.385f);
        glVertex2f(-0.18f,-0.40f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(153,0,79);
        glVertex2f(0.22f,-0.40f);
        glVertex2f(0.22f,-0.385f);
        glVertex2f(0.24f,-0.385f);
        glVertex2f(0.24f,-0.40f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.42f,0,0);
    glBegin(GL_POLYGON);
        glColor3ub(153,0,79);
        glVertex2f(0.21f,-0.40f);
        glVertex2f(0.21f,-0.385f);
        glVertex2f(0.249f,-0.385f);
        glVertex2f(0.249f,-0.40f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
     glColor3ub(0,97,0);
                    glVertex2f(0.22f,-0.41f);
                    glVertex2f(-0.18f,-0.41f);
                    glVertex2f(-0.18f,-0.30f);
                    glVertex2f(0.22f,-0.30f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3ub(237,237,237);
                    glVertex2f(0.24f,-0.41f);
                    glVertex2f(0.64f,-0.41f);
                    glVertex2f(0.64f,-0.30f);
                    glVertex2f(0.24f,-0.30f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        for(float i=0.15;i<0.5;i+=0.05){
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
                glVertex2f(-0.702+i,-0.373);
                glVertex2f(-0.678+i,-0.373);
                glVertex2f(-0.678+i,-0.327);
                glVertex2f(-0.702+i,-0.327);
            glEnd();
        }
        for(float i=0.15;i<0.5;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3ub(br,bg,bb);
                glVertex2f(-0.7f+i,-0.37);
                glVertex2f(-0.68f+i,-0.37f);
                glVertex2f(-0.68f+i,-0.33f);
                glVertex2f(-0.7f+i,-0.33f);
            glEnd();
        }
    glPopMatrix();
    glPushMatrix();
        for(float i=0.54;i<0.92;i+=0.05){
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
                glVertex2f(-0.702f+i,-0.373f);
                glVertex2f(-0.68f+i,-0.373f);
                glVertex2f(-0.68f+i,-0.327f);
                glVertex2f(-0.702f+i,-0.327f);
            glEnd();
        }
        for(float i=0.54;i<0.92;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3ub(br,bg,bb);
                glVertex2f(-0.7+i,-0.37f);
                glVertex2f(-0.68+i,-0.37f);
                glVertex2f(-0.68+i,-0.33f);
                glVertex2f(-0.7+i,-0.33f);
            glEnd();
        }
    glPopMatrix();
    glPushMatrix();
        for(float i=0.96;i<1.34;i+=0.05){
            glBegin(GL_POLYGON);
                glColor3ub(0,0,0);
                glVertex2f(-0.702+i,-0.373);
                glVertex2f(-0.68+i,-0.373f);
                glVertex2f(-0.68+i,-0.327f);
                glVertex2f(-0.702+i,-0.327f);
            glEnd();
        }
        for(float i=0.96;i<1.34;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3ub(br,bg,bb);
                glVertex2f(-0.7+i,-0.37);
                glVertex2f(-0.68+i,-0.37f);
                glVertex2f(-0.68+i,-0.33f);
                glVertex2f(-0.7+i,-0.33f);
            glEnd();
        }
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(-0.53,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(-0.27,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(-0.11,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(0.15,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(0.31f,-0.41f, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(0.57f,-0.41f, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
glPopMatrix();
glPopMatrix();
	glPopMatrix();
}
void sky()
{
      glBegin(GL_QUADS);
	glColor3ub(sr, sg, sb);

	glVertex2f(-0.999f, 1.0f);
	glVertex2f(-0.999f, 0.2f);
	glVertex2f(0.999f, 0.2f);
	glVertex2f(0.999f, 1.0f);

	glEnd();
}
void lake()
{
      glBegin(GL_QUADS);
	glColor3ub(sr, sg, sb);

	glVertex2f(-0.999f, 1.0f);
	glVertex2f(-0.999f, 0.2f);
	glVertex2f(0.999f, 0.2f);
	glVertex2f(0.999f, 1.0f);

	glEnd();
}

void ground()
{
      glBegin(GL_QUADS);
	glColor3f(0.0f,0.4f, 0.0f);

	glVertex2f(-0.999f, 0.2f);
	glVertex2f(-0.999f, -0.3f);
	glVertex2f(0.999f, -0.3f);
	glVertex2f(0.999f, 0.2f);

	glEnd();
}
void footpath()
{
      glBegin(GL_QUADS);
	glColor3f(0.8f, 0.4f, 0.0f);

	glVertex2f(-0.999f, -0.3f);
	glVertex2f(-0.999f, -0.4f);
	glVertex2f(0.999f, -0.4f);
	glVertex2f(0.999f, -0.3f);

	glEnd();
}

void road()
{
      glBegin(GL_QUADS);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(-0.999f, -0.4f);
	glVertex2f(-0.999f, -1.0f);
	glVertex2f(0.999f, -1.0f);
	glVertex2f(0.999f, -0.4f);

	glEnd();


}

void sunmoon()
{
    glPushMatrix();
	glTranslatef(-0.72, 0.8f, 0.0f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(mr,mg,mb);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();
}

void car()
{
    glPushMatrix();
	glTranslatef(positionRL, 0.2f, 0.0f);
    glPushMatrix();
	glTranslatef(-0.3, -0.6f, 0.0f);
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);

	glVertex2f(0.05f, 0.2f);
	glVertex2f(0.05f, 0.12f);
	glVertex2f(0.6f, 0.12f);
	glVertex2f(0.6f, 0.25f);
	glVertex2f(0.18f, 0.25f);

	glEnd();

	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.5f, 1.f);
	glVertex2f(0.18f, 0.24f);
	glVertex2f(0.25f, 0.32f);

	glEnd();
	glPopMatrix();

//tire
glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(0, 0, 0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.07;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(-0.1+x,-0.5+y);
}
glEnd();

//tire
glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(0, 0, 0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.07;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(0.2+x,-0.5+y);
}
glEnd();

    glPopMatrix();

}
void building()
{
    glTranslatef(0.4, -0.2f, 0.0f);
     glBegin(GL_QUADS);
	glColor3f(0.5f, 1.0f, 1.0f);

	glVertex2f(-0.3f, 1.0f);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.3f, 1.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.3f, 0.0f);

	glVertex2f(-0.1f, 1.0f);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 1.0f);

	glEnd();

	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.20f);
	glVertex2f(0.3f, 0.20f);

	glEnd();

	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.4f);
	glVertex2f(0.3f, 0.4f);

	glEnd();

	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.6f);
	glVertex2f(0.3f, 0.6f);
	glEnd();

	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.8f);
	glVertex2f(0.3f, 0.8f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.2f, 0.0f, 0.0f);

	glVertex2f(-0.1f, 0.1f);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.1f);

	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.09f, 0.09f);
	glVertex2f(-0.09f, -0.1f);
	glVertex2f(0.09f, -0.1f);
	glVertex2f(0.09f, 0.09f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.27f);
	glVertex2f(-0.23f, 0.34f);
	glVertex2f(-0.17f, 0.34f);
	glVertex2f(-0.17f, 0.27f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.47f);
	glVertex2f(-0.23f, 0.54f);
	glVertex2f(-0.17f, 0.54f);
	glVertex2f(-0.17f, 0.47f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.67f);
	glVertex2f(-0.23f, 0.74f);
	glVertex2f(-0.17f, 0.74f);
	glVertex2f(-0.17f, 0.67f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.87f);
	glVertex2f(-0.23f, 0.94f);
	glVertex2f(-0.17f, 0.94f);
	glVertex2f(-0.17f, 0.87f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.27f);
	glVertex2f(0.23f, 0.34f);
	glVertex2f(0.17f, 0.34f);
	glVertex2f(0.17f, 0.27f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.47f);
	glVertex2f(0.23f, 0.54f);
	glVertex2f(0.17f, 0.54f);
	glVertex2f(0.17f, 0.47f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.67f);
	glVertex2f(0.23f, 0.74f);
	glVertex2f(0.17f, 0.74f);
	glVertex2f(0.17f, 0.67f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.87f);
	glVertex2f(0.23f, 0.94f);
	glVertex2f(0.17f, 0.94f);
	glVertex2f(0.17f, 0.87f);

	glEnd();

}

void scene1()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //sky
    glBegin(GL_QUADS);
    glColor3ub(sr,sg,sb);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glEnd();

    //grass
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex2f(-1.0,-0.5);
    glVertex2f(1.0,-0.5);
    glVertex2f(1.0,-1.0);
    glVertex2f(-1.0,-1.0);
    glEnd();

    //field
    glBegin(GL_QUADS);
    glColor3ub(205,105,0);
    glVertex2f(-1.0,0.1);
    glVertex2f(1.0,0.1);
    glVertex2f(1,.0-0.5);
    glVertex2f(-1.0,-0.5);
    glEnd();

    //barn
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex2f(-0.2,0.4);
    glVertex2f(0.8,0.4);
    glVertex2f(0.8,-0.1);
    glVertex2f(-0.2,-0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.2,0.1);
    glVertex2f(0.4,0.1);
    glVertex2f(0.4,-0.1);
    glVertex2f(0.2,-0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.1,0.3);
    glVertex2f(0.1,0.3);
    glVertex2f(0.1,0.1);
    glVertex2f(-0.1,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.5,0.3);
    glVertex2f(0.7,0.3);
    glVertex2f(0.7,0.1);
    glVertex2f(0.5,0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.3);

    glVertex2f(-0.1,0.2);
    glVertex2f(0.1,0.2);

    glVertex2f(0.6,0.1);
    glVertex2f(0.6,0.3);

    glVertex2f(0.5,0.2);
    glVertex2f(0.7,0.2);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,100,153);
    glVertex2f(-0.2,0.5);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,0.4);
    glVertex2f(-0.2,0.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,153);
    glVertex2f(-0.2,0.5);
    glVertex2f(-0.3,0.4);
    glVertex2f(-0.2,0.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,153);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,0.4);
    glVertex2f(0.9,0.4);
    glEnd();

	//birds
	sunmoon();
    glPushMatrix();
    glTranslatef(positionRL,0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0,0,0);

    glVertex2f(0.7,0.7);
    glVertex2f(0.8,0.8);

    glVertex2f(0.7,0.7);
    glVertex2f(0.6,0.8);

    glVertex2f(0.4,0.8);
    glVertex2f(0.5,0.9);

    glVertex2f(0.4,0.8);
    glVertex2f(0.3,0.9);

    glEnd();
    glPopMatrix();

   //windmill
	glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-0.75,0.5);
    glVertex2f(-0.65,0.5);
    glVertex2f(-0.65,0.1);
    glVertex2f(-0.75,0.1);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.7,0.5,0.0);
    glScalef(0.5,0.5,0.5);
    glRotatef(m,0.0,0.0,0.1);

    glBegin(GL_QUAD_STRIP);
    glColor4f(1.0,1.0,1.0, 0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.1,0.2);
    glVertex2f(0.1,0.2);
    glVertex2f(0.0,0.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor4f(1.0,1.0,1.0, 0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.2,0.1);
    glVertex2f(0.2,-0.1);
    glVertex2f(0.5,0.0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor4f(1.0,1.0,1.0, 0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,-0.2);
    glVertex2f(-0.1,-0.2);
    glVertex2f(0.0,-0.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor4f(1.0,1.0,1.0, 0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.2,0.1);
    glVertex2f(-0.2,-0.1);
    glVertex2f(-0.5,0.0);
    glEnd();

    glPopMatrix();//glPopMatrix pops the top matrix off the stack
    m-=0.01f;//i=i+.1=.2

    tree();
    glPushMatrix();
	glScalef(0.5f,0.5f,0);
	glTranslatef(-0.6f,0.0f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.6f,0);
	glTranslatef(-0.2f,-0.1f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.45,0,0);
	forest();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.1,0,0);
	forest();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.45,-0.2,0);
	forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.8f,0.8f,0);
	glTranslatef(-0.4f,0.0f,0);
	tree();
	glPopMatrix();

    railline();
    glPushMatrix();
    glTranslatef(0,-0.1,0);
    train();
    glPopMatrix();
	glFlush();
}

void scene2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	sky();
	ground();
	glPushMatrix();
	glScalef(0.7f,0.7f,0);
	glTranslatef(-0.9f,0.1f,0);
	building();
	glPopMatrix();
	tree();
	glPushMatrix();
	glScalef(0.5f,0.5f,0);
	glTranslatef(-0.6f,0.0f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.6f,0);
	glTranslatef(-0.2f,-0.1f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.8f,0);
	glTranslatef(-0.4f,0.0f,0);
	tree();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.1,0,0);
	forest();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.2,0,0);
	forest();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.7f,0.7f,0);
	glTranslatef(-1.6f,0.0f,0);
	building();
	glPopMatrix();
	road();
	footpath();
	glPushMatrix();
	glScalef(0.3f,0.3f,0);
	glTranslatef(-1.4f,-0.8f,0);
	glPopMatrix();
	sunmoon();
	building();
	car();
	glPushMatrix();
	glTranslatef(-0.4,0.1,0);
	railline();
	glPopMatrix();
	train();
	glFlush();

}

void keyboard(unsigned char key, int x, int y) {

    switch(key){

      case 'n':
                {
                sr=0; //night
                sg=0;
                sb=100;
                mr=255;//moon
                mg=255;
                mb=255;
                }
                break;

        case 'd':
                {

                 sr=133;//day
                 sg=204;
                 sb=250;
                 mr=255;//sun
                 mg=255;
                 mb=0;
               }
            break;
        case 'p':
                 speedLR = 0.0f;
                 break;
        case 'r':
                 speedLR = 0.1f;
                 break;

        case 'l':
			speedLR += 0.1f;
			break;
        case 'z':
			   glutDisplayFunc(scene1);
			   glutPostRedisplay();
	           break;
         case 'x':
			   glutDisplayFunc(scene2);
			   glutPostRedisplay();
	           break;
            }

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("Transportation System Scenario");
	glutInitWindowSize(320, 320);// Set the window's initial width & height
	glutKeyboardFunc(keyboard);
    glutDisplayFunc(scene1);
    glutIdleFunc(Idle);
	glutTimerFunc(100, updateRL, 0);
	glutTimerFunc(100, updateLR, 0);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
