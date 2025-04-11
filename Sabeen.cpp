#include<GL/glut.h>  //Library to open window

float CarX=0.0f;     //CarX is global variable here speed still 0

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void specialkeys(int key, int x, int y)  //this function used to press the arrows keys
{
	switch(key){
		case GLUT_KEY_LEFT:    //use to move the car left
		  CarX-= 0.1f;         //move left
		  break;
		
		case GLUT_KEY_RIGHT:
	      CarX+=0.1f;        //use to move car right
	      break;             //move right
	}
	
	glutPostRedisplay();    //used to refresh the screen so that we see the movement on screen
	
}

void drawCar()            //to draw a car
{                    
    glColor3f(1.0f,0.0f,0.0f);    //RGB color values
	glBegin(GL_QUADS);            //built-in function to draw quadrilateral 
		
		//box of car
	glVertex2f(CarX -0.2f,-0.2f);
	glVertex2f(CarX +0.2f,-0.2f);    //Measurements of the rectangle
	glVertex2f(CarX +0.2f, 0.0f);
	glVertex2f(CarX -0.2f, 0.0f);
		
	glEnd();        //to indicate end of drawing shapes
	
	//built-in function to draw wheels
	glColor3f(0.0f, 0.0f, 0.0f);  //black color of wheels
	glBegin(GL_QUADS);            //built-in function to draw quadrilateral 
		
		//1st tyre
	glVertex2f(CarX -0.15f,-0.25f);
	glVertex2f(CarX -0.05f,-0.25f);    //Measurements of the rectangle
	glVertex2f(CarX -0.05f,-0.2f);
	glVertex2f(CarX -0.15f,-0.2f);
	
	glEnd();
	
	glBegin(GL_QUADS);            //built-in function to draw quadrilateral 
		
		//2nd tyre
	glVertex2f(CarX +0.15f,-0.25f);
	glVertex2f(CarX +0.05f,-0.25f);    //Measurements of the rectangle
	glVertex2f(CarX +0.05f,-0.2f);
	glVertex2f(CarX +0.15f,-0.2f);
	
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);  //clear screen
	
	glLoadIdentity();   //co-ordinate(x,y axis) ko reset krta hai
	
	drawCar();
	
	glFlush();   //To show on drawing screen 
}

void init()    //open gl initialization
{
	glClearColor(0.8f,0.8f,1.0f,1.0f); //background screen (skyblue)
	
	glMatrixMode(GL_PROJECTION);     //for dimensions 2D/3D
	
	glLoadIdentity();
	
}

int main(int argc, char** argv) {
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    //to show the number of screens in thisw case (GLUT_SINGLE) means single screen
	glutInitWindowSize(500,500);          //set windows resolution (size)
	glutInitWindowPosition(100,100);      //to show starting position 
	glutCreateWindow("My OpenGL Window");     //screen name
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specialkeys);         //Handling keys
	glutMainLoop();               //Loop continues until user stop
	
	
	return 0;	
}