#pragma once
#ifndef _OBJAPP_H_
#define _OBJAPP_H_

#include <Year2-Rendering/Application.h>
#include <TINYOBJ/tiny_obj_loader.h>

class ObjApp : public Application {
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
public:
    ObjApp();
    ObjApp( const string set_name );
    ObjApp( const string set_name, const int set_width, const int set_height );
    ~ObjApp();

    virtual void AfterInit() override;
};

#endif
