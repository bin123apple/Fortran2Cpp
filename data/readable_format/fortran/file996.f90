module gsw_mod_kinds

implicit none

integer, parameter :: r4 = selected_real_kind(6,30)
integer, parameter :: r8 = selected_real_kind(14,30)

end module gsw_mod_kinds

program test_kinds
    use gsw_mod_kinds
    implicit none

    real(kind=r4) :: var_r4
    real(kind=r8) :: var_r8

    ! Test precision
    var_r4 = 1.234567
    var_r8 = 1.23456789012345

    print *, "Testing precision..."
    print *, "r4 (should be ~1.234567): ", var_r4
    print *, "r8 (should be ~1.23456789012345): ", var_r8

    ! Test range by assigning a very small and very large number
    var_r4 = 1.0E30_r4
    var_r8 = 1.0E300_r8

    print *, "Testing range..."
    print *, "r4 (large number, should be ~1E30): ", var_r4
    print *, "r8 (very large number, should be ~1E300): ", var_r8

end program test_kinds