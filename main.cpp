#ifdef __APPLE__
#include <windows.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat movY=0,movX=0,rotar=0,tam=0.0,escX=0.3,escY=0.3,escZ=0.1;

	void principal()
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glTranslated(movX,movY,0.0);
		glRotatef(rotar,0.1,0.1,0.0);
		glScalef(escX,escY,escZ);
		glPushMatrix();
		glutWireSphere(tam, 50, 50);
		glPopMatrix();
		glFlush(); 
		glutSwapBuffers();
	}

	void movimiento( char keys, int x, int y )
	{	
		switch(keys)
			{	//MOVIMIENTO
			case GLUT_KEY_RIGHT:
				movX+=0.1;
				break;		
			case GLUT_KEY_LEFT:
				movX-=0.1;
				break;
			case GLUT_KEY_UP:
				movY+=0.1;
				break;
			case GLUT_KEY_DOWN:
				movY-=0.1;	
				break;	
			}	
		glutPostRedisplay();
	}

	void aumentar(char pres)
	{
		switch(pres)
		{
			case 'a'://rotar 
				rotar-=4.1;
				break;
			case 's'://rotar
				rotar+=4.1;
				break;	
			case 'j'://aumenta tama?o
				tam+=0.3 ;
				break;
			case 'k'://reduce tama?o
				tam-=0.3 ;
				break;					
			case 'u'://estirar en X
				escX+=0.1;
				break;	
			case 'i'://estirar en Y
				escY+=0.1;
				break;	
			case 'o'://estirar en Z
				escZ+=0.1;
				break;				
		}
		glutPostRedisplay();
	}

	int main(int argc, char* argv[])
	{
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(800,800);
		glutInitWindowPosition(450,150);
		glutCreateWindow("Movimiento circulo"); 
		glEnable(GL_DEPTH_TEST);
		glutDisplayFunc(principal); 
		glutSpecialFunc(movimiento);//Traslacion
		glutKeyboardFunc(aumentar);//rotacion y escalacion
		glutMainLoop();
		return 0;
	}
