module linspace_module
    implicit none
contains
    function linspace(a,b,n) result(x)
        real(kind=8), intent(in) :: a,b
        integer, intent(in) :: n
        real(kind=8), allocatable :: x(:)
        integer :: i
        real(kind=8) :: s
        
        if (n <= 0) then
            print *, "Error: n must be greater than 0."
            stop
        end if
        
        allocate(x(n))
        if (n == 1) then
            x(1) = a
        else
            s = (b-a)/(n-1.d0)
            do i=1,n
                x(i) = a + s*(i-1.d0)
            end do
        end if
    end function linspace
end module linspace_module

program test_linspace
    use linspace_module
    implicit none
    double precision, allocatable :: array(:)
    integer :: i

    ! Normal case
    print *, 'Normal case: linspace(0, 10, 5)'
    array = linspace(0.d0, 10.d0, 5)
    do i=1, size(array)
        print *, array(i)
    end do

    ! Edge case: n=1
    print *, 'Edge case: linspace(0, 10, 1)'
    array = linspace(0.d0, 10.d0, 1)
    do i=1, size(array)
        print *, array(i)
    end do

    ! Edge case: n is a very large number
    print *, 'Edge case: linspace(0, 10, 100000)'
    array = linspace(0.d0, 10.d0, 100000)  ! Use a smaller number if this is too large for your system
    print *, 'First and last elements for large n:'
    print *, array(1), array(size(array))
end program test_linspace