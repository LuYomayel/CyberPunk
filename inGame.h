#pragma once
#include "NPC.h"
#include "jugador.h"
#include "Armas.h"
#include "TileEngine.h"
#include"Esqueleto.h"
#include "Guardia.h"
#include "Rondas.h"
#include"Centinela.h"
#include "puntuacion.h"
#include "structPuntuacion.h"

/*#ifndef INGAME_H_INCLUDED
#define INGAME_H_INCLUDED*/
//#include "allegro5/allegro.h"
//ALLEGRO_BITMAP* choque;
//ALLEGRO_BITMAP* alto;

class inGame {
    private:
        
        ALLEGRO_BITMAP* loading = al_load_bitmap("IMG/intro.bmp");
        ALLEGRO_BITMAP* menu1 = al_load_bitmap("IMG/menu1.bmp");
        ALLEGRO_BITMAP* menu2 = al_load_bitmap("IMG/menu2.bmp");
        ALLEGRO_BITMAP* menu3 = al_load_bitmap("IMG/menu3.bmp");
        ALLEGRO_BITMAP* menu4 = al_load_bitmap("IMG/menu4.bmp");
        ALLEGRO_BITMAP* menu5 = al_load_bitmap("IMG/menu5.bmp");
        ALLEGRO_BITMAP* menu6 = al_load_bitmap("IMG/menu6.bmp");
        ALLEGRO_BITMAP* cursor = al_load_bitmap("IMG/cursor.bmp");
        ALLEGRO_BITMAP* sonido1 = al_load_bitmap("IMG/sonido1.bmp");
        ALLEGRO_BITMAP* sonido2 = al_load_bitmap("IMG/sonido2.bmp");
        ALLEGRO_BITMAP* sonido3 = al_load_bitmap("IMG/sonido3.bmp");
        ALLEGRO_BITMAP* sonnido4 = al_load_bitmap("IMG/sonido4.bmp");
        ALLEGRO_BITMAP* opciones1 = al_load_bitmap("IMG/opciones1.bmp");
        ALLEGRO_BITMAP* opciones2 = al_load_bitmap("IMG/opciones2.bmp");
        ALLEGRO_BITMAP* opciones3 = al_load_bitmap("IMG/opciones3.bmp");
        ALLEGRO_BITMAP* opciones4 = al_load_bitmap("IMG/opciones4.bmp");
        ALLEGRO_BITMAP* controles1 = al_load_bitmap("IMG/controles1.bmp");
        ALLEGRO_BITMAP* controles2 = al_load_bitmap("IMG/controles.bmp");
        ALLEGRO_BITMAP* top_normal = al_load_bitmap("IMG/top_normal.bmp");
        ALLEGRO_BITMAP* top_salir = al_load_bitmap("IMG/top_salir.bmp");
        ALLEGRO_BITMAP* top_vae = al_load_bitmap("IMG/top_VAE.bmp");
        ALLEGRO_COLOR vacio = al_map_rgb(0, 0, 0);
        ALLEGRO_SAMPLE* sufreDano;
        ALLEGRO_SAMPLE* sufreDano2;

        //puntuaciones
        ALLEGRO_FONT* fTop5;
        ALLEGRO_FONT* punt;
        ALLEGRO_USTR* input = al_ustr_new("");

    public:
        void GAME();
        int encima, debajo, izquierda, derecha;
        ALLEGRO_BITMAP* fondo = al_load_bitmap("IMG/Arena.bmp");
        ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
        //Metodos de pintura
        void pinta_fondo();
        void pinta_jugador(jugador jugador, float x, float y);
        void pinta_npc(NPC &guardia, float x, float y);
        void pinta_esqueleto(Esqueleto &esqueleto,float x,float y);
        void pinta_arma(Armas arma1, float sourceX, float sourceY, float x, float y);
        //Metodos de gameplay
        void actualiza_juego(jugador jugador);
        void juego_inicia(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer, ALLEGRO_TIMER* npcTimer, ALLEGRO_TIMER* rondasTimer, ALLEGRO_TIMER* scoreTimer, bool&done, puntuacion& Score);
        void menu_top5(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer, ALLEGRO_TIMER* npcTimer, ALLEGRO_TIMER* rondasTimer, ALLEGRO_TIMER* scoreTimer, bool& done, bool& gamed, float x, float y, structPuntuacion* scr, char* s, char* s2, puntuacion &Score, bool & getting_username);
        void menu_principal(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer, ALLEGRO_TIMER* npcTimer, ALLEGRO_TIMER* rondasTimer, ALLEGRO_TIMER* scoreTimer, bool& done, bool& gamed, float x, float y, structPuntuacion* scr, char* s, char* s2, puntuacion &Score, bool & getting_username);
        bool colision(float x, float y, float npc_x, float npc_y, float width, float height);
        bool rect(jugador& jugador, FRect* npcRect, NPC& elnpc);
        bool guardRect(Guardia& npc, FRect* npcRect, NPC& elnpc);
        bool centiRect(Centinela& npc, FRect* npcRect, NPC& elnpc);
        bool esqueRect(Esqueleto& npc, FRect* npcRect, NPC& elnpc);
        bool cerca(float x, float y, float npc_x, float npc_y, float width, float height, float dir, float moveSpeed);
        void dmg_npc(jugador& jugador, InterfaceNPC &guardia);
        void dmg_jugador(jugador& jugador, InterfaceNPC &guardia);
        void dmg_esqueleto(jugador& jugador, InterfaceNPC& guardia);
        bool miraHaciaArriba(jugador &jugador, InterfaceNPC& guardia);
        bool miraHaciaAbajo(jugador& jugador, InterfaceNPC& guardia);
        bool miraHaciaIzquierda(jugador& jugador, InterfaceNPC& guardia );
        bool miraHaciaDerecha(jugador& jugador, InterfaceNPC& guardia );
        void menu_opciones(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, bool& done, float x, float y);
        void checkRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador& jugador, bool estanVivos, bool estanVivos2, bool estanVivos3);
        void updateRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador &jugador);
        void drawRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador &jugador, bool estanVivos);
        bool Dano(jugador& jugador);
        int suma_puntos(bool dano);
        ~inGame();
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          