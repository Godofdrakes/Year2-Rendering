#include "ObjApp.h"

ObjApp::ObjApp() : Application() {}

ObjApp::ObjApp( const string set_name ) : Application( set_name ) {}

ObjApp::ObjApp( const string set_name, const int set_width, const int set_height ) : Application( set_name, set_width, set_height ) {}

ObjApp::~ObjApp() {}

void ObjApp::AfterInit() {
    std::string err = tinyobj::LoadObj( shapes, materials, "./files/bunny.obj" );
    printf( err.c_str() );
    printf( "\n" );
}