module my_module
    implicit none
contains
    subroutine perform_operations(a, b, c, d, e, f, result)
        integer, intent(inout) :: a
        integer, intent(inout) :: b
        real, intent(inout) :: c
        double precision, intent(inout) :: d
        integer, dimension(10), intent(inout) :: e
        real, intent(inout) :: f
        integer, intent(out) :: result

        integer :: i
        a = 1
        b = 2
        c = 3.0
        d = 4.0
        e = 5
        f = 6.0

        a = a + 4
        b = 4 - b
        c = c * 2
        d = 2 / d

        if (a /= 5 .or. b /= 2 .or. c /= 6 .or. d /= 0.5) then
            result = 1
            return
        endif
        
        d = 1.2
        a = a + int(c) + int(d)
        b = b - (a + int(c) + int(d))

        if (a /= 12 .or. b /= -17) then
            result = 2
            return
        endif
        
        a = int(c) + int(d) + a
        b = a + int(c) + int(d) - b
        
        if (a /= 19 .or. b /= 43) then
            result = 3
            return
        endif
        
        b = (a + int(c) + int(d)) - b
        a = 32
        a = a / 3

        if (a /= 10 .or. b /= -16) then
            result = 4
            return
        endif
        
        result = 0
    end subroutine perform_operations
end module my_module

program test_program
    use my_module
    implicit none
    integer :: a, b, result
    real :: c, f
    double precision :: d
    integer, dimension(10) :: e
    
    call perform_operations(a, b, c, d, e, f, result)
    print *, "Operation Result: ", result
end program test_program