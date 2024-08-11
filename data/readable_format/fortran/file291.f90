! modreport_and_tests.f90
module modreport
  implicit none
  integer :: tests, nfailed, npassed
  integer :: reportfileu
  character(len=256) :: reportfilename
  character(len=256) :: testplan_name
  character(len=256) :: tdirectory
  character(len=20) :: testunitname, inputf, outputf
end module modreport

program test_modreport
  use modreport
  implicit none

  ! Initialize module variables
  tests = 0
  nfailed = 0
  npassed = 0
  reportfileu = 0
  reportfilename = ''
  testplan_name = ''
  tdirectory = ''
  testunitname = ''
  inputf = ''
  outputf = ''

  ! Test initial state
  call assert_equals_int(tests, 0, 'tests initialization')
  call assert_equals_int(nfailed, 0, 'nfailed initialization')
  call assert_equals_int(npassed, 0, 'npassed initialization')
  call assert_equals_int(reportfileu, 0, 'reportfileu initialization')

  ! Modify and test
  tests = 5
  nfailed = 1
  npassed = 4
  reportfileu = 10
  reportfilename = 'report.txt'
  testplan_name = 'main plan'
  tdirectory = '/tmp'
  testunitname = 'unit1'
  inputf = 'input.txt'
  outputf = 'output.txt'

  call assert_equals_int(tests, 5, 'tests modification')
  call assert_equals_int(nfailed, 1, 'nfailed modification')
  call assert_equals_int(npassed, 4, 'npassed modification')
  call assert_equals_int(reportfileu, 10, 'reportfileu modification')

  print *, 'All tests passed.'

contains

  subroutine assert_equals_int(value, expected, message)
    implicit none
    integer, intent(in) :: value, expected
    character(len=*), intent(in) :: message
    if (value /= expected) then
      print *, 'Assertion failed:', trim(message)
      print *, 'Expected:', expected, 'but got:', value
      stop
    end if
  end subroutine assert_equals_int

end program test_modreport