#include "accinfo.h"

void setRho(ComplexNDArray* E, SOMIM* somim) {
  int N = E->dims()(0);
  int J = E->dims()(2);
  for (int j = 0; j < J; j++)
    for (int n = 0; n < N; n++)
      for (int m = 0; m < N; m++)
	somim->setRho(j,n,m, E->elem(n,m,j));
}

void setPOVM(ComplexNDArray* P, SOMIM* somim) {
  for (int k = 0; k < P->dims()(2); k++)
    for (int n = 0; n < P->dims()(0); n++)
      for (int m = 0; m < P->dims()(1); m++)
	somim->setPOVM(k,n,m, P->elem(n,m,k));
}

void getPOVM(ComplexNDArray* P, SOMIM* somim) {
  for (int k = 0; k < P->dims()(2); k++)
    for (int n = 0; n < P->dims()(0); n++)
      for (int m = 0; m < P->dims()(1); m++)
	P->elem(n,m,k) = somim->getPOVM(k,n,m);
}

DEFUN_DLD (accinfo, args, , USAGE)
{
  double A;
  int N, M, J, K;
  ComplexNDArray E, P;
  int nargin = args.length ();
  octave_value_list retval;

  if (nargin == 0) {print_usage (); return octave_value_list (retval);}

  if (nargin >= 1) {
    E = args(0).complex_array_value ();
    N = E.dims()(0); M = E.dims()(1); J = E.dims()(2); K = N*N;
  }

  if (nargin >= 2) {
    P = args(1).complex_array_value ();
    if (P.dims()(0) == 1) {
      K = (int) P.elem(0).real();
      if (K < N || K > N*N) {print_usage (); return octave_value_list (retval);}
    }
    else K = P.dims()(2);
  }

  SOMIM* somim = new SOMIM(N, J, K);

  if (nargin >= 3) somim->setDirectGrad(args(2).matrix_value().elem(0));
  if (nargin >= 4) somim->setTolerance(args(3).matrix_value().elem(0));

  setRho(&E, somim);
  if (P.dims()(0) > 1) setPOVM(&P, somim);
  
  A = somim->getMI();
  K = somim->getK();

  dim_vector dv(N, N, K);
  ComplexNDArray Q(dv);
  getPOVM(&Q, somim);

  retval(0) = octave_value (A);
  retval(1) = octave_value (Q);

  return octave_value_list (retval);
}

