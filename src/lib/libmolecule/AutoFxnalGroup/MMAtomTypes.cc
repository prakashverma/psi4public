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
#ifndef SRC_LIB_LIBMOLECULE_AUTOFXNALGROUP_ATOMTYPES_CC_
#define SRC_LIB_LIBMOLECULE_AUTOFXNALGROUP_ATOMTYPES_CC_
#include<string>
#include "MMAtomTypes.h"
namespace psi{
namespace LibMolecule{
/*
#define CASE(sym,str)case(FxnGrpType::sym):{out=str;break;}
std::string FxnGrpType2String(const FxnGrpType& Ty){
   std::string out;
   switch(Ty){
      CASE(NONE,"The Group That is Not A Group")
      CASE(TEMP,"Dummy Group")
      CASE(H,"Hydrogen")
      CASE(He,"Helium")
      CASE(Li,"Lithium")
      CASE(Be,"Beryllium")
      CASE(B,"Boron")
      CASE(C,"Carbon")
      CASE(N,"Nitrogen")
      CASE(O,"Oxygen")
      CASE(F,"Fluorine")
      CASE(Ne,"Neon")
      CASE(Na,"Sodium")
      CASE(Mg,"Magnesium")
      CASE(Al,"Aluminum")
      CASE(Si,"Silicon")
      CASE(P,"Phosphorus")
      CASE(S,"Sulfur")
      CASE(Cl,"Chlorine")
      CASE(Ar,"Argon")
      CASE(K,"Potassium")
      CASE(Ca,"Calcium")
      CASE(Sc,"Scandium")
      CASE(Ti,"Titanium")
      CASE(V,"Vanadium")
      CASE(Cr,"Chromium")
      CASE(Mn,"Manganese")
      CASE(Fe,"Iron")
      CASE(Co,"Cobalt")
      CASE(Ni,"Nickel")
      CASE(Cu,"Copper")
      CASE(Zn,"Zinc")
      CASE(Ga,"Gallium")
      CASE(Ge,"Germanium")
      CASE(As,"Arsenic")
      CASE(Se,"Selenium")
      CASE(Br,"Bromine")
      CASE(Kr,"Krypton")
      CASE(Rb,"Rubidium")
      CASE(Sr,"Strontium")
      CASE(Y,"Yttrium")
      CASE(Zr,"Zirconium")
      CASE(Nb,"Niobium")
      CASE(Mo,"Molybdenum")
      CASE(Tc,"Technetium")
      CASE(Ru,"Ruthenium")
      CASE(Rh,"Rhodium")
      CASE(Pd,"Palladium")
      CASE(Ag,"Silver")
      CASE(Cd,"Cadmium")
      CASE(In,"Indium")
      CASE(Sn,"Tin")
      CASE(Sb,"Antimony")
      CASE(Te,"Tellurium")
      CASE(I,"Iodine")
      CASE(Xe,"Xenon")
      CASE(Cs,"Cesium")
      CASE(Ba,"Barium")
      CASE(La,"Lanthanum")
      CASE(Ce,"Cerium")
      CASE(Pr,"Praseodymium")
      CASE(Nd,"Neodymium")
      CASE(Pm,"Promethium")
      CASE(Sm,"Samarium")
      CASE(Eu,"Europium")
      CASE(Gd,"Gadolinium")
      CASE(Tb,"Terbium")
      CASE(Dy,"Dysprosium")
      CASE(Ho,"Holmium")
      CASE(Er,"Erbium")
      CASE(Tm,"Thulium")
      CASE(Yb,"Ytterbium")
      CASE(Lu,"Lutetium")
      CASE(Hf,"Hafnium")
      CASE(Ta,"Tantalum")
      CASE(W,"Tungsten")
      CASE(Re,"Rhenium")
      CASE(Os,"Osmium")
      CASE(Ir,"Iridium")
      CASE(Pt,"Platinum")
      CASE(Au,"Gold")
      CASE(Hg,"Mercury")
      CASE(Tl,"Thallium")
      CASE(Pb,"Lead")
      CASE(Bi,"Bismuth")
      CASE(Po,"Polonium")
      CASE(At,"Astatine")
      CASE(Rn,"Radon")
      CASE(Fr,"Francium")
      CASE(Ra,"Radium")
      CASE(Ac,"Actinium")
      CASE(Th,"Thorium")
      CASE(Pa,"Protactinium")
      CASE(U,"Uranium")
      CASE(Np,"Neptunium")
      CASE(Pu,"Plutonium")
      CASE(Am,"Americium")
      CASE(Cm,"Curium")
      CASE(Bk,"Berkelium")
      CASE(Cf,"Californium")
      CASE(Es,"Einsteinium")
      CASE(Fm,"Fermium")
      CASE(Md,"Mendelevium")
      CASE(No,"Nobelium")
      CASE(Lr,"Lawrencium")
      CASE(Rf,"Rutherfordium")
      CASE(Db,"Dubnium")
      CASE(Sg,"Seaborgium")
      CASE(Bh,"Bohrium")
      CASE(Hs,"Hassium")
      CASE(Mt,"Meitnerium")
      CASE(Ds,"Darmstadtium")
      CASE(Rg,"Roentgenium")
      CASE(Cn,"Copernicium")
      CASE(Uut,"Ununtrium")
      CASE(Fl,"Flerovium")
      CASE(Uup,"Ununpentium")
      CASE(Lv,"Livermorium")
      CASE(Uus,"Ununseptium")
      CASE(Uuo,"Ununoctium")
      CASE(C0,"Methane")
      CASE(CC0,"Methane Carbon")
      CASE(HC0,"Methane Hydrogen")
      CASE(C1,"Methyl")
      CASE(CC1,"Methyl Carbon")
      CASE(HC1,"Methyl Hydrogen")
      CASE(C2,"Methene")
      CASE(CC2,"Methene Carbon")
      CASE(HC2,"Methene Hydrogen")
      CASE(C3,"Methyne")
      CASE(CC3,"Methyne Carbon")
      CASE(HC3,"Methyne Hydrogen")
      CASE(C4,"Quatenary Carbon Unit")
      CASE(CC4,"Quatenary Carbon")
      CASE(CDB1,"Primary Alkene")
      CASE(CCDB1,"Primary Alkene Carbon")
      CASE(HCDB1,"Primary Alkene Hydrogen")
      CASE(CDB2,"Secondary Alkene")
      CASE(CCDB2,"Secondary Alkene Carbon")
      CASE(HCDB2,"Secondary Alkene Hydrogen")
      CASE(CDB3,"Tertiary Alkene")
      CASE(CCDB3,"Tertiary Alkene Carbon")
      CASE(CTB1,"Primary Alkyne")
      CASE(CCTB1,"Primary Alkyne Carbon")
      CASE(HCTB1,"Primary Alkyne Hydrogen")
      CASE(CTB2,"Secondary Alkyne")
      CASE(CCTB2,"Secondary Alkyne Carbon")
      CASE(N0,"Ammonia")
      CASE(NN0,"Ammonia Nitrogen")
      CASE(HN0,"Ammonia Hydrogen")
      CASE(N1,"Primary Amine")
      CASE(NN1,"Primary Amine Nitrogen")
      CASE(HN1,"Primary Amine Hydrogen")
      CASE(N2,"Seconard Amine")
      CASE(NN2,"Secondary Amine Nitrogen")
      CASE(HN2,"Secondary Amine Hydrogen")
      CASE(N3,"Tertiary Amine")
      CASE(NN3,"Tertiary Amine Nitrogen")
      CASE(NDB1,"Primary Azene")
      CASE(NNDB1,"Primary Azene Nitrogen")
      CASE(HNDB1,"Primary Azene Hydrogen")
      CASE(NDB2,"Secondary Azene")
      CASE(NNDB2,"Secondary Azene Nitrogen")
      CASE(NTB,"Nitrogen 3X Bond")
      CASE(NNTB,"Nitrogen 3X Bond Nitrogen")
      CASE(NP0,"Ammonium Ion")
      CASE(NNP0,"Ammonium Ion Nitrogen")
      CASE(HNP0,"Ammonium Ion Hydrogen")
      CASE(NP1,"Primary Ammonium Ion")
      CASE(NNP1,"Primary Ammonium Ion Nitrogen")
      CASE(HNP1,"Primary Ammonium Ion Hydrogen")
      CASE(NP2,"Secondary Ammonium Ion")
      CASE(NNP2,"Secondary Ammonium Ion Nitrogen")
      CASE(HNP2,"Secondary Ammonium Ion Hydrogen")
      CASE(NP3,"Tertiary Ammonium Ion")
      CASE(NNP3,"Tertiary Ammonium Ion Nitrogen")
      CASE(HNP3,"Tertiary Ammonium Ion Hydrogen")
      CASE(NP4,"Quatenary Ammonium Ion")
      CASE(NNP4,"Quatenary Ammonium Ion Nitrogen")
      CASE(O0,"Water")
      CASE(OO0,"Water Oxygen")
      CASE(HO0,"Water Hydrogen")
      CASE(O1,"Hydroxyl")
      CASE(OO1,"Hydroxyl Oxygen")
      CASE(HO1,"Hydroxyl Hydrogen")
      CASE(O2,"Ether")
      CASE(OO2,"Ether Oxygen")
      CASE(ODB,"Oxygen Double Bond")
      CASE(OODB,"Oxygen Double Bond Oxygen")
      CASE(S0,"Hydrogen Sulfide")
      CASE(SS0,"Hydrogen Sulfide Sulfur")
      CASE(HS0,"Hydrogen Sulfide Hydrogen")
      CASE(S1,"Thiol")
      CASE(SS1,"Thiol Sulfur")
      CASE(HS1,"Thiol Hydrogen")
      CASE(S2,"Sulfide")
      CASE(SS2,"Sulfide Sulfur")
      CASE(SDB,"Sulfur Double Bond")
      CASE(SSDB,"Sulfur Double Bond Sulfur")
      CASE(DBCC0,"Ethene")
      CASE(CDBCC0,"Ethene Carbon")
      CASE(HDBCC0,"Ethene Hydrogen")
      CASE(DBCC1,"Ethenyl")
      CASE(C1DBCC1,"Ethenyl Carbon1")
      CASE(H1DBCC1,"Ethenyl Hydrogen1")
      CASE(C2DBCC1,"Ethenyl Carbon2")
      CASE(H2DBCC1,"Ethenyl Hydrogen2")
      CASE(DBCC2,"Secondary C-C 2X Bond")
      CASE(CDBCC2,"Secondary C-C 2X Bond Carbon")
      CASE(HDBCC2,"Secondary C-C 2X Bond Hydrogen")
      CASE(DBCC2G,"Secondary Geminal C-C 2X Bond")
      CASE(C1DBCC2G,"Secondary Geminal C-C 2X Bond Carbon1")
      CASE(HDBCC2G,"Secondary Geminal C-C 2X Bond Hydrogen")
      CASE(C2DBCC2G,"Secondary Geminal C-C 2X Bond Carbon2")
      CASE(DBCC3,"Tertiary C-C 2X Bond")
      CASE(C1DBCC3,"Tertiary C-C 2X Bond Carbon1")
      CASE(HDBCC3,"Tertiary C-C 2X Bond Hydrogen")
      CASE(C2DBCC3,"Tertiary C-C 2X Bond Carbon2")
      CASE(DBCC4,"Quatenary C-C 2X Bond")
      CASE(CDBCC4,"Quatenary C-C 2X Bond Carbon")
      CASE(TBCC0,"Acetylene")
      CASE(CTBCC0,"Acetylene Carbon")
      CASE(HTBCC0,"Acetylene Hydrogen")
      CASE(DBCN0,"Formaldimine")
      CASE(CDBCN0,"Formaldimine Carbon")
      CASE(NDBCN0,"Formaldimine Nitrogen")
      CASE(H1DBCN0,"Formaldimine N's Hydrogen")
      CASE(H2DBCN0,"Formaldimine C's Hydrogen")
      CASE(DBCN1N,"Primary C-N 2X Bond")
      CASE(CDBCN1N,"Primary C-N 2X Bond Carbon")
      CASE(NDBCN1N,"Primary C-N 2X Bond Nitrogen")
      CASE(HDBCN1N,"Primary C-N 2X Bond Hydrogen")
      CASE(DBCN1C,"Primary Aldimine")
      CASE(CDBCN1C,"Primary Aldimine Carbon")
      CASE(NDBCN1C,"Primary Aldimine Nitrogen")
      CASE(H1DBCN1C,"Primary Aldimine Nitrogen Hydrogen")
      CASE(H2DBCN1C,"Primary Aldimine Carbon Hydrogen")
      CASE(DBCN2,"Secondary Aldimine")
      CASE(CDBCN2,"Secondary Aldimine Carbon")
      CASE(NDBCN2,"Secondary Aldimine Nitrogen")
      CASE(HDBCN2,"Secondary Aldimine Hydrogen")
      CASE(DBCN2G,"Primary Ketimine")
      CASE(CDBCN2G,"Primary Ketimine Carbon")
      CASE(NDBCN2G,"Primary Ketimine Nitrogen")
      CASE(HDBCN2G,"Primary Ketimine Hydrogen")
      CASE(DBCN3,"Secondary Ketimine")
      CASE(CDBCN3,"Seconary Ketimine Carbon")
      CASE(NDBCN3,"Secondary Ketimine Nitrogen")
      CASE(TBCN0,"Hydrogen Cyanide")
      CASE(CTBCN0,"Hydrogen Cyanide Carbon")
      CASE(NTBCN0,"Hydrogen Cyanide Nitrogen")
      CASE(HTBCN0,"Hydrogen Cyanide Hydrogen")
      CASE(TBCN1,"Nitrile")
      CASE(CTBCN1,"Nitrile Carbon")
      CASE(NTBCN1,"Nitrile Nitrogen")
      CASE(DBCO0,"Formaldehyde")
      CASE(CDBCO0,"Formaldehyde Carbon")
      CASE(HDBCO0,"Formaldehyde Hydrogen")
      CASE(ODBCO0,"Formaldehyde Oxygen")
      CASE(DBCO1,"Aldehyde")
      CASE(CDBCO1,"Aldehyde Carbon")
      CASE(HDBCO1,"Aldehyde Hydrogen")
      CASE(ODBCO1,"Aldehyde Oxygen")
      CASE(DBCO2,"Carbonyl")
      CASE(CDBCO2,"Carbonyl Carbon")
      CASE(ODBCO2,"Carbonyl Oxygen")
      CASE(CO2M,"Carboxylate")
      CASE(CCO2M,"Carboxylate Carbon")
      CASE(OCO2M,"Carboxylate Oxygen")
      CASE(CO2H,"Carboxyl")
      CASE(CCO2H,"Carboxyl Carbon")
      CASE(O2CO2H,"Carboxyl Hydroxyl Oxygen")
      CASE(O1CO2H,"Carboxyl Carbonyl Oxygen")
      CASE(HCO2H,"Carboxyl Hydrogen")
      CASE(CO2,"Ester")
      CASE(CCO2,"Ester Carbon")
      CASE(O2CO2,"Ester Carbonyl Oxygen")
      CASE(O1CO2,"Ester Ether Oxygen")
      CASE(CO3,"Carbonate")
      CASE(CCO3,"Carbonate Carbon")
      CASE(O1CO3,"Carbonate Ether Oxygen")
      CASE(O2CO3,"Carbonate Carbonyl Oxygen")
      CASE(CONH2,"Primary (C-Side) Amide")
      CASE(CCONH2,"Primary (C-Side) Amide Carbon")
      CASE(OCONH2,"Primary (C-Side) Amide Oxygen")
      CASE(NCONH2,"Primary (C-Side) Amide Nitrogen")
      CASE(HCONH2,"Primary (C-Side) Amide Hydrogen")
      CASE(CHONH,"Primary (N-Side) Amide")
      CASE(CCHONH,"Primary (N-Side) Amide Carbon")
      CASE(OCHONH,"Primary (N-Side) Amide Oxygen")
      CASE(NCHONH,"Primary (N-Side) Amide Nitrogen")
      CASE(H1CHONH,"Primary (N-Side) Amide N's Hydrogen")
      CASE(H2CHONH,"Primary (N-Side) Amide C's Hydrogen")
      CASE(CONH,"Secondary Amide")
      CASE(CCONH,"Secondary Amide Carbon")
      CASE(OCONH,"Secondary Amide Oxygen")
      CASE(NCONH,"Secondary Amide Nitrogen")
      CASE(HCONH,"Secondary Amide Hydrogen")
      CASE(CHON,"Secondary Geminal Amide")
      CASE(CCHON,"Secondary Geminal Amide Carbon")
      CASE(OCHON,"Secondary Geminal Amide Oxygen")
      CASE(NCHON,"Secondary Geminal Amide Nitrogen")
      CASE(HCHON,"Secondary Geminal Amide Hydrogen")
      CASE(CON,"Tertiary Amide")
      CASE(CCON,"Tertiary Amide Carbon")
      CASE(OCON,"Tertiary Amide Oxygen")
      CASE(NCON,"Tertiary Amide Nitrogen")
      CASE(CONHCOH,"Primary (C-Side) Imide")
      CASE(C1CONHCOH,"Primary (C-Side) Imide Carbonyl Carbon")
      CASE(C2CONHCOH,"Primary (C-Side) Imide Aldehyde Carbon")
      CASE(O1CONHCOH,"Primary (C-Side) Imide Carbonyl Oxygen")
      CASE(O2CONHCOH,"Primary (C-Side) Imide Aldehyde Oxygen")
      CASE(NCONHCOH,"Primary (C-Side) Imide Nitrogen")
      CASE(H1CONHCOH,"Primary (C-Side) Imide Nitrogen Hydrogen")
      CASE(H2CONHCOH,"Primary (C-Side) Imide Aldehyde Hydrogen")
      CASE(CHONCOH,"Primary (N-Side) Imide")
      CASE(CCHONCOH,"Primary (N-Side) Imide Carbon")
      CASE(OCHONCOH,"Primary (N-Side) Imide Oxygen")
      CASE(HCHONCOH,"Primary (N-Side) Imide Hydrogen")
      CASE(CONCOH,"Secondary 1,2 Imide")
      CASE(C1CONCOH,"Secondary 1,2 Imide Carbonyl Carbon")
      CASE(C2CONCOH,"Secondary 1,2 Imide Aldehyde Carbon")
      CASE(O1CONCOH,"Secondary 1,2 Imide Carbonyl Oxygen")
      CASE(O2CONCOH,"Secondary 1,2 Imide Aldehyde Oxygen")
      CASE(NCONCOH,"Secondary 1,2 Imide Nitrogen")
      CASE(HCONCOH,"Secondary 1,2 Imide Hydrogen")
      CASE(CONHCO,"Secondary 1,3 Imide")
      CASE(CCONHCO,"Secondary 1,3 Imide Carbon")
      CASE(OCONHCO,"Secondary 1,3 Imide Oxygen")
      CASE(HCONHCO,"Secondary 1,3 Imide Hydrogen")
      CASE(NCONHCO,"Secondary 1,3 Imide Nitrogen")
      CASE(CONCO,"Tertiary Imide")
      CASE(CCONCO,"Tertiary Imide Carbon")
      CASE(OCONCO,"Tertiary Imide Oxygen")
      CASE(NCONCO,"Tertiary Imide Nitrogen")
      CASE(OCH4,"Methanol")
      CASE(OOCH4,"Methanol Oxygen")
      CASE(COCH4,"Methanol Carbon")
      CASE(H1OCH4,"Methanol Hydroxyl Hydrogen")
      CASE(H2OCH4,"Methanol Methyl Hydrogen")
      CASE(OCH3,"Methoxy")
      CASE(OOCH3,"Methoxy Oxygen")
      CASE(COCH3,"Methoxy Carbon")
      CASE(HOCH3,"Methoxy Hydrogen")
      CASE(O2H2,"Hydrogen Peroxide")
      CASE(OO2H2,"Hydrogen Peroxide Oxygen")
      CASE(HO2H2,"Hydrogen Peroxide Hydrogen")
      CASE(O2H,"Hydroperoxide")
      CASE(O1O2H,"Hydroperoxide Ether Oxygen")
      CASE(O2O2H,"Hydroperoxide Hydroxyl Oxygen")
      CASE(HO2H,"Hydroperoxide Hydrogen")
      CASE(OO,"Peroxide")
      CASE(OOO,"Peroxide Oxygen")
      CASE(OCHOH,"Hemiacetal")
      CASE(O1OCHOH,"Hemiacetal Ether Oxygen")
      CASE(O2OCHOH,"Hemiacetal Hydroxyl Oxygen")
      CASE(COCHOH,"Hemiacetal Carbon")
      CASE(H1OCHOH,"Hemiacetal Hydroxyl Hydrogen")
      CASE(H2OCHOH,"Hemiacetal Methyne Hydrogen")
      CASE(OCOH,"Hemiketal")
      CASE(O1OCOH,"Hemiketal Ether Oxygen")
      CASE(O2OCOH,"Hemiketal Hydroxyl Oxygen")
      CASE(COCOH,"Hemiketal Carbon")
      CASE(HOCOH,"Hemiketal Hydrogen")
      CASE(OCHO,"Acetal")
      CASE(OOCHO,"Acetal Oxygen")
      CASE(COCHO,"Acetal Carbon")
      CASE(HOCHO,"Acetal Hydrogen")
      CASE(OCO,"Ketal")
      CASE(OOCO,"Ketal Oxygen")
      CASE(COCO,"Ketal Carbon")
      CASE(COOO,"Orthoester")
      CASE(CCOOO,"Orthoester Carbon")
      CASE(OCOOO,"Orthoester oxygen")
      CASE(NNN,"Azide")
      CASE(N1NNN,"Azide Neutral Nitrogen")
      CASE(N2NNN,"Azide Cationic Nitrogen")
      CASE(N3NNN,"Azide Anionic Nitrogen")
      CASE(DBNN0,"Diazene")
      CASE(NDBNN0,"Diazene Nitrogen")
      CASE(HDBNN0,"Diazene Hydrogen")
      CASE(DBNN1,"Primary Azo")
      CASE(N1DBNN1,"Primary Azo Nitrogen1")
      CASE(N2DBNN1,"Primary Azo Nitrogen2")
      CASE(DBNN2,"Secondary Azo")
      CASE(NDBNN2,"Secondary Azo Nitrogen")
      CASE(OCN,"Cyanate")
      CASE(COCN,"Cyanate Carbon")
      CASE(NOCN,"Cyanate Nitrogen")
      CASE(OOCN,"Cyanate Oxygen")
      CASE(NCO,"Isocyanate")
      CASE(NNCO,"Isocyanate Nitrogen")
      CASE(CNCO,"Isocyanate Carbon")
      CASE(ONCO,"Isocyanate Oxygen")
      CASE(NOO,"Nitro")
      CASE(NNOO,"Nitro Nitrogen")
      CASE(ONOO,"Nitro Oxygen")
      CASE(NO3,"Nitrate")
      CASE(O1NO3,"Nitrate Ether Oxygen")
      CASE(O2NO3,"Nitrate Nitro Oxygen")
      CASE(NNO3,"Nitrate Nitrogen")
      CASE(NO,"Nitroso")
      CASE(NNO,"Nitroso Nitrogen")
      CASE(ONO,"Nitroso Oxygen")
      CASE(NO2,"Nitrite")
      CASE(NNO2,"Nitrite Nitrogen")
      CASE(O1NO2,"Nitrate Ether Oxygen")
      CASE(O2NO2,"Nitrate Nitroso Oxygen")
      CASE(IPR,"Isopropyl")
      CASE(C1IPR,"Isopropyl Methyl Carbon")
      CASE(C2IPR,"Isopropyl Methyne Carbon")
      CASE(H1IPR,"Isopropyl Methyl Hydrogen")
      CASE(H2IPR,"Isopropyl Methyne Hydrogen")
      CASE(Bz0,"Benzene")
      CASE(CBz0,"Benzene Carbon")
      CASE(HBz0,"Benzene Hydrogen")
      CASE(Bz1,"Phenyl")
      CASE(C1Bz1,"Phenyl 1 Carbon")
      CASE(C2Bz1,"Phenyl 2 or 6 Carbon")
      CASE(C3Bz1,"Phenyl 3 or 5 Carbon")
      CASE(C4Bz1,"Phenyl 4 Carbon")
      CASE(H1Bz1,"Phenyl 2 or 6 Hydgrogen")
      CASE(H2Bz1,"Phenyl 3 or 5 Hydrogen")
      CASE(H3Bz1,"Phenyl 4 Hydrogen")
      CASE(Bz2o,"Ortho Benzene")
      CASE(C1Bz2o,"Ortho Benzene 1 or 2 Carbon")
      CASE(C2Bz2o,"Ortho Benzene 3 or 6 Carbon")
      CASE(C3Bz2o,"Ortho Benzene 4 or 5 Carbon")
      CASE(H1Bz2o,"Ortho Benzene 3 or 6 Hydrogen")
      CASE(H2Bz2o,"Ortho Benzene 4 or 5 Hydrogen")
      CASE(Bz2m,"Meta Benzene")
      CASE(C1Bz2m,"Meta Benzene 1 or 3 Carbon")
      CASE(C2Bz2m,"Meta Benzene 2 Carbon")
      CASE(C3Bz2m,"Meta Benzene 4 or 6 Carbon")
      CASE(C4Bz2m,"Meta Benzene 5 Carbon")
      CASE(H1Bz2m,"Meta Benzene 2 Hydrogen")
      CASE(H2Bz2m,"Meta Benzene 4 or 6 Hydrogen")
      CASE(H3Bz2m,"Meta Benzene 5 Hydrogen")
      CASE(Bz2p,"Para Benzene")
      CASE(C1Bz2p,"Para Benzene 1 or 4 Carbon")
      CASE(C2Bz2p,"Para Benzene 2,3,5, or 6 Carbon")
      CASE(HBz2p,"Para Benzene Hydrogen")
      CASE(Bz6,"Hexasubstituted Benzene")
      CASE(CBz6,"Hexasubstituted Benzene Carbon")
      CASE(PNT,"Protonated N-Terminus")
      CASE(NPNT,"Protonated N-Terminus Nitrogen")
      CASE(HNPNT,"Protonated N-Terminus Ammonim Hydrogen")
      CASE(CAPNT,"Protonated N-Terminus Alpha Carbon")
      CASE(HCAPNT,"Protonated N-Terminus Alpha Carbon Hydrogen")
      CASE(CPBPNT,"Protonated N-Terminus Peptide Bond Carbon")
      CASE(OPBPNT,"Protonated N-Terminus Peptide Bond Oxygen")
      CASE(GLYPNT,"Protonated N-Terminus Glycine")
      CASE(NGLYPNT,"Protonated N-Terminus Gycine Nitrogen")
      CASE(HNGLYPNT,"Protonated N-Terminus Glycine Ammonium Hydrogen")
      CASE(CAGLYPNT,"Protonated N-Terminus Glycine Alpha Carbon")
      CASE(HCAGLYPNT,"Protonated N-Terminus Glycine Alpha Carbon Hydrogen")
      CASE(CPBGLYPNT,"Protonated N-Terminus Glycine Peptide Bond Carbon")
      CASE(OPBGLYPNT,"Protonated N-Terminus Glycine Peptide Bond Oxygen")
      CASE(GLYNCT,"Negative C-Terminus Glycine")
      CASE(NGLYNCT,"Negative C-Terminus Gycine Nitrogen")
      CASE(HNGLYNCT,"Negative C-Terminus Glycine Peptide Bond Hydrogen")
      CASE(CAGLYNCT,"Negative C-Terminus Glycine Alpha Carbon")
      CASE(HCAGLYNCT,"Negative C-Terminus Glycine Alpha Carbon Hydrogen")
      CASE(CGLYNCT,"Negative C-Terminus Glycine Carboxylate Carbon")
      CASE(OGLYNCT,"Negative C-Terminus Glycine Carboxylate Oxygen")
      CASE(NCT,"Negative C-Terminus")
      CASE(CNCT,"Negative C-Terminus Carboxylate Carbon")
      CASE(ONCT,"Negative C-Terminus Carboxylate Oxygen")
      CASE(CANCT,"Negative C-Terminus Alpha Carbon")
      CASE(HCANCT,"Negative C-Terminus Alpha Carbon Hydrogen")
      CASE(NPBNCT,"Negative C-Terminus Peptide Bond Nitrogen")
      CASE(HPBNCT,"Negative C-Terminus Peptide Bond Hydrogen")
      CASE(AABB,"Amino-Acid Back Bone")
      CASE(CPBAABB,"Amino-Acid Back Bone Peptide Bond Carbon")
      CASE(OPBAABB,"Amino-Acid Back Bone Peptide Bond Oxygen")
      CASE(CCAAABB,"Amino-Acid Back Bone Alpha Carbon")
      CASE(HCAAABB,"Amino-Acid Back Bone Alpha Carbon Hydrogen")
      CASE(NPBAABB,"Amino-Acid Back Bone Peptide Bond Nitrogen")
      CASE(HPBAABB,"Amino-Acid Back Bone Peptide Bond Hydrogen")
      CASE(GLY,"Glycine")
      CASE(CPBGLY,"Glycine Peptide Bond Carbon")
      CASE(OPBGLY,"Glycine Peptide Bond Oxygen")
      CASE(CCAGLY,"Glycine Alpha Carbon")
      CASE(HCAGLY,"Glycine Alpha Hydrogen")
      CASE(NPBGLY,"Glycine Peptide Bond Nitrogen")
      CASE(HPBGLY,"Glycine Peptide Bond Hydrogen")
      CASE(ALAR,"Alanine Side Chain")
      CASE(CALAR,"Alanine Side Chain Carbon")
      CASE(HALAR,"Alanine Side Chain Hydrogen")
      CASE(VALR,"Valine Side Chain")
      CASE(C1VALR,"Valine Side Chain Beta Carbon")
      CASE(C2VALR,"Valine Side Chain Gamma Carbon")
      CASE(H1VALR,"Valine Side Chain Beta Hydrogen")
      CASE(H2VALR,"Valine Side Chain Gamma Hydrogen")
      CASE(ILER,"Isoleucine Side Chain")
      CASE(C1ILER,"Isoleucine Side Chain Beta Carbon")
      CASE(C2ILER,"Isoleucine Side Chain Gamma Methene Carbon")
      CASE(C3ILER,"Isoleucine Side Chain Gamma Methyl Carbon")
      CASE(C4ILER,"Isoleucine Side Chain Delta Methyl Carbon")
      CASE(H1ILER,"Isoleucine Side Chain Beta Carbon")
      CASE(H2ILER,"Isoleucine Side Chain Gamma Methene Hydrogen")
      CASE(H3ILER,"Isoleucine Side Chain Gamma Methyl Hydrogen")
      CASE(H4ILER,"Isoleucine Side Chain Delta Methyl Hydrogen")
      CASE(LEUR,"Lecuine Side Chain")
      CASE(C1LEUR,"Lecuine Side Chain Beta Carbon")
      CASE(C2LEUR,"Lecuine Side Chain Gamma Carbon")
      CASE(C3LEUR,"Lecuine Side Chain Delta Carbon")
      CASE(H1LEUR,"Lecuine Side Chain Beta Hydrogen")
      CASE(H2LEUR,"Lecuine Side Chain Gamma Hydrogen")
      CASE(H3LEUR,"Lecuine Side Chain Delta Hydrogen")
      CASE(METR,"Methionine Side Chain")
      CASE(C1METR,"Methionine Side Chain Beta Carbon")
      CASE(C2METR,"Methionine Side Chain Gamma Carbon")
      CASE(C3METR,"Methionine Side Chain Delta Carbon")
      CASE(SMETR,"Methionine Side Chain Sulfur")
      CASE(H1METR,"Methionine Side Chain Beta Hydrogen")
      CASE(H2METR,"Methionine Side Chain Gamma Hydrogen")
      CASE(H3METR,"Methionine Side Chain Delta Hydrogen")
      CASE(PHER,"Phenylalanine Side Chain")
      CASE(C1PHER,"Phenylalanine Side Chain Beta Carbon")
      CASE(C2PHER,"Phenylalanine Side Chain Gamma Carbon")
      CASE(C3PHER,"Phenylalanine Side Chain Delta Carbon")
      CASE(C4PHER,"Phenylalanine Side Chain Epsilon Carbon")
      CASE(C5PHER,"Phenylalanine Side Chain Zeta Carbon")
      CASE(H1PHER,"Phenylalanine Side Chain Beta Hydrogen")
      CASE(H2PHER,"Phenylalanine Side Chain Delta Hydrogen")
      CASE(H3PHER,"Phenylalanine Side Chain Epsilon Hydrogen")
      CASE(H4PHER,"Phenylalanine Side Chain Zeta Hydrogen")
      CASE(TYRR,"Tyrosine Side Chain")
      CASE(C1TYRR,"Tyrosine Side Chain Beta Carbon")
      CASE(C2TYRR,"Tyrosine Side Chain Gamma Carbon")
      CASE(C3TYRR,"Tyrosine Side Chain Delta Carbon")
      CASE(C4TYRR,"Tyrosine Side Chain Epsilon Carbon")
      CASE(C5TYRR,"Tyrosine Side Chain Zeta Carbon")
      CASE(OTYRR,"Tyrosine Side Chain Oxygen")
      CASE(H1TYRR,"Tyrosine Side Chain Beta Hydrogen")
      CASE(H2TYRR,"Tyrosine Side Chain Delta Hydrogen")
      CASE(H3TYRR,"Tyrosine Side Chain Epsilon Hydrogen")
      CASE(H4TYRR,"Tyrosine Side Chain Hydroxyl Hydrogen")
      CASE(TRPR,"Tryptophan Side Chain")
      CASE(NTRPR,"Tryptophan Side Chain Nitrogen")
      CASE(C1TRPR,"Tryptophan Side Chain Beta Carbon")
      CASE(C2TRPR,"Tryptophan Side Chain Indole 2 Carbon")
      CASE(C3TRPR,"Tryptophan Side Chain Gamma Carbon")
      CASE(C4TRPR,"Tryptophan Side Chain Indole 4 Carbon")
      CASE(C5TRPR,"Tryptophan Side Chain Indole 5 Carbon")
      CASE(C6TRPR,"Tryptophan Side Chain Indole 6 Carbon")
      CASE(C7TRPR,"Tryptophan Side Chain Indole 7 Carbon")
      CASE(C8TRPR,"Tryptophan Side Chain Indole 8 Carbon")
      CASE(C9TRPR,"Tryptophan Side Chain Indole 9 Carbon")
      CASE(H1TRPR,"Tryptophan Side Chain Methene Hydrogen")
      CASE(H2TRPR,"Tryptophan Side Chain Nitrogen Hydrogen")
      CASE(H3TRPR,"Tryptophan Side Chain Indole 2 Hydrogen")
      CASE(H4TRPR,"Tryptophan Side Chain Indole 5 Hydrogen")
      CASE(H5TRPR,"Tryptophan Side Chain Indole 6 Hydrogen")
      CASE(H6TRPR,"Tryptophan Side Chain Indole 7 Hydrogen")
      CASE(H7TRPR,"Tryptophan Side Chain Indole 8 Hydrogen")
      CASE(SERR,"Serine Side Chain")
      CASE(OSERR,"Serine Side Chain Oxygen")
      CASE(CSERR,"Serine Side Chain Beta Carbon")
      CASE(H1SERR,"Serine Side Chain Beta Hydrogen")
      CASE(H2SERR,"Serine Side Chain Hydroxyl Hydrogen")

      //Bragging Point:Line number less 32=# of discernible fxnal groups
      //Stuff below here is auto-generated and feels kinda cheap to include...
      #include "PrintIndole.hh"

      default:{break;}
   }
   return out;
}
*/
}}//end namespaces


#endif /* SRC_LIB_LIBMOLECULE_AUTOFXNALGROUP_ATOMTYPES_CC_ */
