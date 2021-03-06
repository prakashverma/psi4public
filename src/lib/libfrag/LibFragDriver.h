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
#ifndef SRC_LIB_LIBFRAG_LIBFRAGDRIVER_H_
#define SRC_LIB_LIBFRAG_LIBFRAGDRIVER_H_
#include <vector>
#include <boost/shared_ptr.hpp>
namespace psi{
namespace LibMolecule{
   class FragmentedSystem;
   class Molecule;
}
namespace LibFrag{
template<typename T> class MBEProp;

class LibFragDriver{
   private:
      boost::shared_ptr<LibMolecule::FragmentedSystem> Frags_;
      void RunCalc(const std::string& MethodName,int Start,int Stop);
      std::string MakeMol(boost::shared_ptr<LibMolecule::Molecule>)const;
      std::vector<boost::shared_ptr<MBEProp<double> > > Energies_;
   public:
      LibFragDriver(const std::string& MethodName);
      void RunMonomers(const std::string& MethodName);
      void RunNMers(int Start,const std::string& MethodName);
};


}}//End namespaces



#endif /* SRC_LIB_LIBFRAG_LIBFRAGDRIVER_H_ */
