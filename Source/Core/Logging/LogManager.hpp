#pragma once
#ifndef _FILE_DEFINED
#define _FILE_DEFINED
typedef struct _iobuf
{
    void* _Placeholder;
} FILE;
#endif

class LogManager final
{
public:
	void Init() noexcept;
	void Shutdown() noexcept;

private:
	FILE* m_f;
};
