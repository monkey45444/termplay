#include "render.h"

#include "term.h"

void Render::init(){
    term::set_playmode(true);
    term::set_color(default_color, default_color);
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
        dirty_vec.assign(vec_size, UpdateState::update);
    }

    reset_brush_pos();
    for(Point p(0, 0); p.y < window_size.y; p.y+=2)
        for(p.x = 0; p.x < window_size.x; p.x++)
            update_glyph(p);
}
void Render::update_glyph(Point p){
    UpdateState& u1 = get_dirty_at(p);
    UpdateState& u2 = get_dirty_at(Point(p.x, p.y + 1));
    if(u1 == UpdateState::unchanged && u2 == UpdateState::unchanged)
        return;

    RGB& c1 = get_color_at(p);
    RGB& c2 = get_color_at(Point(p.x, p.y + 1));
    process_tile(c1, u1);
    process_tile(c2, u2);

    if(tile_fg_color != c1){
        tile_fg_color = c1;
        term::set_fg_color(c1);
    }
    if(c1 == c2){
        write_glyph(p, L'█');
    }
    else{
        if(tile_bg_color != c2){
            tile_bg_color = c2;
            term::set_bg_color(c2);
        }
        write_glyph(p, L'▀');
    }
}
void Render::process_tile(RGB& c, UpdateState& u){
    if(u == UpdateState::erase){
        c = default_color;
        u = UpdateState::unchanged;
    }
    else{
        u = UpdateState::erase;
    }
}

RGB& Render::get_color_at(Point p){
    return color_vec[p.x + p.y * window_size.x];
}
Render::UpdateState& Render::get_dirty_at(Point p){
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
        get_dirty_at(p) = UpdateState::update;
    }
}
