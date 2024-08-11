PROGRAM test_tensors
  IMPLICIT NONE

  ! Defining constants
  INTEGER, PARAMETER :: dp = SELECTED_REAL_KIND(p=15, r=307)
  
  ! Define the types directly here
  TYPE :: tensor_rank0
    REAL(KIND=dp) :: sca
  END TYPE tensor_rank0

  TYPE :: tensor_rank1
    REAL(KIND=dp) :: a(3)
    REAL(KIND=dp) :: a_damp(3)
    REAL(KIND=dp) :: a_damp2(3)
  END TYPE tensor_rank1

  TYPE :: tensor_rank2
    REAL(KIND=dp) :: ab(3,3)
    REAL(KIND=dp) :: ab_damp(3,3)
    REAL(KIND=dp) :: ab_damp2(3,3)
    REAL(KIND=dp) :: ab_thole(3,3)
  END TYPE tensor_rank2

  TYPE :: tensor_rank3
    REAL(KIND=dp) :: abc(3,3,3)
  END TYPE tensor_rank3

  TYPE :: tensor_rank4
    REAL(KIND=dp) :: abcd(3,3,3,3)
  END TYPE tensor_rank4

  TYPE :: tensor_rank5
    REAL(KIND=dp) :: abcde(3,3,3,3,3)
  END TYPE tensor_rank5

  TYPE :: interaction_dd
    TYPE(tensor_rank2) :: T2
    TYPE(tensor_rank3) :: T3
  END TYPE interaction_dd

  ! Test variables
  TYPE(tensor_rank0) :: t0
  TYPE(tensor_rank1) :: t1
  TYPE(tensor_rank2) :: t2
  TYPE(tensor_rank3) :: t3
  TYPE(tensor_rank4) :: t4
  TYPE(tensor_rank5) :: t5
  TYPE(interaction_dd) :: int_dd

  ! Testing tensor_rank0
  t0%sca = 1.0_dp
  PRINT *, "tensor_rank0 sca =", t0%sca

  ! Testing tensor_rank1
  t1%a = [1.0_dp, 2.0_dp, 3.0_dp]
  PRINT *, "tensor_rank1 a =", t1%a

  ! Testing tensor_rank2
  t2%ab = RESHAPE(SOURCE=[1.0_dp, 2.0_dp, 3.0_dp, 4.0_dp, 5.0_dp, 6.0_dp, 7.0_dp, 8.0_dp, 9.0_dp], SHAPE=[3,3])
  PRINT *, "tensor_rank2 ab =", t2%ab

  ! Testing tensor_rank3
  t3%abc(1,1,1) = 1.0_dp
  PRINT *, "tensor_rank3 abc(1,1,1) =", t3%abc(1,1,1)

  ! Testing tensor_rank4
  t4%abcd(1,1,1,1) = 1.0_dp
  PRINT *, "tensor_rank4 abcd(1,1,1,1) =", t4%abcd(1,1,1,1)

  ! Testing tensor_rank5
  t5%abcde(1,1,1,1,1) = 1.0_dp
  PRINT *, "tensor_rank5 abcde(1,1,1,1,1) =", t5%abcde(1,1,1,1,1)

  ! Testing interaction_dd
  int_dd%T2%ab(1,1) = 2.0_dp
  PRINT *, "interaction_dd T2 ab(1,1) =", int_dd%T2%ab(1,1)
  
END PROGRAM test_tensors