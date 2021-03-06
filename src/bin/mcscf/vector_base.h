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

#ifndef _psi_src_lib_libmemtrix_vector_base_h_
#define _psi_src_lib_libmemtrix_vector_base_h_

#include <libpsi4util/memory_manager.h>
#include <cstring> // for size_t

namespace psi{ namespace mcscf{

class VectorBase
{
public:
  VectorBase();
  VectorBase(int rows);
  ~VectorBase();

  //Inlines
  int     get_elements()    {return(elements_);}
  void    set(int i, double value) {vector_[i]  = value;}
  void    add(int i, double value) {vector_[i] += value;}
  double  get(int i)               {return(vector_[i]);}
  double* get_vector()  {return(vector_);}

  void print();
  void copy(VectorBase& source);
private:
  // Vector size
  size_t  elements_;

  // Vector data
  double* vector_;
};

}}

#endif // _psi_src_lib_libmemtrix_vector_base_h_
