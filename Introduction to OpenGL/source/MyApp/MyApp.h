#pragma once
#ifndef _MYAPP_H_
#define _MYAPP_H_

#include <Year2-Rendering/Application.h>

class Camera;

class MyApp : public Application {
    Camera* camera_;
protected:
    virtual void AfterInit() override;
    virtual void BeforeShutdown() override;
    virtual void AfterTick() override;
    virtual void BeforeUpdate() override;
    virtual void BeforeRender() override;
    virtual void AfterRender() override;
public:
    MyApp();
    MyApp( const string set_name );
    MyApp( const string set_name, const int set_width, const int set_height );
    ~MyApp();
};

#endif


