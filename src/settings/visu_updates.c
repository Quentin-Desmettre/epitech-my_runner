/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** visu_updates.c
*/

#include "runner.h"

void update_all_texts(settings_t *se)
{
    sfSprite_setTextureRect(se->res_button->sprite,
    set_rects[se->resolution + 7]);
    sfSprite_setTextureRect(se->framerate_button->sprite,
    set_rects[se->framerate + 2]);
    sfText_setString(se->sfx_vol_text, nbr_to_str(se->sfx_vol));
    sfText_setString(se->music_vol_text, nbr_to_str(se->music_vol));
}

void reset_set_buttons(settings_t *se)
{
    button_t *buttons[9] = {se->back, NULL, NULL, se->res_button,
    se->framerate_button, se->sfx_minus, se->sfx_plus,
    se->music_minus, se->music_plus};

    for (int i = 0; i < 9; i++) {
        if (i == 1 || i == 2)
            continue;
        hover_button(buttons[i], 0);
        press_button(buttons[i], 0);
    }
}
