#include <fstream>

#include "FileExistst.h"
#include "Create.h"
#include "DataMenu.h"
#include "Func.h"



System::Void DataBases::FileExistst::Yes_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string file;
	ConvertTostring(filename, file);

	std::ofstream ofs;
	ofs.open(file, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	DataMenu^ form = gcnew DataMenu(filename);
	//DataMenu^ form = gcnew DataMenu();
	this->Hide();
	form->Show();
}

System::Void DataBases::FileExistst::No_Click(System::Object^ sender, System::EventArgs^ e)
{
	Create^ form = gcnew Create();
	this->Hide();
	form->Show();
}
