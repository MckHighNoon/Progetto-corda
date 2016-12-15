#include"Class_Corda.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Button.H>
#include<FL/Fl_Widget.H>
#include <FL/gl.h>
#include <GL/glu.h>
#include<math.h>

//costruttori
Corda::Corda():N_Punti(0),L(0), l(0), k(0), x(0), y(0) {
	colore[0] = 0;
    colore[1] = 0;
	colore[2] = 0;
	for (int i = 0; i <= N_Punti; ++i) {
		c[i].SetR(0);
		c[i].SetN_id(0);
		c[i].Setmass(0);
		c[i].Setxi(0);
		c[i].Setyi(0);
		c[i].Setxf(0);
		c[i].Setyf(0);
		c[i].Setcolore(0, 0, 0);
	}
}

Corda::Corda(int n, double ll, double kk, double colorer, double coloreg, double coloreb, double xx, double yy) :
	N_Punti(n), l(ll), k(kk), x(xx), y(yy) {
	colore[0] = colorer;
	colore[1] = coloreg;
	colore[2] = coloreb;
	L = l*(N_Punti - 1);
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].SetR(0.1);
		c[i].SetN_id(i);
		c[i].Setmass(1.0);
		c[i].Setxi(xx+ll*i); 
		c[i].Setyi(yy);
		c[i].Setxf(xx + ll*i);
		c[i].Setyf(yy);
		c[i].Setcolore(colorer, coloreg, coloreb);
	}
}

Corda::Corda(int n, double ll, double kk, double colorer, double coloreg, double coloreb, double xx, double yy, double RR, double m) :
	N_Punti(n), l(ll), k(kk), x(xx), y(yy) {
	colore[0] = colorer;
	colore[1] = coloreg;
	colore[2] = coloreb;
	L = l*(N_Punti - 1);
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].SetR(RR);
		c[i].SetN_id(i);
		c[i].Setmass(m);
		c[i].Setxi(xx + ll*i);
		c[i].Setyi(yy);
		c[i].Setxf(xx + ll*i);
		c[i].Setyf(yy);
		c[i].Setcolore(colorer, coloreg, coloreb);
	}
}
//getter
int Corda::GetN_Punti() {
	return N_Punti;
}

double Corda::GetL() {
	return L;
}

double Corda::Getl() {
	return l;
}

double Corda::Getk() {
	return k;
}

double Corda::Getcolore(int n) {
	if (n == 0) return colore[n];
	else if (n == 1) return colore[n];
	else if (n == 2) return colore[n];
	else cout << "Errore dal getter del colore della corda \n";
}

double Corda::Getx() {
	return x;
}

double Corda::Getxi(int i) {
	return c[i].Getxf();
}

double Corda::Gety() {
	return y;
}

double Corda::Getyi(int i) {
	return c[i].Getyf();
}

double Corda::GetR() {
	return c[0].GetR();
}

double Corda::GetRi(int i) {
	return c[i].GetR();
}

double Corda ::Getmass() {
	double massa = 0;
	for (int i = 1; i <= N_Punti; ++i) {
		massa = massa + c[i].Getmass();
	}
	return massa;
}

double Corda::Getmassi(int i) {
	return c[i].Getmass();
}

//setter
int Corda::SetN_Punti(int n) {
	double r=c[1].GetR();
	double m = c[1].Getmass();
	double colorer = c[1].Getcolore(0);
	double coloreg = c[1].Getcolore(1);
	double coloreb = c[1].Getcolore(2);
	for (int i = N_Punti+1; i <= n; ++i) {
		c[i].SetR(r);
		c[i].Setmass(m);
		c[i].Setcolore(colorer, coloreg, coloreb);
	}
	N_Punti = n;
	l = L / (N_Punti - 1);
	
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].SetN_id(i);
		c[i].Setxi(x + i*l);
		c[i].Setyi(y);
		c[i].Setxf(x + i*l);
		c[i].Setyf(y);
	}
	
	return 1;
}

int Corda::SetL(double lunghezza) {
	L = lunghezza;
	l = L / (N_Punti - 1);
	for (int i = 1; i <= N_Punti; ++i) {
		if(i==1) {
			c[i].Setxi(x);
			c[i].Setyi(y);
			c[i].Setxf(x);
			c[i].Setyf(y);
		}
		else {
			c[i].Setxi(x + (i-1)*l);
			c[i].Setyi(y);
			c[i].Setxf(x + (i-1)*l);
			c[i].Setyf(y);
		}
		
	}
	return 1;
}

int Corda::Setl(double ll) {
	l = ll;
	L = l*(N_Punti - 1);
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].Setxi(x+i*l);
		c[i].Setyi(y);
		c[i].Setxf(x + i*l);
		c[i].Setyf(y);
	}
	return 1;
}

int Corda::Setk(double kk) {
	k = kk; 
	return 1;
}

int Corda::Setcolore(double r, double g, double b) {
	colore[0] = r;
	colore[1] = g;
	colore[2] = b;
	return 1;
}

int Corda::SetcoloreT(double r, double g, double b) {
	colore[0] = r;
	colore[1] = g;
	colore[2] = b;
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].Setcolore(r, g, b);
	}
	return 1;
}

int Corda::Setx(double xx) {
	x = xx;
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].Setxi(xx+i*l);
		double a = c[i].Getxf();
		c[i].Setxf(a + xx);
	}
	return 1;
}

int Corda::Setxi(int i, double xx) {
	c[i].Setxf(xx);
	return 1;
}

int Corda::Sety(double yy) {
	y = yy;
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].Setyi(yy + i*l);
		double a = c[i].Getxf();
		c[i].Setyf(a + yy);
	}
	return 1;
}

int Corda::Setyi(int i, double yy) {
	c[i].Setyf(yy);
	return 1;
}

int Corda::SetR(double RR) {
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].SetR(RR);
	}
	return 1;
}

int Corda::Setmass(double m) {
	for (int i = 0; i <= N_Punti; ++i) {
		c[i].Setmass(m);
	}
	return 1;
}
// stampa 
void Corda::Proprieta_Corda() {
	cout << " Le proprietà della corda sono le seguenti : \n";
	cout << " N Punti = " << N_Punti << "\n";
	cout << " Lunghezza totale = " << L << "\n";
	cout << " distanza tra un punto e quello sucessivo = " << l << "\n";
	cout << "Costante elastica = " << k << "\n";
	cout << " x = " << x << "  y = " << y << "\n";
	cout << " Colore : " << colore[0] << " " << colore[1] << " " << colore[2] <<" \n";
	cout << " E i punti materiali che la compongono hanno Massa = " << c[2].Getmass() << " E raggio = " << c[2].GetR() << "\n";//c[2] preso a caso tanto la massa per ora è sempre uguale per ogni punto
}

void Corda::Pos_Attuale_corda() {
	cout << " Le posizioni attuali dei punti che compongono la corda sono :\n";
		for (int i = 1; i <= N_Punti; ++i) {
			cout << "N id = " << c[i].GetN_id() << " x = " << c[i].Getxf() << " y = " << c[i].Getyf()<< "\n";
		}
}

void Corda::Traccia_corda() {
	for (int i = 1; i <= N_Punti; ++i) {
		cout << " Il punto materiale con N_id = " << c[i].GetN_id() << " ha subito il seguente spostamento : \n";
		cout << "  " << c[i].Getxi() << "-->" << c[i].Getxf() << "\n";
		cout << "  " << c[i].Getyi() << "-->" << c[i].Getyf() << "\n";
	}
}


void Corda::Crea_List_corda(int i) {

	glNewList(N_Punti+1, GL_COMPILE);
	glBegin(GL_QUADS);
	glColor3f(Getcolore(0), Getcolore(1), Getcolore(2));
	glVertex3f(c[i].Getxf(),c[i].Getyf()+c[i].GetR(), 0);
	glVertex3f(c[i+1].Getxf(), c[i+1].Getyf()+c[i+1].GetR(), 0);
	glVertex3f(c[i + 1].Getxf(), c[i + 1].Getyf() - c[i + 1].GetR(), 0);
	glVertex3f(c[i].Getxf(), c[i].Getyf() - (c[i].GetR() ), 0);
	glEnd();
	glEndList();
}

void Corda::Draw_Corda() {
	
	for (int i = 1; i <= N_Punti; ++i) {
		c[i].Crea_List_Punto();
		glPushMatrix();
		glTranslated(c[i].Getxf(), c[i].Getyf(), 0);   //disegna i punti materiali 
		glCallList(c[i].GetN_id());
		glPopMatrix();
	}
	for (int i = 1; i <= N_Punti ; ++i) {
		Crea_List_corda(i);
		glPushMatrix();
		glCallList(N_Punti + 1);   //disegna i collegamenti tra i punti
		glPopMatrix();

		}
	
}