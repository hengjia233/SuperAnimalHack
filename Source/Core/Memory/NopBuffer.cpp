#include "NopBuffer.hpp"
#include <Windows.h>
#include <stdexcept>

NopBuffer::NopBuffer(uintptr_t address, size_t length)
	: m_address(address), m_length(length), m_bytes(nullptr), m_bNopped(false)
{}

NopBuffer::~NopBuffer()
{
	if (m_bNopped)
	{
		Restore();
	}
}

void NopBuffer::Nop()
{
	if (m_bNopped) return;

	DWORD oldProt;
	VirtualProtect((void*)m_address, m_length, PAGE_EXECUTE_READWRITE, &oldProt);
	{
		m_bytes = new unsigned char[m_length];
		memcpy_s(m_bytes, m_length, (void*)m_address, m_length);

		auto nopArea = new unsigned char[m_length];
		memset(nopArea, 0x90, m_length);

		memcpy_s((void*)m_address, m_length, nopArea, m_length);

		delete[] nopArea;
	}
	VirtualProtect((void*)m_address, m_length, oldProt, &oldProt);

	m_bNopped = true;
}

void NopBuffer::Restore()
{
	if (!m_bNopped || m_bytes == nullptr) return;

	DWORD oldProt;
	VirtualProtect((void*)m_address, m_length, PAGE_EXECUTE_READWRITE, &oldProt);
	{
		memcpy_s((void*)m_address, m_length, m_bytes, m_length);
		delete[] m_bytes;
	}
	VirtualProtect((void*)m_address, m_length, oldProt, &oldProt);

	m_bNopped = false;
}
