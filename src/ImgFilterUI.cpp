// generated by Fast Light User Interface Designer (fluid) version 1.0011


#include "ImgFilterUI.h"

  // The following static members were originally non-static
  // made them static because they were being corrupted for
  // mysterious reasons in VC 7.0 release mode (not 6.0 or debug mode).
  // It's ok to make them static in this
  // program because there is ever only one instance of ImgFilterUI.
  // begin hack
  Fl_Window *ImgFilterUI::mainWindow=NULL; // hack
  Fl_Output *ImgFilterUI::mouseInfo=NULL; // hack
  Fl_Menu_Bar *ImgFilterUI::mainMenu=NULL; // hack
  ImgView *ImgFilterUI::imgView=NULL; // hack
  // end hack

inline void ImgFilterUI::cb_Open_i(Fl_Menu_*, void*) {
  imgView->OpenImage();
}
void ImgFilterUI::cb_Open(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_Open_i(o,v);
}

inline void ImgFilterUI::cb_Save_i(Fl_Menu_*, void*) {
  imgView->SaveContour();
}
void ImgFilterUI::cb_Save(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_Save_i(o,v);
}

inline void ImgFilterUI::cb_Save1_i(Fl_Menu_*, void*) {
  imgView->SaveMask();
}
void ImgFilterUI::cb_Save1(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_Save1_i(o,v);
}

inline void ImgFilterUI::cb_Exit_i(Fl_Menu_*, void*) {
  imgView->HideAll();
hide();
}
void ImgFilterUI::cb_Exit(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_Exit_i(o,v);
}

inline void ImgFilterUI::cb_Filter_i(Fl_Menu_*, void*) {
  imgView->TryFilter();
}
void ImgFilterUI::cb_Filter(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_Filter_i(o,v);
}

inline void ImgFilterUI::cb_Brush_i(Fl_Menu_*, void*) {
  imgView->TryBrush();
}
void ImgFilterUI::cb_Brush(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_Brush_i(o,v);
}



inline void ImgFilterUI::cb_Scissor_i(Fl_Menu_*, void*) {
  imgView->TryScissor();
}
void ImgFilterUI::cb_Scissor(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_Scissor_i(o,v);
}

inline void ImgFilterUI::cb_My_i(Fl_Menu_*, void*) {
  imgView->AboutMe();
}
void ImgFilterUI::cb_My(Fl_Menu_* o, void* v) {
  ((ImgFilterUI*)(o->parent()->user_data()))->cb_My_i(o,v);
}

Fl_Menu_Item ImgFilterUI::menu_mainMenu[] = {
 {"&File", 0,  0, 0, 64, 0, 0, 14, 0},
 {"&Open...", 0,  (Fl_Callback*)ImgFilterUI::cb_Open, 0, 0, 0, 0, 14, 0},
 {"Save &Contour", 0,  (Fl_Callback*)ImgFilterUI::cb_Save, 0, 0, 0, 0, 14, 0},
 {"Save &Mask", 0,  (Fl_Callback*)ImgFilterUI::cb_Save1, 0, 0, 0, 0, 14, 0},
 {"&Exit", 0,  (Fl_Callback*)ImgFilterUI::cb_Exit, 0, 0, 0, 0, 14, 0},
 {0},
 {"&Tools", 0,  0, 0, 64, 0, 0, 14, 0},
 {"&Brush", 0,  (Fl_Callback*)ImgFilterUI::cb_Brush, 0, 0, 0, 0, 14, 0},
 {"&Scissor", 0,  (Fl_Callback*)ImgFilterUI::cb_Scissor, 0, 0, 0, 0, 14, 0},
 {"&Filter", 0,  (Fl_Callback*)ImgFilterUI::cb_Filter, 0, 0, 0, 0, 14, 0},
 {0},
 {"&Help", 0,  0, 0, 64, 0, 0, 14, 0},
 {"&My Intelligent Scissor?", 0,  (Fl_Callback*)ImgFilterUI::cb_My, 0, 0, 0, 0, 14, 0},
 {0},
 {0}
};

ImgFilterUI::ImgFilterUI() {
  Fl_Window* w;
  { Fl_Window* o = mainWindow = new Fl_Window(445, 439, "Intelligent Scissor UI");
    w = o;
    o->user_data((void*)(this));
    mouseInfo = new Fl_Output(92, 411, 353, 28, "mouse status:");
    { Fl_Menu_Bar* o = mainMenu = new Fl_Menu_Bar(0, 0, 444, 28, "mainMenu");
      o->menu(menu_mainMenu);
    }
    { ImgView* o = imgView = new ImgView(0, 32, 444, 376);
      o->box(FL_DOWN_BOX);
    }
    o->end();
  }
}

void ImgFilterUI::show() {
  imgView->mouseInfo = mouseInfo;
imgView->mainMenu = mainMenu;
mainWindow->resizable(imgView);
mainWindow->show();
}

void ImgFilterUI::hide() {
  mainWindow->hide();
}