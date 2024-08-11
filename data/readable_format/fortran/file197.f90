program test_calcrhofacomp
    use omp_lib
    implicit none
    integer, parameter :: nface=2, ntmat_=1
    integer, dimension(3) :: mi = (/4, 2, 3/)
    integer, dimension(3, nface) :: ielmat
    integer, dimension(4, nface) :: ielfa
    real(kind=8), dimension(0:5, nface) :: vfa
    real(kind=8), dimension(0:3, ntmat_, 3) :: shcon
    integer :: i

    ! Initialize inputs
    do i=1, nface
        ielmat(1, i) = 1
        ielfa(1, i) = i
        vfa(0, i) = 1.0d0
        vfa(4, i) = 10.0d0
    end do

    shcon(3, 1, 1) = 2.0d0

    ! Call subroutine
    call calcrhofacomp(nface, vfa, shcon, ielmat, ntmat_, mi, ielfa)

    ! Print results
    do i=1, nface
        print *, 'vfa(5,', i, ') = ', vfa(5, i)
    end do

contains

    subroutine calcrhofacomp(nface,vfa,shcon,ielmat,ntmat_,mi,ielfa)
        implicit none

        integer nface,i,imat,ntmat_,mi(*)
        integer ielmat(mi(3),*),ielfa(4,*)
        real(kind=8) t1l,vfa(0:5,*),shcon(0:3,ntmat_,*) 

        !$omp parallel default(none) shared(nface,vfa,ielmat,ielfa,shcon) private(i,t1l,imat)
        !$omp do
        do i=1,nface
            t1l=vfa(0,i)

            imat=ielmat(1,ielfa(1,i))
            vfa(5,i)=vfa(4,i)/(shcon(3,1,imat)*t1l)
        end do
        !$omp end do
        !$omp end parallel
    end subroutine calcrhofacomp

end program test_calcrhofacomp