MODULE multistats
  ! Define numerical kinds directly in this module
  INTEGER, PARAMETER :: SP = SELECTED_REAL_KIND(p=6, r=37) ! Single precision
  INTEGER, PARAMETER :: DP = SELECTED_REAL_KIND(p=15, r=307) ! Double precision (for reference)
  INTEGER, PARAMETER :: I4B = SELECTED_INT_KIND(9) ! ~4-byte integer

  TYPE SUMMARY
    REAL(SP)                             :: VAR_RESIDUL
    REAL(SP)                             :: LOGP_SIMULN
    REAL(SP)                             :: JUMP_TAKEN
    REAL(SP)                             :: QOBS_MEAN
    REAL(SP)                             :: QSIM_MEAN
    REAL(SP)                             :: QOBS_CVAR
    REAL(SP)                             :: QSIM_CVAR
    REAL(SP)                             :: QOBS_LAG1
    REAL(SP)                             :: QSIM_LAG1
    REAL(SP)                             :: RAW_RMSE
    REAL(SP)                             :: LOG_RMSE
    REAL(SP)                             :: NASH_SUTT
    REAL(SP)                             :: NUM_RMSE
    REAL(SP)                             :: NUM_FUNCS
    REAL(SP)                             :: NUM_JACOBIAN
    REAL(SP)                             :: NUMSUB_ACCEPT
    REAL(SP)                             :: NUMSUB_REJECT
    REAL(SP)                             :: NUMSUB_NOCONV
    INTEGER(I4B)                         :: MAXNUM_ITERNS
    REAL(SP), DIMENSION(20)              :: NUMSUB_PROB
    CHARACTER(LEN=1024)                  :: ERR_MESSAGE
  ENDTYPE SUMMARY

  TYPE(SUMMARY)                         :: MSTATS
  INTEGER(I4B)                          :: MOD_IX=1
  INTEGER(I4B)                          :: PCOUNT
  INTEGER(I4B)                          :: FCOUNT

END MODULE multistats

PROGRAM test_multistats
  USE multistats
  IMPLICIT NONE

  ! Example code to manipulate and print MSTATS variables
  MSTATS%VAR_RESIDUL = 1.234_SP
  PRINT *, 'VAR_RESIDUL:', MSTATS%VAR_RESIDUL

END PROGRAM test_multistats