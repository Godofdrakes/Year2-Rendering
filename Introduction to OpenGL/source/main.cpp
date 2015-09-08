#include "MyApp/MyApp.h"

int main( ) {
    MyApp* app = new MyApp();

    if( app->Init() == ApplicationFail::NONE ) {
        while( app->Tick() ) {
            app->Update();
            app->Render();
        }
        app->Shutdown();
    }

    delete( app );

    return 0;
}