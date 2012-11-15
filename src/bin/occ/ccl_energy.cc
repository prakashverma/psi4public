/** Standard library includes */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

/** Required PSI3 includes */ 
#include <psifiles.h>
#include <libciomr/libciomr.h>
#include <libpsio/psio.h>
#include <libchkpt/chkpt.h>
#include <libpsio/psio.hpp>
#include <libchkpt/chkpt.hpp>
#include <libiwl/iwl.h>
#include <libqt/qt.h>
#include <libtrans/mospace.h>
#include <libtrans/integraltransform.h>

/** Required libmints includes */
#include <libmints/mints.h>
#include <libmints/factory.h>
#include <libmints/wavefunction.h>

#include "defines.h"
#include "occwave.h"

using namespace boost;
using namespace psi;
using namespace std;


namespace psi{ namespace occwave{

void OCCWave::ccl_energy()
{      
    //fprintf(outfile,"\n ccl_energy is starting... \n"); fflush(outfile);
    // Two-electron contribution
    dpdbuf4 G, K;
    
    psio_->open(PSIF_LIBTRANS_DPD, PSIO_OPEN_OLD);  
    psio_->open(PSIF_OCC_DENSITY, PSIO_OPEN_OLD); 

 if (reference_ == "RESTRICTED") {
    // OOOO-Block contribution
    // E += 2*G_ijkl <ij|kl>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,O]"), ID("[O,O]"),
                  ID("[O,O]"), ID("[O,O]"), 0, "MO Ints <OO|OO>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,O]"), ID("[O,O]"),
                  ID("[O,O]"), ID("[O,O]"), 0, "TPDM <OO|OO>");
    Ecc_rdm += 2.0 * dpd_buf4_dot(&G, &K);         
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);   
    
  if (wfn_type_ != "OMP2") {
    // VVVV-Block contribution
    // E += 2*G_ABCD <AB|CD>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[V,V]"), ID("[V,V]"),
                  ID("[V,V]"), ID("[V,V]"), 0, "MO Ints <VV|VV>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[V,V]"), ID("[V,V]"),
                  ID("[V,V]"), ID("[V,V]"), 0, "TPDM <VV|VV>");    
    Ecc_rdm += 2.0 * dpd_buf4_dot(&G, &K);         
    dpd_buf4_close(&K);
    dpd_buf4_close(&G); 
  }// end if (wfn_type_ != "OMP2") {
    
    
    // OOVV-Block contribution
    // E += 8*G_IJAB <IJ|AB>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,O]"), ID("[V,V]"),
                  ID("[O,O]"), ID("[V,V]"), 0, "MO Ints <OO|VV>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,O]"), ID("[V,V]"),
                  ID("[O,O]"), ID("[V,V]"), 0, "TPDM <OO|VV>");
    Ecc_rdm += 8.0 * dpd_buf4_dot(&G, &K);   
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);    
    
    
    // OVOV-Block contribution
    // E += 4*G_IAJB <IA|JB>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,V]"), ID("[O,V]"),
                  ID("[O,V]"), ID("[O,V]"), 0, "MO Ints <OV|OV>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,V]"), ID("[O,V]"),
                  ID("[O,V]"), ID("[O,V]"), 0, "TPDM <OV|OV>");
    Ecc_rdm += 4.0 * dpd_buf4_dot(&G, &K);     
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);
 
 }// end rhf

 else if (reference_ == "UNRESTRICTED") {
    // OOOO-Block contribution
    // E += G_IJKL <IJ||KL>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,O]"), ID("[O,O]"),
                  ID("[O,O]"), ID("[O,O]"), 0, "MO Ints <OO||OO>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,O]"), ID("[O,O]"),
                  ID("[O,O]"), ID("[O,O]"), 0, "TPDM <OO|OO>");
    Ecc_rdm += dpd_buf4_dot(&G, &K);         
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);   
    
    // E += G_ijkl <ij||kl>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[o,o]"), ID("[o,o]"),
                  ID("[o,o]"), ID("[o,o]"), 0, "MO Ints <oo||oo>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[o,o]"), ID("[o,o]"),
                  ID("[o,o]"), ID("[o,o]"), 0, "TPDM <oo|oo>");
    Ecc_rdm += dpd_buf4_dot(&G, &K);  
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);  
    
    // E += 4*G_IjKl <Ij||Kl>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,o]"), ID("[O,o]"),
                  ID("[O,o]"), ID("[O,o]"), 0, "MO Ints <Oo|Oo>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,o]"), ID("[O,o]"),
                  ID("[O,o]"), ID("[O,o]"), 0, "TPDM <Oo|Oo>");
    Ecc_rdm += 4.0 * dpd_buf4_dot(&G, &K); 
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);

     
  if (wfn_type_ != "OMP2") {
    // VVVV-Block contribution
    /*
    // E += G_ABCD <AB||CD>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[V,V]"), ID("[V,V]"),
                  ID("[V,V]"), ID("[V,V]"), 0, "MO Ints <VV||VV>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[V,V]"), ID("[V,V]"),
                  ID("[V,V]"), ID("[V,V]"), 0, "TPDM <VV|VV>");    
    Ecc_rdm += dpd_buf4_dot(&G, &K);         
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);   
    */

     // E += 2*G_ABCD <AB|CD>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[V,V]"), ID("[V,V]"),
                  ID("[V,V]"), ID("[V,V]"), 0, "MO Ints <VV|VV>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[V,V]"), ID("[V,V]"),
                  ID("[V,V]"), ID("[V,V]"), 0, "TPDM <VV|VV>");    
    Ecc_rdm += 2.0 * dpd_buf4_dot(&G, &K);         
    dpd_buf4_close(&K);
    dpd_buf4_close(&G); 

    /* 
    // E += G_abcd <ab||cd>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[v,v]"), ID("[v,v]"),
                  ID("[v,v]"), ID("[v,v]"), 0, "MO Ints <vv||vv>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[v,v]"), ID("[v,v]"),
                  ID("[v,v]"), ID("[v,v]"), 0, "TPDM <vv|vv>");
    Ecc_rdm += dpd_buf4_dot(&G, &K);  
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);  
    */
     
     // E += 2*G_abcd <ab|cd>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[v,v]"), ID("[v,v]"),
                  ID("[v,v]"), ID("[v,v]"), 0, "MO Ints <vv|vv>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[v,v]"), ID("[v,v]"),
                  ID("[v,v]"), ID("[v,v]"), 0, "TPDM <vv|vv>");
    Ecc_rdm += 2.0 * dpd_buf4_dot(&G, &K);  
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);  
    
    // E += 4*G_AbCd <Ab||Cd>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[V,v]"), ID("[V,v]"),
                  ID("[V,v]"), ID("[V,v]"), 0, "MO Ints <Vv|Vv>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[V,v]"), ID("[V,v]"),
                  ID("[V,v]"), ID("[V,v]"), 0, "TPDM <Vv|Vv>");
    Ecc_rdm += 4.0 * dpd_buf4_dot(&G, &K); 
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);
  }// end if (wfn_type_ != "OMP2") {
 
    
    // OOVV-Block contribution
    // E += 2*G_IJAB <IJ||AB>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,O]"), ID("[V,V]"),
                  ID("[O,O]"), ID("[V,V]"), 0, "MO Ints <OO||VV>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,O]"), ID("[V,V]"),
                  ID("[O,O]"), ID("[V,V]"), 0, "TPDM <OO|VV>");
    Ecc_rdm += 2.0 * dpd_buf4_dot(&G, &K);   
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);    
    
    // E += 2*G_ijab <ij|ab>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[o,o]"), ID("[v,v]"),
                  ID("[o,o]"), ID("[v,v]"), 0, "MO Ints <oo||vv>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[o,o]"), ID("[v,v]"),
                  ID("[o,o]"), ID("[v,v]"), 0, "TPDM <oo|vv>");
    Ecc_rdm += 2.0 * dpd_buf4_dot(&G, &K);   
    dpd_buf4_close(&K);
    dpd_buf4_close(&G); 
    
    // E += 8*G_IjAb <Ij||Ab>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,o]"), ID("[V,v]"),
                  ID("[O,o]"), ID("[V,v]"), 0, "MO Ints <Oo|Vv>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,o]"), ID("[V,v]"),
                  ID("[O,o]"), ID("[V,v]"), 0, "TPDM <Oo|Vv>");
    Ecc_rdm += 8.0 * dpd_buf4_dot(&G, &K);   
    dpd_buf4_close(&K);
    dpd_buf4_close(&G); 

    
    // OVOV-Block contribution
    // E += 4*G_IAJB <IA||JB>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,V]"), ID("[O,V]"),
                  ID("[O,V]"), ID("[O,V]"), 0, "MO Ints <OV||OV>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,V]"), ID("[O,V]"),
                  ID("[O,V]"), ID("[O,V]"), 0, "TPDM <OV|OV>");
    Ecc_rdm += 4.0 * dpd_buf4_dot(&G, &K);     
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);
    
    // E += 4*G_iajb <ia||jb>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[o,v]"), ID("[o,v]"),
                  ID("[o,v]"), ID("[o,v]"), 0, "MO Ints <ov||ov>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[o,v]"), ID("[o,v]"),
                  ID("[o,v]"), ID("[o,v]"), 0, "TPDM <ov|ov>");
    Ecc_rdm += 4.0 * dpd_buf4_dot(&G, &K);     
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);
    
    // E += 4*G_IaJb <Ia||Jb>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0, ID("[O,v]"), ID("[O,v]"),
                  ID("[O,v]"), ID("[O,v]"), 0, "MO Ints <Ov|Ov>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,v]"), ID("[O,v]"),
                  ID("[O,v]"), ID("[O,v]"), 0, "TPDM <Ov|Ov>");
    Ecc_rdm += 4.0 * dpd_buf4_dot(&G, &K);     
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);
    
    // VOVO-Block contribution
    // E += 4*G_AiBj <Ai||Bj>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0,ID("[V,o]"), ID("[V,o]"),
                  ID("[V,o]"), ID("[V,o]"), 0, "MO Ints <Vo|Vo>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[V,o]"), ID("[V,o]"),
                  ID("[V,o]"), ID("[V,o]"), 0, "TPDM <Vo|Vo>"); 
    Ecc_rdm += 4.0 * dpd_buf4_dot(&G, &K);     
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);
    
    // OVVO-Block contribution
    // E += 8*G_IaBj <Ia||Bj>
    dpd_buf4_init(&K, PSIF_LIBTRANS_DPD, 0,ID("[O,v]"), ID("[V,o]"),
                  ID("[O,v]"), ID("[V,o]"), 0, "MO Ints <Ov|Vo>");
    dpd_buf4_init(&G, PSIF_OCC_DENSITY, 0, ID("[O,v]"), ID("[V,o]"),
                  ID("[O,v]"), ID("[V,o]"), 0, "TPDM <Ov|Vo>"); 
    Ecc_rdm += 8.0 * dpd_buf4_dot(&G, &K);     
    dpd_buf4_close(&K);
    dpd_buf4_close(&G);
    
 }// end uhf

    psio_->close(PSIF_LIBTRANS_DPD, 1);  
    psio_->close(PSIF_OCC_DENSITY, 1);  

  if (wfn_type_ == "OMP2") {
    EcorrL=Ecc_rdm-Escf;        
    Emp2L=Ecc_rdm;  
    DE = Emp2L - Emp2L_old;
    Emp2L_old = Emp2L;
  } 
  
  else if (wfn_type_ == "OMP3") {
    EcorrL=Ecc_rdm-Escf;        
    Emp3L=Ecc_rdm;  
    DE = Emp3L - Emp3L_old;
    Emp3L_old = Emp3L;
  } 

  else if (wfn_type_ == "OCEPA") {
    EcorrL = Ecc_rdm - Escf;        
    EcepaL = Ecc_rdm;  
    DE = EcepaL - EcepaL_old;
    EcepaL_old = EcepaL;
  } 
    
    //fprintf(outfile,"\n CC Total Energy via pdms       : %12.14f\n", Ecc_rdm); fflush(outfile);    
    //fprintf(outfile,"\n ccl_energy is done... \n"); fflush(outfile);
    
} // end of ccl_energy
}} // End Namespaces


