program arrayio_2_test
    implicit none
    integer :: test_result

    call test_arrayio_2(test_result)
    
    if (test_result .eq. 0) then
        print *, "All tests passed successfully."
    else
        print *, "Some tests failed."
    end if

contains

    subroutine test_arrayio_2(result)
        implicit none
        integer, intent(out) :: result
        integer :: i=2
        character(len=12), dimension(4,2) :: r = "0123456789ab"
        character(len=80) :: f
        result = 0

        f = '("hello"/"world")'
        write(r(1:4,i-1), f)
        f = '("hello",t1,"HELLO",1x,"!"/"world",tl12,"WORLD")'
        write(r((i-1):(i+1),i), f)

        if ( r(1,1).ne.'hello       ' .or. &
             r(2,1).ne.'world       ' .or. &
             r(3,1).ne.'0123456789ab' .or. &
             r(4,1).ne.'0123456789ab' .or. &
             r(1,2).ne.'HELLO !     ' .or. &
             r(2,2).ne.'WORLD       ' .or. &
             r(3,2).ne.'0123456789ab' .or. &
             r(4,2).ne.'0123456789ab') then
            result = 1
        end if
    end subroutine test_arrayio_2

end program arrayio_2_test