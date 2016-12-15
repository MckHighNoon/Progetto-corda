#ifndef CLASS_CORDA_HPP
#define CLASS_CORDA_HPP


#include<iostream>
#include"Punti_Materiali.h"



class Corda  {
	int N_Punti; //numero punti con cui rappresentiamo la corda
	double L;          //lunghezza totale corda
	double l;          //lunghezza sngolo pezzettino
	double k;          //costante elastica
	double colore[3];     // colore della corda
	         
	double x;         //coordinate del punto materiale  iniziale della corda 
	double y;
	Punto_Materiale c[100];
	      

public :
	//costruttori
	Corda();
	Corda(int n, double ll, double kk, double colorer, double coloreg, double coloreb, double xx, double yy);//costruttore che deduce la lunghezza totale dalla lunghezza dei singoli tratti
    Corda(int n,double ll,double kk,double colorer, double coloreg, double coloreb, double xx, double yy, double RR, double m); // costruttore in cui è possibile settare anche massa e raggio dei punti materiali
    
	void Crea_List_corda(int i);
	void Draw_Corda();


	//getter
	int GetN_Punti();
	double GetL();
	double Getl();
	double Getk();
	double Getcolore(int n);
	double Getx();
	double Getxi(int i);
	double Gety();
	double Getyi(int i);
	double GetR();            //LEGGI QUI !!!!
	double GetRi(int i);// returna il raggio dell'iesimo punto materiale dovrei farlo anche per le altre variabili e anche i setter 
	double Getmass();
	double Getmassi(int i);
	//setter
	int SetN_Punti(int n);
	int SetL(double lunghezza);
	int Setl(double ll);
	int Setk(double kk);
	int Setcolore(double r, double g, double b);// permette di settare solo il colore dei collegamenti tra i punti cioè la corda
	int SetcoloreT(double r, double g, double b);// permette di settare il colore Totale cioè dei collegamenti e dei punti materiali 
	int Setx(double xx);
	int Setxi(int i,double xx);
	int Sety(double yy);
	int Setyi(int i,double yy);
	int SetR(double RR);
	int Setmass(double m);
	//stampa
	void Proprieta_Corda(); // stampa gli attributi della corda 
	void Pos_Attuale_corda();//stampa la posizione attuale di tutti i punti materiali della corda 
	void Traccia_corda();//stampa il movimento dei punti materiali della corda 

};
#endif // !CLASS_CORDA_HPP