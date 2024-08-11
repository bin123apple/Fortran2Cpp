module random_number_generators_mod
    implicit none
    contains

    double precision function randlc(x, a)
        double precision, intent(inout) :: x
        double precision, intent(in) :: a
        double precision :: r23, r46, t23, t46, t1, t2, t3, t4, a1, a2, x1, x2, z
        parameter (r23 = 0.5d0 ** 23, r46 = r23 ** 2, t23 = 2.d0 ** 23, t46 = t23 ** 2)
        t1 = r23 * a
        a1 = int(t1)
        a2 = a - t23 * a1
        t1 = r23 * x
        x1 = int(t1)
        x2 = x - t23 * x1
        t1 = a1 * x2 + a2 * x1
        t2 = int(r23 * t1)
        z = t1 - t23 * t2
        t3 = t23 * z + a2 * x2
        t4 = int(r46 * t3)
        x = t3 - t46 * t4
        randlc = r46 * x
    end function randlc

    subroutine vranlc(n, x, a, y)
        integer, intent(in) :: n
        double precision, intent(inout) :: x
        double precision, intent(in) :: a
        double precision, intent(out) :: y(n)
        integer :: i
        do i = 1, n
            y(i) = randlc(x, a)
        end do
    end subroutine vranlc
end module random_number_generators_mod

program test_random_number_generators
    use random_number_generators_mod
    implicit none
    double precision :: x, a, y(10)
    integer :: i

    x = 12345.6789d0
    a = 987654.321d0

    print *, 'Testing randlc with x =', x, 'and a =', a
    print *, 'randlc result:', randlc(x, a)

    call vranlc(10, x, a, y)
    print *, 'Testing vranlc with 10 elements'
    do i = 1, 10
        print *, 'y(', i, ') =', y(i)
    end do
end program test_random_number_generators