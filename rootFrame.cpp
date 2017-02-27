#include "rootFrame.h"

RootFrame::RootFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 510)) //rozmiar początkowy
{
    std::cout << "konstr line " << this << "  " << sizeof(*this) << std::endl;
    //SetBackgroundStyle(wxBG_STYLE_SYSTEM);
    RootFrame::MakeMenuStatusbar();
    main_panel = new wxPanel(this, wxID_ANY); //główny panel okna
    bb = new WorkPanel(main_panel); //nowy panel - typ WorkPanel zdefiniowany w pliku WorkPanel
    btn = new Buttons(main_panel); //panel prawy
    //wxPanel* panelik = bb->PanelPointer(); //wskaźnik do panela utworzonego powyżej
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL); //box poziomy
    hbox->Add(bb, 1, wxEXPAND | wxALL, 5); //włożenie do hboxa
    hbox->Add(btn, 1, wxEXPAND | wxALL, 5);
    main_panel->SetSizer(hbox);
    //this->Connect(wxEVT_MOVE, wxMoveEventHandler(RootFrame::OnMove)); //zdarzenie przesuwania okna (tego okna this) które wpływa na etykiety na paneliku utworzonym głebiej
    //main_panel->Connect(wxEVT_MOTION, wxMouseEventHandler(RootFrame::OnMouseMoving)); //zdarzenie ruchu mysza na oknie
    this->Centre();
}

RootFrame::~RootFrame()
{
	//dtor
}


void RootFrame::MakeMenuStatusbar()
{
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuHelpReadMe, _("&Help\tF1"), _("User's manual"));
    helpMenu->Append(idMenuAbout, _("&About\tF2"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);

    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(3); //liczba etykiet (pól) na pasku stanu
    SetStatusText(_("czcionki 5x7 i 5x8"),0);
    //SetStatusText(wxbuildinfo(long_f), 1);
    SetStatusText("www.ololuki.elektroda.eu", 2);
	Connect(idMenuHelpReadMe, wxEVT_MENU, wxCommandEventHandler(RootFrame::OnHelpReadMe));
	Connect(idMenuAbout, wxEVT_MENU, wxCommandEventHandler(RootFrame::OnAbout));
	Connect(idMenuQuit, wxEVT_MENU, wxCommandEventHandler(RootFrame::OnQuit));
    Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(RootFrame::OnClose));
}


void RootFrame::OnMouseMoving(wxMouseEvent& event)
{
    std::cout << "Mouse moving no click" << std::endl;
}




/*

void RootFrame::OnMove(wxMoveEvent& event)
{
  wxPoint size = event.GetPosition();
  bb->st1->SetLabel(wxString::Format(wxT("x: %d"), size.x ));
  bb->st2->SetLabel(wxString::Format(wxT("y: %d"), size.y ));
  std::cout << "Przenoszenie okna x = " << size.x << " y = " << size.y << std::endl;
}

*/



void RootFrame::OnClose(wxCloseEvent &event) //zamykanie okna krzyżykiem
{
    std::cout << "Destroy on close" << std::endl;
    if ( event.CanVeto() ) //veto - czy na pewno zamknąć?
    {
            if ( wxMessageBox("The file has not been saved... continue closing?",
            "Please confirm",
            wxICON_QUESTION | wxYES_NO) != wxYES )
            {
            event.Veto();
            return;
        }
    }
    Destroy();
}

void RootFrame::OnQuit(wxCommandEvent &event) //menu > file > quit
{
    std::cout << "Destroy on quit" << std::endl;
    Destroy();
}

void RootFrame::OnAbout(wxCommandEvent &event) //menu > help > about
{
    wxString msg = "Author: Ololuki \nwww.ololuki.elektroda.eu\n2015";
    wxMessageBox(msg, _("About this program..."));
}

void RootFrame::OnHelpReadMe(wxCommandEvent &event) //menu > help > help
{
	wxString msg = wxT("Program do projektowania czcionek 5x7 pikseli, \
w przyszłości zostanie rozbudowany na inne rozmiary czcionek \
oraz dodany zostanie symulator matrycy LED.\n\
Matryca wyświetla ekran wyświetlacza.\n\
Białe pola oznaczają wartość 0.\n\
Pozostałe kolory mają wartość 1.\n\
Przycisk CLEAR czysci całą planszę.\n\
Przyciski White, Red, Green, Blue ustawiają rysowanie odpowiedniego koloru.\n\
Wartość liczbowa danego wiersza wyswietlana jest obok tego wiersza.\n\
Wartośc liczbowa kolumny wyświetlana jest poniżej odpowiedniej kolumny (początek napisu zawsze leży pod odpowiadającą kolumną).\n\
Wartość liczbowa może być wyświetlona w postaci szesnastkowej, dziesiętnej lub dwójkowej. Do wyboru trybu służy przycisk \"Hex Dec Bin\". Aktualnie wybrany tryb wyswietlony jest poniżej tego przycisku.\n\
www.ololuki.elektroda.eu\n2015\n\
	");
	wxMessageBox(msg,
            "Please confirm",
            wxICON_QUESTION);
}
