#ifndef VIEW_VIEW_H
#define VIEW_VIEW_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL_mixer.h"
#include "model.h"


class View {
public:
    View(Model &model);

    ~View();

    bool init();

    void close();

    SDL_Texture *loadTexture(const std::string &path);

    bool loadMedia();

    void free();

    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

    void renderElement(SDL_Texture *element, SDL_Rect position);

    void renderText(int x, int y, SDL_Rect *clip = nullptr, double angle = 0.0, SDL_Point *center = nullptr,
                    SDL_RendererFlip flip = SDL_FLIP_NONE);

    void playEffect(std::string effect);

    Model *getModel();

    SDL_Renderer *getGRenderer() const;

    ////

    void drawBackground();

private:

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    SDL_Window *_gWindow{};
    SDL_Renderer *_gRenderer{};
    TTF_Font *_gFont{};

    Mix_Chunk *_keystroke;
    Mix_Chunk *_invalid;

    SDL_Texture *_background;

    SDL_Texture *_text;
    int _textWidth;
    int _textHeigth;

    Model *_model;
};

#endif