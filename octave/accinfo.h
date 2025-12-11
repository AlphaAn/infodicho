#include "libsomim.h"
#include <octave/oct.h>

const string USAGE = "\
 -- Loadable Function: [A, Q] = accinfo (E)\n\
 -- Loadable Function: [A, Q] = accinfo (E, P)\n\
 -- Loadable Function: [A, Q] = accinfo (E, P, GRAD)\n\
 -- Loadable Function: [A, Q] = accinfo (E, P, GRAD, TOL)\n\
\n\
Evaluates the accessible information A and the optimal POVM\n\
Q for quantum ensemble E.\n\
\n\
Copyright 2013 Michele Dall'Arno (michele.dallarno@gmail.com).\n\
\n\
Based on SOMIM (http://www.quantumlah.org/publications/software/SOMIM).\n\
\n\
\n\
\n";
