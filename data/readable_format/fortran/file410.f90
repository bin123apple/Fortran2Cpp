program test_parameterized_types
    use, intrinsic :: iso_fortran_env, only: int8, int16, int32, int64, real32, real64
    implicit none

    ! Type definitions
    type :: ipdt(k)
        integer, kind :: k
        integer(kind=k) :: x
    end type ipdt

    type :: rpdt(k)
        integer, kind :: k
        real(kind=k) :: x
    end type rpdt

    type :: zpdt(k)
        integer, kind :: k
        complex(kind=k) :: x
    end type zpdt

    type :: lpdt(k)
        integer, kind :: k
        logical(kind=k) :: x
    end type lpdt

    ! Variable declarations
    type(ipdt(int32)) :: i4
    type(rpdt(real32)) :: a4
    type(zpdt(real32)) :: z4
    type(lpdt(int8)) :: l1

    ! Test integer type
    i4%x = 42
    print *, 'i4%x = ', i4%x

    ! Test real type
    a4%x = 3.14_real32
    print *, 'a4%x = ', a4%x

    ! Test complex type
    z4%x = (2.0_real32, 3.0_real32)
    print *, 'z4%x = ', z4%x

    ! Test logical type
    l1%x = .true.
    print *, 'l1%x = ', l1%x

end program test_parameterized_types