#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <cmath>
#include "./include/window.h"
#include "./include/timer.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define Y0 SCREEN_HEIGHT - (SCREEN_HEIGHT / 5) - 50
#define metro SCREEN_HEIGHT / 10

typedef unsigned char uint8;
std::string getTimeString(Uint32 time);

double y(double y_pos) { return Y0 - (y_pos * metro); }
double Y(double screen_y_pos) { return ((Y0 - screen_y_pos) / 48) ; }

int main()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "simuBox initialized successfully!" << std::endl;
    }

    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL_ttf initialized successfully!" << std::endl;
    }

    Timer timer(1);
    std::string timeString;
    std::cout << "Timer started!" << std::endl;
    window win("simuBox", 3, 6, 100, SCREEN_HEIGHT, SCREEN_WIDTH);

    // double metro = SCREEN_HEIGHT / 10;
    int x0 = 0;
    double a = 9.81 / 100000;
    float v = 0;
    double massa = 10;
    double h;
    int segundo;
    int y0 = y(0) - metro;
    float tempo = 0;

    win.add_element_to_workbench(0, 0, SCREEN_WIDTH / 2, y(0), metro, metro, {255, 255, 255});
    // chão

    bool quit = false;
    bool drop = false;
    SDL_Event e;
    h = 5;
    win.layers[0].elements[0].rect.y = y(h) - metro;

    int mouse_x, mouse_y;

    while (!quit)
    {

        // Atualiza o tempo total do timer
        timeString = getTimeString(timer.getTotalTime());
        win.GUI().setTextElementString(6, "Time: " + timeString);
        tempo = timer.getTotalTime() / 1000.0;

        if(drop)
        {
            if (h > 0)
            {
                v = v + a * tempo;
                std::cout << "h: " << h << " v: " << v << " a: " << a << std::endl;
                h = h - v * tempo;
                std::cout << "h: " << h << " v: " << v << " a: " << a << std::endl;
                if (h > 0)
                    win.layers[0].elements[0].rect.y = y(h) - metro;
            }
        }

        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym)
                    {
                        case 0x00000072u: // 'r' key
                            // quit = true;
                            timer.stop();
                            timer.reset();
                            drop = false;
                            SDL_GetGlobalMouseState(&mouse_x, &mouse_y);
                            win.layers[0].elements[0].rect.x = mouse_x - win.layers[0].elements[0].rect.w;
                            win.layers[0].elements[0].rect.y = mouse_y - win.layers[0].elements[0].rect.h;
                        break;
                    }
                break;

                case SDL_MOUSEMOTION:
                if(!drop)
                {
                    int x = e.motion.x;
                    int y = e.motion.y;
                    if (x < SCREEN_WIDTH - win.layers[0].elements[0].rect.w/2 && y < y0 + win.layers[0].elements[0].rect.h/2 && x > win.layers[0].elements[0].rect.w/2 && y > win.layers[0].elements[0].rect.h/2)
                    {
                        win.layers[0].elements[0].rect.x = x - win.layers[0].elements[0].rect.w/2;
                        win.layers[0].elements[0].rect.y = y - win.layers[0].elements[0].rect.h/2;
                    }
                }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    if(!drop)
                    {
                        h = Y( win.layers[0].elements[0].rect.y) - 1;
                        std::cout << "Y0: " << Y0 << std::endl;
                        std::cout << "Y_rec: " << win.layers[0].elements[0].rect.y << std::endl;
                        std::cout << "h: " << h<<std::endl;
                        timer.reset();
                        timer.start();
                        drop = true;
                    }
                break;
            }
        }

        win.show();
    }

    SDL_Quit();
}

std::string getTimeString(Uint32 time)
{
    Uint32 miliseconds = time / 10; // :00
    Uint32 seconds = time / 1000;   // :00
    Uint32 minutes = seconds / 60;  // :00
    Uint32 hours = minutes / 60;    // :00

    miliseconds = miliseconds % 100; // :00
    seconds = seconds % 60;          // :00
    minutes = minutes % 60;          // :00

    std::string milisecondsString;
    std::string secondsString;
    std::string minutesString;
    std::string hoursString;

    if (miliseconds > 1000)
    {
        miliseconds = 0;
    }
    miliseconds < 10 ? milisecondsString = "0" + std::to_string(miliseconds) : milisecondsString = std::to_string(miliseconds);
    seconds < 10 ? secondsString = "0" + std::to_string(seconds) : secondsString = std::to_string(seconds);
    minutes < 10 ? minutesString = "0" + std::to_string(minutes) : minutesString = std::to_string(minutes);
    hours < 10 ? hoursString = "0" + std::to_string(hours) : hoursString = std::to_string(hours);

    std::string timeString = hoursString + ":" + minutesString + ":" + secondsString + ":" + milisecondsString;
    return timeString;
}