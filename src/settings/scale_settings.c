/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-quentin.desmettre
** File description:
** scale_settings.c
*/

#include "runner.h"

static void rescale_sounds(settings_t *se, window_t *win)
{
    sfSprite_setScale(se->sfx_plus->sprite, (sfVector2f)
    {win->mode.width / 1110.0, win->mode.width / 1110.0});
    sfSprite_setScale(se->sfx_minus->sprite, (sfVector2f)
    {win->mode.width / 1110.0, win->mode.width / 1110.0});
    sfSprite_setScale(se->music_plus->sprite, (sfVector2f)
    {win->mode.width / 1110.0, win->mode.width / 1110.0});
    sfSprite_setScale(se->music_minus->sprite, (sfVector2f)
    {win->mode.width / 1110.0, win->mode.width / 1110.0});
}

static void rescale_buttons(settings_t *se, window_t *win)
{
    set_sprite_size(se->framerate_button->sprite,
    (sfVector2f){win->mode.width / 2.2, win->mode.height / 5.0});
    set_sprite_size(se->res_button->sprite,
    (sfVector2f){win->mode.width / 2.2, win->mode.height / 5.0});
    sfSprite_setScale(se->back->sprite,
    (sfVector2f){win->mode.height / 1183.0, win->mode.height / 1391.0});
}

static void rescale_texts(settings_t *se, window_t *win)
{
    float new_char_size = win->mode.width / 800.0 * 30;

    sfText_setCharacterSize(se->full_screen->text, new_char_size);
    sfText_setCharacterSize(se->vsync->text, new_char_size);
    sfText_setCharacterSize(se->sfx_text, new_char_size);
    sfText_setOrigin(se->sfx_text,
    (sfVector2f){1.5 * new_char_size, new_char_size / 1.5});
    sfText_setCharacterSize(se->music_text, new_char_size);
    sfText_setOrigin(se->music_text,
    (sfVector2f){3.0 * new_char_size, new_char_size / 1.5});
    sfText_setCharacterSize(se->sfx_vol_text, new_char_size);
    sfText_setOrigin(se->sfx_vol_text,
    (sfVector2f){((int)(log10(se->sfx_vol + 1)) / 2.0) * new_char_size,
    new_char_size / 1.5});
    sfText_setCharacterSize(se->music_vol_text, new_char_size);
    sfText_setOrigin(se->music_vol_text,
    (sfVector2f){((int)(log10(se->music_vol + 1)) / 2.0) * new_char_size,
    new_char_size / 1.5});
}

void rescale_settings(settings_t *se, window_t *win)
{
    sfRenderTexture_destroy(se->rtex);
    se->rtex = sfRenderTexture_create(win->mode.width, win->mode.height, 0);
    set_sprite_size(se->background,
    (sfVector2f){win->mode.width, win->mode.height});
    scale_check_box(se->full_screen, (sfVector2f)
    {win->mode.width / 936.0, win->mode.width / 936.0});
    scale_check_box(se->vsync, (sfVector2f)
    {win->mode.width / 936.0, win->mode.width / 936.0});
    rescale_sounds(se, win);
    rescale_buttons(se, win);
    rescale_texts(se, win);
    move_settings(se, win);
}
