#pragma once

// STL includes.
#include    <memory>

// "Home-made" includes.
#include    <Graphic.h>

#pragma pack(push, 1)

namespace Folio
{

namespace Games
{

namespace AticAtac
{

// The font.
typedef std::shared_ptr<Folio::Core::Graphic::GdiRasterFont>    Font;


// Routines.

extern  Font    GetFont ();

} // Endnamespace.

} // Endnamespace.

} // Endnamespace.

#pragma pack(pop)

/******************************* End of File *******************************/
