! data_proc.f90
module data_proc
  implicit none
  public :: print_data

  integer :: nproc
  integer :: mynum
  character(len=4) :: appnproc, appmynum
  logical :: lpr
  character(len=8) :: procstrg

contains

  subroutine print_data()
    print *, 'Testing data_proc module...'
    print *, 'nproc = ', nproc
    print *, 'mynum = ', mynum
    print *, 'appnproc = ', appnproc
    print *, 'appmynum = ', appmynum
    print *, 'lpr = ', lpr
    print *, 'procstrg = ', procstrg
  end subroutine print_data

end module data_proc

program test_data_proc
  use data_proc
  implicit none
  ! Initialize variables
  nproc = 2
  mynum = 1
  appnproc = '002 '
  appmynum = '001 '
  lpr = .true.
  procstrg = 'process1'
  ! Test and print the variables
  call print_data()
end program test_data_proc