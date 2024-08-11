module pdt_m
  implicit none
  type :: vec(k)
     integer, len :: k=10
     integer :: foo(k)
  end type vec
contains
  function total(a)
    type(vec(k=*)), intent(in) :: a
    integer :: total
    
    total=sum(a%foo)
  end function total

  subroutine test_total()
    type(vec(k=5)) :: test_vec
    integer :: result

    test_vec%foo = (/1, 2, 3, 4, 5/)
    result = total(test_vec)
    if (result .eq. 15) then
        print *, "Test Passed: Sum is correct."
    else
        print *, "Test Failed: Sum is incorrect."
    endif
  end subroutine test_total
end module pdt_m

program test_pdt
  use pdt_m
  implicit none
  type(vec(k=123)) :: u

  call test_total() ! Call the test procedure

  u%foo=1
  if (total(u) .ne. u%k) STOP 1
end program test_pdt