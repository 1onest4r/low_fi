#pragma once
#include "config.h"

enum class GPUType {
	Integrated,
	Dedicated,
	Unknown
};

class GPUInfo {
public:
	static void Init();

	static GPUType GetType();
	static const std::string& GetVendor();
	static const std::string& GetRenderer();

private:
	static GPUType m_type;
	static std::string m_vendor;
	static std::string m_renderer;
};