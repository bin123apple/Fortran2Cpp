! Combined Fortran file with module and test routines
module embed_lstm_module
  implicit none
  private
  public :: diemlstmfw, dlemlstmfw, siemlstmfw, slemlstmfw

contains

  subroutine diemlstmfw()
    print *, "Running diemlstmfw"
    ! Placeholder for actual implementation
  end subroutine diemlstmfw

  subroutine dlemlstmfw()
    print *, "Running dlemlstmfw"
    ! Placeholder for actual implementation
  end subroutine dlemlstmfw

  subroutine siemlstmfw()
    print *, "Running siemlstmfw"
    ! Placeholder for actual implementation
  end subroutine siemlstmfw

  subroutine slemlstmfw()
    print *, "Running slemlstmfw"
    ! Placeholder for actual implementation
  end subroutine slemlstmfw

end module embed_lstm_module

program test_embed_lstm
  use embed_lstm_module
  implicit none

  call test_diemlstmfw()
  call test_dlemlstmfw()
  call test_siemlstmfw()
  call test_slemlstmfw()

  print *, "All tests passed successfully."

contains

  subroutine test_diemlstmfw()
    call diemlstmfw()
    print *, "diemlstmfw test passed."
  end subroutine test_diemlstmfw

  subroutine test_dlemlstmfw()
    call dlemlstmfw()
    print *, "dlemlstmfw test passed."
  end subroutine test_dlemlstmfw
  
  subroutine test_siemlstmfw()
    call siemlstmfw()
    print *, "siemlstmfw test passed."
  end subroutine test_siemlstmfw

  subroutine test_slemlstmfw()
    call slemlstmfw()
    print *, "slemlstmfw test passed."
  end subroutine test_slemlstmfw

end program test_embed_lstm