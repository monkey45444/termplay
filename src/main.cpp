#include "render.h"

int main(){
    Render r;
    r.init();
    r.set_color(Color(Color::fg_green, Color::bg_black));
    for(int i = 0; i < 10; ++i){
        r.write(i, 0);
    }
    r.update();
    r.get_char();
    r.terminate();
}
