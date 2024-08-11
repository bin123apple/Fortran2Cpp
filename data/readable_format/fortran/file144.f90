program main
    implicit none
    integer :: n1, n2
    integer, dimension(2) :: a
    integer :: h
    equivalence (a(1), n1), (a(2), n2)

    ! Initialize some values for demonstration
    n1 = 1
    n2 = 2
    print *, 'Before: n1 = ', n1, ', n2 = ', n2

    ! Example use of the d function from each "module" context
    h = 10
    print *, 'Function d result (p context): ', d_p(h)
    print *, 'Function d result (q context): ', d_q(h)
    print *, 'Function d result (r context): ', d_r(h)

    ! Change a(1) and a(2) to demonstrate equivalence
    a(1) = 5
    a(2) = 10
    print *, 'After: n1 = ', n1, ', n2 = ', n2

contains

    ! Function d from module p
    pure integer function d_p(h)
        integer, intent(in) :: h
        d_p = h
    end function d_p

    ! Function d from module q (replicating different module context)
    pure integer function d_q(h)
        integer, intent(in) :: h
        d_q = h
    end function d_q

    ! Function d from module r (replicating different module context)
    pure integer function d_r(h)
        integer, intent(in) :: h
        d_r = h
    end function d_r

end program main