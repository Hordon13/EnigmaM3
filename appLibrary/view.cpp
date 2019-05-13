#include "view.h"

#include <SDL_image.h>
#include <string>

View::View(Model &model)
{
    _model = &model;
}

View::~View()
{
    free();
}

bool View::init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }
        _gWindow = SDL_CreateWindow("Enigma", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                    SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (_gWindow == nullptr) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            _gRenderer = SDL_CreateRenderer(_gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (_gRenderer == nullptr) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                SDL_SetRenderDrawColor(_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }

                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == 1) {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }

                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

void View::close()
{
    free();

    Mix_FreeChunk(_keystroke);
    _keystroke = nullptr;
    Mix_FreeChunk(_invalid);
    _invalid = nullptr;

    TTF_CloseFont(_gFont);
    _gFont = nullptr;

    SDL_DestroyWindow(_gWindow);
    _gWindow = nullptr;

    SDL_DestroyRenderer(_gRenderer);
    _gRenderer = nullptr;

    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

SDL_Texture *View::loadTexture(const std::string &path)
{

    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }

    return SDL_CreateTextureFromSurface(_gRenderer, loadedSurface);
}

bool View::loadMedia()
{
    bool success = true;

    _background = loadTexture("../media/background.jpg");
    if (_background == nullptr) {
        printf("Failed to load PNG image!\n");
        success = false;
    }

    _gFont = TTF_OpenFont("../media/tox_typewriter.ttf", 20);
    if (_gFont == nullptr) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    _keystroke = Mix_LoadWAV("../media/keystroke.wav");
    if (_keystroke == nullptr) {
        printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    _invalid = Mix_LoadWAV("../media/invalid.wav");
    if (_invalid == nullptr) {
        printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

bool View::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    free();

    SDL_Surface *textSurface = TTF_RenderText_Solid(_gFont, textureText.c_str(), textColor);
    if (textSurface == nullptr) {
        printf("Unable to renderText text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        _text = SDL_CreateTextureFromSurface(_gRenderer, textSurface);
        if (_text == nullptr) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            _textWidth = textSurface->w;
            _textHeigth = textSurface->h;
        }

        SDL_FreeSurface(textSurface);
    }

    return _text != nullptr;
}

void View::renderElement(SDL_Texture *element, SDL_Rect position)
{
    SDL_RenderCopy(_gRenderer, element, nullptr, &position);
}

void View::renderText(int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = {x, y, _textWidth, _textHeigth};

    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(_gRenderer, _text, clip, &renderQuad, angle, center, flip);
}

void View::free()
{
    if (_text != nullptr) {
        SDL_DestroyTexture(_text);
        _text = nullptr;
        _textWidth = 0;
        _textHeigth = 0;
    }
}

void View::playEffect(std::string effect)
{
    if (!effect.empty()) {
        if (effect == "keystroke") {
            Mix_PlayChannel(-1, _keystroke, 0);
        } else if (effect == "invalid") {
            Mix_PlayChannel(-1, _invalid, 0);
        }
    }

    //_model->setPlayEffect("");
}

SDL_Renderer *View::getGRenderer() const
{
    return _gRenderer;
}

Model *View::getModel()
{
    return _model;
}

void View::drawBackground()
{
    SDL_Rect position = {0, 0, 1280, 720};
    renderElement(_background, position);
}
