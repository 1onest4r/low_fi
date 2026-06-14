#include "config.h"
#include "gpu_preference.h"

//for forcing the dGPU
#ifdef _WIN32
extern "C"
{
	// Prefer NVIDIA dGPU
	__declspec(dllexport)
		unsigned long NvOptimusEnablement = 0x00000001;
}

extern "C"
{
	// Prefer AMD dGPU
	__declspec(dllexport)
		int AmdPowerXpressRequestHighPerformance = 1;
}
#endif

GPUType GPUInfo::m_type = GPUType::Unknown;
std::string GPUInfo::m_vendor = "";
std::string GPUInfo::m_renderer = "";

void GPUInfo::Init() {
	const char* vendor = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
	const char* renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));

	if (!vendor || !renderer) {
		std::cout << "Couldn't get GPU info" << std::endl;
		return;
	}

	m_vendor = vendor;
	m_renderer = renderer;

	std::string info = m_vendor + " " + m_renderer;

	if (info.find("Intel") != info.npos) {
		m_type = GPUType::Integrated;
	}
	else if (
		info.find("NVIDIA") != info.npos ||
		info.find("Radeon") != info.npos ||
		info.find("AMD") != info.npos) {
		m_type = GPUType::Dedicated;
	}
	else {
		return;
	}

}

GPUType GPUInfo::GetType() {
	return m_type;
}

const std::string& GPUInfo::GetVendor() {
	return m_vendor;
}

const std::string& GPUInfo::GetRenderer() {
	return m_renderer;
}