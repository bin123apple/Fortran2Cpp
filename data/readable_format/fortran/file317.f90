program test_optimize_message
  implicit none
  ! Call the subroutine
  call print_optimize_message

contains

  subroutine print_optimize_message
    implicit none
    print *, 'Preprocessor: '

! ARTED_SC
#ifdef ARTED_SC
    print *, '  ARTED_SC'
#endif

! ARTED_MS
#ifdef ARTED_MS
    print *, '  ARTED_MS'
#endif

! Add similar blocks for other conditions

  end subroutine print_optimize_message

end program test_optimize_message