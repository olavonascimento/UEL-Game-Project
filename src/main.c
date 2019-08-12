#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include "game_state.h"
#include "menu_screen.h"
#include "game_screen.h"
#include "events.h"
#include "player_ship.h"


// Inicia todas os recursos do Allegro necessários
bool allegro_init() {
    if(!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!");
        return false;
    }
    if(!al_init_image_addon()) {
        fprintf(stderr, "Failed to initialize Allegro image addon!");
        return false;
    }
    if(!al_install_keyboard()) {
        fprintf(stderr, "Failed to initialize Allegro keyboard addon!");
        return false;
    }
    if(!al_init_font_addon()) {
        fprintf(stderr, "Failed to initialize Allegro font addon!");
        return false;
    }
    if(!al_init_ttf_addon()) {
        fprintf(stderr, "Failed to initialize Allegro ttf addon!");
        return false;
    }
    return true;
}

int main() {
    if(!allegro_init())
        return 1;

    // Cria e carrega as informações do jogo
    GameState game;
    if(!init_game_state(&game))
        return 1;
    DEBUG_PRINT("Loaded game state...\n");

    GameMenu menu;
    if(!init_game_menu(&menu))
        return 1;

    // Inicia o timer que atualiza a tela
    al_start_timer(game.screen_timer);
 
    while(game.running) {
        DEBUG_PRINT("Loaded game menu...\n");
        wait_menu_selection(&menu, &game);
        DEBUG_PRINT("Game menu exited...\n");

        if(game.current_screen == GAME_SCREEN) {
            // Cria e carrega a nave do jogador
            PlayerShip player_ship;
            if(!init_player_ship(&player_ship))
                return 1;
            DEBUG_PRINT("Loaded player ship...\n");

            while(player_ship.alive) 
                process_player_events(&game, &player_ship);

            free_player_resources(&player_ship);
        }
    }

    DEBUG_PRINT("Stopping game...\n");
    free_menu_resources(&menu);
    free_game_state_resources(&game);

    return 0;
}