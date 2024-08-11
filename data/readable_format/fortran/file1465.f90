module MOD_ISRCHFLE
contains
    function ISRCHFLE(N, array, istep, value)
        implicit none
        integer, intent(in) :: N, istep
        real*8, intent(in) :: array(N), value
        integer :: ISRCHFLE, i, k
        real*8 :: arr
        
        i = 0
        do k = N, 1, -istep
            arr = array(k)
            if (arr <= value) then
                i = k
                exit
            endif
        enddo
        
        if (i > 0) then
            ISRCHFLE = i
            print *, 'ISRCHFLE= ', i, array(i), value
        else
            write (6, *) 'ISRCHFLE failed'
            stop 'error'
        endif
    end function ISRCHFLE
    
    subroutine test_ISRCHFLE()
        implicit none
        real*8, dimension(5) :: testArray
        integer :: result
        
        testArray = (/10.0d0, 20.0d0, 30.0d0, 40.0d0, 50.0d0/)
        result = ISRCHFLE(5, testArray, 1, 25.0d0)
        
        if (result == 3) then
            print *, 'Test passed.'
        else
            print *, 'Test failed: Expected 3, got ', result
        endif
    end subroutine test_ISRCHFLE
end module MOD_ISRCHFLE

program test
    use MOD_ISRCHFLE
    call test_ISRCHFLE()
end program test