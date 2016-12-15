#include "Fisica.h"

double Forza[2];



double Campo_Convettivo(double x, double y) {
	double Xmaxbox = 5, Xminbox = -5,
		Ymaxbox = 5, Yminbox = -5;



	if (x < 0) /*parte SX della box*/ {
		if (y < Yminbox - (2 * Yminbox / 5)) /*parte bassa*/ {
			if (x > Xminbox - Xminbox / 5) /*freccia parte bassa verso SX*/ { Forza[0] = -1; Forza[1] = 0; }
			else /*freccia parte bassa verso alto*/ { Forza[0] = 0; Forza[1] = 1; }
		}
		else {
			if (y < Ymaxbox - (2 * Ymaxbox / 5) && x < Xminbox / 2)/*corpo centrale a SX*/ { Forza[0] = 0; Forza[1] = 1; }
			else { if (y < Ymaxbox - (2 * Ymaxbox / 5) && x > Xminbox / 2) /*corpo centrale parte DX*/ { Forza[0] = 0; Forza[1] = -1; } }
		}
		if (y>Ymaxbox - (2 * Ymaxbox / 5)) /*parte alta*/ {
			if (x < Xminbox / 5) /*freccia parte alta verso DX*/ { Forza[0] = 1; Forza[1] = 0; }
			else /*freccia parte alta verso basso*/ { Forza[0] = 0; Forza[1] = -1; }
		}
	}
	else /*parte DX della box*/ {
		if (y < Yminbox - (2 * Yminbox / 5)) /*parte bassa*/ {
			if (x < Xmaxbox - Xmaxbox / 5)	/*freccia parte bassa verso DX*/ { Forza[0] = 1; Forza[1] = 0; }
			else /*freccia parte bassa verso l'alto*/ { Forza[0] = 0; Forza[1] = 1; }
		}
		else {
			if (y < Ymaxbox - (2 * Ymaxbox / 5) && x < Xmaxbox / 2) /*corpo centrale a SX*/ { Forza[0] = 0; Forza[1] = -1; }
			else { if (y < Ymaxbox - (2 * Ymaxbox / 5) && x > Xmaxbox / 2) /*corpo centrale parte DX*/ { Forza[0] = 0; Forza[1] = 1; } }
		}
		if (y>Ymaxbox - (2 * Ymaxbox / 5)) /*parte alta*/ {
			if (x > Xmaxbox / 5) /*freccia parte alta verso SX*/ { Forza[0] = -1; Forza[1] = 0; }
			else /*freccia parte alta verso basso*/ { Forza[0] = 0; Forza[1] = -1; }
		}
	}
	return 1.0;
}


void coutForza(double x, double y) {
	Campo_Convettivo(x, y);
	cout << "I valori delle componenti della forza nel punto di coordinate (" << x << ',' << y << ") sono:" << endl
		<< "Fx=" << Forza[0] << endl
		<< "Fy=" << Forza[1] << endl;
}





void Movimento(Corda corda) {
	/*int * Campo[700][700][700]; //Ipotizziamo di stare in una scatola di 1000*1000 (poi basterà fare le dovute proporzioni per riportarsi nel nostro caso)
	// for (int i = 0; i < 1000000000; ++i) { Campo[i] = new int [1000]; };		// Inizio a impostare il campo per fare una specie di moto convettivo non del tutto simmetrico (vedi disegno sul quaderno) da sbilanciare poi ulteriormente, se necessario,
	// con tutte le componenti x y z di modulo unitario. Assegno un vettore a tre componenti per ogni punto dello spazio con forza massima MaxFc in una sola direzione.


	//Bisogna adattare tutto alle dimensioni dello schermo. Anche gli spostamenti dei punti
	// --> PROBLEMA: gli spostamenti si discretizzano ma se si approssima troppo rispetto ai veri risultati numerici
	// poi abbiamo una cosa ben poco realistica in quanto a molle.
	// --> Si deve trovare un modo per classificare i punti del campo senza usare un solo array a 4 dimensioni che diventa troppo grande
	// e il prog non lo accetta (DCCCCC).






	//QUA SOTTO è TUTTO DA ADATTARE AI NUMERI EFFETTIVI CHE RIUSCIREMO A RIPRODURRE
	//Settore esterno basso
	for (int x = 0; x < 140; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 0; z < 700; ++z) { Campo[x][y][z] = new int[3]{ 0,1,0 }; } } }
	for (int x = 140; x < 700; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 0; z < 140; ++z) { Campo[x][y][z] = new int[3]{ 0,1,0 }; } } }
	for (int x = 140; x < 700; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 560; z < 700; ++z) { Campo[x][y][z] = new int[3]{ 0,1,0 }; } } }
	for (int x = 560; x < 700; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 140; z < 560; ++z) { Campo[x][y][z] = new int[3]{ 0,1,0 }; } } }

	//Settore alto
	for (int x = 0; x < 233; ++x) { for (int y = 466; y < 700; ++y) { for (int z = 0; z < 700; ++z) { Campo[x][y][z] = new int[3]{ 1,-1,1 }; } } }
	for (int x = 466; x < 700; ++x) { for (int y = 466; y < 700; ++y) { for (int z = 0; z < 700; ++z) { Campo[x][y][z] = new int[3]{ 1,-1,1 }; } } }
	for (int x = 233; x < 466; ++x) { for (int y = 466; y < 700; ++y) { for (int z = 0; z < 466; ++z) { Campo[x][y][z] = new int[3]{ 0,-1, 1 }; } } }
	for (int x = 233; x < 466; ++x) { for (int y = 466; y < 700; ++y) { for (int z = 466; z < 700; ++z) { Campo[x][y][z] = new int[3]{ 0,-1, -1 }; } } }

	//Settore interno basso
	for (int x = 140; x < 280; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 140; z < 560; ++z) { Campo[x][y][z] = new int[3]{ 0,-1, 0 }; } } }
	for (int x = 420; x < 560; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 140; z < 560; ++z) { Campo[x][y][z] = new int[3]{ 0,-1, 0 }; } } }
	for (int x = 280; x < 420; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 280; z < 560; ++z) { Campo[x][y][z] = new int[3]{ 0,-1, 0 }; } } }
	for (int x = 280; x < 420; ++x) { for (int y = 0; y < 466; ++y) { for (int z = 140; z < 280; ++z) { Campo[x][y][z] = new int[3]{ 0, 1, 0 }; } } }

	// Comincio con le iterazioni (da aggiungere interazione con pareti o diversi delta t)

	int Iterazioni = 1000;
	double l0 = corda.Getl();
	int Npunti = corda.GetN_Punti();
	int ** Pos = new int *[Npunti];
	double * Dist = new double[Npunti - 1];
	double ** Vel = new double *[Npunti];
	double Acc[3];
	for (int i = 0; i < Npunti; ++i) { Pos[i] = new int[3];  Vel[i] = new double[3]; };
	int ExpPos[3];

	for (int i = 0; i < Iterazioni; ++i)
	{
	for (int i = 0; i < Npunti; ++i) {
	Pos[i] = new int[3]{ corda.Getxi(i), corda.Getyi(i), corda.Getzi(i) };
	Vel[i] = new double[3]{ corda.GetVxi(i), corda.GetVyi(i), corda.GetVzi(i) };
	}
	for (int i = 0; i < Npunti - 1; ++i) { Dist[i] = sqrt(pow((Pos[0][i] - Pos[0][i + 1]), 2) + pow((Pos[1][i] - Pos[1][i + 1]), 2) + pow((Pos[2][i] - Pos[2][i + 1]), 2)); }



	for (int punto = 1; punto < Npunti; ++punto)
	{
	for (int coord = 0; coord < 2; ++coord) {
	Acc[coord] = Campo[Pos[punto][0]][Pos[punto][1]][Pos[punto][2]][0] +
	corda.Getk()*((Pos[punto - 1][0] - Pos[punto][0])*(1 - l0 / Dist[punto - 1]) + (Pos[punto][0] - Pos[punto + 1][0])*(1 - l0 / Dist[punto - 1]));
	}

	corda.SetVxi(Vel[punto][0] + Acc[0], punto),
	corda.SetVyi(Vel[punto][1] + Acc[1], punto),
	corda.SetVzi(Vel[punto][2] + Acc[2], punto);


	corda.Setxi(Pos[punto][0] + Vel[punto][0] + 0.5*Acc[0], punto),
	corda.Setyi(Pos[punto][1] + Vel[punto][1] + 0.5*Acc[1], punto),
	corda.Setzi(Pos[punto][2] + Vel[punto][2] + 0.5*Acc[2], punto);

	// cose da risolvere ora: impenetrabilità della corda -> se un punto si scontro contro un altro, possiamo gestire tutto con un urto elastico
	// (e analogamente faremo con i muri), ma come famo a impedire che una molla sia attraversata da un'altro punto/molla?
	// --> Escludere tutto ciò che sta dietro ai punti e alle molle come soluzione possibile e aggiornare di conseguenza la posizione.
	// è una soluzione poco fisica (1) ? evito di fatto degli urti, che però in genere suppongo essere altamente anelastici
	//	--> Penso che così si faciliti la formazione dei nodi -> ad ogni urto si sostituisce uno "scivolamento" in prossimità della corda
	// è una soluzione poco fisica(2)--> si dovrebbe escludere tutto l'angolo solido come proiezione ma intanto per facilitare il calcolo può bastare
	// la proiezione --> dovrebbe bastare se la lunghezza di riposo è di pochi pixel e lo spostamento è piccolo rispetto alla lunghezza di riposo,
	// come effettivamente dovrebbe essere per avere una situazione fisicamente plausibile per una corda non troppo elastica.
	// Risolto in maniera approssimativa il problema urto che penetra corda o molla. --> SEGUE UNA SOLUZIONE MIGLIORE
	// Per evitare del tutto il problema comprendenendo anche il problema compenetrazione tra molle bisogna escludere dalla soluzione dei piani.
	// I piani sono individuati da due assi. Gli assi sono individuati da:
	// - il punto P in esame e i due punti contigui a P (vogliamo considerare solo i punti collegati più vicini considerando minore di l0 lo spostamento generico del punto)
	// - altri N punti vicini a P (vicinanza da determinare; simile a prima, max l0, 2l0) e dai punti contingui ad essi.
	// Ogni volta che un punto sta per attraversare il piano, lo si ferma subito prima e
	// gli si da per l'iterazione dopo una spinta come se si fosse scontrato contro un ostacolo parzialmente anelastico,
	// come sarebbe da fare anche con i muri poi (perde un tot di energia, es. 50%).
	// L'energia persa finisce sul punto/molla(due punti) colpiti come addizionale forza!


	}
	}*/
}
