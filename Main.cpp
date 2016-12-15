#include"Class_Corda.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/gl.h>
#include <GL/glu.h>
#include<math.h>
#include"Finestra.h"
#include"Fisica.h"


using namespace std;

Corda corda(20, 3, 4, 1, 0.0, 0.0, -4, 0); // n,l,k,colorer,coloreg,coloreb,x,y



#define LARGHEZZA_FINESTRA 1400
#define ALTEZZA_FINESTRA 700

double Disc_Pixel = 8.28 / (ALTEZZA_FINESTRA - 1);
int Trova_Pixel(double coor) {
	for (int i = 1; i <= ALTEZZA_FINESTRA - 1; ++i) {
		double coordi = i*Disc_Pixel;
		double coordi1 = (i + 1)*Disc_Pixel;

		if ((coor - coordi) < (coordi1 - coor)) return i;
		else return i + 1;
	}

}



void Frame::draw() {

	glClearColor(0.0, 0.0, 0.0, 1);                        // Turn the background color black
	glViewport(0, 0, w(), h());                               // Make our viewport the whole window
	glMatrixMode(GL_PROJECTION);                           // Select The Projection Matrix
	glLoadIdentity();                                      // Reset The Projection Matrix
														   //  gluOrtho2D(-gluorto,gluorto,-gluorto, gluorto);  // (xmin,xmax,ymin,ymax)
	gluPerspective(45.0f, w() / h(), 1.0f, 150.0f);
	glMatrixMode(GL_MODELVIEW);                            // Select The Modelview Matrix
	glLoadIdentity();                                      // Reset The Modelview Matrix
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Clear The Screen And The Depth Buffer
	glLoadIdentity();                                      // Reset The View
	gluLookAt(TRASLAZIONE_X, 0, 10, TRASLAZIONE_X, 0, 0, 0, 1, 0);         // Position - View  - Up Vector
	glEnable(GL_DEPTH_TEST);
	glScalef(zoom, zoom, zoom);
	corda.SetL(LUNGHEZZA_CORDA);
	corda.SetR(RAGGIO);
	corda.Draw_Corda();
	//Movimento();
}


void exit_callback(Fl_Widget *) { finestra->hide(); }
void LUNGHEZZA_CORDA_callback(Fl_Widget *) { gg->LUNGHEZZA_CORDA = LUNGHEZZA_CORDA->value(); }
void RAGGIO_callback(Fl_Widget *) { gg->RAGGIO = RAGGIO->value(); }
void TRASLAZIONE_X_callback(Fl_Widget *) { gg->TRASLAZIONE_X = TRASLAZIONE_X->value(); }
void zoom_callback(Fl_Widget *) { gg->zoom = zoom->value(); }




void Crea_Finestra() {
	int w_est, h_est;

	w_est = LARGHEZZA_FINESTRA - 50;   h_est = ALTEZZA_FINESTRA;

	int pixUL = 20;
	int pixULb = 5;
	finestra = new Fl_Window(LARGHEZZA_FINESTRA + 2 * pixUL, ALTEZZA_FINESTRA + 2 * pixUL, "CORDA");
	new Fl_Box(FL_DOWN_FRAME, pixUL - pixULb, pixUL - pixULb, LARGHEZZA_FINESTRA / 2 + 2 * pixULb, ALTEZZA_FINESTRA + 2 * pixULb, "");
	gg = new Frame(pixUL, pixUL, LARGHEZZA_FINESTRA / 2, ALTEZZA_FINESTRA, "");


	LUNGHEZZA_CORDA = new Fl_Value_Slider(w_est - 230, 20 + 0 * 50, 210, 20, "LUNGHEZZA CORDA");
	RAGGIO = new Fl_Value_Slider(w_est - 230, 20 + 1 * 50, 210, 20, "RAGGIO");
	TRASLAZIONE_X = new Fl_Value_Slider(w_est - 230, 20 + 2 * 50, 210, 20, " TRASLAZIONE X");
	zoom = new Fl_Value_Slider(w_est - 230, 20 + 3 * 50, 210, 20, "ZOOM");
	//linee = new Fl_Multiline_Output(w_est - 230, 20 + 4 * 50, 210, 70, "");

	button = new Fl_Button(w_est - 230, h_est - 130, 210, 110, "Exit");
	button->tooltip(" Comporta la chiusura della finestra  ");
	LUNGHEZZA_CORDA->tooltip(" Regola la lunghezza della corda ");
	LUNGHEZZA_CORDA->type(FL_HOR_SLIDER); LUNGHEZZA_CORDA->bounds(0, 50); LUNGHEZZA_CORDA->value(gg->LUNGHEZZA_CORDA = 0);
	RAGGIO->type(FL_HOR_FILL_SLIDER); RAGGIO->bounds(0, 1); RAGGIO->value(gg->RAGGIO = 0.05);
	TRASLAZIONE_X->type(FL_HOR_SLIDER); TRASLAZIONE_X->bounds(-10, 10); TRASLAZIONE_X->value(gg->TRASLAZIONE_X = 0);
	zoom->type(FL_HOR_NICE_SLIDER); zoom->bounds(0.1, 10); zoom->value(gg->zoom = 1.0);
	LUNGHEZZA_CORDA->callback(LUNGHEZZA_CORDA_callback);
	RAGGIO->callback(RAGGIO_callback);
	TRASLAZIONE_X->callback(TRASLAZIONE_X_callback);
	zoom->callback(zoom_callback);


	button->callback(exit_callback);


	finestra->end();
	finestra->show();
	gg->show();
}

void idle_cb(void*) {
	gg->redraw();
}


int main() {
	corda.Setcolore(0.5, 0.5, 0.5);
	corda.SetR(0.02);
	corda.Pos_Attuale_corda();
	corda.Proprieta_Corda();
	coutForza(-3, 0);
	Crea_Finestra();

	Fl::add_idle(idle_cb, 0);
	Fl::run();
	getchar();

	

}

