#include "cMain.h"
#include "Pinyin.h"
#include <Windows.h>
#include <wx/icon.h>



wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Pinyin Converter", wxPoint(30, 30), wxSize(335, 300), wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {
	
	SetBackgroundColour(*wxWHITE);
	InputLabel = new wxStaticText(this, wxID_ANY, "Input: ", wxPoint(10, 20), wxSize(300, 15));
	Input = new wxTextCtrl(this, wxID_ANY, "Ni3 Hao3", wxPoint(10, 40), wxSize(300, 60));
	Convert = new wxButton(this, 10001, "Convert", wxPoint(92.5, 120), wxSize(130, 40));
	InputLabel = new wxStaticText(this, wxID_ANY, "Output: ", wxPoint(10, 170), wxSize(300, 15));
	Output = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 190), wxSize(300, 60));
	
}


cMain::~cMain() {

}

void cMain::OnButtonClicked(wxCommandEvent& evt) {
	Output->Clear();

	wxString mystring = Input->GetValue();
	std::string stlstring = std::string(mystring.mb_str());


	Output->AppendText(Pinyin::convertToPinyin(stlstring));
	evt.Skip();
}


	
