/* 

                          Firewall Builder

                 Copyright (C) 2009 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@vk.crocodile.org

  $Id: OSConfigurator_linux24.h 752 2009-01-30 04:54:03Z vadim $

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef _OSNETWORKCONFIGURATOR_IPCOP_HH
#define _OSNETWORKCONFIGURATOR_IPCOP_HH

#include "config.h"

#include "OSConfigurator_linux24.h"

#include "OSData.h"

namespace fwcompiler {

    class OSConfigurator_ipcop : public OSConfigurator_linux24 {
public:

	virtual ~OSConfigurator_ipcop() {};
	OSConfigurator_ipcop(libfwbuilder::FWObjectDatabase *_db,
                             libfwbuilder::Firewall *fw, bool ipv6_policy);

	virtual std::string myPlatformName();

        virtual int  prolog();
        virtual void epilog();

	virtual void addVirtualAddressForNAT(const libfwbuilder::Address *addr);
	virtual void addVirtualAddressForNAT(const libfwbuilder::Network *nw);

    };
}

#endif
