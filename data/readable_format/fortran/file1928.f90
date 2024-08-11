PROGRAM Main
  IMPLICIT NONE
  INTEGER, PARAMETER :: DP = KIND(1.0D0)
  INTEGER :: nat
  REAL(KIND=DP), ALLOCATABLE :: if_pos(:,:), fix_atom_pos(:,:)

  ! Assuming 'nat' represents the number of atoms. Here we initialize it for the example.
  nat = 3

  ! Allocate and initialize 'if_pos' for demonstration purposes.
  ALLOCATE(if_pos(3, nat))
  if_pos = RESHAPE(SOURCE=[1.0_DP, 2.0_DP, 3.0_DP, &
                           4.0_DP, 5.0_DP, 6.0_DP, &
                           7.0_DP, 8.0_DP, 9.0_DP], SHAPE=[3, nat])

  CALL engine_to_path_fix_atom_pos(nat, if_pos, fix_atom_pos)

  ! Example: Output the result to verify correctness
  PRINT *, "Resulting fix_atom_pos:"
  PRINT *, fix_atom_pos

  DEALLOCATE(if_pos)
  DEALLOCATE(fix_atom_pos)

CONTAINS

  SUBROUTINE engine_to_path_fix_atom_pos(nat, if_pos, fix_atom_pos)
    INTEGER, INTENT(IN) :: nat
    REAL(KIND=DP), INTENT(IN) :: if_pos(:,:)
    REAL(KIND=DP), ALLOCATABLE, INTENT(OUT) :: fix_atom_pos(:,:)
    ALLOCATE(fix_atom_pos(3, nat))
    fix_atom_pos = if_pos
  END SUBROUTINE engine_to_path_fix_atom_pos

END PROGRAM Main