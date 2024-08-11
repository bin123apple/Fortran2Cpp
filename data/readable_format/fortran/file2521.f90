module var_sys_parameter
  implicit none

  public :: setDispSwitch
  character(len=4), public :: pp_kind = "NCPP"
  logical, public :: isRootRank = .false.
  logical, public :: isTestRank = .false.
  integer, public :: testRank = 1
  logical, public :: isParallelTest = .false.

contains

  subroutine setDispSwitch(myrank, nprocs)
    implicit none
    integer, intent(in) :: myrank, nprocs

#ifdef _ParallelTest_
    isParallelTest = .true.
#else
    isParallelTest = .false.
#endif

    isRootRank = (myrank == 0)
    isTestRank = (myrank == testRank)
    if (isParallelTest .and. nprocs > 9) then
       print *, 'nprocs > 9 is not suitable for parallel test'
       stop
    endif
  end subroutine setDispSwitch

end module var_sys_parameter

program test_var_sys_parameter
  use var_sys_parameter
  implicit none

  call setDispSwitch(0, 5)
  if (isRootRank .and. .not. isTestRank) then
    print *, "Test 1 Passed"
  else
    print *, "Test 1 Failed"
  endif

  call setDispSwitch(1, 5)
  if (.not. isRootRank .and. isTestRank) then
    print *, "Test 2 Passed"
  else
    print *, "Test 2 Failed"
  endif
end program test_var_sys_parameter