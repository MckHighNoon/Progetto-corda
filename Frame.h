#ifndef FRAME_HPP
#define FRAME_HPP
#include <FL/Fl_Gl_Window.H>
#include"Class_Corda.h"
#include<iostream>
using namespace std;
class Frame : public Fl_Gl_Window {
public:
	double LUNGHEZZA_CORDA, RAGGIO, TRASLAZIONE_X, zoom;
	void draw();
	Frame(int x, int y, int w, int h, const char *l = 0) : Fl_Gl_Window(x, y, w, h, l) {}

};
#endif // !FRAME_HPP

