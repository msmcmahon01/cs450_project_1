#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#ifndef F_PI
#define F_PI		((float)(M_PI))
#define F_2_PI		((float)(2.f*F_PI))
#define F_PI_2		((float)(F_PI/2.f))
#endif


//void
//TrmptBell(float x_pos, float y_pos, float z_pos, float x_scale, float y_scale, float z_scale, int verticies, int thinness) {
//
//	glBegin( GL_TRIANGLES );
//
//	for (int i = 0; i < verticies; ++i) {
//		float sinNum = (sin(i * F_2_PI)) / verticies;
//		float cosNum = (cos(i * F_2_PI)) / verticies;
//		float sinNumi1 = (sin((1 + i) * F_2_PI)) / verticies;
//		float cosNumi1 = (cos((1 + i) * F_2_PI)) / verticies;
//
//		glNormal3f(0, 0, 0);
//			glVertex3f(sinNum + x_pos, cosNum + y_pos, z_pos);
//			glVertex3f(((sinNum / (thinness + (z_pos * 4))) + x_pos), ((cosNum / (thinness + (z_pos * 4))) + y_pos), z_pos);
//			glVertex3f(((sinNumi1 / (thinness + (z_pos * 4))) + x_pos), ((cosNumi1 / (thinness + (z_pos * 4))) + y_pos), z_pos);
//
//			glVertex3f()
//	}
//}

void
TrmptTubeXY(float x_pos, float y_pos, float z_pos_s, float z_pos_e, int verticies, int thinness) {
	for (int i = 0; i < verticies; ++i) {
		float sinNum = (((sin(i * F_2_PI)) / verticies) / thinness) + x_pos;
		float cosNum = (((cos(i * F_2_PI)) / verticies) / thinness) + y_pos;
		float sinNumi1 = (((sin((1 + i) * F_2_PI)) / verticies) / thinness) + x_pos;
		float cosNumi1 = (((cos((1 + i) * F_2_PI)) / verticies) / thinness) + y_pos;

		glNormal3f(0, 0, 0);
			//glColor3f(1, 0, 0);
			glVertex3f(sinNum, cosNum, z_pos_s);
			glVertex3f(sinNum, cosNum, z_pos_e);
			glVertex3f(sinNumi1, cosNumi1, z_pos_e);

			//glColor3f(0, 1, 0);
			glVertex3f(sinNum, cosNum, z_pos_s);
			glVertex3f(sinNumi1, cosNumi1, z_pos_e);
			glVertex3f(sinNumi1, cosNumi1, z_pos_s);
	}
}

