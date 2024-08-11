program test_parameters
    implicit none

    integer, parameter :: nn=25,ni=48,nj=096,nnaf=23,minc=4
    integer, parameter :: nnp2=nn+2,nnp1=nn+1,nn1=nn-1,nn2=nn-2,nn3=nn-3
    integer, parameter :: nps2=nnp1/2,ns2=nn1/2,nnx2=2*nn,nja=nj/minc
    integer, parameter :: nrp=nja+2,ncp=nrp/2,ntf=3*nja/2+1,njp1=nj+1,nip1=ni+1
    integer, parameter :: lmax=(nj)/3,mmax=(lmax/minc)*minc,nmaf=mmax+1
    integer, parameter :: nmafa=mmax/minc+1,nlm=(nmaf*(nmaf+1))/2,nlaf=lmax+1
    integer, parameter :: nlma=mmax*nlaf/minc-mmax*(mmax-minc)/(2*minc)+nlaf-mmax
    integer, parameter :: lot=2*nlma,nlafp1=nlaf+1,nlmpa=nlma+nmafa

    ! Test cases
    call test_value("nnp2", nnp2, 27)
    call test_value("njp1", njp1, 97)
    ! Add more tests as needed...

end program test_parameters

subroutine test_value(name, value, expected)
    implicit none
    character(len=*), intent(in) :: name
    integer, intent(in) :: value, expected

    if (value == expected) then
        print *, trim(name)//" test passed."
    else
        print *, trim(name)//" test failed. Expected: ", expected, " Got: ", value
    end if
end subroutine test_value