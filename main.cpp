#include <iostream>

#include <view.h>
#include <model.h>

int main()
{
    std::cout << "Choose GUI: consol | graphic | readfile" << std::endl;
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
        std::string enigmaReturn;

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
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_b:
                                    message = "b";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_c:
                                    message = "c";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_d:
                                    message = "d";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_e:
                                    message = "e";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_f:
                                    message = "f";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_g:
                                    message = "g";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_h:
                                    message = "h";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_i:
                                    message = "i";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_j:
                                    message = "j";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_k:
                                    message = "k";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_l:
                                    message = "l";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_m:
                                    message = "m";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_n:
                                    message = "n";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_o:
                                    message = "o";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_p:
                                    message = "p";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_q:
                                    message = "q";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_r:
                                    message = "r";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_s:
                                    message = "s";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_t:
                                    message = "t";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_u:
                                    message = "u";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_v:
                                    message = "v";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_w:
                                    message = "w";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_x:
                                    message = "x";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_y:
                                    message = "y";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                case SDLK_z:
                                    message = "z";
                                    enigmaReturn = view.getModel()->encrypt(message);
                                    view.playEffect("keystroke");
                                    break;
                                default:
                                    view.playEffect("invalid");
                                    break;
                            }
                        }
                    }

                    view.drawBackground();
                    view.highlight(enigmaReturn);
                    view.drawRotorPositions();
                    view.drawUI();

                    SDL_RenderPresent(view.getGRenderer());
                }
            }

            view.close();
        }
    } else if (guiType == "readfile") {
        std::cout << "Soon..." << std::endl;
    }

    return 0;
}