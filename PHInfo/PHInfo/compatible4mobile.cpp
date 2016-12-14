#include "stdafx.h"
#include "compatible4mobile.h"

using namespace std;

CFont CCompatibleFont::ListFont;
CFont CCompatibleFont::NormalFont;
CFont CCompatibleFont::NoteFont;
CFont CCompatibleFont::TimerFont;
CFont CCompatibleFont::TreeFont;
CFont CCompatibleFont::TinyFont;
CFont CCompatibleFont::BigFont;
CFont CCompatibleFont::SontiFont;
//////////////////////////////////////////////////////////////////////////
BOOL CCompatibleFont::InitFonts()
{
	BOOL bRes = TRUE;
#ifdef BUILD_MOBILE
	bRes &= BigFont.CreateFontW(-20,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= TreeFont.CreateFontW(-19,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= ListFont.CreateFontW(-18,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= NormalFont.CreateFontW(-17,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= TimerFont.CreateFontW(-16,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= NoteFont.CreateFontW(-15,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= TinyFont.CreateFontW(-12,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= SontiFont.CreateFontW(-15,0,0,0,400,0,0,0,' ',0,0,0,0,L"ËÎÌå");
#else
	bRes &= BigFont.CreateFontW(-15,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= TreeFont.CreateFontW(-12,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= ListFont.CreateFontW(-12,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= NormalFont.CreateFontW(-13,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= TimerFont.CreateFontW(-15,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= NoteFont.CreateFontW(-12,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= TinyFont.CreateFontW(-10,0,0,0,400,0,0,0,' ',0,0,0,0,L"Î¢ÈíÑÅºÚ");
	bRes &= SontiFont.CreateFontW(-15,0,0,0,400,0,0,0,' ',0,0,0,0,L"ËÎÌå");
#endif
	return bRes;
}