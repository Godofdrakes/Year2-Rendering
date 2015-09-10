#include "RenderApp.h"
#include "Vertex/Vertex.h"
#include <GLCORE/gl_core_4_4.h>

void RenderApp::GenerateGrid(unsigned rows, unsigned cols) {
    Vertex* arrVertex = new Vertex[rows* cols];
    for ( unsigned int r = 0; r < rows; ++r ) {
        for ( unsigned int c = 0; c < cols; ++c ) {
            unsigned int n = r*cols + c;
            arrVertex[n].position = glm::vec4( float( c ), 0, float( r ), 1 );
            glm::vec3 color = glm::vec3( sinf( ( c / float( cols - 1 ) )*( r / float( rows - 1 ) ) ) );
            arrVertex[n].color = glm::vec4( color, 1 );
        }
    }

    unsigned int* arrIndex = new  unsigned int[( rows - 1 * ( cols - 1 ) * 6 )];
    unsigned int n = 0;
    for ( unsigned int r = 0; r < ( rows - 1 ); ++r ) {
        for ( unsigned int c = 0; c < ( cols - 1 ); ++c ) {
            arrIndex[n++] = r * cols + c;
            arrIndex[n++] = ( r + 1 ) * cols + c;
            arrIndex[n++] = ( r + 1 ) * cols + ( c + 1 );

            arrIndex[n++] = r * cols + c;
            arrIndex[n++] = ( r + 1 ) * cols + ( c + 1 );
            arrIndex[n++] = r * cols + ( c + 1 );
        }
    }

    glGenBuffers( 1, &vbo );
    glGenBuffers( 1, &ibo );

    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glBufferData( GL_ARRAY_BUFFER, ( rows * cols ) * sizeof( Vertex ), arrVertex, GL_STATIC_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ibo );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, ( rows - 1 ) * ( cols - 1 ) * 6 * sizeof( unsigned int ), arrIndex, GL_STATIC_DRAW );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

    glBindVertexArray( 0 );

    glEnableVertexAttribArray( 0 );
    glEnableVertexAttribArray( 1 );
    glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, sizeof( Vertex ), 0 );
    glVertexAttribPointer( 1, 4, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void*)( sizeof( glm::vec4 ) ) );

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

    delete[]( arrIndex );
    delete[]( arrVertex );
}

void RenderApp::AfterInit() {
    const char* vsSource = "#version 410\n \
layout(location=0) in vec4 Position; \n \
layout(location=1) in vec4 Color; \n \
out vec4 vColor; \n \
uniform mat4 ProjectionView; \n \
void main() { \n \
    vColor = Color; \n \
    gl_Position = ProjectionVIew * Position; \n \
}";

    const char* fsSource = "#version 410"
}

void RenderApp::BeforeRender() {}

RenderApp::RenderApp() : RenderApp( "TEST" ) {}

RenderApp::RenderApp( const string set_name ) : RenderApp( set_name, 1280, 720 ) {}

RenderApp::RenderApp( const string set_name, const int set_width, const int set_height ) : Application( set_name, set_width, set_height ), vao( 0 ), vbo( 0 ), ibo( 0 ) {}

RenderApp::~RenderApp() {}
