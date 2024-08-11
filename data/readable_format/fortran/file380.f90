module xc_pzca_module
    implicit none
contains
    subroutine xc_pzca(n, rho, ex, ec, vx, vc)
        integer, intent(in) :: n
        real(8), intent(in) :: rho(n)
        real(8), intent(out) :: ex(n), ec(n), vx(n), vc(n)
        integer :: i
        real(8), parameter :: pi=3.1415926535897932385d0
        real(8), parameter :: thrd=1.d0/3.d0, thrd2=2.d0/3.d0, thrd4=4.d0/3.d0
        real(8), parameter :: g=-0.1423d0, b1=1.0529d0, b2=0.3334d0
        real(8), parameter :: a=0.0311d0, b=-0.048d0, c=0.0020d0, d=-0.0116d0
        real(8) :: p1, p2, r, rs, t1

        if (n.le.0) then
            print *, "Error(xc_pzca): invalid n : ", n
            stop
        end if

        t1=3.d0/(4.d0*pi)
        p1=t1**thrd
        p2=t1*(9.d0*pi/4.d0)**thrd

        do i=1,n
            r=rho(i)
            if (r.lt.1.d-12) then
                ex(i)=0.d0
                ec(i)=0.d0
                vx(i)=0.d0
                vc(i)=0.d0
                cycle
            end if
            rs=p1/r**thrd
            ex(i)=-p2/rs
            vx(i)=thrd4*ex(i)
            if (rs.ge.1.d0) then
                t1=sqrt(rs)
                ec(i)=g/(1.d0+b1*t1+b2*rs)
                vc(i)=ec(i)*(1.d0+(7.d0/6.d0)*b1*t1+thrd4*b2*rs)/(1.d0+b1*t1+b2*rs)
            else
                t1=dlog(rs)
                ec(i)=a*t1+b+c*rs*t1+d*rs
                vc(i)=a*t1+(b-thrd*a)+thrd2*c*rs*t1+thrd*(2.d0*d-c)*rs
            end if
        end do
    end subroutine xc_pzca
end module xc_pzca_module

program test_xc_pzca
    use xc_pzca_module
    implicit none
    integer :: n
    double precision :: rho(5), ex(5), ec(5), vx(5), vc(5)

    ! Test 1: General case
    n = 5
    rho = (/0.1d0, 0.2d0, 0.3d0, 0.4d0, 0.5d0/)
    call xc_pzca(n, rho, ex, ec, vx, vc)
    print *, "Test 1: General case"
    print *, "ex:", ex
    print *, "ec:", ec
    print *, "vx:", vx
    print *, "vc:", vc
    print *, ""

    ! Additional tests can be added here following the same structure
    ! For instance, testing with n=0, negative values in rho, etc.

end program test_xc_pzca