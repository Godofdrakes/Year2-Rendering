#pragma once
#ifndef _RENDERAPP_H_
#define _RENDERAPP_H_

#include <Year2-Rendering/Application.h>

class RenderApp : public Application {
    void GenerateGrid( unsigned int rows, unsigned int cols );
    unsigned int vao, vbo, ibo, programID;

    virtual void AfterInit() override;
    virtual void BeforeRender() override;
public:
    RenderApp();
    RenderApp( const string set_name );
    RenderApp( const string set_name, const int set_width, const int set_height );
    ~RenderApp();
};

#endif
