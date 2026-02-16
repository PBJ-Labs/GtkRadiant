/*
   Copyright (C) 1999-2007 id Software, Inc. and contributors.
   For a list of contributors, see the accompanying CONTRIBUTORS file.

   This file is part of GtkRadiant.

   GtkRadiant is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   GtkRadiant is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GtkRadiant; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  
*/

#ifndef CLIPBOARD_H
#define CLIPBOARD_H

auto constexpr CLIPBOARD_BRUSH;
auto constexpr CLIPBOARD_ENTITY;
auto constexpr CLIPBOARD_MODEL;
auto constexpr CLIPBOARD_TEXTURE;
auto constexpr CLIPBOARD_GRID;
auto constexpr CLIPBOARD_WINDOW;
auto constexpr CLIPBOARD_CAULK;

class Clipboard {
public:
  Clipboard();
  virtual ~Clipboard() = delete;

  const char* m_ClipboardName = "CLIPBOARD";

  //*getClipboard, returns a clipboard
  Clipboard& getClipboard(const Clipboard& pClipboard){
     Clipboard& m_clipboard = (&pClipboard);
     if(!m_clipboard){
        delete ( &this );
     }
     return m_clipboard;
  }

  // needs to returns so make (*)
  virtual void * createClipboard(auto pType) = 0;
  virtual void senderObjectToClipboard(const Clipboard& pBoard, void* OBJ) = 0;

};

#endif
