#include <iostream>

#include <view.h>
#include <model.h>

int main()
{
    std::cout << "Load GUI: consol/graphic" << std::endl;
    std::string guiType;
    std::cin >> guiType;


    if (guiType == "consol") {
        std::cout << "Configure enigma... " << std::endl;
        std::cout << "Example: 368/UZV/AHM/B/AN.EZ.HK.IJ.LR.MQ.OT.PV.SW.UX" << std::endl;
        std::string config;
        std::cin >> config;

        if (config == ".") {
            config = "368/UZV/AHM/B/AN.EZ.HK.IJ.LR.MQ.OT.PV.SW.UX";
        }

        Model enigma(config);

        while (true) {
            std::cout << std::endl;
            std::cout << "Enter a message: ";
            std::string input;
            std::cin >> input;
            if (input == "@exit") {
                break;
            }
            std::cout << enigma.encrypt(input) << std::endl;
        }

    } else if (guiType == "graphic") {
        Model model;
        View view(model);
        std::string message;

        if (!view.init()) {
            printf("Failed to initialize!\n");
        } else {
            if (!view.loadMedia()) {
                printf("Failed to load media!\n");
            } else {

                bool quit = false;

                SDL_Event e;

                while (!quit) {
                    while (SDL_PollEvent(&e) != 0) {
                        if (e.type == SDL_QUIT) {
                            quit = true;
                        } else if (e.type == SDL_KEYDOWN) {
                            switch (e.key.keysym.sym) {
                                case SDLK_a:
                                    message = "a";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_b:
                                    message = "b";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_c:
                                    message = "c";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_d:
                                    message = "d";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_e:
                                    message = "e";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_f:
                                    message = "f";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_g:
                                    message = "g";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_h:
                                    message = "h";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_i:
                                    message = "i";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_j:
                                    message = "j";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_k:
                                    message = "k";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_l:
                                    message = "l";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_m:
                                    message = "m";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_n:
                                    message = "n";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_o:
                                    message = "o";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_p:
                                    message = "p";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_q:
                                    message = "q";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_r:
                                    message = "r";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_s:
                                    message = "s";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_t:
                                    message = "t";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_u:
                                    message = "u";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_v:
                                    message = "v";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_w:
                                    message = "w";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_x:
                                    message = "x";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_y:
                                    message = "y";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_z:
                                    message = "z";
                                    view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                default:
                                    view.playEffect("invalid");
                                    break;
                            }
                        }
                    }

                    view.drawBackground();

                    SDL_RenderPresent(view.getGRenderer());
                }
            }

            view.close();
        }
    }

    return 0;
}