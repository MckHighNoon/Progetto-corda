#ifndef FINESTRA_HPP
#define FINESTRA_HPP
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include"Frame.h"
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Multiline_Output.H>


Fl_Window *finestra;
Frame *gg;
Fl_Button *button;
Fl_Value_Slider *LUNGHEZZA_CORDA, *RAGGIO, *TRASLAZIONE_X, *zoom;
Fl_Multiline_Output *linee;


void exit_callback(Fl_Widget *);
void LUNGHEZZA_CORDA_callback(Fl_Widget *);
void RAGGIO_callback(Fl_Widget *);
void TRASLAZIONE_X_callback(Fl_Widget *);
void zoom_callback(Fl_Widget *);


void Crea_Finestra();

#endif // !FINESTRA_HPP