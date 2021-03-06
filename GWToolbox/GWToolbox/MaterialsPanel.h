#pragma once

#include "ToolboxPanel.h"

class MaterialsPanel : public ToolboxPanel {
	enum Item {
		Essence,
		Grail,
		Armor,
		Powerstone,
		ResScroll,
		Any
	};

public:
	MaterialsPanel(OSHGui::Control* parent) : ToolboxPanel(parent) {}

	void BuildUI() override;
	void UpdateUI() override {};
	void MainRoutine() override {};

private:
};

