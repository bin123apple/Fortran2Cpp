MODULE DataPrecisionGlobals

  IMPLICIT NONE

  PUBLIC

  INTEGER, PARAMETER :: i32=Selected_Int_Kind(6)
  INTEGER, PARAMETER :: i64=Selected_Int_Kind(12)
  INTEGER, PARAMETER :: r32=KIND(1.0)
  INTEGER, PARAMETER :: r64=KIND(1.0D0)
  INTEGER, PARAMETER :: default_prec=r64
  REAL(r64), PARAMETER :: constant_zero=0.0d0
  REAL(r64), PARAMETER :: constant_one=1.0d0
  REAL(r64), PARAMETER :: constant_minusone=-1.0d0
  REAL(r64), PARAMETER :: constant_twenty=20.0d0
  REAL(r64), PARAMETER :: constant_pointfive=.5d0
  REAL(r64), PARAMETER :: EXP_LowerLimit=-20.d0
  REAL(r64), PARAMETER :: EXP_UpperLimit= 40.d0

END MODULE DataPrecisionGlobals

PROGRAM Test_DataPrecisionGlobals
  USE DataPrecisionGlobals
  IMPLICIT NONE

  WRITE(*,*) 'Testing constants from DataPrecisionGlobals...'
  WRITE(*,*) 'constant_zero:', constant_zero
  WRITE(*,*) 'constant_one:', constant_one
  WRITE(*,*) 'constant_minusone:', constant_minusone
  WRITE(*,*) 'constant_twenty:', constant_twenty
  WRITE(*,*) 'constant_pointfive:', constant_pointfive
  WRITE(*,*) 'EXP_LowerLimit:', EXP_LowerLimit
  WRITE(*,*) 'EXP_UpperLimit:', EXP_UpperLimit

  ! You can add more tests or program logic here.

END PROGRAM Test_DataPrecisionGlobals