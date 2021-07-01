#ifndef PRIV_H_GUARD
#define PRIV_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include "gpu.h"
#include "glbopts.h"
#include "linalg.h"
#include "scs.h"
#include "csparse.h"

struct SCS_LIN_SYS_WORK {
  /* reporting */
  scs_int tot_cg_its;
  /* ALL BELOW HOSTED ON THE GPU */
  scs_float *p;     /* cg iterate, n  */
  scs_float *r;     /* cg residual, n */
  scs_float *Gp;    /* G * p, n */
  scs_float *bg;    /* b, n */
  scs_float *tmp_m; /* m, used in mat_vec */
  scs_float *z;     /* preconditioned */
  scs_float *M;     /* preconditioner */
  ScsGpuMatrix *Ag;    /* A matrix on GPU */
  ScsGpuMatrix *Agt;   /* A trans matrix on GPU */
  ScsGpuMatrix *Pg;     /* P matrix on GPU */
  /* CUDA */
  cublasHandle_t cublas_handle;
  cusparseHandle_t cusparse_handle;
  /* CUSPARSE */
  size_t buffer_size;
  void *buffer;
  cusparseDnVecDescr_t dn_vec_m;   /* Dense vector of length m */
  cusparseDnVecDescr_t dn_vec_n;   /* Dense vector of length n */
  cusparseDnVecDescr_t dn_vec_n_p; /* Dense vector of length n */

  /* rho terms */
  scs_float rho_x;
  scs_float *rho_y_vec_gpu; /* rho_y_vec on GPU */
};

#ifdef __cplusplus
}
#endif
#endif
