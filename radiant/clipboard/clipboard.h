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

auto constexpr CLIPBOARD_BRUSH = 0;
auto constexpr CLIPBOARD_ENTITY = 1;
auto constexpr CLIPBOARD_MODEL = 2;
auto constexpr CLIPBOARD_TEXTURE = 3;
auto constexpr CLIPBOARD_GRID = 4;
auto constexpr CLIPBOARD_WINDOW = 5;
auto constexpr CLIPBOARD_CAULK = 6;

class Clipboard {
public:
  Clipboard();
  virtual ~Clipboard() = default;

  //*getClipboard, returns a clipboard
  const Clipboard& getClipboard() const{
     return *this;
  }


  // needs to returns so make (*)
  virtual void * createClipboard(auto pType) = 0;
  virtual void senderObjectToClipboard(const Clipboard& pBoard, void* OBJ) = 0;
  virtual void deleteObjectFromClipboard(const Clipboard& pBoard, void * OBJ) = 0;

  virtual void setClipboardName(const Clipboard& pBoard, const char* pName) = 0;

  const std::string& getBoardName() const{
     return m_ClipboardName;
  }


protected:
 std::string m_ClipboardName = "DEF_NAME";
 

};

#endif
