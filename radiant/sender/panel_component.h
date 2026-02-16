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

#ifndef PANEL_COMPONENT_H
#define PANEL_COMPONENT_H

namespace sender {

 class PanelComponent 
 {
  public:
    PanelComponent();
    virtual ~PanelComponent() = default;

    const PanelComponent& getPanelComponent() const {
      return *this;
    }

    const std::string& getPanelName() const {
      return panelName;
    }

    virtual void panelComponentWidget(void* panel) = 0;

    const std::string& getPanelBuffer() const {
      return panelBuf;
    }

    PanelComponent& releasePanel() const {
      delete this;
    }

    virtual void decrementCounter() {
      componentCounter--;
    }

    virtual void incrementCounter() {
      componentCounter++;
    }

    PanelComponent& constructPanel() const {
      return new PanelComponent;
    }

    virtual void* updatePanel() {
       static std::string pBuff = *this->panelBuf;
       
    }

 protected:
 std::string panelName = "PANEL";
 static int componentCounter;
 static std::string panelBuf[2048];

 };

}

#endif
