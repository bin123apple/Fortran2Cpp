module rrlw_kg03
    implicit none
    save

    ! Assuming kind parameter definitions
    integer, parameter :: im = selected_int_kind(8)
    integer, parameter :: rb = selected_real_kind(p=6, r=37)

    ! Constants
    integer(kind=im), parameter :: no3 = 16
    real(kind=rb) :: fracrefao(no3,9), fracrefbo(no3,5)
    real(kind=rb) :: kao(9,5,13,no3)
    real(kind=rb) :: kbo(5,5,47,no3) ! Adjusted for 0-based indexing in tests
    real(kind=rb) :: kao_mn2o(9,19,no3), kbo_mn2o(5,19,no3)
    real(kind=rb) :: selfrefo(10,no3)
    real(kind=rb) :: forrefo(4,no3)

    integer(kind=im), parameter :: ng3 = 16
    real(kind=rb) :: fracrefa(ng3,9), fracrefb(ng3,5)
    real(kind=rb) :: ka(9,5,13,ng3)
    real(kind=rb) :: kb(5,5,47,ng3) ! Adjusted for 0-based indexing in tests
    real(kind=rb) :: ka_mn2o(9,19,ng3), kb_mn2o(5,19,ng3)
    real(kind=rb) :: selfref(10,ng3)
    real(kind=rb) :: forref(4,ng3)

end module rrlw_kg03

program test_rrlw_kg03
    use rrlw_kg03
    implicit none

    ! Test array sizes and assignments
    fracrefao(1, 1) = 1.0_rb
    fracrefbo(1, 1) = 2.0_rb
    kao(1, 1, 1, 1) = 3.0_rb
    kbo(1, 1, 1, 1) = 4.0_rb
    selfrefo(1, 1) = 5.0_rb
    forrefo(1, 1) = 6.0_rb

    ! Output to verify the assignments
    print *, "fracrefao(1,1):", fracrefao(1, 1)
    print *, "fracrefbo(1,1):", fracrefbo(1, 1)
    print *, "kao(1,1,1,1):", kao(1, 1, 1, 1)
    print *, "kbo(1,1,1,1):", kbo(1, 1, 1, 1)
    print *, "selfrefo(1,1):", selfrefo(1, 1)
    print *, "forrefo(1,1):", forrefo(1, 1)

    if (fracrefao(1, 1) == 1.0_rb .and. &
        fracrefbo(1, 1) == 2.0_rb .and. &
        kao(1, 1, 1, 1) == 3.0_rb .and. &
        kbo(1, 1, 1, 1) == 4.0_rb .and. &
        selfrefo(1, 1) == 5.0_rb .and. &
        forrefo(1, 1) == 6.0_rb) then
        print *, "Fortran Test Passed"
    else
        print *, "Fortran Test Failed"
    endif
end program test_rrlw_kg03