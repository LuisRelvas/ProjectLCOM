#include "menu.h"
#include "lcom/vbe.h"
#include "../game.h"

extern uint8_t scancode;
extern uint8_t byte_position;
SystemState systemState = RUNNING;
MenuState menuState = START;
extern Mouse_Info_Struct mouse_info_s;
extern vbe_mode_info_t mode_info;
extern real_time_mode_info time_mode_info;
int gameplayCounter = 200;
bool is_processing = false; 

Sprite *mouse;
Sprite *hand;
Sprite *teste;
Sprite *logo;
Sprite *quitButton;
Sprite *quitButtonPressed;
Sprite *button1;
Sprite *button2;
Sprite *button3;
Sprite *button4;
Sprite *number1;
Sprite *number2;
Sprite *number3;
Sprite *number4;
Sprite *number5;
Sprite *number6;
Sprite *number7;
Sprite *number8;
Sprite *back;
Sprite *back_anim1;
Sprite *back_anim2;
Sprite *back_anim3;
Sprite *back_anim4;
Sprite *game;
Sprite *start;
Sprite *hard;
Sprite *easy;
Sprite *medium;
Sprite *quit;
Sprite *Start;
Sprite *Quit;
Sprite *Easy;
Sprite *Medium;
Sprite *Hard;
Sprite *score0;
Sprite *score1; 
Sprite *score2; 
Sprite *score3; 
Sprite *score4; 
Sprite *score5; 
Sprite *score6;
Sprite *score7;
Sprite *score8;
Sprite *score9;
Sprite *player_1_xpm;
Sprite *player_2_xpm;
Sprite *player_1_menu; 
Sprite *player_2_menu;
Sprite *victory;


int timer_interrupts = 0;

void start_sprites()
{
    mouse = initiate_xpm((xpm_map_t)mouse_xpm);
    hand = initiate_xpm((xpm_map_t)hand_xpm);
    teste = initiate_xpm((xpm_map_t)teste_xpm);
    logo = initiate_xpm((xpm_map_t)logo_xpm);
    number1 = initiate_xpm((xpm_map_t)number1_xpm);
    number2 = initiate_xpm((xpm_map_t)number2_xpm);
    number3 = initiate_xpm((xpm_map_t)number3_xpm);
    number4 = initiate_xpm((xpm_map_t)number4_xpm);
    number5 = initiate_xpm((xpm_map_t)number5_xpm);
    number6 = initiate_xpm((xpm_map_t)number6_xpm);
    number7 = initiate_xpm((xpm_map_t)number7_xpm);
    number8 = initiate_xpm((xpm_map_t)number8_xpm);
    back = initiate_xpm((xpm_map_t)back_xpm);
    game = initiate_xpm((xpm_map_t)game_xpm);
    start = initiate_xpm((xpm_map_t)start_xpm);
    easy = initiate_xpm((xpm_map_t)easy_xpm);
    medium = initiate_xpm((xpm_map_t)medium_xpm);
    hard = initiate_xpm((xpm_map_t)hard_xpm);
    quit = initiate_xpm((xpm_map_t)quit_xpm);
    quitButton = initiate_xpm((xpm_map_t)quitButton_xpm);
    quitButtonPressed = initiate_xpm((xpm_map_t)quitButtonPressed_xpm);
    easy = initiate_xpm((xpm_map_t)easy_xpm);
    medium = initiate_xpm((xpm_map_t)medium_xpm);
    hard = initiate_xpm((xpm_map_t)hard_xpm);
    quit = initiate_xpm((xpm_map_t)quit_xpm);
    start = initiate_xpm((xpm_map_t)start_xpm);
    back_anim1 = initiate_xpm((xpm_map_t)back_anim1_xpm);
    back_anim2 = initiate_xpm((xpm_map_t)back_anim2_xpm);
    back_anim3 = initiate_xpm((xpm_map_t)back_anim3_xpm);
    back_anim4 = initiate_xpm((xpm_map_t)back_anim4_xpm);
    Start = initiate_xpm((xpm_map_t)Start_xpm);
    Quit = initiate_xpm((xpm_map_t)Quit_xpm);
    Easy = initiate_xpm((xpm_map_t)Easy_xpm);
    Medium = initiate_xpm((xpm_map_t)Medium_xpm);
    Hard = initiate_xpm((xpm_map_t)Hard_xpm);
    score0 = initiate_xpm((xpm_map_t)score_0_xpm);
    score1 = initiate_xpm((xpm_map_t)score_1_xpm);
    score2 = initiate_xpm((xpm_map_t)score_2_xpm);
    score3 = initiate_xpm((xpm_map_t)score_3_xpm);
    score4 = initiate_xpm((xpm_map_t)score_4_xpm);
    score5 = initiate_xpm((xpm_map_t)score_5_xpm);
    score6 = initiate_xpm((xpm_map_t)score_6_xpm);
    score7 = initiate_xpm((xpm_map_t)score_7_xpm);
    score8 = initiate_xpm((xpm_map_t)score_8_xpm);
    score9 = initiate_xpm((xpm_map_t)score_9_xpm);
    player_1_xpm = initiate_xpm((xpm_map_t)player1_xpm);
    player_2_xpm = initiate_xpm((xpm_map_t)player2_xpm);
    player_1_menu = initiate_xpm((xpm_map_t)_1player_xpm);
    player_2_menu = initiate_xpm((xpm_map_t)_2player_xpm);
    victory = initiate_xpm((xpm_map_t)victory_xpm);


}

void del_sprites()
{
    del_sprite(game);
    del_sprite(mouse);
    del_sprite(hand);
    del_sprite(teste);
    del_sprite(number1);
    del_sprite(number2);
    del_sprite(number3);
    del_sprite(number4);
    del_sprite(number5);
    del_sprite(number6);
    del_sprite(number7);
    del_sprite(back);
    del_sprite(quitButton);
    del_sprite(quitButtonPressed);
    del_sprite(back);
    del_sprite(easy);
    del_sprite(medium);
    del_sprite(hard);
    del_sprite(quit);
    del_sprite(start);
    del_sprite(back_anim1);
    del_sprite(back_anim2);
    del_sprite(back_anim3);
    del_sprite(back_anim4);
    del_sprite(Start);
    del_sprite(Quit);
    del_sprite(Easy);
    del_sprite(Medium);
    del_sprite(Hard);
    del_sprite(score0);
    del_sprite(score1);
    del_sprite(score2);
    del_sprite(score3);
    del_sprite(score4);
    del_sprite(score5);
    del_sprite(score6);
    del_sprite(score7);
    del_sprite(score8);
    del_sprite(score9);
    del_sprite(player_1_xpm);
    del_sprite(player_2_xpm);
    del_sprite(player_1_menu);
    del_sprite(player_2_menu);
    del_sprite(victory);
}

void update_timer_frame()
{
    if (DOUBLE_BUFFER)
        swap_buffers();
    timer_interrupts++;
    if (timer_interrupts % 60 == 0 && (menuState == GAME || menuState == GAME_2 || menuState == GAME_3 || menuState == GAME_2P || menuState == GAME_4_2P || menuState == GAME_8_2P || menuState == END))
    {
        gameplayCounter--;
        printf("Counter: %d\n", gameplayCounter);
    }
    draw_new_fb();
}

void update_rtc_frame()
{
    if (timer_interrupts % FPS == 0)
        rtc_update_display();
}

void update_keyboard_frame()
{
    (kbc_ih)();
    switch (scancode)
    {
    case S_KEY:
        menuState = START;
        break;
    case G_KEY:
    if(menuState == START){
        menuState = GAME;}
        break;
    case Q_KEY:
        systemState = EXIT;
        break;
    case I_KEY:
    if(menuState == START){
        menuState = GAME_2;}
        break;
    case H_KEY:
    if(menuState == START) {
        menuState = GAME_3;}
        break;
    case K_KEY:
    if(menuState == START){
        menuState = GAME_2P;}
        break;
    case L_KEY: 
    if(menuState == START){
        menuState = GAME_4_2P;}
        break;
    case P_KEY:
    if(menuState == START){
        menuState = GAME_8_2P;}
        break;
    default:
        break;
    }
    draw_new_fb();
}

void update_mouse_frame()
{
    (mouse_ih)();
    mouse_align_bytes();
    if (byte_position == 3)
    {
        mouse_sync_info();
        draw_new_fb();
        byte_position = 0;
    }
}
