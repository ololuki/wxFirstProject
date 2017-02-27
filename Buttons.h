// Panel to obiekt po lewej stronie zawierający matrycę kwadratów
// Buttons to obiekt po prawej zawierający przyciski
// oba leżą na obiekcie RootFrame z pliku rootFrame.h

#ifndef BUTTONS_H
#define BUTTONS_H

#include <wx/dcbuffer.h> //wxBufferedPaintDC - buforowanie ekranu
#include <wx/ffile.h>       //files
#include "rootFrame.h"


class Buttons : public wxPanel
{
public:
    Buttons(wxWindow * parent);
    virtual ~Buttons();
    int GetColor(); //zwraca kliknięty ostatnio przycisk
    wxButton * btnClear;
    wxButton * white;
    wxButton * red; //wskaźnik na przycisk red
    wxButton * green; //wskaźnik na przycisk green
    wxButton * blue; //wskaźnik na przycisk blue
    wxButton * btnHexOrDecOrBin; //wskaźnik na przycisk wyboru rodzaju wyswietlanej liczby: hex, binarna lub dziesiętna
    wxStaticText * labelHexOrDecOrBin;	//wskaźnik na etykietę wyboru rodzaju wyswietlanej liczby: hex, binarna lub dziesiętna

    wxPanel * ptr_parent; //wskaźnik na panel rodzica - main panel z klasy Line

    int color; //kolor - ostatnio kliknięty
private:
	void OnBtnClear(wxCommandEvent & event);
	void OnWhite(wxCommandEvent & event);
    void OnRed(wxCommandEvent & event);
    void OnGreen(wxCommandEvent & event);
    void OnBlue(wxCommandEvent & event);
    void OnHexOrDecOrBin(wxCommandEvent & event);
};

#endif // BUTTONS_H
