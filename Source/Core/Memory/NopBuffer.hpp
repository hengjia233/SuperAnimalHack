#pragma once
#include <cstdint>

class NopBuffer final
{
public:
	explicit NopBuffer(uintptr_t address, size_t length);
	~NopBuffer();

	void Nop();
	void Restore();

private:
	unsigned char* m_bytes;
	bool m_bNopped;

	const uintptr_t m_address;
	const size_t m_length;
};