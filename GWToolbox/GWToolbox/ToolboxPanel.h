#pragma once

#include "OSHGui\OSHGui.hpp"

class ToolboxPanel : public OSHGui::Panel {
public:
	ToolboxPanel(OSHGui::Control* parent) : OSHGui::Panel(parent) {}

	// Create user interface
	virtual void BuildUI() = 0;

	// Update user interface, try to keep it lightweight, will be executed in gw render thread
	virtual void UpdateUI() = 0;

	// Update everything else. DO NOT TOUCH USER INTERFACE.
	virtual void MainRoutine() = 0;
};
