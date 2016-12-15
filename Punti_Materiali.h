#ifndef PUNTI_MATERIALI_HPP
#define PUNTI_MATERIALI_HPP



#include<iostream>
using namespace std;



class Punto_Materiale {
	double colore[3];    //colore del punto
	double R;         // raggio del punto 
	int N_id;         // numero identificativo del punto
	double mass;      //massa
	double xi;        //coordinate iniziali e finali del punto per tenere traccia dei movimenti 
	double yi;
	double xf;
	double yf;

public :
	//costruttori
	Punto_Materiale();
	Punto_Materiale(double colorer,double coloreg, double coloreb, double r, int n, double m, double xin, double yin);
	
	void Crea_List_Punto();
		
	//getter
	double Getcolore(int n);	
	double GetR();
	int GetN_id();
	double Getmass();
    double Getxi();
	double Getyi();
	double Getxf();
	double Getyf();
	//setter
	int Setcolore(double r, double g, double b);
	int SetR(double RR);
	int SetN_id(int N);
	int Setmass(double m);
	int Setxi(double xin);
	int Setyi(double yin);
	int Setxf(double xfin);
	int Setyf(double yfin);
	//stampa
	void Proprieta_Punto();   //couta tutte le prop del punto materiale
	void Pos_Attuale(); //couta la pos attuale del punto materiale
	void Traccia();      //couta lo spostamento 
};
#endif // !PUNTI_MATERIALI HPP
