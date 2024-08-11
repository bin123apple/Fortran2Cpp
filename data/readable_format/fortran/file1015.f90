program test_dec_comparison_character
  implicit none
  character(len=1) :: a, b

  ! Test 1: A < B
  a = 'A'
  b = 'B'
  call test_comparison(a, b, "Test 1")

  ! Test 2: B > A
  a = 'B'
  b = 'A'
  call test_comparison(a, b, "Test 2")

contains

  subroutine test_comparison(a, b, test_name)
    character(len=1), intent(in) :: a, b
    character(len=*), intent(in) :: test_name
    print *, test_name
    if (a < b) then
      print *, a, "is less than", b
    else
      print *, a, "is not less than", b
    endif
  end subroutine test_comparison

end program test_dec_comparison_character