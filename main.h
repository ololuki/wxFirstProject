/***************************************************************
 * Name:      wxWidgets_hello_worldApp.h
 * Purpose:   Defines Application Class
 * Author:    Luke ()
 * Created:   2015-01-02
 * Copyright: Luke ()
 * License:
 **************************************************************/

#ifndef WXWIDGETS_HELLO_WORLDAPP_H
#define WXWIDGETS_HELLO_WORLDAPP_H

#include <wx/app.h>
//#include "wx/xrc/xmlres.h"
#include <iostream>
#include "rootFrame.h"

extern int dupa;

class wxWidgets_hello_worldApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXWIDGETS_HELLO_WORLDAPP_H
