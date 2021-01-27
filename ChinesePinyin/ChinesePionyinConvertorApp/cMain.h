#pragma once
#include "wx/wx.h"



class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:


	wxButton* Convert = nullptr;
	wxTextCtrl* Input = nullptr;
	wxTextCtrl* Output = nullptr;
	wxStaticText* InputLabel = nullptr;
	wxStaticText* OutputLabel = nullptr;


	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

