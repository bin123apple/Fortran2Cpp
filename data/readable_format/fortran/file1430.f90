module mod1
    implicit none
    integer, parameter :: modval1 = 1
end module mod1

program test_mod1
    use mod1
    implicit none

    write(*,*) 'Testing mod1...'
    write(*,*) 'modval1 = ', modval1

    if (modval1 == 1) then
        write(*,*) 'Test PASSED.'
    else
        write(*,*) 'Test FAILED.'
    endif
end program test_mod1