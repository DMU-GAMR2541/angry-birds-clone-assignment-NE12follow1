#pragma once
#include "DynamicObject.h"
#include "StaticObject.h"

class UI : public DynamicObject, public StaticObject {
private:
public:
	UI() = default;

	~UI() {};
};