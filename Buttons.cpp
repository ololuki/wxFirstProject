#include "Buttons.h"

/*Buttons::Buttons()
{
	//ctor
}
*/

Buttons::Buttons(wxWindow * parent) //: wxPanel(parent)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270, 150), wxBORDER_SUNKEN)
{
    color = 103666;
    ptr_parent = (wxPanel*)parent; //zapamietanie panelu parent
    btnClear = new wxButton(this, ID_CLEAR, wxT("CLEAR"), wxPoint(10, 20));
    white = new wxButton(this, ID_WHITE, wxT("White"), wxPoint(10, 60));
    red = new wxButton(this, ID_RED, wxT("Red"), wxPoint(10, 100));
    green = new wxButton(this, ID_GREEN, wxT("Green"), wxPoint(10, 140));
    blue = new wxButton(this, ID_BLUE, wxT("Blue"), wxPoint(10, 180));
    btnHexOrDecOrBin = new wxButton(this, ID_HEXORDECORBIN, wxT("Hex Dec Bin"), wxPoint(10, 220));
    
    labelHexOrDecOrBin = new wxStaticText(this, -1, wxT("hex/dec/bin"), wxPoint(10, 260)); //etykieta na Buttons
    
    this->Connect(ID_CLEAR, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Buttons::OnBtnClear));
    this->Connect(ID_WHITE, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Buttons::OnWhite));
    this->Connect(ID_RED, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Buttons::OnRed));
    this->Connect(ID_GREEN, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Buttons::OnGreen));
    this->Connect(ID_BLUE, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Buttons::OnBlue));
	this->Connect(ID_HEXORDECORBIN, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Buttons::OnHexOrDecOrBin));
    std::cout << "buttons::red adres " << parent << std::endl;
}

Buttons::~Buttons()
{
	//dtor
}

int Buttons::GetColor()
{
    return color;
}

void Buttons::OnBtnClear(wxCommandEvent & event) {
	//color = ID_WHITE; //przestarzałe - wywalić
    RootFrame *comm = (RootFrame *) ptr_parent->GetParent();
    comm->bb->ClearMatrix();
    comm->bb->CalculateRowsAndColumns();		// przeliczenie nowych wartości rzędów i kolumn
	comm->bb->DisplayRowsAndColumns();		// wyświetl nowe wartości
	comm->bb->Refresh();		// invalidate
	comm->bb->Update();			// invalidate ciąg dalszy
}

void Buttons::OnWhite(wxCommandEvent & event)
{
    color = ID_WHITE; //przestarzałe - wywalić
    RootFrame *comm = (RootFrame *) ptr_parent->GetParent();
    comm->bb->color = ID_WHITE; // zapisujemy kolor - może zmienić na metodę ;D
}

void Buttons::OnRed(wxCommandEvent & event)
{
    color = ID_RED; //przestarzałe - wywalić
    std::cout << "buttons.red adres " << this << std::endl;
    RootFrame *comm = (RootFrame *) ptr_parent->GetParent();
    std::cout << "buttons.red parent adres (main panel) " << ptr_parent << std::endl; //main panel
    std::cout << "buttons.red parent adres (rootFrame) " << comm << std::endl; //main panel parent = rootFrame
    std::cout << "buttons.red parent adres (bb panel)" << comm->bb << std::endl; //lewy panel bb
    std::cout << "buttons.red parent adres (bb panel)" << comm->bb->color << std::endl; //lewy panel bb -> kolor
    comm->bb->color = ID_RED; // zapisujemy kolor - może zmienić na metodę ;D
}

void Buttons::OnGreen(wxCommandEvent & event)
{
    color = ID_GREEN;//przestarzałe - wywalić
    RootFrame *comm = (RootFrame *) ptr_parent->GetParent();
    comm->bb->color = ID_GREEN; // zapisujemy kolor - może zmienić na metodę ;D
    std::cout << "buttons.green adres " << this << std::endl;
}

void Buttons::OnBlue(wxCommandEvent & event)
{
    color = ID_BLUE;//przestarzałe - wywalić
    RootFrame *comm = (RootFrame *) ptr_parent->GetParent();
    comm->bb->color = ID_BLUE; // zapisujemy kolor - może zmienić na metodę ;D
    std::cout << "buttons.blue adres " << this << std::endl;
}

void Buttons::OnHexOrDecOrBin(wxCommandEvent & event)
{
    RootFrame *comm = (RootFrame *) ptr_parent->GetParent();
    switch(comm->bb->hexOrDecOrBin) {
	case 2:
		comm->bb->hexOrDecOrBin = 10;
		labelHexOrDecOrBin->SetLabel(wxString::Format(wxT("Decimal")));
		break;
	case 10:
		comm->bb->hexOrDecOrBin = 16;
		labelHexOrDecOrBin->SetLabel(wxString::Format(wxT("Hexadecimal")));
		break;
	case 16:
		comm->bb->hexOrDecOrBin = 2;
		labelHexOrDecOrBin->SetLabel(wxString::Format(wxT("Binary")));
		break;
    }
	comm->bb->CalculateRowsAndColumns();		// przeliczenie nowych wartości rzędów i kolumn
	comm->bb->DisplayRowsAndColumns();		// wyświetl nowe wartości
	comm->bb->Refresh();		// invalidate
	comm->bb->Update();			// invalidate ciąg dalszy
}



























