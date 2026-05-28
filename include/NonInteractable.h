#pragma once
#include "StaticObject.h"

class NonInteractable : public StaticObject {
private:

public:
	NonInteractable() = default;
	NonInteractable() {

	}

	~NonInteractable() {
		std::cout << "Non-Interactable Destroyed";
	}
};