
// WorkPanel to obiekt po lewej stronie zawierający matrycę kwadratów
// Buttons to obiekt po prawej zawierający przyciski
// oba leżą na obiekcie RootFrame z pliku rootFrame.h

#ifndef WORKPANEL_H
#define WORKPANEL_H

#include <wx/dcbuffer.h> //wxBufferedPaintDC - buforowanie ekranu
#include <wx/ffile.h>       //files
#include "rootFrame.h"
#include "IdColorEnum.h"

class WorkPanel : public wxPanel
{
public:
	WorkPanel(wxWindow * parent);
	//virtual ~WorkPanel();
	wxPanel* PanelPointer();

	//Buttons * ptr_buttons;
	wxPanel * ptr_parent; //wskaźnik na panel rodzica - main panel z klasy Line

	int color; //kolor - ostatnio kliknięty
	int hexOrDecOrBin;	//wybór rodzaju wyswietlanej liczby: hex, binarna lub dziesiętna
	
	void ClearMatrix();		// czysci calą matrycę

	void OnPaint(wxPaintEvent& event); //przerysowywanie okna - (expose + resize)

	void OnMove(wxMoveEvent & event); //przesuwanie okna
	void OnResize(wxSizeEvent & event); //zmiana rozmiaru okna
	void OnMouseMoving(wxMouseEvent& event); //przesuwanie myszy po oknie
	void OnMouseLeftClick(wxMouseEvent& event);
	//wxStaticText *st1;
	//wxStaticText *st2;
	
	void CalculateRowsAndColumns();				// oblicza wartość liczbową dla każdej kolumy i wiersza
	void DisplayRowsAndColumns();				// wyswietla wartości liczbowe dla każdej kolumny i wiersza

private:
	wxStaticText **etiquettes_rows;				// tablica wskaźników na etykietki wierszy
	wxStaticText **etiquettes_columns;			// tablica wskaźników na etykietki kolumn
	static const int boardmatrix_width = 5;		// szerokość matrycy w kwadracikach
	static const int boardmatrix_height = 8;	// wysokość matrycy w kwadracikach
	static const int boardrect_width = 20;		// szerokość kwadraciku w pikselach
	static const int boardrect_height = 20;		// wysokość kwadraciku w pikselach
	//int boardmatrix_width_pixels;				// inicjowana dopiero w konstruktorze = boardmatrix_width * boardrect_width
	//int boardmatrix_height_pixels;				// inicjowana dopiero w konstruktorze = boardmatrix_height * boardrect_height
	int **boardmatrix;							// wskaźnik na tablice dwuwymiarową z zawartością matrycy[x][y]
	enum
	{
		idMenuQuit = 1000,
		idMenuAbout
	};
	int * values_of_rows;						// tablica wartości każdego z wierszy
	int * values_of_columns;					// tablica wartości każdej z kolumn

	
};

#endif // WORKPANEL_H
