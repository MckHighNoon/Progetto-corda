#include"Punti_Materiali.h"
#include <FL/Fl.H>
#include<FL/gl.h>  

#define APP_CERCHIO 100




//costruttori
Punto_Materiale::Punto_Materiale(): R(0), N_id(0), mass(0), xi(0), xf(0), yi(0), yf(0) {
	double c[3] = { 0,0,0 }; colore[3] = c[3];
}

Punto_Materiale::Punto_Materiale(double colorer, double coloreg, double coloreb, double r, int n, double m, double xin, double yin)
	:R(r), N_id(n), mass(m),xi(xin), yi(yin), xf(xin), yf(yin) {
	colore[0] = colorer; colore[1] = coloreg; colore[2] = coloreb;
}


//getter
double Punto_Materiale::Getcolore(int n) {
	if (n == 0) return colore[n]; 
	else if (n == 1) return colore[n]; 
	else if (n == 2) return colore[n];
	else cout << "Errore dal getter del colore del punto materiale \n";
}

double Punto_Materiale::GetR() {
	return R;
}

int Punto_Materiale::GetN_id() {
	return N_id;
}

double Punto_Materiale::Getmass() {
	return mass;
}

double Punto_Materiale::Getxi() {
	return xi;
}

double Punto_Materiale::Getxf() {
	return xf;
}

double Punto_Materiale::Getyi() {
	return yi;
}

double Punto_Materiale::Getyf() {
	return yf;
}
//setter
int Punto_Materiale::Setcolore(double r, double g, double b) {
	colore[0] = r; 
	colore[1] = g;
	colore[2] = b;
	return 1;
}

int Punto_Materiale::SetR(double RR) {
	R = RR;
	return 1;
}

int Punto_Materiale::SetN_id(int n) {
	N_id = n;
	return 1;
}

int Punto_Materiale::Setmass(double m) {
	mass = m;
	return 1;
}

int Punto_Materiale::Setxi(double xin) {
	xi = xin;
	return 1;
}

int Punto_Materiale::Setxf(double xfin) {
	xf=xfin;
	return 1;
}

int Punto_Materiale::Setyi(double yin) {
	yi = yin;
	return 1;
}

int Punto_Materiale::Setyf(double yfin) {
	yf = yfin;
	return 1;
}



void Punto_Materiale::Proprieta_Punto() {
	cout << " Le proprietà del punto materiale " <<N_id << " sono le seguenti : \n";
	cout << " colore : " << colore[0] << " " << colore[1] << " " << colore[2] << "\n";
	cout << " Raggio = " << R << "\n";
	cout << " Massa = " << mass << "\n";
	cout << " E di coordinate iniziali : x = " << xi << " y = " << yi << "\n";
}

void Punto_Materiale::Pos_Attuale() {
	cout << " La posizione attuale del punto materiale con N_id = " << N_id << " si trova alle coordinate x = " << xf << " y = " << yf << "\n";
}

void Punto_Materiale::Traccia() {
	cout << " Il punto materiale con N_id = " << N_id << " ha subito il seguente spostamento : \n";
	cout << "  " << xi << "-->" << xf << "\n";
	cout << "  " << yi << "-->" << yf << "\n";
}


void Punto_Materiale:: Crea_List_Punto() {
	double r = GetR();
	glNewList(N_id, GL_COMPILE); // DA FINIRE 
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(Getcolore(0), Getcolore(1), Getcolore(2));
	glVertex3f(0, 0, 0);
	for (int i = 0; i <= APP_CERCHIO; ++i) {
		
		double t = 2 * 3.14*i / APP_CERCHIO;
		double x = r*cos(t);
		double y = r*sin(t);
		glVertex3f(x, y, 0);
	}
	glEnd();
	glEndList();
}






































