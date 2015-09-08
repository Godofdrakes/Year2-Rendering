#include "MyApp.h"
#include <GLM/glm.hpp>
#include <GIZMOS/Gizmos.h>
#include <Year2-Rendering/Camera/Camera.h>
#include <Year2-Rendering/Camera/FlyCamera.h>

using glm::vec3;
using glm::vec4;
using glm::mat4;

void MyApp::AfterInit() {
    Gizmos::create();
    camera_ = new FlyCamera( 1.f );
    camera_->SetPerspective( glm::pi<float>() * 0.25f, SIXTEEN_NINE, 0.1f, 1000.f );
    camera_->SetLookAt( vec3( 10, 10, 10 ), vec3( 0 ), vec3( 0, 1, 0 ) );
}

void MyApp::BeforeShutdown() {
    delete( camera_ );
    Gizmos::destroy();
}

void MyApp::AfterTick() {
    Gizmos::clear();
    Gizmos::addTransform( mat4( 1 ) );
}

void MyApp::BeforeUpdate() {
    camera_->Update();
}

void MyApp::BeforeRender() {
    for ( int n = 0; n < 21; ++n ) {
        Gizmos::addLine( vec3( -10 + n, 0, 10 ),
                         vec3( -10 + n, 0, -10 ),
                         n == 10 ? vec4( 1, 1, 1, 1 ) : vec4( 0, 0, 0, 1 ) );
        Gizmos::addLine( vec3( 10, 0, -10 + n ),
                         vec3( -10, 0, -10 + n ),
                         n == 10 ? vec4( 1, 1, 1, 1 ) : vec4( 0, 0, 0, 1 ) );
    }
    camera_->UpdateProjectionViewTransform();
}

void MyApp::AfterRender() {
    Gizmos::draw( camera_->Camera_View_Transform_Mat4 );
}

MyApp::MyApp() : MyApp( "TEST" ) {}

MyApp::MyApp( const string set_name ) : MyApp( set_name, 1280, 720 ) {}

MyApp::MyApp( const string set_name, const int set_width, const int set_height ) : Application( set_name, set_width, set_height ) {
    camera_ = nullptr;
}

MyApp::~MyApp() {}
