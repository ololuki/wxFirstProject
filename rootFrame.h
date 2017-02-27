/***************************************************************
 * Name:      rootFrame.h
 * Purpose:   główna ramka programu
 * Author:    Luke ()
 * Created:   2015-01-02
 * Copyright: Luke ()
 * License:
 **************************************************************/

#ifndef ROOTFRAME_H
#define ROOTFRAME_H

#include <wx/wx.h>
#include "WorkPanel.h"
#include "Buttons.h"

class WorkPanel;    //deklaracja klas z pliku button.h
class Buttons;

class RootFrame : public wxFrame
{		
public:
    RootFrame(const wxString& title);
	virtual ~RootFrame();
	
    wxPanel *main_panel;

    void OnMouseMoving(wxMouseEvent& event); //przesuwanie myszy po oknie

    WorkPanel * bb ;
    Buttons * btn;

private:
    enum
    {
        idMenuQuit = 1000,
        idMenuAbout,
        idMenuHelpReadMe
    };
    void MakeMenuStatusbar();
    
    //void OnMove(wxMoveEvent & event); //przesuwanie okna
    void OnClose(wxCloseEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnHelpReadMe(wxCommandEvent &event);
};



#endif // ROOTFRAME_H
