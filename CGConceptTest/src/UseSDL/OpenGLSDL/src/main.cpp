#include <SDL.h>
#include "GLCore.h"
#include "GLCore/Core/Log.h"

int main (int argc, char *argv[]) {
    GLCore::Log::Init();
    SDL_Window* window = nullptr;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        CG_ERROR("SDL could not be initialized: {0}", SDL_GetError());
    }
    else {
        CG_INFO("SDL video system is ready to go");
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    window = SDL_CreateWindow("C++ SDL2 Window",
            20,
            20,
            640,
            480,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // OpenGL setup the graphics context
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);

    // Setup our function pointers
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    // Infinite loop for our application
    bool gameIsRunning = true;
    while(gameIsRunning){
        glViewport(0,0,640,480);

        SDL_Event event;
        // Start our event loop
        while(SDL_PollEvent(&event)){
            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }
            if(event.type == SDL_MOUSEMOTION){
                std::cout << "mouse has been moved\n";
            }
            if(event.type == SDL_KEYDOWN){
                std::cout << "a key has been pressed\n";
                if(event.key.keysym.sym == SDLK_0){
                    std::cout << "0 was pressed\n";
                }else{
                    std::cout << "0 was not pressed\n";
                }
            }
            // NOTE: Retrieve the state of all of the keys Then we can query the scan code of one or more keys at a time
            const Uint8* state = SDL_GetKeyboardState(nullptr);
            if(state[SDL_SCANCODE_RIGHT]){
                std::cout << "right arrow key is pressed\n";
            }
        }

        glClearColor(1.0f,0.0f,0.0f,1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    // NOTE: We destroy our window. We are passing in the pointer that points to the memory allocated by the 
    // NOTE: 'SDL_CreateWindow' function. Remember, this is a 'C-style' API, we don't have destructors.
    SDL_DestroyWindow(window);
    
    // NOTE: We safely uninitialize SDL2, that is, we are taking down the subsystems here before we exit We add a delay in order to see that our window has successfully popped up.
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}
