/*
 *@BEGIN LICENSE
 *
 * PSI4: an ab initio quantum chemistry software package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *@END LICENSE
 */

/*!
 \file
 \ingroup PSIO
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <libpsio/psio.h>
#include <libpsio/psio.hpp>
#include <psi4-dec.h>

namespace psi {

void PSIO::get_filename(unsigned int unit, char **name, bool remove_namespace) {
  std::string kval;
  std::string dot(".");
  std::string ns = dot + pid_;
  ns += (default_namespace_ == "" || remove_namespace) ? "" : dot + default_namespace_;
  //std::string path = PSIOManager::shared_object()->get_file_path(unit);
  //printf("%s %s: %d\n", path.c_str(), ns.c_str(), unit);
  //*name = strdup((path + ns).c_str());
  //return;

  kval = filecfg_kwd("PSI", "NAME", unit);
  if (!kval.empty()) {
    kval = kval + ns;
    *name = strdup(kval.c_str());
    return;
  }
  kval = filecfg_kwd("PSI", "NAME", -1);
  if (!kval.empty()) {
    kval = kval + ns;
    *name = strdup(kval.c_str());
    return;
  }
  kval = filecfg_kwd("DEFAULT", "NAME", unit);
  if (!kval.empty()) {
    kval = kval + ns;
    *name = strdup(kval.c_str());
    return;
  }
  kval = filecfg_kwd("DEFAULT", "NAME", -1);
  if (!kval.empty()) {
    kval = kval + ns;
    *name = strdup(kval.c_str());
    return;
  }


  // assume that the default has been provided already
  abort();
}

int psio_get_filename_default(char **name) {
  std::string kval;
  kval = _default_psio_lib_->filecfg_kwd("PSI", "NAME", -1);
  if (!kval.empty()) {
    *name = strdup(kval.c_str());
    return (1);
  }
  kval = _default_psio_lib_->filecfg_kwd("DEFAULT", "NAME", -1);
  if (!kval.empty()) {
    *name = strdup(kval.c_str());
    return (1);
  }

  // assume that the default has been provided already
  abort();
}

}

