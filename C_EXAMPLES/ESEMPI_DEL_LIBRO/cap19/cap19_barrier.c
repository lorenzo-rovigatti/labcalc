/*
  cap19_barrier.c: A Monte Carlo simulation in a double well potential.
  Copyright (C) 2006 Federico Ricci-Tersenghi (Federico.Ricci@roma1.infn.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

  This program has been extracted from "Programmazione Scientifica",
  Pearson Education ed. (2006), by Barone, Marinari, Organtini and
  Ricci-Tersenghi. ISBN 8871922425.
*/

/* by FRT */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FNORM   (2.3283064365e-10)
#define RANDOM  ((ira[ip++] = ira[ip1++] + ira[ip2++]) ^ ira[ip3++])
#define FRANDOM (FNORM * RANDOM)
#define pm1 ((FRANDOM > 0.5) ? 1 : -1)

/* variabili globali per il generatore random */
unsigned myrand, ira[256];
unsigned char ip, ip1, ip2, ip3;

unsigned randForInit(void);
void initRandom(void);
float gaussRan(void);
void error(char *);
int oneStep(int, int);

int main(int argc, char *argv[]) {
  int pos, L, t, nIter, measTime;

  if (argc != 4) {
    fprintf(stderr, "usage: %s <L> <nIter> <seed>\n", argv[0]);
    exit(1);
  }
  
  L = (int)atoi(argv[1]);
  nIter = (long long int)atoi(argv[2]);
  myrand = (unsigned)atoi(argv[3]);

  if (myrand == 2147483647)
    error("seed must be less than 2147483647");

  initRandom();
  printf("# L = %i\n", L);
  measTime = (int)(nIter / 10000);
  pos = 0;
  for (t = 1; t <= nIter; t++) {
    pos = oneStep(pos, L);
    if (t % measTime == 0) printf("%i %i\n", t, pos);
  }
  return 0;
}

int oneStep(int pos, int L) {
  int newPos = pos + pm1;
  double ratio = exp(-0.5 * (newPos * newPos - pos * pos)) *
    cosh(newPos * L) / cosh(pos * L);

  if (ratio >= 1.0 || FRANDOM < ratio)
    return newPos;
  else
    return pos;
}

unsigned randForInit(void) {
  unsigned long long y;
  
  y = myrand * 16807LL;
  myrand = (y & 0x7fffffff) + (y >> 31);
  if (myrand & 0x80000000) {
    myrand = (myrand & 0x7fffffff) + 1;
  }
  return myrand;
}

void initRandom(void) {
  int i;
  
  ip = 128;    
  ip1 = ip - 24;    
  ip2 = ip - 55;    
  ip3 = ip - 61;
  
  for (i = ip3; i < ip; i++) {
    ira[i] = randForInit();
  }
}

float gaussRan(void) {
  static int iset = 0;
  static float gset;
  float fac, rsq, v1, v2;

  if (iset == 0) {
    do {
      v1 = 2.0 * FRANDOM - 1.0;
      v2 = 2.0 * FRANDOM - 1.0;
      rsq = v1 * v1 + v2 * v2;
    } while (rsq >= 1.0 || rsq == 0.0);
    fac = sqrt(-2.0 * log(rsq) / rsq);
    gset = v1 * fac;
    iset = 1;
    return v2 * fac;
  } else {
    iset = 0;
    return gset;
  }
}

void error(char *string) {
  fprintf(stderr, "ERROR: %s\n", string);
  exit(EXIT_FAILURE);
}
