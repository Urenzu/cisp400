#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);
private:
    // data
    Open_polyline lines;

    // widgets
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button cmenu_button;
    Menu style_menu;
    Button smenu_button;

    void change(Color c) { lines.set_color(c); }
    void style_change(Line_style l) { lines.set_style(l); }

    void show_cmenu();  // and hide style menu
    void hide_cmenu();  // and hide style menu
    void hide_smenu() { style_menu.hide(); smenu_button.show(); }

    // actions invoked by callbacks
    void red_pressed() { change(Color::red); hide_cmenu(); }
    void blue_pressed() { change(Color::blue); hide_cmenu(); }
    void black_pressed() { change(Color::black); hide_cmenu(); }
    void cmenu_pressed() { cmenu_button.hide(); show_cmenu(); }
    void solid_pressed() { style_change(Line_style(Line_style::solid)); hide_smenu(); }
    void dash_pressed() { style_change(Line_style(Line_style::dash)); hide_smenu(); }
    void dot_pressed() { style_change(Line_style(Line_style::dot)); hide_smenu(); }
    void smenu_pressed() { smenu_button.hide(); style_menu.show(); }
    void next();
    void quit();

    // callback functions
    static void cb_red(Address,Address);
    static void cb_blue(Address,Address);
    static void cb_black(Address,Address);
    static void cb_cmenu(Address,Address);
    static void cb_solid(Address,Address);
    static void cb_dash(Address,Address);
    static void cb_dot(Address,Address);
    static void cb_smenu(Address,Address);
    static void cb_next(Address,Address);
    static void cb_quit(Address,Address);
};