#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <cmath>
#include "./include/window.h"
#include "./include/timer.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef unsigned char uint8;
std::string getTimeString(Uint32 time);

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

    Timer timer(1000);
    std::string timeString;
    timer.start();
    std::cout << "Timer started!" << std::endl;
    window win("simuBox", 3, 6, 100, SCREEN_HEIGHT, SCREEN_WIDTH);

    int x0 = 0;
    int y0 = SCREEN_HEIGHT - (SCREEN_HEIGHT / 5) - 50;
    double a = 9.81 * SCREEN_HEIGHT / 10000000;
    double v = 0;
    double massa = 10;
    double h = 100;

    
    win.add_element_to_workbench(0,0, SCREEN_WIDTH/2, h, 32, 32, {255, 255, 255});
    //chão
    
    win.add_element_to_workbench(2,1,x0,y0, SCREEN_WIDTH, y0, {255, 255, 255});

    

    

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        // Atualiza o tempo total do timer
        timeString = getTimeString(timer.getTotalTime());
        win.GUI().setTextElementString(6, "Time: " + timeString);


        if(h<y0)
        {
            std::cout << "h: " << h << std::endl;
            v = v + a * (timer.getTotalTime() / 1000);
            h = h + v*(timer.getTotalTime()/1000);
            win.layers[0].elements[0].rect.y = h - win.layers[0].elements[0].rect.h;
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
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
                break;
            // case SDL_MOUSEMOTION:
            //     int x = e.motion.x;
            //     int y = e.motion.y;
            //     if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x > win.layers[0].elements[0].rect.w && y > win.layers[0].elements[0].rect.h)
            //     {
            //         win.layers[0].elements[0].rect.x = x - win.layers[0].elements[0].rect.w;
            //         win.layers[0].elements[0].rect.y = y - win.layers[0].elements[0].rect.h;
            //     }
            //     break;
            }
        }

        win.show();
    }


    SDL_Quit();
}

std::string getTimeString(Uint32 time)
{
    Uint32 miliseconds = time/10;// :00
    Uint32 seconds = time / 1000; // :00
    Uint32 minutes = seconds / 60; // :00
    Uint32 hours = minutes / 60; // :00

    miliseconds = miliseconds % 100; // :00
    seconds = seconds % 60; // :00
    minutes = minutes % 60; // :00

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