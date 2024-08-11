! combined_test_openpde_kinds.f90
module openpde_kinds

    implicit none
    private
    public :: R8P
    public :: R4P
    public :: R_P
    public :: I8P
    public :: I4P
    public :: I2P
    public :: I1P
    public :: I_P

    integer, parameter :: R8P  = selected_real_kind(15,307)
    integer, parameter :: R4P  = selected_real_kind(6,37)
    integer, parameter :: R_P  = R8P
    integer, parameter :: I8P  = selected_int_kind(18)
    integer, parameter :: I4P  = selected_int_kind(9)
    integer, parameter :: I2P  = selected_int_kind(4)
    integer, parameter :: I1P  = selected_int_kind(2)
    integer, parameter :: I_P  = I4P
end module openpde_kinds

program test_openpde_kinds
    use openpde_kinds
    implicit none

    ! Test variables
    real(R4P) :: test_r4
    real(R8P) :: test_r8
    integer(I1P) :: test_i1
    integer(I2P) :: test_i2
    integer(I4P) :: test_i4
    integer(I8P) :: test_i8

    ! Real precision tests
    test_r4 = 12345.6789_R4P
    test_r8 = 123456789012345.6789_R8P

    if (test_r4 /= 12345.6789_R4P) then
        print *, "R4P precision test failed."
    else
        print *, "R4P precision test passed."
    endif

    if (test_r8 /= 123456789012345.6789_R8P) then
        print *, "R8P precision test failed."
    else
        print *, "R8P precision test passed."
    endif

    ! Integer range tests
    test_i1 = 127_I1P
    test_i2 = 32767_I2P
    test_i4 = 2147483647_I4P
    test_i8 = 9223372036854775807_I8P

    if (test_i1 /= 127_I1P) then
        print *, "I1P range test failed."
    else
        print *, "I1P range test passed."
    endif

    if (test_i2 /= 32767_I2P) then
        print *, "I2P range test failed."
    else
        print *, "I2P range test passed."
    endif

    if (test_i4 /= 2147483647_I4P) then
        print *, "I4P range test failed."
    else
        print *, "I4P range test passed."
    endif

    if (test_i8 /= 9223372036854775807_I8P) then
        print *, "I8P range test failed."
    else
        print *, "I8P range test passed."
    endif

end program test_openpde_kinds