module globalPHMF
  implicit none

  private
  public :: ioutPHMF, iprecision, ndigits, outfile

  integer :: ioutPHMF = 0
  integer :: iprecision = 2
  integer :: ndigits = 7
  character(len=30) :: outfile = 'PreHeadsMF_output.txt'
end module globalPHMF

program test_globalPHMF
    use globalPHMF
    implicit none

    ! Test initialization
    if (ioutPHMF /= 0) then
        print *, "Test failed for ioutPHMF"
    end if

    if (iprecision /= 2) then
        print *, "Test failed for iprecision"
    end if

    if (ndigits /= 7) then
        print *, "Test failed for ndigits"
    end if

    if (trim(outfile) /= 'PreHeadsMF_output.txt') then
        print *, "Test failed for outfile"
    end if

    ! Test modifications
    ioutPHMF = 1
    iprecision = 3
    ndigits = 8
    outfile = 'Modified_output.txt'

    if (ioutPHMF /= 1) then
        print *, "Modification test failed for ioutPHMF"
    end if

    if (iprecision /= 3) then
        print *, "Modification test failed for iprecision"
    end if

    if (ndigits /= 8) then
        print *, "Modification test failed for ndigits"
    end if

    if (trim(outfile) /= 'Modified_output.txt') then
        print *, "Modification test failed for outfile"
    end if

    print *, "Fortran tests completed."
end program test_globalPHMF