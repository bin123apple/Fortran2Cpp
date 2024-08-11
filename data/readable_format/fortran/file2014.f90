program test_sub
  implicit none
  integer :: m

  ! Test 1: Original behavior
  call sub(0, m)
  print *, "Test 1 (Expect m=1): m =", m

  ! Test 2: Simulated 'hoge' behavior
  call hoge(2, m)
  print *, "Test 2 (Expect m=2): m =", m

  ! Test 3: Simulated 'hoge' behavior with out-of-range input
  call hoge(5, m)
  print *, "Test 3 (Expect m=1): m =", m

contains

  subroutine sub(l2, m)
    implicit none
    integer, intent(in) :: l2
    integer, intent(out) :: m
    m = 1
    if (l2 >= 1 .and. l2 <= 4) m = l2
  end subroutine sub

  subroutine hoge(l1, m)
    implicit none
    integer, intent(in) :: l1
    integer, intent(out) :: m
    m = 1
    if (l1 >= 1 .and. l1 <= 4) m = l1
  end subroutine hoge

end program test_sub