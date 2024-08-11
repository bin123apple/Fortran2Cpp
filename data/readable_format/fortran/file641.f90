program test
    implicit none
    real :: i

    ! Test 1: i > 7.7
    write(*,*) "Test 1: i = 9.9"
    i = 9.9
    call testBlock(i)

    ! Test 2: i <= 7.7
    write(*,*) "Test 2: i = 6.6"
    i = 6.6
    call testBlock(i)

contains

    subroutine testBlock(i)
        real, intent(inout) :: i
        
        if (i > 7.7) then
            ! No action needed, just mimic exit behavior
        else
            i = 2.2
        end if
        
        print*, "Result:", i
    end subroutine testBlock

end program test