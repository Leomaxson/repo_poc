//////////////////////////////////////////////////////////
// QCADesigner                                          //
// Copyright 2002 Konrad Walus                          //
// All Rights Reserved                                  //
// Author: Konrad Walus                                 //
// Email: qcadesigner@gmail.com                         //
// WEB: http://qcadesigner.ca/                          //
//////////////////////////////////////////////////////////
//******************************************************//
//*********** PLEASE DO NOT REFORMAT THIS CODE *********//
//******************************************************//
// If your editor wraps long lines disable it or don't  //
// save the core files that way. Any independent files  //
// you generate format as you wish.                     //
//////////////////////////////////////////////////////////
// Please use complete names in variables and fucntions //
// This will reduce ramp up time for new people trying  //
// to contribute to the project.                        //
//////////////////////////////////////////////////////////
// This file was contributed by Gabriel Schulhof        //
// (schulhof@atips.ca).                                 //
//////////////////////////////////////////////////////////
// Contents:                                            //
//                                                      //
// Small wrapper functions for opening and closing      //
// print file descriptors based on whether they were    //
// process pipes or files.                              //
//                                                      //
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
#include <glib.h>
#include "print.h"
#include "print_util.h"

FILE *OpenPrintStream (print_OP *pPO)
  {
  if (NULL == pPO) return NULL ;

  if (pPO->bPrintFile)
    return fopen (pPO->pszPrintString, "w") ;
  else
    return popen (pPO->pszPrintString, "w") ;
  }

void ClosePrintStream  (FILE *pfile, print_OP *pPO)
  {
  if (NULL == pfile || NULL == pPO) return ;

  if (pPO->bPrintFile)
    fclose (pfile) ;
  else
    pclose (pfile) ;
  }

/* Global variables */
static int clocks = NUMBER_OF_CLOCKS_DEFAULT;

/**
 * Set the number of clocks.
 * @param nClocks Number of clocks
 */
void setNumberOfClocks(int nClocks) {
  clocks = nClocks;
}

/**
 * Gets the number of clocks
 * @return Number of clocks
 */
int getNumberOfClocks(void) {
  return clocks;
}

/**
 * Get the number of meta-clocks (shifted clocks)
 * @return Number of meta-clocks.
 */
int getNumberOfMetaClocks(void) {
  return 4;
}

/**
 * Get the number of clocks in total.
 * #clocks x #meta-clocks
 * @return Number of clocks in total
 */
int getNumberOfTotalClocks(void) {
  return getNumberOfClocks() * getNumberOfMetaClocks();
}

// -------------------------------------------------------------------------------------------------

static const double PARAMETER_B_03_CLOCKS[] = {
  -6.18540,
   0.00000,
   6.18540
};

static const double PARAMETER_B_04_CLOCKS[] = {
  -6.55761,
  -2.78716,
   2.78716,
   6.55761
};

static const double PARAMETER_B_05_CLOCKS[] = {
  -6.72463,
  -4.26100,
   0.00000,
   4.26100,
   6.72463
};

static const double PARAMETER_B_06_CLOCKS[] = {
  -6.81283,
  -5.10274,
  -1.88804,
   1.88804,
   5.10274,
   6.81283
};

static const double PARAMETER_B_07_CLOCKS[] = {
  -6.86477,
  -5.61943,
  -3.15723,
   0.00000,
   3.15723,
   5.61943,
   6.86477
};

static const double PARAMETER_B_08_CLOCKS[] = {
  -6.89784,
  -5.95578,
  -4.03129,
  -1.42394,
   1.42394,
   4.03129,
   5.95578,
   6.89784
};

static const double PARAMETER_B_09_CLOCKS[] = {
  -6.92015,
  -6.18540,
  -4.65102,
  -2.49251,
   0.00000,
   2.49251,
   4.65102,
   6.18540,
   6.92015
};

static const double PARAMETER_B_10_CLOCKS[] = {
  -6.93590,
  -6.34834,
  -5.10275,
  -3.30224,
  -1.14208,
   1.14208,
   5.10275,
   3.30224,
   6.34834,
   6.93590
};

static const double PARAMETER_B_11_CLOCKS[] = {
  -6.94742,
  -6.46773,
  -5.44029,
  -3.92456,
  -2.05470,
   0.00000,
   2.05470,
   3.92456,
   5.44029,
   6.46773,
   6.94742
};

static const double PARAMETER_B_12_CLOCKS[] = {
  -6.95610,
  -6.55761,
  -5.69808,
  -4.41009,
  -2.78716,
  -0.95306,
   0.95306,
   2.78716,
   4.41009,
   5.69808,
   6.55761,
   6.95610
};

static const double PARAMETER_B_13_CLOCKS[] = {
  -6.96280,
  -6.62683,
  -5.89877,
  -4.79440,
  -3.37956,
  -1.74609,
   0.00000,
   1.74609,
   3.37956,
   4.79440,
   5.89877,
   6.62683,
   6.96280
};

static const double PARAMETER_B_14_CLOCKS[] = {
  -6.96808,
  -6.68119,
  -6.05768,
  -5.10275,
  -3.86295,
  -2.40733,
  -0.81760,
   0.81760,
   2.40733,
   3.86295,
   5.10275,
   6.05768,
   6.68119,
   6.96808
};

static const double PARAMETER_B_15_CLOCKS[] = {
  -6.97231,
  -6.72463,
  -6.18540,
  -5.35322,
  -4.26100,
  -2.96115,
  -1.51737,
   0.00000,
   1.51737,
   2.96115,
   5.35322,
   6.18540,
   4.26100,
   6.72463,
   6.97231
};

static const double PARAMETER_B_16_CLOCKS[] = {
  -6.97575,
  -6.75984,
  -6.28942,
  -5.55901,
  -4.59170,
  -3.42760,
  -2.11687,
  -0.71579,
   0.71579,
   2.11687,
   3.42760,
   4.59170,
   5.55901,
   6.28942,
   6.75984,
   6.97575
};

static const double PARAMETER_B_17_CLOCKS[] = {
  -6.97859,
  -6.78878,
  -6.37515,
  -5.72982,
  -4.86876,
  -3.82284,
  -2.63187,
  -1.34127,
   0.00000,
   1.34127,
   2.63187,
   3.82284,
   4.86876,
   5.72982,
   6.37515,
   6.78878,
   6.97859
};

static const double PARAMETER_B_18_CLOCKS[] = {
  -6.98096,
  -6.81282,
  -6.44657,
  -5.87296,
  -5.10275,
  -4.15979,
  -3.07590,
  -1.88804,
  -0.63649,
   0.63649,
   1.88804,
   3.07590,
   5.10275,
   5.87296,
   4.15979,
   6.44657,
   6.81283,
   6.98096
};

static const double PARAMETER_B_19_CLOCKS[] = {
  -6.98296,
  -6.83302,
  -6.50664,
  -5.99393,
  -5.30183,
  -4.44876,
  -3.46035,
  -2.36684,
  -1.20150,
   0.00000,
   1.20150,
   2.36684,
   3.46035,
   4.44876,
   5.30183,
   5.99393,
   6.50664,
   6.83302,
   6.98296
};

static const double PARAMETER_B_20_CLOCKS[] = {
  -6.98465,
  -6.85014,
  -6.55761,
  -6.09698,
  -5.47238,
  -4.69804,
  -3.79466,
  -2.78716,
  -1.70335,
  -0.57300,
   0.57300,
   1.70335,
   2.78716,
   3.79466,
   4.69804,
   5.47238,
   6.09698,
   6.55761,
   6.85014,
   6.98465
};

static const double * PARAMETERS_B_03_TO_07_CLOCKS[] = {
  PARAMETER_B_03_CLOCKS,
  PARAMETER_B_04_CLOCKS,
  PARAMETER_B_05_CLOCKS,
  PARAMETER_B_06_CLOCKS,
  PARAMETER_B_07_CLOCKS,
  PARAMETER_B_08_CLOCKS,
  PARAMETER_B_09_CLOCKS,
  PARAMETER_B_10_CLOCKS,
  PARAMETER_B_11_CLOCKS,
  PARAMETER_B_12_CLOCKS,
  PARAMETER_B_13_CLOCKS,
  PARAMETER_B_14_CLOCKS,
  PARAMETER_B_15_CLOCKS,
  PARAMETER_B_16_CLOCKS,
  PARAMETER_B_17_CLOCKS,
  PARAMETER_B_18_CLOCKS,
  PARAMETER_B_19_CLOCKS,
  PARAMETER_B_20_CLOCKS
};

double getParameterB(int clock, int numberOfClocks) {
  return (PARAMETERS_B_03_TO_07_CLOCKS[numberOfClocks-3])[clock];
}

//------------------------------------------------------------------------------

int numberOfClocksUsed(DESIGN *design) {
    GList *llItr;
    GList *llItrObj;
    int maxClock;
    int clock;
  
    if(design == NULL) {
        return -1;
    }
  
    maxClock = 0;
    llItr = design->lstLayers;
    while(llItr != NULL) {  // Itera pela lista de layers.
        if(QCAD_LAYER(llItr->data)->type == LAYER_TYPE_CELLS) {  // Se é uma layer de células.
            llItrObj = QCAD_LAYER(llItr->data)->lstObjs;
            while(llItrObj != NULL) {  // Itera pela lista de células da layer.
                if(NULL != llItrObj->data) {
                    clock = (((QCADCell*)llItrObj->data)->cell_options.clock) % getNumberOfClocks();
                    if(clock > maxClock) {
                        maxClock = clock;
                    }
                }
                llItrObj = llItrObj->next;
            }
        }
        llItr = llItr->next;
    }
    // Retorna o maior clock encontrado dentre todas as células.
    return (maxClock + 1);
}

void updateNumberOfClocksUsed(DESIGN *design, int oldNumberOfClocks) {
    GList *llItr;
    GList *llItrObj;
    int maxClock;
    int clock;
    int clk, metaClk;
  
    if(design == NULL) {
        return -1;
    }
  
    maxClock = 0;
    llItr = design->lstLayers;
    while(llItr != NULL) {  // Itera pela lista de layers.
        if(QCAD_LAYER(llItr->data)->type == LAYER_TYPE_CELLS) {  // Se é uma layer de células.
            llItrObj = QCAD_LAYER(llItr->data)->lstObjs;
            while(llItrObj != NULL) {  // Itera pela lista de células da layer.
                if(NULL != llItrObj->data) {
                    clock = ((QCADCell*)llItrObj->data)->cell_options.clock;
                    clk = clock % oldNumberOfClocks;
                    metaClk = clock / oldNumberOfClocks;
                    ((QCADCell*)llItrObj->data)->cell_options.clock = getNumberOfClocks() * metaClk + clk;
                }
                llItrObj = llItrObj->next;
            }
        }
        llItr = llItr->next;
    }
}