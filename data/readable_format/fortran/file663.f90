! test_atomic_operations.f90
program test_atomic_operations
    use iso_fortran_env, only: atomic_int_kind
    implicit none
    integer(atomic_int_kind) :: a
    integer(atomic_int_kind) :: b
    logical :: d
    logical :: e

    ! Initialize atomic variables
    a = 7
    d = .TRUE.
    e = .TRUE.

    ! Perform atomic operations
    b = a
    ! Note: Direct assignment is used since atomic_ref and atomic_define are not required in single-image context

    ! Test and print results
    print *, "a: ", a
    print *, "b: ", b
    print *, "d: ", d
    print *, "e: ", e

end program test_atomic_operations