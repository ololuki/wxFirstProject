#include "WorkPanel.h"

WorkPanel::WorkPanel(wxWindow * parent)
       //: wxPanel(parent)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
    //SetBackgroundStyle(wxBG_STYLE_SYSTEM);
	
	hexOrDecOrBin = 16; //domyslne wyswietlanie wartości kolumn i wierszy szesnastkowo (HEX)
	
	//obliczenie wielkości matrycy w pikselach (podane w kwadracikach i wymiary kwadraciku)
	int boardmatrix_width_pixels = boardmatrix_width * boardrect_width;
	int boardmatrix_height_pixels = boardmatrix_height * boardrect_height;
	
    //utworzenie dwuwymiarowej tablicy ze stanem kwadracików
    boardmatrix = new int * [boardmatrix_height];
    for (int i = 0; i<boardmatrix_height; i++) {
        boardmatrix[i] = new int[boardmatrix_width];
    }
    //inicjalizacja tablicy ze stanem kwadracików
    for (int x = 0; x<boardmatrix_width; x++) {
        for (int y = 0; y<boardmatrix_height; y++) {
            boardmatrix[x][y] = 0;// = ID_RED;////////////////////////////////////////////////////////////////////////////////////
        }
    }
    
    // etykiety z liczbą opisującą dany wiersz lub kolumne
    etiquettes_rows = new wxStaticText * [boardmatrix_height];
    for (int i = 0; i<boardmatrix_height; i++) {
        etiquettes_rows[i] = new wxStaticText(this, -1, wxT("wartości wierszy"), wxPoint(boardmatrix_width_pixels + 10, 2 + i * boardrect_height));
    }
    etiquettes_columns = new wxStaticText * [boardmatrix_width];
    for (int i = 0; i<boardmatrix_width; i++) {
        etiquettes_columns[i] = new wxStaticText(this, -1, wxT("wartości kolumn"), wxPoint(2 + i * boardrect_width, boardmatrix_height_pixels + i * 20));
    }
    // utworzenie tablicy zmiennych przechowujących wartość rzędów i kolumn
    values_of_rows = new int[boardmatrix_height];
    values_of_columns = new int[boardmatrix_width];

    //etykiety testowe z położeniem okna
    //st1 = new wxStaticText(this, -1, wxT("hh"), wxPoint(200, 10)); //etykieta na panelu
    //st2 = new wxStaticText(this, -1, wxT("gg"), wxPoint(200, 30)); //etykieta
	
    color = 234000; //kolor wstępny
	
    //Buttons buttons(this); //stworzenie obiektu z buttonami na tym (this) panelu
    //ptr_buttons = &buttons; //pobranie wskaźnika na obiekt buttons - potrzebny do wyłuskania koloru ptr_buttons->GetColor()
    //ptr_buttons = this; //pobranie wskaźnika na obiekt buttons - potrzebny do wyłuskania koloru ptr_buttons->GetColor()

   // std::cout << "buttons adres " << &buttons  << std::endl; //adres obiektu buttons
    //std::cout << "buttons adres " << ptr_buttons  << std::endl; //adres obiektu buttons

    //std::cout << "buttons->GetColor() " << ptr_buttons->GetColor() << std::endl;

    //wxPanel *panel = new wxPanel(this, -1);//////////nowy panel

    //wxPanel panel(this, -1);


    this->Connect(wxEVT_PAINT, wxPaintEventHandler(WorkPanel::OnPaint)); //zdarzenie rysowania dla panelu

    //this->Connect(wxEVT_MOVE, wxMoveEventHandler(WorkPanel::OnMove)); //zdarzenie przesuwania okna
    this->Connect(wxEVT_SIZE, wxSizeEventHandler(WorkPanel::OnResize)); //zdarzenie zmiany rzomiaru okna
    //this->Connect(wxEVT_MOTION, wxMouseEventHandler(WorkPanel::OnMouseMoving)); //zdarzenie ruchu mysza na oknie

    this->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(WorkPanel::OnMouseLeftClick)); //zdarzenie klikniecia lewym przyciskiem mysza na oknie
}

/*
WorkPanel::~WorkPanel()
{
	//dtor
}
*/

wxPanel* WorkPanel::PanelPointer()
{
    return this;
}

void WorkPanel::ClearMatrix() {
	for (int i = 0; i < boardmatrix_width; ++i) {
		for (int j = 0; j < boardmatrix_height; ++j) {
			boardmatrix[i][j] = 0;
		}
	}
}

//malowanie przy pokazywaniu, odświeżaniu itp
void WorkPanel::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    //wxBufferedPaintDC dc(this); //buforowanie - przeniesienie na ekran przy destrukcji obiektu dc - na końcu tej metody

    std::cout << "Rysowanie  " << std::endl;

    int board_width = boardmatrix_width * boardrect_width;
    int board_height = boardmatrix_height * boardrect_height;

    dc.SetPen(wxPen(wxColour(255, 255, 255))); //ołowek (ramka)
    dc.SetBrush(wxBrush(wxColour(255, 255, 255)));    //wypelnienie
    dc.DrawRectangle(0, 0, board_width, board_height);

    /*
    dc.SetPen(wxPen(wxColour(0, 0, 255))); //niebieski prostokąt
    dc.SetBrush(wxBrush(wxColour(255, 0, 0))); //czerwone wypełnienie
    dc.DrawRectangle(board_width, 0, 88, 60);

    dc.SetPen(wxPen(wxColour(0, 0, 0)));    //czarny prostokąt
    dc.SetBrush(wxBrush(wxColour(0, 0, 255))); //niebieskie wypełnienie
    dc.DrawRectangle(board_width, 60, 88, 100);

    dc.SetPen(wxPen(wxColour(0, 0, 0)));    //czarny iks
    dc.DrawLine(board_width, 160, board_width + 88, board_height); //start x y end x y
    dc.DrawLine(board_width + 88, 160, board_width, board_height);
    */

    dc.SetPen(wxPen(wxColour(0, 0, 0))); //ołowek (ramka)
    //dc.SetBrush(wxBrush(wxColour(0, 255, 0)));   		 //wypelnienie
    //if(color == 1003) dc.SetBrush(wxBrush(wxColour(255, 0, 0)));    //wypelnienie ID_RED == 1003
    for (int x = 0; x<boardmatrix_width; x++) {
        for (int y = 0; y<boardmatrix_height; y++) {
			switch(boardmatrix[x][y]) {
				case ID_RED:
					dc.SetBrush(wxBrush(wxColour(255, 0, 0)));  //wypelnienie czerwonym
				break;
				case ID_GREEN:
					dc.SetBrush(wxBrush(wxColour(0, 255, 0)));  //wypełnienie zielonym
				break;
				case ID_BLUE:
					dc.SetBrush(wxBrush(wxColour(0, 0, 255)));  //wypełnienie niebieskim
				break;
				default:
					dc.SetBrush(wxBrush(wxColour(255, 255, 255))); //biały pusty kwadrat
				break;
			};
			dc.DrawRectangle(x*boardrect_width, y*boardrect_height, boardrect_width, boardrect_height); //zawsze rysuj kwadrat
        }
    }
}

/*
void WorkPanel::OnMove(wxMoveEvent& event)
{
	wxPoint size = event.GetPosition();
	st1->SetLabel(wxString::Format(wxT("x: %d"), size.x ));
	st2->SetLabel(wxString::Format(wxT("y: %d"), size.y ));
	std::cout << "Przenoszenie okna x = " << size.x << " y = " << size.y << std::endl;
}
*/

void WorkPanel::OnResize(wxSizeEvent & event) //zmiana rozmiaru okna
{
    std::cout << "Zmiana rozmiaru  " << std::endl;
    wxSize size = event.GetSize();

    int x = size.x;
    wxPoint ppp;
    ppp.x = x;
    //st1->SetLabel(wxString::Format(wxT("x: %d"), ppp.x ));
    //st2->SetLabel(wxString::Format(wxT("y: %d"), size.y ));

    std::cout << "x = " << x << " y = " << size.y << std::endl;
}

void WorkPanel::OnMouseMoving(wxMouseEvent& event)
{
    std::cout << "Mouse moving no click" << std::endl;
}

void WorkPanel::OnMouseLeftClick(wxMouseEvent& event)
{
    int x = event.GetX()/20;
    int y = event.GetY()/20;
    std::cout << "Left Click x = " << x << " y = " << y << std::endl;

    if(x>=0 && x < boardmatrix_width && y >=0 && y < boardmatrix_height)
    {
        std::cout << "board OK " << std::endl;


        std::cout << "click " << this << std::endl;

        //std::cout << "get color " << ptr_buttons->GetColor() << std::endl; //CHUJ dupa i kamieni kupa bo niezainicjalizowana instancja :/

        //int kolor = ptr_buttons->color;

        //std::cout << "get color " << kolor << std::endl; //CHUJ dupa i kamieni kupa bo niezainicjalizowana instancja :/

        //std::cout << "onMouse buttons adres " << ptr_buttons  << std::endl; //adres obiektu buttons

        wxClientDC dc(this);
        dc.SetPen(wxPen(wxColour(0, 0, 0))); //ołowek (ramka)
        switch(color)
        {
        	case ID_WHITE:
                dc.SetBrush(wxBrush(wxColour(255, 255, 255)));  //wypełnienie niebieskim
                boardmatrix[x][y] = ID_WHITE;
            break;
            case ID_RED:
                dc.SetBrush(wxBrush(wxColour(255, 0, 0)));  //wypelnienie czerwonym
                boardmatrix[x][y] = ID_RED; //ten piksel ustawimy w kolor czerwony
            break;
            case ID_GREEN:
                dc.SetBrush(wxBrush(wxColour(0, 255, 0)));  //wypełnienie zielonym
                boardmatrix[x][y] = ID_GREEN;
            break;
            case ID_BLUE:
                dc.SetBrush(wxBrush(wxColour(0, 0, 255)));  //wypełnienie niebieskim
                boardmatrix[x][y] = ID_BLUE;
            break;
        };
		dc.DrawRectangle(x*20, y*20, 20, 20);
		CalculateRowsAndColumns();		// przeliczenie nowych wartości rzędów i kolumn
		DisplayRowsAndColumns();		// wyświetl nowe wartości
    }
}

void WorkPanel::CalculateRowsAndColumns() {
	for (int i = 0; i < boardmatrix_height; ++i) {		// dla każdego wiersza
		values_of_rows[i] = 0;							// wyczyszczenie zmiennej pod nowe obliczenia
		for (int j = 0; j < boardmatrix_width; ++j) {	// dla każdej wartości x w danym rzędzie
			if (boardmatrix[j][i]) {
				values_of_rows[i] += (1 << j);
			}
		}
	}
	for (int i = 0; i < boardmatrix_width; ++i) {		// dla każdej kolumny
		values_of_columns[i] = 0;						// wyczyszczenie zmiennej pod nowe obliczenia
		for (int j = 0; j < boardmatrix_height; ++j) {	// dla każdej wartości y w danej kolumnie
			if (boardmatrix[i][j]) {
				values_of_columns[i] += (1 << j);
			}
		}
	}
}

void WorkPanel::DisplayRowsAndColumns() {
	char buffer[100];
	for (int i = 0; i < boardmatrix_height; ++i) {
		itoa(values_of_rows[i], buffer, hexOrDecOrBin);
		etiquettes_rows[i]->SetLabel(buffer);
	}
	for (int i = 0; i < boardmatrix_width; ++i) {
		//etiquettes_columns[i]->SetLabel(wxString::Format(wxT("x: %d"), number ));
		itoa(values_of_columns[i], buffer, hexOrDecOrBin);
		etiquettes_columns[i]->SetLabel(buffer);
	}
}















































