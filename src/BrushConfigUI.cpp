// generated by Fast Light User Interface Designer (fluid) version 1.0011

#include "BrushConfigUI.h"

inline void BrushConfigUI::cb_round_i(Fl_Round_Button*, void*) {
  imgView->UpdateBrushConfig();
}
void BrushConfigUI::cb_round(Fl_Round_Button* o, void* v) {
  ((BrushConfigUI*)(o->parent()->parent()->user_data()))->cb_round_i(o,v);
}

inline void BrushConfigUI::cb_square_i(Fl_Check_Button*, void*) {
  imgView->UpdateBrushConfig();
}
void BrushConfigUI::cb_square(Fl_Check_Button* o, void* v) {
  ((BrushConfigUI*)(o->parent()->parent()->user_data()))->cb_square_i(o,v);
}

inline void BrushConfigUI::cb_brushSize_i(Fl_Value_Slider*, void*) {
  imgView->UpdateBrushConfig();
}
void BrushConfigUI::cb_brushSize(Fl_Value_Slider* o, void* v) {
  ((BrushConfigUI*)(o->parent()->user_data()))->cb_brushSize_i(o,v);
}

inline void BrushConfigUI::cb_brushOpacity_i(Fl_Value_Slider*, void*) {
  imgView->UpdateBrushConfig();
}
void BrushConfigUI::cb_brushOpacity(Fl_Value_Slider* o, void* v) {
  ((BrushConfigUI*)(o->parent()->user_data()))->cb_brushOpacity_i(o,v);
}

inline void BrushConfigUI::cb_Clean_i(Fl_Button*, void*) {
  imgView->CleanBrushSelection();
}
void BrushConfigUI::cb_Clean(Fl_Button* o, void* v) {
  ((BrushConfigUI*)(o->parent()->user_data()))->cb_Clean_i(o,v);
}

inline void BrushConfigUI::cb_Close_i(Fl_Button*, void*) {
  hide();
}
void BrushConfigUI::cb_Close(Fl_Button* o, void* v) {
  ((BrushConfigUI*)(o->parent()->user_data()))->cb_Close_i(o,v);
}

BrushConfigUI::BrushConfigUI() {
  Fl_Window* w;
  { Fl_Window* o = mainWindow = new Fl_Window(234, 116, "Brush Property");
    w = o;
    o->user_data((void*)(this));
    { Fl_Group* o = new Fl_Group(5, 25, 120, 55, "Brush Type:");
      o->box(FL_ENGRAVED_FRAME);
      { Fl_Round_Button* o = round = new Fl_Round_Button(9, 30, 111, 25, "Round Brush");
        o->type(102);
        o->down_box(FL_ROUND_DOWN_BOX);
        o->callback((Fl_Callback*)cb_round);
      }
      { Fl_Check_Button* o = square = new Fl_Check_Button(6, 50, 111, 28, "Square Brush");
        o->type(102);
        o->down_box(FL_DIAMOND_DOWN_BOX);
        o->callback((Fl_Callback*)cb_square);
      }
      o->end();
    }
    { Fl_Value_Slider* o = brushSize = new Fl_Value_Slider(140, 25, 90, 20, "Brush Size:");
      o->type(1);
      o->maximum(20);
      o->step(1);
      o->value(10);
      o->callback((Fl_Callback*)cb_brushSize);
      o->align(FL_ALIGN_TOP);
      o->when(FL_WHEN_RELEASE);
    }
    { Fl_Value_Slider* o = brushOpacity = new Fl_Value_Slider(140, 60, 90, 19, "Brush Opacity:");
      o->type(1);
      o->value(1);
      o->callback((Fl_Callback*)cb_brushOpacity);
      o->align(FL_ALIGN_TOP);
      o->when(FL_WHEN_RELEASE);
    }
    { Fl_Button* o = new Fl_Button(5, 90, 107, 25, "Clean All");
      o->callback((Fl_Callback*)cb_Clean);
    }
    { Fl_Button* o = new Fl_Button(128, 90, 102, 25, "Close");
      o->callback((Fl_Callback*)cb_Close);
    }
    o->end();
  }
}

void BrushConfigUI::show() {
  mainWindow->show();
}

void BrushConfigUI::hide() {
  mainWindow->hide();
}
