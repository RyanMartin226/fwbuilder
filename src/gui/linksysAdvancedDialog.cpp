/*

                          Firewall Builder

                 Copyright (C) 2004 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

  $Id$

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

#include "../../config.h"
#include "global.h"
#include "platforms.h"

#include "linksysAdvancedDialog.h"
#include "FWWindow.h"

#include "fwbuilder/Firewall.h"
#include "fwbuilder/Management.h"
#include "fwbuilder/Resources.h"

#include <qcheckbox.h>
#include <qspinbox.h>
#include <qcombobox.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qregexp.h>
#include <qtabwidget.h>

using namespace std;
using namespace libfwbuilder;

linksysAdvancedDialog::~linksysAdvancedDialog()
{
    delete m_dialog;
}

linksysAdvancedDialog::linksysAdvancedDialog(QWidget *parent,FWObject *o)
    : QDialog(parent)
{
    m_dialog = new Ui::linksysAdvancedDialog_q;
    m_dialog->setupUi(this);

    obj=o;

    FWOptions *fwopt=(Firewall::cast(obj))->getOptionsObject();
    assert(fwopt!=NULL);

    Management *mgmt=(Firewall::cast(obj))->getManagementObject();
    assert(mgmt!=NULL);
/*
 * since v2.0.3 we do not need to know shell prompt on linksys. Will
 * remove the page completely when code becomes stable.
 */
    m_dialog->tabWidget->removeTab( 1 );

    QStringList threeStateMapping;

    threeStateMapping.push_back(QObject::tr("No change"));
    threeStateMapping.push_back("");

    threeStateMapping.push_back(QObject::tr("On"));
    threeStateMapping.push_back("1");

    threeStateMapping.push_back(QObject::tr("Off"));
    threeStateMapping.push_back("0");

/* set default prompts */
    if (fwopt->getStr("prompt1").empty())
        Resources::os_res["linksys"]->Resources::setDefaultOption(fwopt,
                           "/FWBuilderResources/Target/options/default/prompt1");

    if (fwopt->getStr("prompt2").empty())
        Resources::os_res["linksys"]->Resources::setDefaultOption(fwopt,
                           "/FWBuilderResources/Target/options/default/prompt2");

    data.registerOption( m_dialog->linksys_prompt1,
                         fwopt,
                         "prompt1" );
    data.registerOption( m_dialog->linksys_prompt2,
                         fwopt,
                         "prompt2" );

    data.registerOption( m_dialog->linksys_path_iptables,
                         fwopt,
                         "linux24_path_iptables" );
    data.registerOption( m_dialog->linksys_path_ip,
                         fwopt,
                         "linux24_path_ip"       );
    data.registerOption( m_dialog->linksys_path_lsmod,
                         fwopt,
                         "linux24_path_lsmod"    );
    data.registerOption( m_dialog->linksys_path_logger,
                         fwopt,
                         "linux24_path_logger"   );
    data.registerOption( m_dialog->linksys_path_modprobe,
                         fwopt,
                         "linux24_path_modprobe" );
    data.registerOption( m_dialog->linksys_path_vconfig,
                         fwopt,
                         "linksys_path_vconfig");
    data.registerOption( m_dialog->linksys_path_brctl,
                         fwopt,
                         "linksys_path_brctl");
    data.registerOption( m_dialog->linksys_path_ifenslave,
                         fwopt,
                         "linksys_path_ifenslave");

    data.loadAll();

    m_dialog->tabWidget->setCurrentIndex(0);
}

/*
 * store all data in the object
 */
void linksysAdvancedDialog::accept()
{
    FWOptions *fwopt=(Firewall::cast(obj))->getOptionsObject();
    assert(fwopt!=NULL);

    Management *mgmt=(Firewall::cast(obj))->getManagementObject();
    assert(mgmt!=NULL);

    data.saveAll();

    QDialog::accept();
}

void linksysAdvancedDialog::reject()
{
    QDialog::reject();
}

void linksysAdvancedDialog::setDefaultPrompts()
{
    FWOptions *fwopt=(Firewall::cast(obj))->getOptionsObject();
    assert(fwopt!=NULL);
    m_dialog->linksys_prompt1->setText(
        Resources::getTargetOptionStr("linksys","default/prompt1").c_str() );
    m_dialog->linksys_prompt2->setText(
        Resources::getTargetOptionStr("linksys","default/prompt2").c_str() );
}

