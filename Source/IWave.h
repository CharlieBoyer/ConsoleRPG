#pragma once

class IWave
{
	virtual ~IWave() = default;
	virtual void Display() const = 0;
};
