#include "RenderApp/RenderApp.h"

int main() {
    Application* app = new RenderApp( "Hotdog" );
    if ( app->Init() == ApplicationFail::NONE ) {
        while ( app->Tick() ) {
            app->Update();
            app->Render();
        }
        app->Shutdown();
    }
    return 0;
}