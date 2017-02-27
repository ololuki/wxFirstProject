/***************************************************************
 * Name:      wxWidgets_hello_worldApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Luke ()
 * Created:   2015-01-02
 * Copyright: Luke ()
 * License:
 **************************************************************/

#include "main.h"
#include "wx/xrc/xmlres.h"

IMPLEMENT_APP(wxWidgets_hello_worldApp);


//main
bool wxWidgets_hello_worldApp::OnInit()
{
	
    
    RootFrame *rootFrame = new RootFrame(wxT("Root Frame"));
    rootFrame->SetIcon(wxICON(aaaa)); // To Set App Icon
    rootFrame->Show(true);
    
    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load("GUIresource.xrc");
    wxXmlResource::Get()->LoadAllFiles("rc");
    
	wxDialog dlg;
    if (wxXmlResource::Get()->LoadDialog(&dlg, NULL, "SimpleDialog"))
        dlg.ShowModal();
    
    return true;
}



