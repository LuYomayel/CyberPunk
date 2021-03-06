#include "inGame.h"
#include <iostream>
#include <string.h>
using namespace std;
/*void inGame::carga_juego(, NPC guardia, Armas arma1)
{
    ///jugador.inicia();
    //al_create_mouse_cursor("IMG/cursor.bmp", 0, 0);
    // cargamos imagenes
    /*loading = al_load_bitmap("IMG/intro.bmp");
    menu1 = al_load_bitmap("IMG/menu1.bmp");
    menu2 = al_load_bitmap("IMG/menu2.bmp");
    menu3 = al_load_bitmap("IMG/menu3.bmp");
    menu4 = al_load_bitmap("IMG/menu4.bmp");
    menu5 = al_load_bitmap("IMG/menu5.bmp");
    menu6 = al_load_bitmap("IMG/menu6.bmp");
    cursor = al_load_bitmap("IMG/cursor.bmp");
    // cargamos imagenes del primer escenario
    fondo = al_load_bitmap("IMG/Arena.bmp");
    //choque = al_load_bitmap("IMG/Arena-choque.bmp");
    //alto = al_load_bitmap("IMG/Arena-Magenta.bmp");
    
    ALLEGRO_BITMAP* p1 = jugador.getBitmap();
    ALLEGRO_BITMAP* npc = guardia.getBitmap();
    ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
    
    /*jugador.inicia(arma1);
    guardia.inicia();
}*/

/*void inGame::teclado(jugador jugador, int x, int y, Armas arma1, ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events,
    bool done, int& sourceX, int& sourceY, int& dir, bool draw, bool active, int moveSpeed) {
    al_wait_for_event(event_queue, &events);
    al_get_keyboard_state(&keyState);
    if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        done = true;
    }
    else if (events.type == ALLEGRO_EVENT_TIMER) {
        active = true;
        if (al_key_down(&keyState, ALLEGRO_KEY_S)) {
            //jugador.setpy(moveSpeed);
            y += moveSpeed;
            dir = 0;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_W)) {
            //jugador.setmy(moveSpeed);
            y -= moveSpeed;
            dir = 3;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
            moveSpeed = 5;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_D)) {
            //jugador.setmx(moveSpeed);
            x -= moveSpeed;
            dir = 2;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_A)) {
            //jugador.setpx(moveSpeed);
            x += moveSpeed;
            dir = 1;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_LCTRL && jugador.getAtk() == 0)) {
            jugador.setAtk(1);
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_LCTRL && jugador.getAtk() == 1)) {
            jugador.setAtk(2);
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
        {
            done = true;
        }
        else {
            active = false;
        }
    }
    if (active) {
        sourceX += al_get_bitmap_width(jugador.getBitmap()) / 3;
        //sourceX += al_get_bitmap_width(arma1.getBitmap()) / 6;
    }
    else {
        sourceX = 32;
    }
    if (sourceX >= al_get_bitmap_width(jugador.getBitmap())) {
        sourceX = 0;
    }
    sourceY = dir;
    draw = true;
    if (draw) {
        jugador.setx(x);
        jugador.sety(y);
        arma1.setx(jugador.getx());
        arma1.sety(jugador.gety());
    }
    return;
}*/

void inGame::actualiza_juego(jugador jugador)
{
    int ax, ay;
    ax = jugador.getx();
    ay = jugador.gety();
    

    bool choca = false;
    float px = jugador.getx();
    float py = jugador.gety();
    
}

void inGame::pinta_jugador(jugador jugador, float x, float y)
{
    jugador.pinta(x, y);
}

void inGame::pinta_fondo()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(fondo, 0, 0, NULL);
    //al_flip_display();
}

void inGame::pinta_npc(NPC& guardia, float x, float y) {
    guardia.pinta2(x, y);
}

void inGame::pinta_esqueleto(Esqueleto& esqueleto, float x, float y)
{
    esqueleto.pinta2(x, y);
}

void inGame::pinta_arma(Armas arma1, float sourceX, float sourceY, float x, float y) {
    arma1.pinta(sourceX, sourceY, x, y);
    //arma1.draw(sourcex, sourcey, x,y);
}

//ac?? vamos a declarar las colisiones
bool inGame::colision(float x, float y, float npc_x, float npc_y, float width, float height) {
    
    if (x + width < npc_x || x > npc_x + width || y + height < npc_y || y > npc_y + height) {
        return false;
    }
    else
    {
    return true;
    }
    

}

/*bool inGame::Rect(jugador& jugador, FRect* elnpc) {
    if (jugador.rect->Intersects(elnpc.npcRect)) {
        if (jugador.rect->Bottom >= elnpc.npcRect->Top && jugador.prevRect->Bottom <= elnpc.npcRect->Top)
        {
            jugador.y = elnpc.gety() - 32;
        }
        else if (jugador.rect->Bottom <= elnpc.npcRect->Top && jugador.prevRect->Bottom >= elnpc.npcRect->Top) {
            jugador.y = elnpc.gety();
        }
        else if (jugador.rect->Right >= elnpc.npcRect->Left && jugador.prevRect->Right <= elnpc.npcRect->Left) {
            jugador.x = elnpc.getx() - 32;
        }
        else if (jugador.rect->Right <= elnpc.npcRect->Left && jugador.prevRect->Right >= elnpc.npcRect->Left) {
            jugador.x = elnpc.getx();
        }
    }
    return true;
}*/

bool inGame::rect(jugador& jugador,FRect* npcRect, NPC& elnpc) {

    if (jugador.rect->Intersects(npcRect) && (!elnpc.ha_muerto())) {
        if (jugador.rect->Bottom >= npcRect->Top && jugador.prevRect->Bottom <= npcRect->Top)
        {
            jugador.y = elnpc.gety() - 32;
        }
        else if (jugador.rect->Top <= npcRect->Bottom && jugador.prevRect->Top >= npcRect->Bottom) {
            jugador.y = elnpc.gety() +32;
        }
        else if (jugador.rect->Right >= npcRect->Left && jugador.prevRect->Right <= npcRect->Left) {
            jugador.x = elnpc.getx()- 32;
        }
        else if (jugador.rect->Left <= npcRect->Right && jugador.prevRect->Left >= npcRect->Right) {
            jugador.x = elnpc.getx() + 32;
        }
    }
    return true;
}

bool inGame::guardRect(Guardia& npc, FRect* npcRect, NPC& elnpc) {

    if (npc.npcRect->Intersects(npcRect) && (!elnpc.ha_muerto())) {
        if (npc.npcRect->Bottom >= npcRect->Top && npc.prevNpcRect->Bottom <= npcRect->Top)
        {
            npc.y = elnpc.gety() - 33;
        }
        else if (npc.npcRect->Top <= npcRect->Bottom && npc.prevNpcRect->Top >= npcRect->Bottom) {
            npc.y = elnpc.gety() + 33;
        }
        else if (npc.npcRect->Right >= npcRect->Left && npc.prevNpcRect->Right <= npcRect->Left) {
            npc.x = elnpc.getx() - 33;
        }
        else if (npc.npcRect->Left <= npcRect->Right && npc.prevNpcRect->Left >= npcRect->Right) {
            npc.x = elnpc.getx() + 33;
        }
    }
    return true;
}

bool inGame::centiRect(Centinela& npc, FRect* npcRect, NPC& elnpc) {

    if (npc.npcRect->Intersects(npcRect) && (!elnpc.ha_muerto())) {
        if (npc.npcRect->Bottom >= npcRect->Top && npc.prevNpcRect->Bottom <= npcRect->Top)
        {
            npc.y = elnpc.gety() - 33;
        }
        else if (npc.npcRect->Top <= npcRect->Bottom && npc.prevNpcRect->Top >= npcRect->Bottom) {
            npc.y = elnpc.gety() + 33;
        }
        else if (npc.npcRect->Right >= npcRect->Left && npc.prevNpcRect->Right <= npcRect->Left) {
            npc.x = elnpc.getx() - 33;
        }
        else if (npc.npcRect->Left <= npcRect->Right && npc.prevNpcRect->Left >= npcRect->Right) {
            npc.x = elnpc.getx() + 33;
        }
    }
    return true;
}

bool inGame::esqueRect(Esqueleto& npc, FRect* npcRect, NPC& elnpc) {

    if (npc.npcRect->Intersects(npcRect) && (!elnpc.ha_muerto())) {
        if (npc.npcRect->Bottom >= npcRect->Top && npc.prevNpcRect->Bottom <= npcRect->Top)
        {
            npc.y = elnpc.gety() - 33;
        }
        else if (npc.npcRect->Top <= npcRect->Bottom && npc.prevNpcRect->Top >= npcRect->Bottom) {
            npc.y = elnpc.gety() + 33;
        }
        else if (npc.npcRect->Right >= npcRect->Left && npc.prevNpcRect->Right <= npcRect->Left) {
            npc.x = elnpc.getx() - 33;
        }
        else if (npc.npcRect->Left <= npcRect->Right && npc.prevNpcRect->Left >= npcRect->Right) {
            npc.x = elnpc.getx() + 33;
        }
    }
    return true;
}

bool inGame::cerca(float x, float y, float npc_x, float npc_y, float width, float height, float dir, float moveSpeed) {

    if ((x + width)+2 < npc_x || x > (npc_x + width)+2 || (y + height)+2 < npc_y || y > (npc_y + height)+2) {
        return false;
    }
    else
    {
        return true;
    }
}


void inGame::dmg_npc(jugador& jugador, InterfaceNPC &guardia)
{
    if ((jugador.atacando() == true) && (cerca(jugador.getx(), jugador.gety(), guardia.getx(), guardia.gety(), 30, 46, jugador.getDir(), jugador.getSpeed())==true)
        && (guardia.ha_muerto()==false) /*&& (miraHacia(jugador, guardia) == true*/)
    {
        if ((miraHaciaAbajo(jugador, guardia) == true) || (miraHaciaArriba(jugador, guardia) == true) || (miraHaciaDerecha(jugador, guardia) == true) || (miraHaciaIzquierda(jugador, guardia) == true)) {
            sufreDano = al_load_sample("IMG/10.wav");
            int xn = 10 + rand() % 2;
            //cout << "entre" << endl;
            //jugador.no_ataca();
            //sonido_espada_da();
            al_play_sample(sufreDano, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            guardia.sufre_dano(xn, guardia);
            //cout << "tiene :" << guardia.getVidaAct() << "de vida" << endl;
           //al_play_sample
        }

    }
}

void inGame::dmg_jugador(jugador &jugador, InterfaceNPC& guardia) {

    if ((guardia.atacando() == true) && (cerca(jugador.getx(), jugador.gety(), guardia.getx(), guardia.gety(), 30, 46, jugador.getDir(), jugador.getSpeed()) == true)
        && (jugador.ha_muerto() == false) && (guardia.ha_muerto() == false) && (guardia.getAtaca() == 1))
    {
            
            sufreDano2 = al_load_sample("IMG/12.wav");
            int xn = guardia.getDmg() + rand() % 2;
            //int xn = guardia.getDmg() + 50;
            // guardia.getDmg() +
            //cout << "entre" << endl;
            //jugador.no_ataca();
            //sonido_espada_da();
            jugador.sufre_dano(xn, jugador);
            al_play_sample(sufreDano2, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            //cout << "ESTOY ACA" << jugador.getVida() << endl;
            //cout << "tiene :" << jugador.getVida() << "de vida" << endl;
            guardia.setDir(QUIETO);
    }
}

void inGame::dmg_esqueleto(jugador& jugador, InterfaceNPC& guardia)
{
}

bool inGame::miraHaciaArriba(jugador &jugador, InterfaceNPC& guardia){
    
        if ((jugador.getDir() == 0) && ((guardia.gety() +5) > jugador.gety())) return true;
        else return false; 
}

bool inGame::miraHaciaAbajo(jugador& jugador, InterfaceNPC& guardia) {

    if ((jugador.getDir() == 3) && ((guardia.gety() -5) < jugador.gety())) return true;
    else return false;
}

bool inGame::miraHaciaDerecha(jugador& jugador, InterfaceNPC& guardia) {

    if ((jugador.getDir() == 2) && (guardia.getx() > jugador.getx())) return true;
    else return false;
}

bool inGame::miraHaciaIzquierda(jugador& jugador, InterfaceNPC& guardia) {

    if ((jugador.getDir() == 1) && (guardia.getx() < jugador.getx())) return true;
    else return false;
}

void inGame::GAME() {

    const float FPS = 30;
    const float frameFPS = 0.4;



    ///Creamos el objeto de eventos
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    //registramos los eventos de la wea
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
    ALLEGRO_TIMER* frameTimer = al_create_timer(1.3 / FPS);
    ALLEGRO_TIMER* npcTimer = al_create_timer(1.8 / FPS);
    ALLEGRO_TIMER* rondasTimer = al_create_timer(1.0 / FPS);
    ALLEGRO_TIMER* scoreTimer = al_create_timer(1.0 / FPS);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));
    
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    /// todo referente a puntuaciones
    //puntuacion _Score;
    fTop5 = al_load_font("IMG/BROADW.ttf", 18, 0);
    punt = al_load_font("IMG/BROADW.ttf", 36, 0);
    structPuntuacion* scr;
    char s[3] = { 'x','x','x' };
    char s2[3] = { 'x','x','x' };
    puntuacion Score;
    bool getting_username = true;


    scr = new structPuntuacion[5];

    /*jugador jugador;
    NPC guardia;
    Armas arma1;
    jugador.inicia();
    guardia.inicia();
    //eljuego.carga_juego(jugador, guardia, arma1);*/

    al_start_timer(timer);
    al_start_timer(frameTimer);
    al_start_timer(npcTimer);

    int x = 0, y = 0;

    bool done = false;
    bool gamed = false;

    ALLEGRO_EVENT events;
    ALLEGRO_KEYBOARD_STATE keyState;

    top5Score();

    while (!done) {
        al_register_event_source(event_queue, al_get_mouse_event_source());
        al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keyState);

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
            x = events.mouse.x;
            y = events.mouse.y;

        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (events.mouse.button & 1);
            else if (events.mouse.button & 2);
        }
        //comienza el jueguin
        if (!done && !gamed) {
            menu_principal(keyState, event_queue, events, timer, frameTimer, npcTimer, rondasTimer, scoreTimer, done, gamed, x, y,scr,s,s2,Score, getting_username);
        }
        else if (gamed) {
            //                gamed = false;
            menu_top5(keyState, event_queue, events, timer, frameTimer, npcTimer, rondasTimer, scoreTimer, done, gamed, x, y,scr,s,s2, Score, getting_username);


        }



        if (done && !gamed) {
            done = false;
            gamed = true;

            juego_inicia(keyState, event_queue, events, timer, frameTimer, npcTimer, rondasTimer, scoreTimer, done, Score);
        }
    }
    al_destroy_event_queue(event_queue);
    //this->~inGame();
}



void inGame::menu_principal(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer, ALLEGRO_TIMER* npcTimer, ALLEGRO_TIMER* rondasTimer, ALLEGRO_TIMER* scoreTimer, bool& done, bool& gamed, float x, float y, structPuntuacion* scr, char* s, char* s2, puntuacion& Score, bool &getting_username) {

    

    if (getting_username)
    {
        switch (events.keyboard.keycode)
        {
            case ALLEGRO_KEY_BACKSPACE:
                  // take a character off the end
                  //    if (Score.getSKN() == s);
                s2[2] = 'x';
                s2[1] = 'x';
                s2[0] = 'x';

                  break;
        case ALLEGRO_KEY_ENTER:

            if (!(Score.getSKN() == s))
            {
                getting_username = false;
                Score.setSKN(s2);
            }
            break;
        default:

            if ((events.keyboard.unichar <= 125) && (events.keyboard.unichar >= 32) && s2[0] == s[0]) {
                s2[0] = events.keyboard.unichar;
            }

            else if ((events.keyboard.unichar <= 125) && (events.keyboard.unichar >= 32) && s2[1] == s[1] && s2[0] != s[0]) {
                s2[1] = events.keyboard.unichar;
            }

            else if ((events.keyboard.unichar <= 125) && (events.keyboard.unichar >= 32) && s2[2] == s[2] && s2[0] != s[0] && s2[1] != s[1]) {
                s2[2] = events.keyboard.unichar;
            }

            break;
        }
    }

    if (x > 970 && x < 1120 &&
        y>360 && y < 420) {
        al_clear_to_color(vacio);
        al_draw_bitmap(menu3, 0, 0, NULL);
                
        if (!getting_username) {
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Nombre Ingresado!");
            al_flip_display();
        }
        else
        {
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Ingrese su nombre y presione enter");
        }
        al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 150, ALLEGRO_ALIGN_CENTRE, s2);

        al_flip_display();
        if (events.mouse.button & 1) {
            done = true;
        }
    }

    else if (x > 970 && x < 1260 &&
        y>460 && y < 510) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu4, 0, 0, NULL);

        if (!getting_username) {
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Nombre Ingresado!");
            al_flip_display();
        }
        else
        {
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Ingrese su nombre y presione enter");
        }
        al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 150, ALLEGRO_ALIGN_CENTRE, s2);

        al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            gamed = true;
            menu_top5(keyState, event_queue, events, timer, frameTimer, npcTimer, rondasTimer, scoreTimer, done, gamed, x, y,scr,s,s2, Score, getting_username);
        }
    }

    else if (x > 388 && x < 921 &&
        y>408 && y < 590) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu2, 0, 0, NULL);

        if(!getting_username) {
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Nombre Ingresado!");
            al_flip_display();
        }
    else
    {
        al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Ingrese su nombre y presione enter");
    }
    al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 150, ALLEGRO_ALIGN_CENTRE, s2);

    al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }

    else if (x > 970 && x < 1262 &&
        y>531 && y < 594) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu5, 0, 0, NULL);

        if (!getting_username) {
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Nombre Ingresado!");
            al_flip_display();
        }
        else
        {
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Ingrese su nombre y presione enter");
        }
        al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 150, ALLEGRO_ALIGN_CENTRE, s2);

        al_flip_display();
        if (events.mouse.button & 1) {

            while (done == false) {

                {
                    menu_opciones(event_queue, events, done, x, y);

                }
            }
        }

        else if (x > 970 && x < 1105 &&
            y>624 && y < 688) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(menu6, 0, 0, NULL);

            if (!getting_username) {
                al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Nombre Ingresado!");
                al_flip_display();
            }
            else
            {
                al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "Ingrese su nombre y presione enter");
            }
            al_draw_text(fTop5, al_map_rgb(255, 255, 255), 400, 150, ALLEGRO_ALIGN_CENTRE, s2);

            al_flip_display();
            if (events.mouse.button & 1) {

                //a = true;   //funcion jugar a desarrolar
                done = true;
            }
        }

        else {
            
        }

    }

}

void inGame::menu_top5(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer, ALLEGRO_TIMER* npcTimer, ALLEGRO_TIMER* rondasTimer, ALLEGRO_TIMER* scoreTimer, bool& done, bool& gamed, float x, float y, structPuntuacion *scr, char *s, char*s2, puntuacion& Score, bool &getting_username) {
  
   // puntuacion Score;
    

    int pos = 0;

    for (int i = 0; i < 5; i++) {


        scr[i] = leerDeDiscoOrdenado(pos++);

        if (scr[i].puntos < 0 || scr[i].puntos > 4000) {
            scr[i].puntos = 0;
            scr[i].secElapsed = 0;
            scr[i].minElapsed = 0;
            for (int x = 0; x < 3; x++) {
                scr[i].SKN[x] = 'E';
            }
        }
    }
    pos = 0;

    /*nt vPuntos[5];


    int vSec[5];


    int vMin[5];


    char vSKN[5][3];
    */



    //top5Score();
    
    al_register_event_source(event_queue, al_get_mouse_event_source());

    

        if (x > 350 && x < 950 &&
            y>625 && y < 675) {
            al_clear_to_color(vacio);
            al_draw_bitmap(top_vae, 0, 0, NULL);

            

            ///pos1
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 320, ALLEGRO_ALIGN_CENTER, "1??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 320, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 320, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[2]);

            ///pos2
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 360, ALLEGRO_ALIGN_CENTER, "2??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 360, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 360, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[2]);

            ///pos3
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 400, ALLEGRO_ALIGN_CENTER, "3??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 400, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 400, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[2]);

            ///pos4
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 440, ALLEGRO_ALIGN_CENTER, "4??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 440, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 440, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[2]);

            ///pos5
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 480, ALLEGRO_ALIGN_CENTER, "5??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 480, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 480, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[2]);

            al_draw_text(punt, al_map_rgb(640, 540, 0), 640, 520, ALLEGRO_ALIGN_CENTER, "Puntos Actuales:");
            al_draw_textf(punt, al_map_rgb(640, 540, 0), 640, 560, ALLEGRO_ALIGN_CENTER, "%d", Score.getPuntos());

            al_flip_display();
            if (events.mouse.button & 1) {
                gamed = false;
                juego_inicia(keyState, event_queue, events, timer, frameTimer, npcTimer, rondasTimer, scoreTimer, done, Score);
            }
        }

        if (x > 1100 && x < 1280 &&
            y>680 && y < 720) {
            al_clear_to_color(vacio);
            al_draw_bitmap(top_salir, 0, 0, NULL);

            ///pos1
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 320, ALLEGRO_ALIGN_CENTER, "1??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 320, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 320, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[2]);

            ///pos2
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 360, ALLEGRO_ALIGN_CENTER, "2??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 360, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 360, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[2]);

            ///pos3
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 400, ALLEGRO_ALIGN_CENTER, "3??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 400, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 400, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[2]);

            ///pos4
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 440, ALLEGRO_ALIGN_CENTER, "4??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 440, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 440, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[2]);

            ///pos5
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 480, ALLEGRO_ALIGN_CENTER, "5??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 480, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 480, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[2]);

            al_draw_text(punt, al_map_rgb(640, 540, 0), 640, 520, ALLEGRO_ALIGN_CENTER, "Puntos Actuales:");
            al_draw_textf(punt, al_map_rgb(640, 540, 0), 640, 560, ALLEGRO_ALIGN_CENTER, "%d", Score.getPuntos());


            al_flip_display();
            if (events.mouse.button & 1) {
                done = true;
            }
        }

        else {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(top_normal, 0, 0, NULL);

            ///pos1
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 320, ALLEGRO_ALIGN_CENTER, "1??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 320, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 320, ALLEGRO_ALIGN_CENTER, "%d", scr[0].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 320, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 320, ALLEGRO_ALIGN_CENTER, "%c", scr[0].SKN[2]);

            ///pos2
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 360, ALLEGRO_ALIGN_CENTER, "2??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 360, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 360, ALLEGRO_ALIGN_CENTER, "%d", scr[1].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 360, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 360, ALLEGRO_ALIGN_CENTER, "%c", scr[1].SKN[2]);

            ///pos3
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 400, ALLEGRO_ALIGN_CENTER, "3??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 400, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 400, ALLEGRO_ALIGN_CENTER, "%d", scr[2].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 400, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 400, ALLEGRO_ALIGN_CENTER, "%c", scr[2].SKN[2]);

            ///pos4
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 440, ALLEGRO_ALIGN_CENTER, "4??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 440, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 440, ALLEGRO_ALIGN_CENTER, "%d", scr[3].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 440, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 440, ALLEGRO_ALIGN_CENTER, "%c", scr[3].SKN[2]);

            ///pos5
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 364, 480, ALLEGRO_ALIGN_CENTER, "5??");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 440, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].puntos);
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 540, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].minElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 590, 480, ALLEGRO_ALIGN_RIGHT, "min");
            al_draw_textf(fTop5, al_map_rgb(640, 540, 0), 640, 480, ALLEGRO_ALIGN_CENTER, "%d", scr[4].secElapsed);
            al_draw_text(fTop5, al_map_rgb(640, 540, 0), 690, 480, ALLEGRO_ALIGN_RIGHT, "sec");
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 740, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[0]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 840, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[1]);
            al_draw_textf(fTop5, al_map_rgb(240, 540, 0), 940, 480, ALLEGRO_ALIGN_CENTER, "%c", scr[4].SKN[2]);

            al_draw_text(punt, al_map_rgb(640, 540, 0), 640, 520, ALLEGRO_ALIGN_CENTER, "Puntos Actuales:");
            al_draw_textf(punt, al_map_rgb(640, 540, 0), 640, 560, ALLEGRO_ALIGN_CENTER, "%d", Score.getPuntos());


            al_flip_display();

        }
}

void inGame::juego_inicia(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer, ALLEGRO_TIMER* npcTimer, ALLEGRO_TIMER* rondasTimer, ALLEGRO_TIMER* scoreTimer, bool& done, puntuacion& Score) {
    jugador jugador;
    ///puntuacion Score;
    structPuntuacion scr;
    char _SKN[3] = { 'x', 'x', 'x' };

    //NPC guardia;
    Guardia A(100);
    Guardia B(200);
    Guardia C(200);
    Guardia D(150);
    Guardia E(125);
    Guardia F(280);
    Guardia G(210);
    Guardia H(300);
    Guardia I(165);
    Guardia J(190);
    Guardia K(600);
    Esqueleto L(1000);
    Centinela O(1000);
    Centinela P(1000);

    Armas arma1;
    //tileEngine pruebita;

    ///vector ronda 1
    NPC* vecNPC1[] = { &A, &B, &C };
    //vector ronda 2
    NPC* vecNPC2[] = { &F, &G, &H,&L };
    //NPC* vecEsq[] = {&L,&O,&P};
    //vector ronda 3
    NPC* vecNPC3[] = { &I, &J, &K ,&O,&P };

    ///Vectores para analizar muertes y sumar puntajes
    NPC* vecNPCPuntaje1[] = { &A, &B, &C, &D, &E, &F, &G, &H, &I, &J, &K };
    NPC* vecNPCPuntaje2[] = { &L };
    NPC* vecNPCPuntaje3[] = { &O, &P };




    al_unregister_event_source(event_queue, al_get_mouse_event_source());
    // ALLEGRO_BITMAP* p1 = jugador.getBitmap();
     //ALLEGRO_BITMAP* npc = guardia.getBitmap();
    ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
    ALLEGRO_SAMPLE* song;
    ALLEGRO_SAMPLE_INSTANCE* midi;
    ///this->carga_juego();

    song = al_load_sample("IMG/1.mid");

    midi = al_create_sample_instance(song);
    al_set_sample_instance_playmode(midi, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(midi, al_get_default_mixer());


    jugador.inicia();
    float x = jugador.getx();
    float y = jugador.getx();
    arma1.inicia(x, y);

    A.inicia(600, 500);
    B.inicia(500, 600);
    C.inicia(400, 200);
    D.inicia(430, 200);
    E.inicia(470, 200);
    F.inicia(550, 200);
    G.inicia(630, 200);
    H.inicia(150, 200);
    I.inicia(350, 200);
    J.inicia(320, 200);
    K.inicia(280, 200);
    L.inicia(500, 250);
    O.inicia(250, 500);
    P.inicia(400, 550);
    Rondas rondita;
    

    bool a = false;
    bool draw = true, active = false;
    bool empezo = false;
    jugador.setSpeed(2.5);
    float sourceX = 32, sourceY = 0, dir = sourceY, dirA = sourceY;
    float sx = 0, sy = 0;
    int cont = 0, cont1 = 0;
    int posX = 0, posY = 0;
    while (!a) {
        actualiza_juego(jugador);
        al_clear_to_color(vacio);
        al_play_sample_instance(midi);


        ///bool done = true;
        bool estanVivos = true;
        bool estanVivos2 = true;
        bool estanVivos3 = true;


        bool doned = true;

        while (doned)
        {
            if (draw) {
                //pruebita.dibujarMapa(pruebita.loadMap());

                pinta_fondo();

                if (!jugador.ha_muerto()) {


                    jugador.teclado(keyState, event_queue, events, done, sourceX, sourceY, dir, draw, active, jugador.getSpeed(), timer, frameTimer);
                    pinta_jugador(jugador, sourceX, sourceY);
                    arma1.cmd(jugador, sourceX, sourceY);
                    arma1.update();
                    pinta_arma(arma1, sourceX, sourceY, jugador.getx(), jugador.gety());

                }
                else if (jugador.ha_muerto()) {

                    jugador.teclado(keyState, event_queue, events, done, sourceX, sourceY, dir, draw, active, jugador.getSpeed(), timer, frameTimer);
                    if (rondita.getComienza() == true) {
                        jugador.setRevivir(true);

                        if (estanVivos == false) {
                            for (InterfaceNPC* obj : vecNPC1) {

                                obj->setReviveNPC(true);
                                obj->setNose0();
                            }
                            estanVivos = true;
                            cont1 = 0;
                        }

                        if (estanVivos2 == false) {
                            for (InterfaceNPC* obj : vecNPC2) {

                                obj->setReviveNPC(true);
                                obj->setNose0();
                            }
                            estanVivos2 = true;
                            cont1 = 0;
                        }

                        if (estanVivos3 == false) {
                            for (InterfaceNPC* obj : vecNPC3) {

                                obj->setReviveNPC(true);
                                obj->setNose0();
                            }
                            estanVivos3 = true;
                            cont1 = 0;
                        }
                    }
                }

                /*if (jugador.ha_muerto()) {
                    jugador.~jugador();
                    arma1.~Armas();
                }*/

                checkRondas(rondasTimer, rondita, jugador, estanVivos, estanVivos2, estanVivos3);
                updateRondas(rondasTimer, rondita, jugador);
                drawRondas(rondasTimer, rondita, jugador, estanVivos);

                Score.cmd(rondita, jugador);
                Score.draw();
                Score.update(rondita, scoreTimer);




                if (rondita.getNumRonda() == 1 && rondita.getComienza() == true && rondita.getFinaliza() == false && !(jugador.ha_muerto())) {
                    for (InterfaceNPC* obj : vecNPC1) {
                        //for (int i = 0; i < 3; i++ ) {
                        InterfaceNPC& rA = *obj;


                        if (!(jugador.ha_muerto())) {
                            dmg_jugador(jugador, rA);
                            dmg_npc(jugador, rA);
                        }
                        else {
                            rondita.setFinaliza(true);
                            rondita.setComienza(false);
                            jugador.setEmpezarRonda(false);
                        }


                        if (!(obj->ha_muerto())) {
                            if (cont == 8) cont = 0;


                            obj->cmd(jugador, cerca(jugador.getx(), jugador.gety(), obj->getx(), obj->gety(), 30, 46, dir, jugador.getSpeed()), jugador.getEmpezarRonda());

                            /*if (obj->getDir() == RIGHT)obj->setDir(RIGHT);
                            if (obj->getDir() == LEFT)obj->setDir(LEFT);
                            if (obj->getDir() == DOWN)obj->setDir(DOWN);
                            if (obj->getDir() == UP)obj->setDir(UP);*/


                            obj->update(npcTimer);

                            //rect jugador
                            rect(jugador, A.npcRect, A);
                            rect(jugador, B.npcRect, B);
                            rect(jugador, C.npcRect, C);

                            ///rect npc
                            guardRect(A, B.npcRect, B);
                            guardRect(A, C.npcRect, C);
                            guardRect(B, A.npcRect, A);
                            guardRect(B, C.npcRect, C);
                            guardRect(C, A.npcRect, A);
                            guardRect(C, B.npcRect, B);

                            obj->draw(sx, sy, cont);
                            cont++;
                        }
                        else {
                            obj->nose();
                            if (obj->getMuerte() == 1) {
                                jugador.sumaEXP();
                                Score.setPuntosPP(obj->getPuntaje());
                                cont1++;
                            }
                            if (cont1 == 3) {
                                estanVivos = false;

                                rondita.setFinaliza(!(estanVivos));
                                rondita.setComienza(estanVivos);

                                if (rondita.getComienza() == false && rondita.getFinaliza() == true) {
                                    jugador.setEmpezarRonda(false);
                                }

                                cont1 = 0;
                                
                            }
                        }
                        posX = obj->getx();
                        posY = obj->gety();
                        // Score.cmd(rondita, jugador, cont1);

                    }
                }


                else if (rondita.getNumRonda() == 2 && rondita.getComienza() == true && rondita.getFinaliza() == false && !(jugador.ha_muerto())) {
                    for (InterfaceNPC* obj : vecNPC2) {

                        InterfaceNPC& rA = *obj;
                        //obj->inicia(500,320);
                        if (!(jugador.ha_muerto())) {
                            dmg_jugador(jugador, rA);
                            dmg_npc(jugador, rA);
                        }
                        else {
                            rondita.setFinaliza(true);
                            rondita.setComienza(false);
                            jugador.setEmpezarRonda(false);
                        }


                        if (!(obj->ha_muerto())) {
                            if (cont == 8) cont = 0;
                            obj->cmd(jugador, cerca(jugador.getx(), jugador.gety(), obj->getx(), obj->gety(), 30, 46, dir, jugador.getSpeed()), jugador.getEmpezarRonda());
                            obj->update(npcTimer);

                            //rect jugador
                            rect(jugador, F.npcRect, F);
                            rect(jugador, G.npcRect, G);
                            rect(jugador, H.npcRect, H);
                            rect(jugador, L.npcRect, L);


                            ///rect npc
                            guardRect(F, G.npcRect, G);
                            guardRect(F, H.npcRect, H);
                            guardRect(F, L.npcRect, L);

                            guardRect(G, H.npcRect, H);
                            guardRect(G, F.npcRect, F);
                            guardRect(G, L.npcRect, L);

                            guardRect(H, F.npcRect, F);
                            guardRect(H, G.npcRect, G);
                            guardRect(H, L.npcRect, L);

                            esqueRect(L, G.npcRect, G);
                            esqueRect(L, F.npcRect, F);
                            esqueRect(L, H.npcRect, H);

                            obj->draw(sx, sy, cont);
                            cont++;
                        }
                        else {
                            obj->nose();
                            if (obj->getMuerte() == 1) {
                                cont1++;
                                jugador.sumaEXP();
                                Score.setPuntosPP(obj->getPuntaje());
                            }
                            if (cont1 == 4) {
                                estanVivos2 = false;

                                rondita.setFinaliza(true);
                                rondita.setComienza(false);
                                if (rondita.getComienza() == false && rondita.getFinaliza() == true) {
                                    jugador.setEmpezarRonda(false);
                                }
                                cont1 = 0;
                            }
                        }
                        posX = obj->getx();
                        posY = obj->gety();
                    }
                }

                else if (rondita.getNumRonda() == 3 && rondita.getComienza() == true && rondita.getFinaliza() == false && !(jugador.ha_muerto())) {
                    for (InterfaceNPC* obj : vecNPC3) {

                        InterfaceNPC& rA = *obj;
                        if (!(jugador.ha_muerto())) {
                            dmg_jugador(jugador, rA);
                            dmg_npc(jugador, rA);
                        }
                        else {
                            rondita.setFinaliza(true);
                            rondita.setComienza(false);
                            jugador.setEmpezarRonda(false);
                        }

                        /*if (colision(jugador.getx(), jugador.gety(), obj->getx(), obj->gety(), 30, 46) && !(obj->ha_muerto())) {
                            if (dir == 0) jugador.setmy(jugador.getSpeed());
                            else if (dir == 1) jugador.setpx(jugador.getSpeed());
                            else if (dir == 2) jugador.setmx(jugador.getSpeed());
                            else if (dir == 3) jugador.setpy(jugador.getSpeed());
                            //cout << guardia.getVida() << endl;
                        }
                        if (colision(obj->getx(), obj->gety(), posX, posY, 30, 46)) {
                            obj->posiciona(obj->getx() - 1, obj->gety() - 1);
                        }*/

                        if (!(obj->ha_muerto())) {
                            if (cont == 8) cont = 0;
                            obj->cmd(jugador, cerca(jugador.getx(), jugador.gety(), obj->getx(), obj->gety(), 30, 46, dir, jugador.getSpeed()), jugador.getEmpezarRonda());
                            obj->update(npcTimer);

                            //rect jugador
                            rect(jugador, I.npcRect, I);
                            rect(jugador, J.npcRect, J);
                            rect(jugador, K.npcRect, K);
                            rect(jugador, O.npcRect, O);
                            rect(jugador, P.npcRect, P);

                            ///rect npc
                            guardRect(I, J.npcRect, J);
                            guardRect(I, K.npcRect, K);
                            guardRect(I, O.npcRect, O);
                            guardRect(I, P.npcRect, P);

                            guardRect(J, I.npcRect, I);
                            guardRect(J, K.npcRect, K);
                            guardRect(J, O.npcRect, O);
                            guardRect(J, P.npcRect, P);

                            guardRect(J, I.npcRect, I);
                            guardRect(J, K.npcRect, K);
                            guardRect(J, O.npcRect, O);
                            guardRect(J, P.npcRect, P);

                            centiRect(O, I.npcRect, I);
                            centiRect(O, J.npcRect, J);
                            centiRect(O, K.npcRect, K);
                            centiRect(O, P.npcRect, P);

                            centiRect(P, I.npcRect, I);
                            centiRect(P, J.npcRect, J);
                            centiRect(P, K.npcRect, K);
                            centiRect(P, O.npcRect, O);

                            obj->draw(sx, sy, cont);
                            cont++;
                        }
                        else {
                            obj->nose();
                            if (obj->getMuerte() == 1) {
                                cont1++;
                                jugador.sumaEXP();
                                Score.setPuntosPP(obj->getPuntaje());

                                
                            }
                            if (cont1 == 5) {
                                estanVivos3 = false;
                                rondita.setFinaliza(true);
                                rondita.setComienza(false);
                                jugador.setEmpezarRonda(false);
                                

                                scr = prasePuntuacion(Score.getSKN(), Score.getPuntos(), Score.getSecElapsed(), Score.getMinElapsed());
                                grabarPuntuacion(scr);
                                top5Score;
                                

                                cont1 = 0;
                                if (rondita.getComienza() == false && rondita.getFinaliza() == true && jugador.getEmpezarRonda() == false && done == false) {
                                    doned = false;
                                    a = true;
                                    draw = false;
                                }
                            }
                        }
                        posX = obj->getx();
                        posY = obj->gety();
                    }
                }
               
                    al_flip_display();
                }
            }
        }
        rondita.setNumRonda(0);

    }

inGame::~inGame() {
}
void inGame::menu_opciones(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, bool& done, float x, float y) {



    if (x > 320 && x < 860 &&
        y>290 && y < 350) {
        al_clear_to_color(vacio);
        al_draw_bitmap(opciones2, 0, 0, NULL);
        al_flip_display();
    }

    else if (x > 320 && x < 750 &&
        y>400 && y < 460) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(opciones3, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {
        }
    }

    else if (x > 850 && x < 1250 &&
        y>580 && y < 600) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(opciones4, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {
        }
    }
}

void inGame::checkRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador &jugador, bool estanVivos, bool estanVivos2, bool estanVivos3)
{   

    bool daaale;

    if (jugador.getEmpezarRonda() == false) daaale = false;

    else if (jugador.getEmpezarRonda() == true) daaale = true;

    /*else if (rondita.getNumRonda() == 2 || rondita.getNumRonda() == 3 && rondita.getFinaliza() == true) {
        daaale = false;
        jugador.setEmpezarRonda(daaale);
    }*/

    rondita.cmd(timer, jugador, estanVivos, estanVivos2, estanVivos3, daaale);

        //if (rondita.getNumRonda() == 2 && daaale == true) rondita.setFinaliza(false);

       // if (!(jugador.ha_muerto()) && rondita.getNumRonda() == 1) {
            //rondita.setComienza(daaale);
            //rondita.cmd(timer, jugador, estanVivos, estanVivos2, estanVivos3, daaale);
        /*}
        else if (!(jugador.ha_muerto()) && rondita.getNumRonda() == 2) {
            //rondita.setComienza(daaale);
            rondita.cmd(timer,  jugador, estanVivos, estanVivos2, estanVivos3, daaale); 
        }
        else if (!(jugador.ha_muerto()) && rondita.getNumRonda() == 3) {
            //rondita.setComienza(daaale);
            rondita.cmd(timer, jugador, estanVivos, estanVivos2, estanVivos3, daaale);
        }*/
    
}

void inGame::updateRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador &jugador)
{
    rondita.update(timer, jugador);
}

void inGame::drawRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador &jugador, bool estanVivos)
{
    rondita.draw(jugador, estanVivos);
}
bool inGame::Dano(jugador& jugador) {

    if (jugador.atacando() == true) return true;
    else return false;
}

int inGame::suma_puntos(bool dano) {
    int puntos1 = 0;
    if (dano == true) {

        puntos1 += 100;
    }



    return puntos1;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  