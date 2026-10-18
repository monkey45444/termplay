#include "render.h"

#include "term.h"

void Render::init(){
    term::set_playmode(true);
    term::reset_color();
    update();
}
void Render::terminate(){
    term::set_playmode(false);
}
void Render::update(){
    Point w_size = term::get_size();
    w_size.y *= 2;
    if(window_size != w_size){
        window_size = w_size;

        size_t vec_size = w_size.x * w_size.y;
        color_vec.resize(vec_size);
        dirty_vec.assign(vec_size, true);
    }

    reset_brush_pos();
    for(Point p(0, 0); p.y < window_size.y; p.y+=2)
        for(p.x = 0; p.x < window_size.x; p.x++){
            uint8_t& d1 = get_dirty_at(p);
            uint8_t& d2 = get_dirty_at(Point(p.x, p.y + 1));
            if(!d1 && !d2)
                continue;
            d1 = false;
            d2 = false;
            RGB c1 = get_color_at(p);
            RGB c2 = get_color_at(Point(p.x, p.y + 1));
            if(c1 == c2){
                if(tile_fg_color != c1){
                    tile_fg_color = c1;
                    term::set_fg_color(c1);
                }
                write_glyph(p, L'█');
            }
            else{
                if(tile_fg_color != c1){
                    tile_fg_color = c1;
                    term::set_fg_color(c1);
                }
                if(tile_bg_color != c2){
                    tile_bg_color = c2;
                    term::set_bg_color(c2);
                }
                write_glyph(p, L'▀');
            }
        }
}

RGB& Render::get_color_at(Point p){
    return color_vec[p.x + p.y * window_size.x];
}
uint8_t& Render::get_dirty_at(Point p){
    return dirty_vec[p.x + p.y * window_size.x];
}
void Render::write_glyph(Point p, wchar_t glyph){
    if(brush_pos != p){
        brush_pos = p;
        term::set_position(Point(p.x, p.y / 2));
    }
    term::write(glyph);
    brush_pos.x++;
    if(brush_pos.x == window_size.x){
        brush_pos.x = 0;
        brush_pos.y+=2;
    }
}
void Render::reset_brush_pos(){
    brush_pos = Point(0, 0);
    term::set_position(brush_pos);
}
char Render::get_char() const{
    return term::get_char();
}
void Render::set_color(RGB c){
    brush_color = c;
}
void Render::write(Point p){
    if(p < window_size && p >= 0){
        get_color_at(p) = brush_color;
        get_dirty_at(p) = true;
    }
}
