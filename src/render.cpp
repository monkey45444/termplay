#include "render.h"

#include "term.h"

Render::Render():
    cur_w_size(),
    brush_color(),
    brush_pos(),
    color_vec(0),
    change_vec(0){}
Render::~Render(){}

void Render::init(){
    term::set_playmode(true);
    update();
}
void Render::terminate(){
    term::set_playmode(false);
}
void Render::update(){
    Point w_size = term::get_size();
    w_size.y *= 2;
    if(cur_w_size != w_size){
        cur_w_size = w_size;

        unsigned long vec_size = w_size.x * w_size.y;
        color_vec.resize(vec_size);
        change_vec.assign(vec_size, true);
    }

    term::set_position(Point(0, 0));
    for(int y = 0; y < cur_w_size.y; y+=2)
        for(int x = 0; x < cur_w_size.x; ++x){
            bool b1 = get_change_from_vec({x, y});
            bool b2 = get_change_from_vec({x, y + 1});
            Color c1 = get_color_from_vec({x, y});
            Color c2 = get_color_from_vec({x, y + 1});
            if(c1 == c2){
                if(brush_color != c1)
                    set_color(c1);
                term::write(L'█');
            }
            else{
                Color new_c(c1.fg, c2.bg);
                if(brush_color != new_c)
                    set_color(new_c);
                term::write(L'▀');
            }
        }
}

Color& Render::get_color_from_vec(Point p){
    return color_vec[p.x + p.y * cur_w_size.x];
}
uint8_t& Render::get_change_from_vec(Point p){
    return change_vec[p.x + p.y * cur_w_size.x];
}
char Render::get_char(){
    return term::get_char();
}
void Render::set_color(Color c){
    term::set_color(c);
    brush_color = c;
}
void Render::write(int x, int y){
    write({x, y});
}
void Render::write(Point p){
    get_color_from_vec(p) = brush_color;
    get_change_from_vec(p) = true;
}
