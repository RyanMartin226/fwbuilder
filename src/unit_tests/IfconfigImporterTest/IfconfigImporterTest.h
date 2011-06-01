/*

                          Firewall Builder

                 Copyright (C) 2011 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

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

#ifndef IFCONFIGIMPORTERTEST_H
#define IFCONFIGIMPORTERTEST_H

#include "fwbuilder/Resources.h"
#include "fwbuilder/FWObjectDatabase.h"
#include "fwbuilder/Library.h"
#include "fwbuilder/FWException.h"
#include "fwbuilder/Logger.h"

#include <cppunit/extensions/HelperMacros.h>

#include <map>
#include <fstream>
#include <iostream>

#include <QString>


class IfconfigImporterTest : public CppUnit::TestFixture
{
    libfwbuilder::FWObjectDatabase *db;
    libfwbuilder::Library *lib;
    libfwbuilder::QueueLogger *logger;
    
    std::string openTestFile(const QString &file_name);
    
public:
    void setUp();

    void linuxIfconfigTest();
    void bsdIfconfigTest();
    
    CPPUNIT_TEST_SUITE(IfconfigImporterTest);

    CPPUNIT_TEST(linuxIfconfigTest);
    CPPUNIT_TEST(bsdIfconfigTest);
    
    CPPUNIT_TEST_SUITE_END();

};

#endif // IFCONFIGIMPORTERTEST_H