#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
                                         // Declaration of global variables//
float y=0,ang=0,i=0,k=0,n=0,ae=0,be=0;	 // y-boat speed
float a=900,b=880,c=900,d=900,p,q=0,s;   // q-sea motion speed
float g=0;                               // car translate indicator speed
float m=0.0,j=0.0,o=0.0;
int t;

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
}

void title()
{	
	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(650.0,1400.0);
	declare("FREEWAY TRAFFIC AROUND A BASCULE BRIDGE IN 2D USING OpenGL ");
	glRasterPos2f(300.0,1100.0);
	declare("|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|*  Mouse Functions  *|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|");
	glRasterPos2f(300.0,1000.0);
	declare("-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-*  Press Right click on your mouse  *-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-");
	glRasterPos2f(300.0,900.0);
	declare("|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|*  Press Enter to select an option  *|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|");
	glRasterPos2f(300.0,600.0);
	declare("-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|*  Keyboard Functions  *-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-");
	glRasterPos2f(300.0,500.0);
	declare("|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|*  Press a|A-START, s|S-STOP or d|D-EXIT  *|-|-|-|-|-|-|-|-|-|-|-|-|-|-|");		 
	glRasterPos2f(300.0,200.0);
	declare("-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-*  Algorithm And Programming by:  *-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-");
	glRasterPos2f(300.0,100.0);
	declare("********************************  Akshay Raina '`'|'_`|'`' B.Roopini  *********************************");	
}
	
void sea()			//sea function to display river//
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(0.0,0.0);
	    	glVertex2f(2000.0,0.0);
		glVertex2f(2000.0,1600.0);
		glVertex2f(0.0,1600.0);
	glEnd();

  	glPushMatrix();
  	glTranslatef(0,q,0);

	glBegin(GL_LINES);
		glColor3f(1.0,1.0,1.0);
   		for(p=0;p<21000;p=p+70)
	   		for(s=0;s<21000;s=s+70)
				glVertex2f(0.0+s,100.0+p);
			glVertex2f(0.0+s,100.0+p);

				
	glEnd();
  glPopMatrix();
}
			//  Bridge function  //
void bridge()
{
	glBegin(GL_POLYGON);
		glColor3f(0.40,0.40,0.40);
		glVertex2f(0.0,900.0);
		glVertex2f(500.0,900.0);
		glVertex2f(500.0,1200.0);   //bridge top 1
		glVertex2f(0.0,1200.0);
    	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.40,0.40,0.40);
		glVertex2f(0.0,900.0);
		glVertex2f(500.0,900.0);
		glVertex2f(500.0,1200.0);   //bridge top 1
		glVertex2f(0.0,1200.0);
    	glEnd();
	
	
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(100.0,1030.0);
		glVertex2f(200.0,1030.0);
		glVertex2f(200.0,1040.0);   //strip1
		glVertex2f(100.0,1040.0);
    	glEnd();


	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(300.0,1030.0);
		glVertex2f(400.0,1030.0);
		glVertex2f(400.0,1040.0);   //strip2
		glVertex2f(300.0,1040.0);
    glEnd();
	

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(0.0,1170.0);
		glVertex2f(500.0,1170.0);
		glVertex2f(500.0,1175.0);   //yellow strip1
		glVertex2f(0.0,1175.0);
    glEnd();


	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(0.0,920.0);
		glVertex2f(500.0,920.0);
		glVertex2f(500.0,925.0);   //yellow strip2
		glVertex2f(0.0,925.0);
    glEnd();
	//   brige up
	glPushMatrix();
	glBegin(GL_POLYGON);
		glColor3f(0.46,0.46,0.46);
		glVertex2f(500.0,900.0);  //bridge top 2
		//up
		glVertex2f(900.0-k,900.0+n);
		glVertex2f(900.0-k,1200.0+n);
		//up
		glVertex2f(500.0,1200.0);
    	glEnd();

	glBegin(GL_LINES); 
		glColor3f(0.0,0.0,0.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(900.0-k,900.0+n); //pole thread front
		glVertex2f(0.0,1400.0);
		glVertex2f(900.0-k,880.0+n);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(30.0,1550.0);
		glVertex2f(900.0-k,1200.0+n); //pole thread back
		glVertex2f(50.0,1550.0);
		glVertex2f(900.0-k,1220.0+n);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(500.0,880.0);
		glVertex2f(900.0-k,880.0+n); //base1
		glVertex2f(900.0-k,900.0+n);
		glVertex2f(500.0,900.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.46,0.46,0.46);
		glVertex2f(900.0+k,900.0+n);
		//up
		glVertex2f(1300.0,900.0);    // bridge top3
		glVertex2f(1300.0,1200.0);
		//up
		glVertex2f(900.0+k,1200.0+n);
        glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(900.0+k,880.0+n);
		glVertex2f(1300.0,880.0);	// base 2
		glVertex2f(1300.0,900.0);
		glVertex2f(900.0+k,900.0+n);
	glEnd();
glPopMatrix();

//		printf("i== %f\t k==%f\n",i,k);

	//============================
	glBegin(GL_POLYGON);
		glColor3f(0.40,0.40,0.40);
		glVertex2f(1300.0,900.0);
		glVertex2f(2000.0,900.0);  //bridge top 4
		glVertex2f(2000.0,1200.0);
		glVertex2f(1300.0,1200.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1300.0,1170.0);
		glVertex2f(2000.0,1170.0);
		glVertex2f(2000.0,1175.0);   //yellow strip3
		glVertex2f(1300.0,1175.0);
     glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1300.0,920.0);
		glVertex2f(2000.0,920.0);
		glVertex2f(2000.0,925.0);   // yellow strip4
		glVertex2f(1300.0,925.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1400.0,1030.0);
		glVertex2f(1500.0,1030.0);
		glVertex2f(1500.0,1040.0);   //strip3
		glVertex2f(1400.0,1040.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1600.0,1030.0);
		glVertex2f(1700.0,1030.0);
		glVertex2f(1700.0,1040.0);   //strip4
		glVertex2f(1600.0,1040.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1800.0,1030.0);
		glVertex2f(1900.0,1030.0);
		glVertex2f(1900.0,1040.0);   //strip5
		glVertex2f(1800.0,1040.0);
    glEnd();


	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1725.0,1550.0);
		glVertex2f(900.0+k,1220.0+n);//rite pole thread 
		glVertex2f(1745.0,1550.0);
		glVertex2f(900.0+k,1200.0+n);
		glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.25,0.25,0.25);
		glVertex2f(200.0,800.0);   //6 point polygon 1
		glVertex2f(200.0,700.0);
		glVertex2f(300.0,700.0);
		glVertex2f(300.0,800.0);
		glVertex2f(350.0,880.0);
		glVertex2f(150.0,880.0);
		glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);     //base3
		glVertex2f(0.0,880.0);
		glVertex2f(500.0,880.0);   
		glVertex2f(500.0,900.0);
		glVertex2f(0.0,900.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);    //base4
		glVertex2f(1300.0,880.0);
		glVertex2f(2000.0,880.0);   
		glVertex2f(2000.0,900.0);
		glVertex2f(1300.0,900.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);    //black top border
		glVertex2f(0.0,1200.0);
		glVertex2f(500.0,1200.0);   
		glVertex2f(500.0,1220.0);
		glVertex2f(0.0,1220.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);    //black top border
		glVertex2f(500.0,1200.0);
		glVertex2f(900.0-k,1200.0+n);   
		glVertex2f(900.0-k,1220.0+n);
		glVertex2f(500.0,1220.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);    //black top border
		glVertex2f(900.0+k,1200.0+n);
		glVertex2f(1300.0,1200.0);   
		glVertex2f(1300.0,1220.0);
		glVertex2f(900.0+k,1220.0+n);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);    //black top border
		glVertex2f(1300.0,1200.0);
		glVertex2f(2000.0,1200.0);   
		glVertex2f(2000.0,1220.0);
		glVertex2f(1300.0,1220.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.25,0.25,0.25);    //6 point polygon2
		glVertex2f(1500.0,800.0);
		glVertex2f(1500.0,700.0);
		glVertex2f(1600.0,700.0);  
		glVertex2f(1600.0,800.0);
		glVertex2f(1650.0,880.0);
		glVertex2f(1450.0,880.0);
	glEnd();
}

//////////////////////////////////////////  Boat function  ///////////////////////////////
void boat()
{
		glPushMatrix();
		glTranslatef(0,y,0);
		glPushMatrix();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.6,0.0);
		glVertex2f(900.0,700.0);
		glVertex2f(800.0,620.0);
		glVertex2f(750.0,500.0);
		glVertex2f(750.0,200.0);     //ship
		glVertex2f(900.0,50.0);
		glVertex2f(1050.0,200.0);
		glVertex2f(1050.0,500.0);
		glVertex2f(1000.0,620.0);
		
	glEnd();
		
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);     //ship back 1
		glVertex2f(750.0,200.0);
		glVertex2f(900.0,0.0);
		glVertex2f(900.0,50.0);
		glVertex2f(750.0,200.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(900.0,0.0);      //ship back  2
		glVertex2f(1050.0,200.0);
		glVertex2f(1050.0,200.0);
		glVertex2f(900.0,50.0);
	glEnd();

	glLineWidth(100);		
	glBegin(GL_LINES);
	
		glColor3f(0.0,0.0,0.0);
		glVertex2f(900.0,700.0);
		glVertex2f(820.0,600.0);  //boat grill
		glVertex2f(820.0,600.0);
		glVertex2f(800.0,620.0);
		glVertex2f(820.0,600.0);
		glVertex2f(770.0,500.0);
		glVertex2f(770.0,500.0);
		glVertex2f(750.0,500.0);
		glVertex2f(770.0,500.0);
		glVertex2f(770.0,200.0);
		glVertex2f(770.0,200.0);
		glVertex2f(750.0,200.0);
		glVertex2f(770.0,200.0);
		glVertex2f(900.0,70.0);
		glVertex2f(900.0,70.0);
		glVertex2f(900.0,50.0);
		glVertex2f(900.0,70.0);
		glVertex2f(1030.0,200.0);
		glVertex2f(1030.0,200.0);
		glVertex2f(1050.0,200.0);
		glVertex2f(1030.0,200.0);
		glVertex2f(1030.0,500.0);
		glVertex2f(1030.0,500.0);
		glVertex2f(1050.0,500.0);
		glVertex2f(1030.0,500.0);
		glVertex2f(980.0,620.0);
		glVertex2f(980.0,620.0);
		glVertex2f(1000.0,620.0);
		glVertex2f(980.0,620.0);
		glVertex2f(900.0,700.0);
		glVertex2f(770.0,350.0);
		glVertex2f(750.0,350.0);
		glVertex2f(770.0,450.0);
		glVertex2f(750.0,450.0);
		glVertex2f(770.0,250.0);
		glVertex2f(750.0,250.0);
		glVertex2f(1030.0,250.0);
		glVertex2f(1050.0,250.0);
		glVertex2f(1030.0,350.0);
		glVertex2f(1050.0,350.0);
		glVertex2f(1030.0,450.0);
		glVertex2f(1050.0,450.0);
		glVertex2f(840.0,130.0);
		glVertex2f(820.0,110.0);
		glVertex2f(975.0,110);
		glVertex2f(955.0,125.0);
	glEnd();
	//	printf("g==%d\n",g);
		
	//table on ship
		glBegin(GL_POLYGON);
			glColor3f(0.0,0.0,0.0);
			glVertex2f(800.0,200.0);   //boat inside polygon
			glVertex2f(800.0,500.0);			
			glVertex2f(1000.0,500.0);
			glVertex2f(1000.0,200.0);
	    	glEnd();
		
		glBegin(GL_POLYGON);
			glColor3f(1.0,1.0,0.0);
			glVertex2f(840.0,240.0);   //boat inside polygon
			glVertex2f(840.0,460.0);			
			glVertex2f(960.0,460.0);
			glVertex2f(960.0,240.0);
	    	glEnd();

		glBegin(GL_POLYGON);
			glColor3f(0.0,0.0,0.0);
			glVertex2f(880.0,280.0);   //boat inside polygon
			glVertex2f(880.0,420.0);			
			glVertex2f(920.0,420.0);
			glVertex2f(920.0,280.0);
	    	glEnd();
		
	 glPopMatrix();
	glPopMatrix();
}

////////////////////////////////////////////    bus/car function   //////////////////////////////////
void car()
{
glPushMatrix();
glTranslatef(g,0,0);
	
	//glPushMatrix();
	//glTranslatef(1820.0,1030.0,0.0);
	//glutSolidSphere(1.0,200,200);
	//glPopMatrix();

	glBegin(GL_POLYGON);                  //  car
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1800.0,1050.0);
		glVertex2f(1950.0,1050.0);
		glVertex2f(1950.0,1150.0);
		glVertex2f(1800.0,1150.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  car
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1770.0,1030.0);
		glVertex2f(1800.0,1050.0);
		glVertex2f(1800.0,1150.0);
		glVertex2f(1770.0,1130.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  car
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1770.0,1030.0);
		glVertex2f(1930.0,1030.0);
		glVertex2f(1950.0,1050.0);
		glVertex2f(1800.0,1050.0);
	glEnd();

    	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1820.0,1080.0);
		glVertex2f(1920.0,1080.0);
		glVertex2f(1920.0,1080.0);
		glVertex2f(1920.0,1110.0);
		glVertex2f(1920.0,1110.0);         //carrier
		glVertex2f(1820.0,1110.0);
		glVertex2f(1820.0,1110.0);
		glVertex2f(1820.0,1080.0);
		glVertex2f(1840.0,1080.0);
		glVertex2f(1840.0,1110.0);
		glVertex2f(1860.0,1080.0);
		glVertex2f(1860.0,1110.0);
		glVertex2f(1880.0,1080.0);
		glVertex2f(1880.0,1110.0);
		glVertex2f(1900.0,1080.0);
		glVertex2f(1900.0,1110.0);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1780.0,1035.0);        //head lamp
		glVertex2f(1780.0,1045.0);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1780.0,1125.0);        //head lamp
		glVertex2f(1780.0,1135.0);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1790.0,1055.0);        //horn grill
		glVertex2f(1790.0,1125.0);
		glEnd();	
		
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1800.0,1040.0);        //side window
		glVertex2f(1928.0,1040.0);
		glEnd();

glPopMatrix();
}

/////////////////////////////////////////////////// Pole Function  ///////////////////////////////
void poles()
{
	glBegin(GL_POLYGON);                 //  left pole behind
		glColor3f(0.0,0.0,0.0);
		glVertex2f(30.0,1200.0);
		glVertex2f(50.0,1200.0);
		glVertex2f(50.0,1550.0);
		glVertex2f(30.0,1550.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  right pole behind
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1725.0,1200.0);
		glVertex2f(1745.0,1200.0);
		glVertex2f(1745.0,1550.0);
		glVertex2f(1725.0,1550.0);
	glEnd();

	glBegin(GL_POLYGON);                 // street light behind 1 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(150.0,1200.0);
		glVertex2f(160.0,1200.0);
		glVertex2f(160.0,1300.0);
		glVertex2f(150.0,1300.0);
	glEnd();

	glBegin(GL_POLYGON);                 // street light behind 1 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(165.0,1300.0);
		glVertex2f(145.0,1300.0);
		glVertex2f(145.0,1325.0);
		glVertex2f(165.0,1325.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light behind 2 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1800.0,1200.0);
		glVertex2f(1810.0,1200.0);
		glVertex2f(1810.0,1300.0);
		glVertex2f(1800.0,1300.0);
	glEnd();
	
	glBegin(GL_POLYGON);                  // street light behind 2 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1815.0,1300.0);
		glVertex2f(1795.0,1300.0);
		glVertex2f(1795.0,1325.0);
		glVertex2f(1815.0,1325.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light behind 3 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1300.0,1200.0);
		glVertex2f(1310.0,1200.0);
		glVertex2f(1310.0,1300.0);
		glVertex2f(1300.0,1300.0);
	glEnd();
	
	glBegin(GL_POLYGON);                  // street light behind 3 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1315.0,1300.0);
		glVertex2f(1295.0,1300.0);
		glVertex2f(1295.0,1325.0);
		glVertex2f(1315.0,1325.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light behind 4 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(490.0,1200.0);
		glVertex2f(500.0,1200.0);
		glVertex2f(500.0,1300.0);
		glVertex2f(490.0,1300.0);
	glEnd();
	
	glBegin(GL_POLYGON);                  // street light behind 4 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(505.0,1300.0);
		glVertex2f(485.0,1300.0);
		glVertex2f(485.0,1325.0);
		glVertex2f(505.0,1325.0);
	glEnd();

  	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1750.0,1400.0);
		glVertex2f(900.0+k,900.0+n);    //right pole thread front
		glVertex2f(1770.0,1400.0);
		glVertex2f(900.0+k,880.0+n);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(900.0-k,900.0+n);    //pole thread front
		glVertex2f(0.0,1400.0);
		glVertex2f(900.0-k,880.0+n);
	glEnd();

	glBegin(GL_POLYGON);                  //  left pole front
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0.0,900.0);
		glVertex2f(20.0,900.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(0.0,1400.0);
	glEnd();		

	glBegin(GL_POLYGON);                  //  right pole front
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1750.0,900.0);
		glVertex2f(1770.0,900.0);
		glVertex2f(1770.0,1400.0);
		glVertex2f(1750.0,1400.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light front 1 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(250.0,900.0);
		glVertex2f(260.0,900.0);
		glVertex2f(260.0,1000.0);
		glVertex2f(250.0,1000.0);
	glEnd();
	
	glBegin(GL_POLYGON);                  // street light front 1 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(265.0,1000.0);
		glVertex2f(245.0,1000.0);
		glVertex2f(245.0,1025.0);
		glVertex2f(265.0,1025.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  street light front 2 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1550.0,900.0);
		glVertex2f(1560.0,900.0);
		glVertex2f(1560.0,1000.0);
		glVertex2f(1550.0,1000.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  street light front 2 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1565.0,1000.0);
		glVertex2f(1545.0,1000.0);
		glVertex2f(1545.0,1025.0);
		glVertex2f(1565.0,1025.0);
	glEnd();
}

void aeroplane()
{
glPushMatrix();
glTranslatef(ae++,be++,0);
glPushMatrix();

glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2f(0.0,20.0);
glVertex2f(0.0,120.0);
glVertex2f(270.0,120.0);
glVertex2f(270.0,20.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0,0.0,0.0);
glVertex2f(270.0,120.0);
glVertex2f(320.0,110.0);
glVertex2f(360.0,95.0);
glVertex2f(390.0,75.0);
glVertex2f(270.0,75.0);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(270.0,121.0);
glVertex2f(321.0,111.0);
glVertex2f(351.0,96.0);
glVertex2f(391.0,76.0);
glVertex2f(270.0,76.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex2f(270.0,75.0);
glVertex2f(390.0,75.0);
glVertex2f(350.0,45.0);
glVertex2f(310.0,30.0);
glVertex2f(270.0,20.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex2f(0.0,120.0);
glVertex2f(0.0,180.0);
glVertex2f(30.0,180.0);
glVertex2f(90.0,120.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex2f(160.0,120.0);
glVertex2f(120.0,150.0);
glVertex2f(190.0,150.0);
glVertex2f(230.0,120.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex2f(150.0,75.0);
glVertex2f(210.0,75.0);
glVertex2f(178.0,5.0);
glVertex2f(120.0,5.0);
glEnd();

glPopMatrix();glPopMatrix();glPopMatrix();glPopMatrix();glPopMatrix();glPopMatrix();
}

/////////////////////////////// display function  ///////////////////////////
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_RGB);
        if(t<1500)
        {
                for(t=0;t<=1500;t++)
                {	
                        title();
                        glutPostRedisplay();
                        glutSwapBuffers();
                        glFlush();
                }
        }

	sea();	
	bridge();
        boat();
        car();
        poles();
	aeroplane();	

glFlush();
glutSwapBuffers();
}

/////////////////////////////////   function to animate and cause motion in vehicles  //////////////////////////////
void animate()
{
	q=q-0.5;
	y=y+0.5;

	a=a+0.8;	

	i+=0.5; 
	if((i>=135) && (i<=439))
	{	k=k+0.4;
		n=n+0.4;
	}
	if(i>=1200 && !(k<=0 && n<=0))
	{
		k=k-0.4;
		n=n-0.4;
	}
	
	if(k<=0)
		g-=1.4;
	
	glutPostRedisplay();
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,2000.0,0.0,1600.0);
}

/////////////////////////////////   Keyboard function   //////////////////
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'a':glutIdleFunc(animate);
		   break;

	case 's':glutIdleFunc(NULL);
		   break;

	case 'd':exit(0);
	}	
}

/////////////////////////////////// Menu function  ///////////////////////
void menu(int ch)
{
	switch(ch)
	{
	case 1:glutIdleFunc(animate);
		   break;

	case 2:glutIdleFunc(NULL);
		   break;

	case 3:exit(0);
	}
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(2000,1600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("FREEWAY TRAFFIC AROUND A BASCULE BRIDGE IN 2D USING OpenGL");
		
	glutKeyboardFunc(keyboard);

	glutCreateMenu(menu);
	glutAddMenuEntry("START MOTION",1);
	glutAddMenuEntry("STOP MOTION",2);
	glutAddMenuEntry("EXIT",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);	

	glutDisplayFunc(display);
	myinit();
	glClearColor (1.0, 1.0, 0.0, 1.0);
	glutMainLoop();
        return 0;

}

////////////////////////////////////  The End   ///////////////////////////
