#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp()
{
}

cApp::~cApp()
{
}

bool cApp::OnInit()
{

    m_frame1 = new cMain();
    m_frame1->Show();
    m_frame1->SetIcon(wxIcon("IDI_ICON1"));
    

    return true;
}