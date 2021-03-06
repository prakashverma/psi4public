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

#ifndef CIWAVE_H
#define CIWAVE_H

// Forward declarations
namespace boost {
template<class T> class shared_ptr;
}

namespace psi {
class Wavefunction;
class Options;
typedef boost::shared_ptr<Matrix> SharedMatrix;
}

namespace psi { namespace detci {

class MCSCF;

class CIWavefunction : public Wavefunction
{
friend class MCSCF;

public:
    CIWavefunction(boost::shared_ptr<Wavefunction> reference_wavefunction, Options &options);
    virtual ~CIWavefunction();

    double compute_energy();
    PsiReturnType cas_update();

    /**!
     * Obtains the OPDM <root| Epq |root> from disk
     * @param root - root to obtain
     * @param spin - 0 returns alpha, 1 returns beta, 2 sums alpha and beta
     * @param transden - obtain <0 | Epq | root> transden
     * @return OPDM or TDM shared matrix
     **/
    SharedMatrix get_opdm(int root, int spin=2, bool transden=false);

    /**!
     * Loads the OPDM to the wavefunction Da_ and Db_
     * @param use_old_d - If no new OPDM is calculated use the reference density matrices
    **/
    void set_opdm(bool use_old_d=false);

    /**!
     * Obtains the TPDM from disk
     * @param symmetrized - symmetrize the TPDM or not 
     * @return TPDM SharedVector
     **/
    SharedVector get_tpdm(bool symmetrized=true);

    /**!
     * Sets the TPDM to the wavefunction TPDM_
    **/
    void set_tpdm();

    void set_lag();


private:
    void common_init();

};

}}

#endif // CIWAVE_H

