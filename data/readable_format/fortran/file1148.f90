program triangular_pentagonal_hexagonal
    implicit none
    
    ! Call the main solver routine
    call solver
    
    ! Perform unit testing
    call test_polygon
    
contains
    
    function polygon(p, n) result(result)
        integer, intent(in) :: p, n
        integer :: result
        integer :: a
        
        select case (p)
        case (3)
            if (mod(n, 2) == 0) then
                a = n / 2
                result = a * (n + 1)
            else
                a = (n + 1) / 2
                result = n * a
            end if
        case (5)
            if (mod(n, 2) == 0) then
                a = n / 2
                result = a * (n * 3 - 1)
            else
                a = n + (n - 1) / 2
                result = n * a
            end if
        case (6)
            result = n * (2 * n - 1)
        case default
            print *, "Error: Invalid polygon type"
            stop
        end select
    end function polygon
    
    subroutine solver
        integer :: i, j, k, pt, pp, ph
        
        i = 285
        j = 165
        k = 143
        pp = polygon(5, j)
        ph = polygon(6, k)
        pt = 0
        
        do while (pt /= pp .or. pt /= ph)
            i = i + 1
            pt = polygon(3, i)
            do while (pp < pt)
                j = j + 1
                pp = polygon(5, j)
            end do
            do while (ph < pt)
                k = k + 1
                ph = polygon(6, k)
            end do
        end do
        
        print *, "result = ", pt
    end subroutine solver
    
    subroutine test_polygon
        integer :: errors
        errors = 0
        ! Test cases for the polygon function
        if (polygon(3, 285) /= 40755) then
            print *, "Test failed for polygon(3, 285)"
            errors = errors + 1
        end if
        if (polygon(5, 165) /= 40755) then
            print *, "Test failed for polygon(5, 165)"
            errors = errors + 1
        end if
        if (polygon(6, 143) /= 40755) then
            print *, "Test failed for polygon(6, 143)"
            errors = errors + 1
        end if
        
        if (errors == 0) then
            print *, "All tests passed."
        else
            print *, errors, " tests failed."
        end if
    end subroutine test_polygon

end program triangular_pentagonal_hexagonal