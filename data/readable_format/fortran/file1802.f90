program test_finalizeoutput
implicit none
character(len=*), parameter :: testFileName = 'testReportFile.xml'
integer :: reportfileu

! Open a new file for testing
open(newunit=reportfileu, file=testFileName, status='replace', action='write')
call finalizeoutput(reportfileu)

! The file is closed by finalizeoutput, so we need to reopen it to check its contents
open(unit=10, file=testFileName, status='old', action='read')
call checkFileContents(10)
close(10)

end program test_finalizeoutput

subroutine finalizeoutput(reportfileu)
implicit none
integer, intent(in) :: reportfileu

write(reportfileu,*)"</report>"
close(reportfileu)

end subroutine finalizeoutput

subroutine checkFileContents(unitNumber)
integer, intent(in) :: unitNumber
character(len=200) :: line

read(unitNumber, *) line
if (trim(adjustl(line)) == "</report>") then
    print *, "Test passed."
else
    print *, "Test failed."
end if

end subroutine checkFileContents