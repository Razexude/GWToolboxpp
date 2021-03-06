#include "Config.h"

#include "GuiUtils.h"

CSimpleIni* Config::inifile_ = nullptr;
std::wstring Config::inifile_path_;

void Config::Initialize() {
	if (inifile_ != nullptr) return;

	inifile_path_ = GuiUtils::getPath(L"GWToolbox.ini");

	inifile_ = new CSimpleIni(false, false, false);
	inifile_->LoadFile(inifile_path_.c_str());
}

void Config::Destroy() {
	if (inifile_ == nullptr) return;

	Save();
	inifile_->Reset();
	delete inifile_;
}

std::list<std::wstring> Config::IniReadSections() {
	CSimpleIni::TNamesDepend entries;
	inifile_->GetAllSections(entries);
	std::list<std::wstring> sections(entries.size());
	for (CSimpleIni::Entry entry : entries) {
		sections.push_back(std::wstring(entry.pItem));
	}
	return sections;
}
