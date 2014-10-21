#include "pch.h"

//////////////////////////////////////////////////////////////////////////////
//
// Effect Object Factories
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// The EffectWindow Class
//
//////////////////////////////////////////////////////////////////////////////

EffectWindow::EffectWindow(
          EffectApp*	papp,
     const ZString&		strCommandLine,
	 const LPCSTR&		strTitle,
          bool			bStartFullscreen,
    const WinRect&		rect,
    const WinPoint&		sizeMin,
          HMENU			hmenu
) :
    EngineWindow(
        papp,
        strCommandLine,
        strTitle,
        bStartFullscreen,
        rect,
        sizeMin,
        hmenu
    )
{
}
