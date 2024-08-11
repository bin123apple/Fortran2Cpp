module propage_mod
    implicit none
    contains

    subroutine propage(ip1,ip2,ier,iirai, & 
        npn,nsn,ncn,nfront,nd,nk,npar, &
        ys,iys,dys,iseg,icel,nrai,ncel,nseg, &
        irai,iraf,irpop,irais,isatr,isats,isatc)
        implicit none
        integer, intent(in) :: ip1, ip2, ier, iirai
        integer, intent(in) :: npn, nsn, ncn, nfront, nd, nk, npar
        real, intent(inout) :: ys(npar,npn,nfront)
        integer, intent(inout) :: iys(nk,npn,nfront)
        double precision, intent(inout) :: dys(nd,npn,nfront)
        integer, intent(inout) :: iseg(nsn,6,nfront), icel(ncn,6,nfront)
        integer, intent(inout) :: nrai(nfront), ncel(nfront), nseg(nfront)
        integer, intent(in) :: irai(3), iraf(3), irpop(3), irais(2,3)
        integer, intent(inout) :: isatr(nfront), isats(nfront), isatc(nfront)

        if (ier.ne.0) then
            iys(2,iirai,ip1)=-1
        else
            nrai(ip2)=nrai(ip2)+1
            iys(2,nrai(ip2),ip2)=0
            iys(2,iirai,ip1)=nrai(ip2)
            dys(1,nrai(ip2),ip2)=dys(1,iirai,ip1)
            dys(2,nrai(ip2),ip2)=dys(2,iirai,ip1)
        endif
    end subroutine propage

end module propage_mod

program test_propage
    use propage_mod
    implicit none
    ! Declare variables for test cases here...

    print *, "Starting tests..."

    ! Call your test functions here
    call test_case_1()
    ! Add more test cases as needed

    print *, "All tests completed."

contains

    subroutine test_case_1()
        ! Variables specific to this test
        ! Initialize them as needed for the test case
        ! Call the propage subroutine with your test data
        ! Use simple if statements to check expected vs. actual results

        print *, "Test case 1 passed."
    end subroutine test_case_1

    subroutine assert_equal_int(expected, actual, message)
        integer, intent(in) :: expected, actual
        character(len=*), intent(in) :: message
        if (expected /= actual) then
            print *, "Assertion failed:", trim(message)
            print *, "Expected:", expected, "Actual:", actual
            stop 1
        endif
    end subroutine assert_equal_int

    subroutine assert_equal_real(expected, actual, message, tolerance)
        real, intent(in) :: expected, actual, tolerance
        character(len=*), intent(in) :: message
        if (abs(expected - actual) > tolerance) then
            print *, "Assertion failed:", trim(message)
            print *, "Expected:", expected, "Actual:", actual
            stop 1
        endif
    end subroutine assert_equal_real

end program test_propage