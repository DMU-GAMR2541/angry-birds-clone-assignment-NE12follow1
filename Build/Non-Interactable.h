#pragma once
#include "DynamicObject.h"
#include "StaticObject.h"

class NonInteractable : public StaticObject {
private:
public:
	NonInteractable() = default;

	~NonInteractable() {};
};