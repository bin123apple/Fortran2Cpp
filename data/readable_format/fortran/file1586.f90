module orders
implicit none
contains
    function double_order(x) result(y)
        double precision, intent(in) :: x
        double precision :: y
        y = 2*x
    end function double_order

    function integer_order(x) result(y)
        integer, intent(in) :: x
        integer :: y
        y = 2*x
    end function integer_order

    function real_order(x) result(y)
        real, intent(in) :: x
        real :: y
        y = 2*x
    end function real_order
end module orders

program test_orders
    use orders
    implicit none
    
    ! Test variables
    double precision :: dresult
    integer :: iresult
    real :: rresult

    ! Testing double_order
    dresult = double_order(2.0d0)
    print *, 'double_order(2.0) = ', dresult

    ! Testing integer_order
    iresult = integer_order(2)
    print *, 'integer_order(2) = ', iresult

    ! Testing real_order
    rresult = real_order(2.0)
    print *, 'real_order(2.0) = ', rresult
end program test_orders