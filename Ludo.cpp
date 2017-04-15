#include<iostream>


/**
* An animated OpenGL ludo 3D program written by 
* @author Anifowoshe Gbenga David 
* @Programming Langauge cpp
* @Graphical Language OpenGL
* @Main Library GLUT 
**/

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void update(int value);

const GLfloat light_ambient[]  = { 0.3f, 0.3f, 0.3f, 1.0f }; 

const GLfloat light_diffuse[]  = { 0.5f, 0.5f, 0.5f, 0.5f }; 
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat directional_light_diffuse[] = {0.5f, 0.2f, 0.2f, 1.0f};
const GLfloat directional_light_position[] = {-1.0f, 0.5f, 0.5f, 0.0f};


const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float _angle = 15.0f;



void resize(int width, int height){
    glViewport(0, 0, width, height);	
    glMatrixMode(GL_PROJECTION);	
    glLoadIdentity();	


	gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
}



void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 8.5f, 10.0f);
	glScalef(8.5f,8.5f,9.5f);

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glLightfv(GL_LIGHT1, GL_DIFFUSE,  directional_light_diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, directional_light_position);
	
	//inner board 
	glBegin(GL_QUADS);
		glColor3f(0,0.3,0.2);
		glVertex3f(-0.69f, -1.5f, -5.0f);
		glVertex3f(0.69f, -1.5f, -5.0f);
		glVertex3f(0.39f, -0.5f, -5.0f);
		glVertex3f(-0.39f, -0.5f, -5.0f);
	glEnd();
	

	//outer board 
	glLoadIdentity();
	glTranslatef(0.0f, 10.0f, 10.0f);
	glScalef(10.0f,10.0f,10.0f);


	glBegin(GL_QUADS);
		glColor3d(1,0,0);
		glVertex3f(-0.7f, -1.5f, -5.0f);
		glVertex3f(0.7f, -1.5f, -5.0f);
		glVertex3f(0.4f, -0.5f, -5.0f);
		glVertex3f(-0.4f, -0.5f, -5.0f);
	glEnd();


	// Left Top Player segment (left-top)
	glLoadIdentity();
	glTranslatef(-1.6f, 2.0f, -20.0f);
	glRotatef(73.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.5f);
	glScalef(0.5f,0.5f,0.5f);
	glScalef(0.5f,0.5f,0.5f);


	glBegin(GL_QUADS);
		glColor3d(247,243,13);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	// Left Top Player segment (right-top)
	glLoadIdentity();
	glTranslatef(-1.30f, 1.9f, -20.0f);
	glRotatef(77.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(247,243,13);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	//Left Top Player (bottom left)
	glLoadIdentity();
	glTranslatef(-1.75f, 1.57f, -20.0f);
	glRotatef(73.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(247,243,13);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	//Left Top Player (bottom right)
	glLoadIdentity();
	glTranslatef(-1.40f, 1.45f, -20.0f);
	glRotatef(73.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(247,243,13);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();



	//Bottom Left Player(bottom left)
	glLoadIdentity();
	glTranslatef(-2.85f, -2.00f, -20.0f);
	glRotatef(74.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();



	//Bottom Left Player(bottom right)
	glLoadIdentity();
	glTranslatef(-2.46f, -2.00f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();



	//Bottom Left Player(top left)
	glLoadIdentity();
	glTranslatef(-2.7f, -1.50f, -20.0f);
	glRotatef(75.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Bottom Left Player(top right)
	glLoadIdentity();
	glTranslatef(-2.35f, -1.50f, -20.0f);
	glRotatef(75.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();



	//Top Right Player(top right)
	glLoadIdentity();
	glTranslatef(1.6f, 2.0f, -20.0f);
	glRotatef(102.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Top Right Player(top left)
	glLoadIdentity();
	glTranslatef(1.25f, 2.0f, -20.0f);
	glRotatef(102.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Top Right Player(bottom right)
	glLoadIdentity();
	glTranslatef(1.30f, 1.55f, -20.0f);
	glRotatef(102.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Top Right Player(bottom left)
	glLoadIdentity();
	glTranslatef(1.70f, 1.55f, -20.0f);
	glRotatef(102.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Bottom Right Player(top right)
	glLoadIdentity();
	glTranslatef(2.65f, -1.50f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Bottom Right Player(top left)
	glLoadIdentity();
	glTranslatef(2.30f, -1.50f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Bottom Right Player(bottom left)
	glLoadIdentity();
	glTranslatef(2.35f, -1.95f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//Bottom Right Player(bottom right)
	glLoadIdentity();
	glTranslatef(2.73f, -1.95f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);


	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();




	/**
	* Begins the drawign of the small square that makes up the 
	* Ludo Game 
	*/


	/**
	* Beginning of the left panel  
	*/
	glLoadIdentity();
	glTranslatef(-0.45f, 2.0f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	glLoadIdentity();
	glTranslatef(-0.50f, 1.55f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	glLoadIdentity();
	glTranslatef(-0.55f, 1.12f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.60f, 0.69f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.65f, 0.26f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	glLoadIdentity();
	glTranslatef(-0.70f, -0.17f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.75f, -0.6f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.80f, -1.03f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.85f, -1.46f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.90f, -1.89f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	//last panel on the left (bottom left)
	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();



	/**
	* Beginning of the right panel 
	*/
	glLoadIdentity();
	glTranslatef(-0.01f, 2.0f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, 1.55f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,0,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, 1.15f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,0,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, 0.70f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,0,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, -0.28f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, -0.74f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, -1.24f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, -1.66f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.01f, -1.90f, -20.0f);
	glRotatef(86.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	/**
	* Right panel
	*/
	glLoadIdentity();
	glTranslatef(0.4f, 2.0f, -20.0f);
	glRotatef(100.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,0,0);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	glLoadIdentity();
	glTranslatef(0.5f, 1.55f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.6f, 1.1f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.7f, 0.65f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();	//middle 
	glTranslatef(0.8f, 0.15f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.9f, -0.35f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.0f, -0.85f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.1f, -1.35f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.2f, -1.85f, -20.0f);
	glRotatef(101.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	/**
	* left panel (side panel)
	*/
	glLoadIdentity();
	glTranslatef(-0.90f, 0.79f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-1.3f, 0.82f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-1.65f, 0.86f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();	//yellow 
	glTranslatef(-2.00f, 0.90f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//middle(panel of left) yellow
	glLoadIdentity();
	glTranslatef(-1.0f, 0.30f, -20.0f);
	glRotatef(80.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	//middle(panel of left) yellow
	glLoadIdentity();
	glTranslatef(-1.4f, 0.33f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	//middle(panel of left) yellow
	glLoadIdentity();
	glTranslatef(-1.8f, 0.36f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	//middle(panel of left) yellow
	glLoadIdentity();
	glTranslatef(-2.2f, 0.39f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	//left panel white 
	glLoadIdentity();
	glTranslatef(-1.1f, -0.15f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-1.5f, -0.16f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-1.9f, -0.17f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-2.3f, -0.18f, -20.0f);
	glRotatef(76.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();




	//Right panel white 
	glLoadIdentity();
	glTranslatef(1.25f, -0.25f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	glLoadIdentity();
	glTranslatef(1.55f, -0.18f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	glLoadIdentity();
	glTranslatef(1.85f, -0.11f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();


	glLoadIdentity();	//blue 
	glTranslatef(2.15f, -0.04f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();



	//middle (right)  blue 
	glLoadIdentity();
	glTranslatef(1.18f, 0.2f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.46f, 0.29f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.74f, 0.31f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(2.01f, 0.34f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();



	//right of right side 
	glLoadIdentity();
	glTranslatef(1.0f, 0.76f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.35f, 0.85f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.70f, 0.94f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	glLoadIdentity();
	glTranslatef(2.00f, 1.03f, -20.0f);
	glRotatef(106.0f,0.0f,0.0f,1.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);
	glScalef(0.5f,0.5f,0.0f);

	glBegin(GL_QUADS);
		glColor3d(1,1,1);
		glVertex3f(-1.0f, -1.0f, 1.5f);
		glVertex3f(1.5f, -1.0f, 1.5f);
		glVertex3f(1.5f, 1.0f, 1.5f);
		glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();




	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -18.0f);

	glScalef(0.5f,0.5f,0.5f);
	glScalef(0.8f,0.8f,0.8f);
	//Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; 
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	
	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -20.0f);
	glColor3f(1.0,1.0,0.6);

	const float DEG2RAD = 3.142/180;
	const int radius = 50; 

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glPointSize(10);
	glBegin(GL_LINE_LOOP);
		for (int i=0; i < 360; i++){
			float degInRad = i * DEG2RAD;
			glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);	//output vertex 
		}
	glEnd();

	glutSwapBuffers();
}

void update(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}
	
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int arg, char** argv){
	glutInit(&arg, argv);
	glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Animated OpenGL cpp Ludo Game");
	 

	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);	
    glEnable(GL_LIGHTING);	
	glShadeModel(GL_FLAT); 

	glutReshapeFunc(resize);	
    glutDisplayFunc(display);	

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();	 
    return 0;
}