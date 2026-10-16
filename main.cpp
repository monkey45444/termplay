#include "term.h"

int main(){
    term::set_playmode(true);
    term::set_color(Color::fg_green);
    term::set_position(Point{10,10});
    term::write(L"Super monkey");
    term::get_char();
    term::set_playmode(false);
}
